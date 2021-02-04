import os
from pathlib import Path, PurePath

from pygccxml import utils
from pygccxml import declarations
from pygccxml import parser

from humon import humon, enums as humonEnums
from ..PlatformDef import PlatformDef
from . import CplusplusDiffs as StdDiffs

from ..enums import Enums, Enum


endl = '\n'

def reportEnums(enums):
    for name, values in enums.items():
        print (f"Enum found: {name}")
        for value in values:
            print (value)


def makeRelativePath(sourceDir, destinationPath):
    common = os.path.commonpath([sourceDir, destinationPath])
    relativePath = ''
    while str(sourceDir) != str(common):
        sourceDir = str(PurePath(sourceDir).parent)
        relativePath += '../'
    return os.path.join(relativePath, str(PurePath(destinationPath).relative_to(common)))


class CplusplusDef(PlatformDef):
    def __init__(self, project, node, defPath, backupDef=None, podsNode=None):
        super().__init__('c++', project, node, defPath, backupDef, podsNode)
        self.seenTypes = []
        self.collectionMakerMemo = set()
        self.getSearchPaths()
        self.searchPathsFound = False
        self.quotedSearchPaths = []
        self.systemSearchPaths = []
        self.loadDefaultPlatformDefs(self.__init__)
    
    def getSearchPaths(self):
        if self.searchPathsFound:
            return

        cp = project.doShellCommand('cpp -v /dev/null -o /dev/null')
        if cp.returncode == 0:
            sps = cp.stderr[
                cp.stderr.find('#include "..." search starts here:') : 
                cp.stderr.find('#include <...> search starts here:')].strip()
            spsp = sps.find('/')
            if spsp >= 0:
                sps = sps[spsp:]
                self.quotedSearchPaths = [p.strip() for p in sps.split('\n')]
            else:
                self.quotedSearchPaths = []

            sps = cp.stderr[
                cp.stderr.find('#include <...> search starts here:') : 
                cp.stderr.find('End of search list.')].strip()
            spsp = sps.find('/')
            if spsp >= 0:
                sps = sps[spsp:]
                self.systemSearchPaths = [p.strip() for p in sps.split('\n')]
            else:
                self.systemSearchPaths = []

        self.searchPathsFound = True


    def processNamespace(self, enums, ns, isCPlusPlus):
        for decl in ns.declarations:
            if hasattr(decl, "elaborated_type_specifier"):
                if decl.elaborated_type_specifier == "enum":
                    enumType = decl.partial_decl_string.replace('::', '.')
                    if enumType[0] == '.':
                        enumType = enumType[1:]
                    enums.addEnum('c++', Enum(enumType, decl.values, None, ns.name, isCPlusPlus))

        for decl in ns.declarations:
            if hasattr(decl, "decl_type"):
                typedefName = decl.partial_decl_string.replace('::', '.')
                if typedefName[0] == '.':
                    typedefName = typedefName[1:]
                declType = decl.decl_type.decl_string.replace('::', '.')
                if declType[0] == '.':
                    declType = declType[1:]
                enum = enums.getEnum(declType)
                if enum:
                    enums.addEnum('c++', Enum(typedefName, None, enum, ns.name, isCPlusPlus))
        
        for decl in ns.namespaces(allow_empty=True):
            self.processNamespace(enums, decl)


    def processHeader(self, filename, isSystemInclude, isCPlusPlus, enums):
        # Find the location of the xml generator (castxml or gccxml)
        generator_path, generator_name = utils.find_xml_generator()

        # Configure the xml generator
        if isSystemInclude:
            incPaths = self.systemSearchPaths
        else:
            incPaths = [*self.quotedSearchPaths, *self.systemSearchPaths]
        xml_generator_config = parser.xml_generator_configuration_t(
            xml_generator_path = generator_path,
            xml_generator = generator_name,
            cflags="-std=c++17",
            include_paths=incPaths)

        # Parse the c++ file
        decls = parser.parse([filename], xml_generator_config)

        # Get access to the global namespace
        global_namespace = declarations.get_global_namespace(decls)

        self.processNamespace(enums, global_namespace, isCPlusPlus)

        print ('Enums processed:')
        for enumName, enumVals in enums.getAllEnums().items():
            print(f'  {enumName}:')
            for enumValName, enumValVal in enumVals.values:
                print(f'    {enumValName}: {enumValVal}')
        return enums


    def getIncludeFiles(self):
        configIncFiles = self.node['includeFiles'].objectify()  # TODO: don't objectify here
        incFiles = []
        for inc in configIncFiles:
            if type(inc) is dict:
                incFiles.append((inc['file'], inc['system'] == 'true'))
            else:
                incFiles.append((inc, False))
        return incFiles


    def fixupScope(self, typeName):
        if typeName in ['size_t', 'string', 'string_view', 'array', 'pair', 'tuple', 'vector', 'set', 'unordered_set', 'map', 'unordered_map', 'optional', 'variant']:
            return 'std::' + typeName
        elif typeName in self.podsNode:
            namespace = self.getSetting('namespace')
            return f'{namespace}::{typeName}' if namespace else typeName
        return typeName.replace('.', '::')


    def const(self, typee):
        eastConst = self.getSetting('const') == 'east'
        if eastConst:
            return f'{typee} const'
        else:
            return f'const {typee}'
    

    def preprocessTypes(self):
        for podNode in self.podsNode:
            self.spreprocessTypesRec(podNode)


    def recordUseOfType(self, typeName):
        if typeName not in self.seenTypes:
            self.seenTypes.append(typeName)


    def seeUsedTypesRec(self, typeNode):
        for memberNode in typeNode:
            if memberNode.kind == humonEnums.NodeKind.VALUE:
                self.recordUseOfType(memberNode.value)
            elif memberNode.kind == humonEnums.NodeKind.DICT:
                self.recordUseOfType(memberNode['type'].value)
                ofNode = memberNode['of']
                if ofNode:
                    for ofElementNode in memberNode['of']:
                        self.seeUsedTypesRec(ofElementNode)


    def seeUsedTypes(self):
        for podNode in self.podsNode:
            self.seeUsedTypesRec(podNode)


    def getRecursiveType(self, typeNode):
        if typeNode.kind == humonEnums.NodeKind.VALUE:
            return self.fixupScope(typeNode.value)

        typeTypeNode = typeNode['type']
        builtType = self.fixupScope(typeTypeNode.value)

        ofNode = typeNode['of']
        if ofNode:
            builtType = f"{builtType}<"
            if ofNode.kind == humonEnums.NodeKind.LIST:
                builtType += ', '.join([f'{self.getRecursiveType(chNode)}' for chNode in ofNode])
            elif ofNode.kind == humonEnums.NodeKind.DICT:
                builtType = f"{builtType}{self.getRecursiveType(ofNode)}"
            else:
                builtType = f"{builtType}{self.fixupScope(ofNode.value)}"
            builtType = f"{builtType}>"

        return builtType        
    

    def getPodMemberPlatformType(self, memberNode):
        '''Return the full, flattened typename for the platform.'''
        return self.getRecursiveType(memberNode)

    
    def getPodMemberBaseType(self, memberNode):
        '''Return the top-level type (BOMA context).'''
        if memberNode.kind == humonEnums.NodeKind.VALUE:
            return memberNode.value
        elif memberNode.kind == humonEnums.NodeKind.DICT:
            return memberNode['type'].value


    def getPodMemberBasePlatformType(self, memberNode):
        '''Return the top-level type (platform context).'''
        return self.fixupScope(self.getPodMemberBaseType(memberNode))
    

    def getPodMemberTypeArgNodes(self, memberNode):
        ''' Return the template type parameters of the base type.'''
        if memberNode.kind == humonEnums.NodeKind.DICT:
            typeArgsNode = memberNode['of']
            if typeArgsNode.kind == humonEnums.NodeKind.VALUE:
                return [typeArgsNode]
            elif typeArgsNode.kind == humonEnums.NodeKind.DICT:
                return [typeArgsNode]
            elif typeArgsNode.kind == humonEnums.NodeKind.LIST:
                return [tan for tan in typeArgsNode]
        return []


    def ind(self, numTabs):
        return self.getIndent() * numTabs


    def cavePerson(self, msg):
        if self.getSetting('cavepersonCtrs') == 'true':
            return f'std::cout << "{msg}\\n";'
        else:
            return ''


    def getNamespaceScope(self):
        namespace = self.getSetting('namespace')
        usingNamespace = namespace != ''
        return f'{namespace}::' if usingNamespace else ''
    

    def getNoexceptStr(self):
        noexcept = self.getSetting('noexcept') == 'true'
        return ' noexcept' if noexcept else ''
    

    def genBomaStreamClass(self, ind):
        src = ''
        if self.getFeature('serialize'):
            src += f'''


{self.ind(ind + 0)}class bomaStream
{self.ind(ind + 0)}{{
{self.ind(ind + 0)}public:
{self.ind(ind + 1)}friend std::ostream & operator <<(std::ostream & out, bomaStream)
{self.ind(ind + 1)}{{
{self.ind(ind + 2)}out << std::boolalpha;
{self.ind(ind + 2)}return out;
{self.ind(ind + 1)}}}
{self.ind(ind + 0)}}};'''
        return src


    def genEnumDeserializer(self, enumName, enum, ind):
        src = ''
        enumType = enumName.replace('.', '::')
        src += f'''


{self.ind(ind + 0)}template <>
{self.ind(ind + 0)}struct hu::val<{enumType}>
{self.ind(ind + 0)}{{
{self.ind(ind + 1)}static inline {enumType} extract(hu::Node node){self.getNoexceptStr()}
{self.ind(ind + 1)}{{
{self.ind(ind + 2)}auto nodeVal = node.value().str().data();'''
        if enum.hasAttrib('flags'):
            src += f'''
{self.ind(ind + 2)}using enumIntType = std::underlying_type<{enumType}>::type;
{self.ind(ind + 2)}enumIntType e = 0;
{self.ind(ind + 2)}bool fromList = node.kind() == hu::NodeKind::list;
{self.ind(ind + 2)}if (fromList)
{self.ind(ind + 3)}{{ node = node.firstChild(); }}
{self.ind(ind + 2)}while(node)
{self.ind(ind + 2)}{{'''

        if enumName == 'VkStructureType':
            breakpoint()

        firstTime = True
        #breakpoint()
        for enumValName, enumValVal in enum.values:
            prefix = enumType
            if enum.hasAttrib('cStyle'):
                scopePos = prefix.rfind('::')
                if scopePos >= 0:
                    prefix = prefix[:scopePos + 1]
            
            modifiers = self.getModifiers(enumName)
            modName = enumValName
            modPrefix = modifiers.get('prefix')
            if modPrefix and len(modPrefix) > 0: # and modName.startswith(modPrefix):
                modName = modName[len(modPrefix):]
            postfix = modifiers.get('postfix')
            if postfix and len(postfix) > 0: # and modName.endswith(postfix):
                modName = modName[:len(modName) - len(postfix)]
            case = modifiers.get('case')
            if case == 'upper':
                modName = modName.lower()
            elif case == 'lower':
                modName = modName.upper()

            if firstTime:
                doElse = ''
                spaces = '     '
                firstTime = False
            else:
                doElse = 'else '
                spaces = ''

            if enum.hasAttrib('flags'):
                src += f'''
{self.ind(ind + 3)}{doElse}if {spaces}(std::strncmp(nodeVal, "{modName}", {len(modName)}) == 0) {{ e |= static_cast<enumIntType>({prefix}::{enumValName}); }}'''
            else:
                src += f'''
{self.ind(ind + 2)}if (std::strncmp(nodeVal, "{modName}", {len(modName)}) == 0) {{ return {prefix}::{enumValName}; }}'''

        if enum.hasAttrib('flags'):
            src += f'''
{self.ind(ind + 3)}if (fromList)
{self.ind(ind + 4)}{{ node = node.nextSibling(); }}
{self.ind(ind + 3)}else
{self.ind(ind + 4)}{{ break; }}
{self.ind(ind + 2)}}}
{self.ind(ind + 2)}return static_cast<{enumType}>(e);'''
        else:
            src += f'''
{self.ind(ind + 2)}return {{}};'''

        # TODO: define and extract a default value
        src += f'''
{self.ind(ind + 1)}}}
{self.ind(ind + 0)}}};'''
        return src


    def genEnumStreamInserter(self, enumName, enum, ind):
        src = ''
        if not self.getFeature('serialize'):
            return src

        enumType = enumName.replace('.', '::')
        src += f'''


{self.ind(ind + 0)}inline std::ostream & operator <<(std::ostream & out, {enumType} obj)
{self.ind(ind + 0)}{{
{self.ind(ind + 1)}using enumIntType = std::underlying_type<{enumType}>::type;'''
        if enum.hasAttrib('flags'):
            src += f'''
{self.ind(ind + 1)}enumIntType bits = static_cast<enumIntType>(obj);
{self.ind(ind + 1)}out << "[";'''
        else:
            src += f'''
{self.ind(ind + 1)}switch (obj)
{self.ind(ind + 1)}{{'''
        enumValues = enum.values
        if enum.hasAttrib('flags'):
            enumValues = reversed(enumValues)

        seenVals = set()
        for enumValName, enumValVal in enumValues:
            if enumValVal in seenVals:
                continue
            seenVals.add(enumValVal)

            prefix = enumType
            if enum.hasAttrib('cStyle'):
                scopePos = prefix.rfind('::')
                if scopePos >= 0:
                    prefix = prefix[:scopePos + 1]
            
            modifiers = self.getModifiers(enumName)
            modName = enumValName
            modPrefix = modifiers.get('prefix')
            if modPrefix and len(modPrefix) > 0: # and modName.startswith(modPrefix):
                modName = modName[len(modPrefix):]
            postfix = modifiers.get('postfix')
            if postfix and len(postfix) > 0: # and modName.endswith(postfix):
                modName = modName[:len(modName) - len(postfix)]
            case = modifiers.get('case')
            if case == 'upper':
                modName = modName.lower()
            elif case == 'lower':
                modName = modName.upper()

            if enum.hasAttrib('flags'):
                src += f'''
{self.ind(ind + 1)}if (bits & static_cast<enumIntType>({prefix}::{enumValName}))
{self.ind(ind + 1)}{{
{self.ind(ind + 2)}out << " {modName}";
{self.ind(ind + 2)}bits &= ~static_cast<enumIntType>({prefix}::{enumValName});
{self.ind(ind + 2)}if (! bits)
{self.ind(ind + 3)}{{ goto done; }}
{self.ind(ind + 1)}}}
'''
            else:
                src += f'''
{self.ind(ind + 1)}case {prefix}::{enumValName}:
{self.ind(ind + 2)}out << "{modName}";
{self.ind(ind + 2)}break;'''
        
        if enum.hasAttrib('flags'):
            src += f'''
{self.ind(ind + 0)}done:
{self.ind(ind + 1)}out << " ]";
'''
        else:
            src += f'''
{self.ind(ind + 1)}default:
{self.ind(ind + 2)}out << static_cast<enumIntType>(obj);
{self.ind(ind + 2)}break;
{self.ind(ind + 1)}}}
'''
        src += f'''
{self.ind(ind + 1)}return out;
{self.ind(ind + 0)}}}'''
        return src


    def generateCollectionStreamInserter(self, memo, memberNode, ind):
        src = ''
        if not self.getFeature('serialize') == 'true':
            return src

        mpt = self.getPodMemberPlatformType(memberNode)
        # TODO: memoize to only make one for each unique platform type
        if mpt in memo:
            return ''
        
        memo.add(mpt)

        noexcept = self.getSetting('noexcept') == 'true'
        noexceptStr = ' noexcept' if noexcept else ''
        namespace = self.getSetting('namespace')
        usingNamespace = namespace != ''
        if usingNamespace:
            scope = namespace + '::'

        mbt = self.getPodMemberBaseType(memberNode)
        if mbt in ['array', 'pair', 'tuple', 'vector', 'set', 'unordered_set', 'map', 'unordered_map', 'optional', 'variant']:
            mbpt = self.getPodMemberBasePlatformType(memberNode)
            mtas = self.getPodMemberTypeArgNodes(memberNode)

            for argNode in mtas:
                src += self.generateCollectionStreamInserter(memo, argNode, ind)

            src += f'''


{self.ind(ind + 0)}inline std::ostream & operator <<(std::ostream & out, {mpt} const & obj){noexceptStr}
{self.ind(ind + 0)}{{'''

            if mbt == 'array':
                elemPlatformType = self.getPodMemberPlatformType(mtas[0])
                mbta0 = self.getPodMemberBaseType(mtas[0])
                numElems = int(mtas[1].value)
                src += f"""
{self.ind(ind + 1)}out << '[';"""
                for i in range(0, numElems):
                    if i != 0:
                        src += f"""
{self.ind(ind + 1)}out << ' ';"""
                    src += f"""
{self.ind(ind + 1)}out << obj[{i}];"""
                src += f"""
{self.ind(ind + 1)}out << ']';"""

            elif mbt == 'pair':
                ept0 = self.getPodMemberPlatformType(mtas[0])
                ept1 = self.getPodMemberPlatformType(mtas[1])
                mbta0 = self.getPodMemberBaseType(mtas[0])
                mbta1 = self.getPodMemberBaseType(mtas[1])
                src += f"""
{self.ind(ind + 1)}out << '[';
{self.ind(ind + 1)}out << std::get<0>(obj);
{self.ind(ind + 1)}out << ' ';
{self.ind(ind + 1)}out << std::get<1>(obj);
{self.ind(ind + 1)}out << ']';"""

            elif mbt == 'tuple':
                epts = [self.getPodMemberPlatformType(mta) for mta in mtas]
                mbtas = [self.getPodMemberBaseType(mta) for mta in mtas]
                src += f"""
{self.ind(ind + 1)}out << '[';"""
                first = True
                for i in range(0, len(mbtas)):
                    mbtan = mbtas[i]
                    if not first:
                        src += f"""
{self.ind(ind + 1)}out << ' ';"""
                    else:
                        first = False
                    src += f"""
{self.ind(ind + 1)}out << std::get<{i}>(obj);"""
                src += f"""
{self.ind(ind + 1)}out << ']';"""

            elif mbt == 'vector' or mbt == 'set' or mbt == 'unordered_set':
                elemPlatformType = self.getPodMemberPlatformType(mtas[0])
                mbta0 = self.getPodMemberBaseType(mtas[0])
                src += f"""
{self.ind(ind + 1)}out << '[';
{self.ind(ind + 1)}bool firstTime = true;
{self.ind(ind + 1)}for (auto const & objmem : obj)
{self.ind(ind + 1)}{{
{self.ind(ind + 2)}if (firstTime)
{self.ind(ind + 3)}{{ firstTime = false; }}
{self.ind(ind + 2)}else
{self.ind(ind + 3)}{{ out << ' '; }}
{self.ind(ind + 2)}out << objmem;
{self.ind(ind + 1)}}}
{self.ind(ind + 1)}out << ']';"""

            elif mbt == 'map' or mbt == 'unordered_map':
                ept0 = self.getPodMemberPlatformType(mtas[0])
                ept1 = self.getPodMemberPlatformType(mtas[1])
                mbta0 = self.getPodMemberBaseType(mtas[0])
                mbta1 = self.getPodMemberBaseType(mtas[1])
                if mbta0 == 'optional':
                    raise RuntimeError('a map or unordered_map key cannot be optional.')
                src += f"""
{self.ind(ind + 1)}out << '{{';
{self.ind(ind + 1)}bool firstTime = true;
{self.ind(ind + 1)}for (auto & elem : obj)
{self.ind(ind + 1)}{{
{self.ind(ind + 2)}if (firstTime)
{self.ind(ind + 3)}{{ firstTime = false; }}
{self.ind(ind + 2)}else
{self.ind(ind + 3)}{{ out << ' '; }}
{self.ind(ind + 2)}out << elem.first << ": " << elem.second;
{self.ind(ind + 1)}}}
{self.ind(ind + 1)}out << '}}';"""

            elif mbt == 'optional':
                src += f"""
{self.ind(ind + 1)}if (obj.has_value())
{self.ind(ind + 2)}{{ out << * obj; }}
{self.ind(ind + 1)}else
{self.ind(ind + 2)}{{ out << '_'; }}"""

            elif mbt == 'variant':
                epts = [(self.getPodMemberPlatformType(mta), self.getPodMemberBaseType(mta), mta['alias']) for mta in mtas]
                mbtas = [self.getPodMemberBaseType(mta) for mta in mtas]
                firstTime = True
                for ept in epts:
                    platformType = ept[0]
                    aliasType = ept[1]
                    if ept[2]:
                        aliasType = ept[2]
                    if firstTime:
                        firstTime = False
                        src += f"""
{self.ind(ind + 1)}"""
                    else:
                        src += f"""
{self.ind(ind + 1)}else """
                    src += f"""if (auto p = std::get_if<{platformType}>(& obj); p) {{ out << *p << " @type: {aliasType}"; }}"""

            src += f'''
{self.ind(ind + 1)}return out;
{self.ind(ind + 0)}}}'''
        return src


    def generateCollectionMaker(self, memo, memberNode, ind):
        src = ''
        mpt = self.getPodMemberPlatformType(memberNode)
        # TODO: memoize to only make one for each unique platform type
        if mpt in memo:
            return ''
        
        memo.add(mpt)

        mbt = self.getPodMemberBaseType(memberNode)
        if mbt in ['array', 'pair', 'tuple', 'vector', 'set', 'unordered_set', 'map', 'unordered_map', 'optional', 'variant']:
            #breakpoint()
            mbpt = self.getPodMemberBasePlatformType(memberNode)
            mtas = self.getPodMemberTypeArgNodes(memberNode)

            noexcept = self.getSetting('noexcept') == 'true'
            noexceptStr = ' noexcept' if noexcept else ''

            for argNode in mtas:
                src += self.generateCollectionMaker(memo, argNode, ind)

            src += f'''


{self.ind(ind + 0)}template <>
{self.ind(ind + 0)}struct hu::val<{mpt}>
{self.ind(ind + 0)}{{
{self.ind(ind + 1)}static inline {mpt} extract(hu::Node const & node){noexceptStr}
{self.ind(ind + 1)}{{'''

            if mbt == 'array':
                elemPlatformType = self.getPodMemberPlatformType(mtas[0])
                numElems = int(mtas[1].value)
                src += f'''
{self.ind(ind + 2)}return {mpt} {{
{f",{endl}".join([f'{self.ind(ind + 3)}std::move(hu::val<{elemPlatformType}>::extract(node / {i}))' for i in range(0, numElems)])}
{self.ind(ind + 2)}}};'''

            elif mbt == 'pair':
                ept0 = self.getPodMemberPlatformType(mtas[0])
                ept1 = self.getPodMemberPlatformType(mtas[1])
                src += f'''
{self.ind(ind + 2)}return {mpt} {{
{self.ind(ind + 3)}std::move(hu::val<{ept0}>::extract(node / 0)),
{self.ind(ind + 3)}std::move(hu::val<{ept1}>::extract(node / 1))
{self.ind(ind + 2)}}};'''

            elif mbt == 'tuple':
                epts = [self.getPodMemberPlatformType(mta) for mta in mtas]
                src += f'''
{self.ind(ind + 2)}return {mpt} {{
{f',{endl}'.join([f"{self.ind(ind + 3)}std::move(hu::val<{epts[i]}>::extract(node / {i}))" for i in range(0, len(epts))])}
{self.ind(ind + 2)}}};'''

            elif mbt == 'vector' or mbt == 'set' or mbt == 'unordered_set':
                elemPlatformType = self.getPodMemberPlatformType(mtas[0])
                src += f'''
{self.ind(ind + 2)}{mpt} rv;
{self.ind(ind + 2)}for (hu::size_t i = 0; i < node.numChildren(); ++i)
{self.ind(ind + 2)}{{
{self.ind(ind + 3)}rv.emplace{'_back' if mbt == 'vector' else ''}(std::move(node / i % hu::val<{elemPlatformType}>{{}}));
{self.ind(ind + 2)}}}
{self.ind(ind + 2)}return rv;'''

            elif mbt == 'map' or mbt == 'unordered_map':
                eptkey = self.getPodMemberPlatformType(mtas[0])
                eptvalue = self.getPodMemberPlatformType(mtas[1])
                src += f'''
{self.ind(ind + 2)}{mpt} rv;
{self.ind(ind + 2)}for (hu::size_t i = 0; i < node.numChildren(); ++i)
{self.ind(ind + 2)}{{
{self.ind(ind + 3)}hu::Node elemNode = node / i;
{self.ind(ind + 3)}rv.emplace(std::move(hu::val<{eptkey}>::extract(elemNode.key().str())),
{self.ind(ind + 3)}           std::move(elemNode % hu::val<{eptvalue}>{{}}));
{self.ind(ind + 2)}}}
{self.ind(ind + 2)}return rv;'''

            elif mbt == 'optional':
                ept = self.getPodMemberPlatformType(mtas[0])
                src += f'''
{self.ind(ind + 2)}if (! node)
{self.ind(ind + 3)}{{ return {{}}; }}
{self.ind(ind + 2)}else if (node.kind() == hu::NodeKind::value && node.value().str() == "_")
{self.ind(ind + 3)}{{ return {{}}; }}
{self.ind(ind + 2)}else
{self.ind(ind + 3)}{{ return node % hu::val<{ept}>{{}}; }}'''

            elif mbt == 'variant':
                epts = [(self.getPodMemberPlatformType(mta), 
                        mta['alias'].value if mta['alias'] else self.getPodMemberBaseType(mta)) for mta in mtas]
                if self.getFeature('nullVariant') == 'default':
                    nullOperation = f'''return {{ }};'''
                else:
                    nullOperation = f'''throw std::runtime_error("Variant could not be initialized.");'''
                src += f'''
{self.ind(ind + 2)}hu::Token tok = node.annotation("type");
{self.ind(ind + 2)}if (! tok)
{self.ind(ind + 3)}{{ {nullOperation} }}
{self.ind(ind + 2)}std::string_view tokStr;'''
                for ept, alias in epts:
                    src += f'''
{self.ind(ind + 2)}tokStr = tok.str();
{self.ind(ind + 2)}if (tokStr == "{alias}")
{self.ind(ind + 3)}{{ return node % hu::val<{ept}>{{}}; }}'''
                src += f'''
{self.ind(ind + 2)}{nullOperation}'''

            src += f'''
{self.ind(ind + 1)}}}
{self.ind(ind + 0)}}};'''
        return src


    def genFriendDecls(self, podNode, ind):
        src = ''

        makingSwap = self.getFeature('copyable') == 'true' or self.getFeature('movable') == 'true'
        makingInserter = self.getFeature('serialize') == 'true'
        makingComparator = self.getFeature('comparable') == 'true'

        if makingSwap or makingInserter or makingComparator:
            src += f'''


{self.ind(ind + 0)}class {podNode.key};'''
            if makingSwap:
                src += f'''
{self.ind(ind + 0)}void swap({podNode.key} & lhs, {podNode.key} & rhs){self.getNoexceptStr()};'''
            if makingInserter:
                src += f'''
{self.ind(ind + 0)}std::ostream & operator <<(std::ostream & out, {podNode.key} const & obj){self.getNoexceptStr()};'''
        
            if makingComparator:
                src += f'''
{self.ind(ind + 0)}bool operator ==({podNode.key} const & lhs, {podNode.key} const & rhs) noexcept;
{self.ind(ind + 0)}bool operator !=({podNode.key} const & lhs, {podNode.key} const & rhs) noexcept;'''

        return src + f'''
'''


    def genDefaultConstructor(self, podNode, classScope, ind):
        src = ''
        if not self.getFeature('defaultConstructible') == 'true':
            return src

        if classScope:
            src += f'''
{self.ind(ind + 0)}{podNode.key}(){self.getNoexceptStr()};'''
        else:
            src += f'''


{self.ind(ind + 0)}{self.getNamespaceScope()}{podNode.key}::{podNode.key}(){self.getNoexceptStr()}
{self.ind(ind + 0)}{{
{self.ind(ind + 1)}{self.cavePerson(f'{self.getNamespaceScope()}{podNode.key}::ctr()')}
{self.ind(ind + 0)}}}'''
        return src


    def genMemberwiseConstructor(self, podNode, classScope, ind):
        src = ''
        if not self.getFeature('memberwiseConstructible') == 'true':
            return src

        if classScope:
            src += f'''
{self.ind(ind + 0)}{podNode.key}('''
        else:
            src += f'''


{self.ind(ind + 0)}{self.getNamespaceScope()}{podNode.key}::{podNode.key}('''

        firstTime = True
        for memberNode in podNode:
            memberName, memberType = memberNode.key, self.getPodMemberPlatformType(memberNode)
            if firstTime:
                firstTime = False
            else:
                src += ','

            if classScope:
                src += f'''
{self.ind(ind + 1)}{self.const(memberType)} & {memberName}'''
            else:
                src += f'''
{self.ind(ind + 1)}{self.const(memberType)} & {memberName}'''

        if classScope:
            src += f'''){self.getNoexceptStr()};'''
        else:
            src += f'''){self.getNoexceptStr()}
{self.ind(ind + 0)}: {f",{endl}{self.ind(ind + 0)}  ".join([f"{v.key}({v.key})" for v in podNode])}
{self.ind(ind + 0)}{{
{self.ind(ind + 1)}{self.cavePerson(f'{self.getNamespaceScope()}{podNode.key}::ctr(memberwise)')}
{self.ind(ind + 0)}}}'''
        return src


    def genHumonConstructor(self, podNode, classScope, ind):
        src = ''
        if not self.getFeature('deserialize') == 'true':
            return src

        if classScope:
            src += f'''
{self.ind(ind + 0)}{podNode.key}(hu::Node node){self.getNoexceptStr()};'''
        else:
            src += f'''


{self.ind(ind + 0)}{self.getNamespaceScope()}{podNode.key}::{podNode.key}(hu::Node node){self.getNoexceptStr()}
'''
            firstMember = True
            for memberNode in podNode:
                memberName, memberType = memberNode.key, self.getPodMemberPlatformType(memberNode)
                decl = f'{memberName}(node / "{memberName}" % hu::val<{memberType}>{{}})'
                if firstMember:
                    firstMember = False
                    src += f'{self.ind(ind + 0)}: '
                else:
                    src += f', \n{self.ind(ind + 0)}  '
                src += decl
            src += f'''
{self.ind(ind + 0)}{{
{self.ind(ind + 1)}{self.cavePerson(f'{self.getNamespaceScope()}{podNode.key}::ctr from humon')}
{self.ind(ind + 0)}}}'''
        return src
    

    def genCopyConstructor(self, podNode, classScope, ind):
        src = ''
        if classScope:
            src += f'''
{self.ind(ind + 0)}{podNode.key}({podNode.key} const & rhs){self.getNoexceptStr() if self.getFeature('copyable') else ' = delete'};'''
        elif self.getFeature('copyable'):
            src += f'''


{self.ind(ind + 0)}{self.getNamespaceScope()}{podNode.key}::{podNode.key}({self.getNamespaceScope()}{podNode.key} const & rhs){self.getNoexceptStr()}
'''
            firstMember = True
            for memberNode in podNode:             
                memberName, memberType = memberNode.key, self.getPodMemberPlatformType(memberNode)
                decl = f'{memberName}(rhs.{memberName})'
                if decl and len(decl) > 0:
                    if firstMember:
                        firstMember = False
                        src += f'{self.ind(ind + 0)}: '
                    else:
                        src += f', \n{self.ind(ind + 0)}  '
                    src += decl
            src += f'''
{self.ind(ind + 0)}{{
{self.ind(ind + 1)}{self.cavePerson(f'{self.getNamespaceScope()}{podNode.key}::copy ctr')}
{self.ind(ind + 0)}}}'''
        return src


    def genCopyAssignment(self, podNode, classScope, ind):
        src = ''
        if classScope:
            src += f'''
{self.ind(ind + 0)}{podNode.key} & operator =({self.getNamespaceScope()}{podNode.key} rhs){self.getNoexceptStr() if self.getFeature('copyable') else ' = delete'};'''
        elif self.getFeature('copyable'):
            src += f'''


{self.ind(ind + 0)}{self.getNamespaceScope()}{podNode.key} & {self.getNamespaceScope()}{podNode.key}::operator =({self.getNamespaceScope()}{podNode.key} rhs){self.getNoexceptStr()}
{{
{self.ind(ind + 1)}{self.cavePerson(f'{self.getNamespaceScope()}{podNode.key}::copy assign')}
{self.ind(ind + 1)}using std::swap;
{self.ind(ind + 1)}swap(*this, rhs);
{self.ind(ind + 1)}return *this;
}}'''
        return src


    def genMoveConstructor(self, podNode, classScope, ind):
        src = ''
        if classScope:
            src += f'''
{self.ind(ind + 0)}{podNode.key}({podNode.key} && rhs){self.getNoexceptStr() if self.getFeature('movable') else ' = delete'};'''
        elif self.getFeature('movable'):
            src += f'''


{self.ind(ind + 0)}{self.getNamespaceScope()}{podNode.key}::{podNode.key}({self.getNamespaceScope()}{podNode.key} && rhs){self.getNoexceptStr()}
'''
            firstMember = True
            for memberNode in podNode:
                memberName, memberType = memberNode.key, self.getPodMemberPlatformType(memberNode)
                decl = f'{memberName}(std::move(rhs.{memberName}))'
                if decl and len(decl) > 0:
                    if firstMember:
                        firstMember = False
                        src += f'{self.ind(ind + 0)}: '
                    else:
                        src += f', \n{self.ind(ind + 0)}  '
                    src += decl
            src += f'''
{self.ind(ind + 0)}{{
{self.ind(ind + 1)}{self.cavePerson(f'{self.getNamespaceScope()}{podNode.key}::move ctr')}
{self.ind(ind + 0)}}}'''
        return src


    def genMoveAssignment(self, podNode, classScope, ind):
        src = ''
        if classScope:
            src += f'''
{self.ind(ind + 0)}{self.getNamespaceScope()}{podNode.key} & operator =({self.getNamespaceScope()}{podNode.key} && rhs){self.getNoexceptStr() if self.getFeature('movable') else ' = delete'};'''
        elif self.getFeature('movable'):
            src += f'''


{self.ind(ind + 0)}{self.getNamespaceScope()}{podNode.key} & {self.getNamespaceScope()}{podNode.key}::operator =({self.getNamespaceScope()}{podNode.key} && rhs){self.getNoexceptStr()}
{self.ind(ind + 0)}{{
{self.ind(ind + 1)}{self.cavePerson(f'{self.getNamespaceScope()}{podNode.key}::move assign')}
{self.ind(ind + 1)}using std::swap;
{self.ind(ind + 1)}swap(*this, rhs);
{self.ind(ind + 1)}return *this;
{self.ind(ind + 0)}}}'''
        return src


    def genDestructor(self, podNode, classScope, ind):
        src = ''
        if classScope:
            src += f'''
{self.ind(ind + 0)}{'virtual ' if self.getFeature('virtualDestructor') else ''}~{podNode.key}();'''
        else:
            src += f'''


{self.ind(ind + 0)}{self.getNamespaceScope()}{podNode.key}::~{podNode.key}()
{{
{self.ind(ind + 1)}{self.cavePerson(f'{self.getNamespaceScope()}{podNode.key}::dtr')}
}}'''
        return src


    def genSwap(self, podNode, classScope, ind):
        src = ''
        if not self.getFeature('copyable') == 'true' and not self.getFeature('movable') == 'true':
            return src
        
        if classScope:
            src += f'''
{self.ind(ind + 0)}friend void {self.getNamespaceScope()}swap({self.getNamespaceScope()}{podNode.key} & lhs, {self.getNamespaceScope()}{podNode.key} & rhs){self.getNoexceptStr()};'''
        else:
            src += f'''


{self.ind(ind + 0)}void {self.getNamespaceScope()}swap({self.getNamespaceScope()}{podNode.key} & lhs, {self.getNamespaceScope()}{podNode.key} & rhs){self.getNoexceptStr()}
{self.ind(ind + 0)}{{
{self.ind(ind + 1)}using std::swap;
{"".join([f"{self.ind(ind + 1)}swap(lhs.{v.key}, rhs.{v.key});{endl}" for v in podNode])}{self.ind(ind + 0)}}}'''
        return src


    def genGet(self, podNode, memberNode, classScope, ind):
        src = ''
        if not self.getFeature('getters') == 'true':
            return src

        memberName, memberType = memberNode.key, self.getPodMemberPlatformType(memberNode)

        if classScope:
            src += f'''
{self.ind(ind + 0)}{self.const(memberType)} & get_{memberName}() const{self.getNoexceptStr()};'''
        else:
            src += f'''


{self.ind(ind + 0)}{self.const(memberType)} & {self.getNamespaceScope()}{podNode.key}::get_{memberName}() const{self.getNoexceptStr()}
{self.ind(ind + 0)}{{
{self.ind(ind + 1)}return {memberName};
{self.ind(ind + 0)}}}'''
        if not self.getFeature('nonConstGetters') == 'true':
            return src

        if classScope:
            src += f'''
{self.ind(ind + 0)}{memberType} &       get_{memberName}(){self.getNoexceptStr()};'''
        else:
            src += f'''


{self.ind(ind + 0)}{memberType} & {self.getNamespaceScope()}{podNode.key}::get_{memberName}(){self.getNoexceptStr()}
{self.ind(ind + 0)}{{
{self.ind(ind + 1)}return {memberName};
{self.ind(ind + 0)}}}'''
        return src


    def genSet(self, podNode, memberNode, classScope, ind):
        src = ''
        if not self.getFeature('setters') == 'true':
            return src

        memberName, memberType = memberNode.key, self.getPodMemberPlatformType(memberNode)
        if classScope:
            src += f'''
{self.ind(ind + 0)}void set_{memberName}({self.const(memberType)} & newVal){self.getNoexceptStr()};'''
        else:
            src += f'''


{self.ind(ind + 0)}void {self.getNamespaceScope()}{podNode.key}::set_{memberName}({self.const(memberType)} & newVal){self.getNoexceptStr()}
{self.ind(ind + 0)}{{
{self.ind(ind + 1)}{memberName} = newVal;
{self.ind(ind + 0)}}}'''
        return src


    def genSetByMove(self, podNode, memberNode, classScope, ind):
        src = ''
        if not self.getFeature('setByMovers') == 'true':
            return src

        memberName, memberType = memberNode.key, self.getPodMemberPlatformType(memberNode)

        if classScope:
            src += f'''
{self.ind(ind + 0)}void set_{memberName}({memberType} && newVal){self.getNoexceptStr()};'''
        else:
            src += f'''


{self.ind(ind + 0)}void {self.getNamespaceScope()}{podNode.key}::set_{memberName}({memberType} && newVal){self.getNoexceptStr()}
{self.ind(ind + 0)}{{
{self.ind(ind + 1)}using std::swap;
{self.ind(ind + 1)}swap({memberName}, newVal);
{self.ind(ind + 0)}}}'''
        return src


    def genStreamInserter(self, podNode, classScope, ind):
        src = ''
        if not self.getFeature('serialize') == 'true':
            return src

        if classScope:
            src += f'''
{self.ind(ind + 0)}friend std::ostream & operator <<(std::ostream & out, {podNode.key} const & obj){self.getNoexceptStr()};'''
        else:
            src += f'''


{self.ind(ind + 0)}std::ostream & {self.getNamespaceScope()}operator <<(std::ostream & out, {self.getNamespaceScope()}{podNode.key} const & obj){self.getNoexceptStr()}
{self.ind(ind + 0)}{{
{self.ind(ind + 1)}out << '{{';'''
            for memberNode in podNode:
                memberName, memberType = memberNode.key, self.getPodMemberPlatformType(memberNode)
                mbt = self.getPodMemberBaseType(memberNode)

                if mbt == 'optional':
                    src += f'''
{self.ind(ind + 1)}if (obj.{memberName}.has_value()) {{ out << " {memberName}: " << obj.{memberName}; }}'''
                else:
                    src += f'''
{self.ind(ind + 1)}out << " {memberName}: " << obj.{memberName};'''
            src += f'''
{self.ind(ind + 1)}out << '}}';
{self.ind(ind + 1)}return out;
{self.ind(ind + 0)}}}'''
        return src


    def genComparator(self, podNode, classScope, ind):
        src = ''
        if not self.getFeature('comparable') == 'true':
            return src

        if classScope:
            src += f'''
{self.ind(ind + 0)}friend bool operator ==({podNode.key} const & lhs, {podNode.key} const & rhs){self.getNoexceptStr()};
{self.ind(ind + 0)}friend bool operator !=({podNode.key} const & lhs, {podNode.key} const & rhs){self.getNoexceptStr()};'''

        else:
            src += f'''


{self.ind(ind + 0)}bool {self.getNamespaceScope()}operator ==({self.getNamespaceScope()}{podNode.key} const & lhs, {podNode.key} const & rhs){self.getNoexceptStr()}
{self.ind(ind + 0)}{{
{self.ind(ind + 1)}return'''
            if podNode.numChildren > 0:
                firstTime = True
                for memberNode in podNode:
                    memberName, memberType = memberNode.key, self.getPodMemberPlatformType(memberNode)
                    mbt = self.getPodMemberBaseType(memberNode)


                    if firstTime:
                        firstTime = False
                        src += ' '
                    else:
                        src += f'''
{self.ind(ind + 1)}    && '''

                    src += f'''lhs.{memberName} == rhs.{memberName}'''
            else:
                src += f''' true'''
            src += f''';
{self.ind(ind + 0)}}}


{self.ind(ind + 0)}bool {self.getNamespaceScope()}operator !=({podNode.key} const & lhs, {podNode.key} const & rhs) noexcept
{self.ind(ind + 0)}{{
{self.ind(ind + 1)}return !(lhs == rhs);
{self.ind(ind + 0)}}}'''

        return src


    def genDiffer(self, podNode, headerScope, classScope, ind):
        src = ''

        diffable = self.getFeature('diffable') == 'true'
        if not diffable:
            return src

        if headerScope:
            src += f'''
{self.ind(ind + 0)}template<>
{self.ind(ind + 0)}struct Diff<{podNode.key}>
{self.ind(ind + 0)}{{'''
            if podNode.numChildren > 0:
                src += f'''
{self.ind(ind + 1)}enum class Members
{self.ind(ind + 1)}{{'''
                for memberNode in podNode:
                    src += f'''
{self.ind(ind + 2)}{memberNode.key}'''
                    if memberNode.childOrdinal < podNode.numChildren - 1:
                        src += ','
                src += f'''
{self.ind(ind + 1)}}};'''

            src += f'''
{self.ind(ind + 1)}Diff() noexcept {{ }}
{self.ind(ind + 1)}Diff({podNode.key} const & lhs, {podNode.key} const & rhs) noexcept;
'''
            if podNode.numChildren > 0:
                src += f'''
{self.ind(ind + 1)}std::bitset<{podNode.numChildren}> memberDiffs;'''
            for memberNode in podNode:
                mbt = self.getPodMemberBaseType(memberNode)
                mpt = self.getPodMemberPlatformType(memberNode)
                mtas = self.getPodMemberTypeArgNodes(memberNode)

                if mbt in ['array', 'pair', 'tuple', 'vector', 'set', 'unordered_set', 'map', 'unordered_map', 'optional', 'variant']:
                    src += f'''
{self.ind(ind + 1)}Diff<{mpt}> {memberNode.key}_diffs;'''
            src += f'''
{self.ind(ind + 0)}}};'''

        elif classScope:
            src += f'''
{self.ind(ind + 0)}friend Diff<{podNode.key}>::Diff() noexcept;
{self.ind(ind + 0)}friend Diff<{podNode.key}>::Diff({podNode.key} const & lhs, {podNode.key} const & rhs) noexcept;'''

        else:   # in source scope, not class scope
            src += f'''


{self.ind(ind + 0)}{self.getNamespaceScope()}Diff<{self.getNamespaceScope()}{podNode.key}>::Diff({self.getNamespaceScope()}{podNode.key} const & lhs, {self.getNamespaceScope()}{podNode.key} const & rhs) noexcept'''
            if podNode.numChildren > 0:
                src += f'''
: memberDiffs('''
            for memberNode in podNode:
                if memberNode.childOrdinal > 0:
                    src += f'''        '''
                src += f'''(lhs.{memberNode.key} != rhs.{memberNode.key}) << static_cast<int>(Members::{memberNode.key})'''
                if memberNode.childOrdinal < podNode.numChildren - 1:
                    src += ' |\n'
                else:
                    src += ')'

            for memberNode in podNode:
                mbt = self.getPodMemberBaseType(memberNode)
                mpt = self.getPodMemberPlatformType(memberNode)
                mtas = self.getPodMemberTypeArgNodes(memberNode)

                if mbt in ['array', 'pair', 'tuple', 'vector', 'set', 'unordered_set', 'map', 'unordered_map', 'optional', 'variant']:
                    src += f''',
  {memberNode.key}_diffs(lhs.{memberNode.key}, rhs.{memberNode.key})'''
            src += f'''
{{ }}
'''

        return src


    def generateHeader(self):
        headerOnly = self.getSetting('headerOnly') == 'true'
        eastConst = self.getSetting('const') == 'east'
        noexcept = self.getSetting('noexcept') == 'true'
        noexceptStr = ' noexcept' if noexcept else ''
        namespace = self.getSetting('namespace')

        usingNamespace = namespace != ''
        ind = 0

        src = f'''#pragma once

// THIS IS A GENERATED FILE. It is a Boilermaker artifact.
// Do not bother modifying this file, as your build process will overwrite
// your changes.

#include <cstring>
#include <type_traits>'''

        self.seeUsedTypes()

        for typeName in self.seenTypes:
            if typeName == 'string':
                src += '''
#include <string>'''
            if typeName == 'string_view':
                src += '''
#include <string_view>'''
            elif typeName == 'array':
                src += '''
#include <array>'''
            elif typeName == 'pair':
                src += '''
#include <utility>'''
            elif typeName == 'tuple':
                src += '''
#include <tuple>'''
            elif typeName == 'vector':
                src += '''
#include <vector>'''
            elif typeName == 'set':
                src += '''
#include <set>'''
            elif typeName == 'unordered_set':
                src += '''
#include <unordered_set>'''
            elif typeName == 'map':
                src += '''
#include <map>'''
            elif typeName == 'unordered_map':
                src += '''
#include <unordered_map>'''
            elif typeName == 'optional':
                src += '''
#include <optional>'''
            elif typeName == 'variant':
                src += '''
#include <variant>'''

        if self.getFeature('deserialize') == 'true':
            src += '''
#include <humon/humon.hpp>'''

        if self.getFeature('diffable') == 'true':
            src += '''
#include <bitset>'''
            if (('array' in self.seenTypes or
                 'set' in self.seenTypes or
                 'unordered_set' in self.seenTypes or
                 'map' in self.seenTypes or
                 'unordered_map' in self.seenTypes) and 
                 'vector' not in self.seenTypes):
                src += '''
#include <vector>'''
            if (('array' in self.seenTypes) and 
                 'pair' not in self.seenTypes):
                src += '''
#include <utility>'''
            if (('vector' in self.seenTypes or
                 'set' in self.seenTypes or
                 'unordered_set' in self.seenTypes or
                 'map' in self.seenTypes or
                 'unordered_map' in self.seenTypes) and 
                 'tuple' not in self.seenTypes):
                src += '''
#include <tuple>'''
            if ('tuple') in self.seenTypes:
                src += '''
#include <functional>'''


        incFiles = self.getIncludeFiles()
        if incFiles:
            for incFile, isSystemInclude in incFiles:
                if isSystemInclude:
                    src += f'''
#include <{incFile}>'''
                else:
                    headerDir = os.path.dirname(self.getOutputPath('header'))
                    includePath = os.path.join(os.path.dirname(self.defPath), incFile['file'])
                    relativeIncPath = makeRelativePath(headerDir, includePath)
                    src += f'''
#include "{relativeIncPath}"'''

        # enum helpers
        for enumName, enum in self.enums.getAllEnums().items():
            # Skip any enums that have a typedef referencing them.
            if enum.isTypedefTarget:
                continue
            # Resolve typedefs to the tag.
            if enum.isTypedef:
                enum = enum.typedefOf

            src += self.genEnumDeserializer(enumName, enum, ind)

        if usingNamespace:
            src += f'''

{self.ind(ind + 0)}namespace {namespace}
{self.ind(ind + 0)}{{'''
            ind += 1

        # collection-level differs
        if self.getFeature('diffable') == 'true':
            src += StdDiffs.getDiff_template(self.ind, 1)
            if 'tuple' in self.seenTypes:
                src += StdDiffs.getDiff_tuple(self.ind, 1)
            if 'pair' in self.seenTypes:
                src += StdDiffs.getDiff_pair(self.ind, 1)
            if 'array' in self.seenTypes:
                src += StdDiffs.getDiff_array(self.ind, 1)
            if 'vector' in self.seenTypes:
                src += StdDiffs.getDiff_vector(self.ind, 1)
            if 'unordered_set' in self.seenTypes:
                src += StdDiffs.getDiff_unordered_set(self.ind, 1)
            if 'set' in self.seenTypes:
                src += StdDiffs.getDiff_set(self.ind, 1)
            if 'unordered_map' in self.seenTypes:
                src += StdDiffs.getDiff_unordered_map(self.ind, 1)
            if 'map' in self.seenTypes:
                src += StdDiffs.getDiff_map(self.ind, 1)

        # bomaStream
        src += self.genBomaStreamClass(ind)

        # enum stream inserters
        for enumName, enum in self.enums.getAllEnums().items():
            # Skip any enums that have a typedef referencing them.
            if enum.isTypedefTarget:
                continue
            # Resolve typedefs to the tag.
            if enum.isTypedef:
                enum = enum.typedefOf
            
            src += self.genEnumStreamInserter(enumName, enum, ind)

        # class decl
        memo = set()    # one memo to constrain them all
        for podNode in self.podsNode:
            src += self.genFriendDecls(podNode, ind)

            podName = podNode.key

            src += self.genDiffer(podNode, True, False, ind)

            src += f'''


{self.ind(ind + 0)}class {podName}
{self.ind(ind + 0)}{{
{self.ind(ind + 0)}public:'''
            ind += 1
            src += self.genDefaultConstructor(podNode, True, ind)
            src += self.genMemberwiseConstructor(podNode, True, ind)
            src += self.genHumonConstructor(podNode, True, ind)
            src += self.genCopyConstructor(podNode, True, ind)
            src += self.genCopyAssignment(podNode, True, ind)
            src += self.genMoveConstructor(podNode, True, ind)
            src += self.genMoveAssignment(podNode, True, ind)
            src += self.genDestructor(podNode, True, ind)
            src += self.genSwap(podNode, True, ind)

            for memberNode in podNode:
                src += self.genGet(podNode, memberNode, True, ind)
            for memberNode in podNode:
                src += self.genSet(podNode, memberNode, True, ind)
            for memberNode in podNode:
                src += self.genSetByMove(podNode, memberNode, True, ind)

            src += self.genStreamInserter(podNode, True, ind)
            src += self.genComparator(podNode, True, ind)
            src += self.genDiffer(podNode, False, True, ind)

            # TODO: other features here

            # members
            ind -= 1
            if self.getFeature('privateMembers') == 'true':
                src += f'''
{self.ind(ind + 0)}private:'''

            for memberNode in podNode:
                memberName, memberType = memberNode.key, self.getPodMemberPlatformType(memberNode)
                src += f'''
{self.ind(ind + 1)}{memberType} {memberName};'''

            # end of class def
            src += f'''
{self.ind(ind + 0)}}};'''

            # static stream inserters for std collections
            for memberNode in podNode:
                src += self.generateCollectionStreamInserter(memo, memberNode, ind)

        if usingNamespace:
            ind -= 1
            src += f'''
{self.ind(ind + 0)}}}'''
            ind -= 1

        if self.getFeature('deserialize') == 'true':
            for podNode in self.podsNode:
                podName = podNode.key
                if usingNamespace:
                    podName = f'{namespace}::{podName}'
                src += f'''


template<>
struct hu::val<{podName}>
{{
    static inline {podName} extract(hu::Node const & node){noexceptStr}
    {{
        return {podName}(node);
    }}
}};'''

        if headerOnly:
            src += f'''

'''
            for podNode in self.podsNode:
                # TODO: Use computed path from defs file
                src += f'''
#include "inl/_{podNode.key}.inl.hpp"'''

        return src


    def generateHeaderFile(self):
        src = self.generateHeader()

        #outputPath = self.getOutputPath('header')
        headerPath = self.getOutputPath('header')
        Path(os.path.dirname(headerPath)).mkdir(parents=True, exist_ok=True)

        print (f"Building header: {headerPath}")
        f = open(f"{headerPath}", 'wt')
        print(src, file = f)
        f.close()


    def generateSrc(self, podName):
        headerOnly = self.getSetting('headerOnly') == 'true'
        eastConst = self.getSetting('const') == 'east'
        noexcept = self.getSetting('noexcept') == 'true'
        noexceptStr = ' noexcept' if noexcept else ''
        namespace = self.getSetting('namespace')
        usingNamespace = namespace != ''
        if usingNamespace:
            scope = namespace + '::'

        src = '''// THIS IS A GENERATED FILE. It is a Boilermaker artifact.
// Do not bother modifying this file, as your build process will overwrite
// your changes.'''

        if self.getSetting('cavepersonCtrs') == 'true':
            src += '''

#include <iostream>'''

        if not headerOnly:
            headerPath = self.getOutputPath('header')
            headerFile = os.path.basename(headerPath)
            src += f'''
#include "../../inc/gen-boma/{headerFile}"'''

        podNode = self.getPodNode(podName)

        # static builders for std collections
        if not self.getSetting('headerOnly') == 'true':
            self.collectionMakerMemo = set()
        for memberNode in podNode:
            src += self.generateCollectionMaker(self.collectionMakerMemo, memberNode, 0)

        src += self.genDefaultConstructor(podNode, False, 0)
        src += self.genMemberwiseConstructor(podNode, False, 0)
        src += self.genHumonConstructor(podNode, False, 0)
        src += self.genCopyConstructor(podNode, False, 0)
        src += self.genCopyAssignment(podNode, False, 0)
        src += self.genMoveConstructor(podNode, False, 0)
        src += self.genMoveAssignment(podNode, False, 0)
        src += self.genDestructor(podNode, False, 0)
        src += self.genSwap(podNode, False, 0)

        for memberNode in podNode:
            src += self.genGet(podNode, memberNode, False, 0)
        for memberNode in podNode:
            src += self.genSet(podNode, memberNode, False, 0)
        for memberNode in podNode:
            src += self.genSetByMove(podNode, memberNode, False, 0)

        src += self.genStreamInserter(podNode, False, 0)
        src += self.genComparator(podNode, False, 0)
        src += self.genDiffer(podNode, False, False, 0)

        return src


    def generateSrcFiles(self):
        srcType = 'source'
        if self.getSetting('headerOnly') == 'true':
            srcType = 'inline'

        for podNode in self.podsNode:
            src = self.generateSrc(podNode.key)
            srcPath = self.getOutputPath(srcType, podNode.key)
            Path(os.path.dirname(srcPath)).mkdir(parents=True, exist_ok=True)

            print (f"Building source: {srcPath}")
            f = open(f"{srcPath}", 'wt')
            print(src, file = f)
            f.close()


    def generateArtifacts(self, podsNode, enums):
        self.podsNode = podsNode
        self.enums = enums
        self.seeUsedTypes()
        self.generateHeaderFile()
        self.generateSrcFiles()
    

    def generateEnumSuggestions(self, enums):
        def determineCommonPrePostfixLengthBetweenTwo(a, b, postfix):
            # I'm sure there's a pythonic way
            commonLength = 0
            for i in range(0, min(len(a), len(b))):
                idx = i if not postfix else -i - 1
                if a[idx] == b[idx]:
                    commonLength += 1
                else:
                    break

            # if the prefix ends in a non-_, dial it back until we find one
            # (also if postfix starts in a non-_...)
            
            #if commonLength < len(a):
            if True:
                idx = commonLength - 1 if not postfix else -commonLength
                while commonLength > 0 and a[idx] != '_':
                    commonLength -= 1
                    idx -= 1

            return commonLength


        def determineCommonPrePostfixLength(strs, postfix):
            cev = strs[0]
            commonLength = len(cev[0])
            for ev in strs[1:]:
                l = determineCommonPrePostfixLengthBetweenTwo(cev[0], ev[0], postfix)
                if l < commonLength:
                    commonLength = l
                if commonLength == 0:
                    break
            return commonLength
        
        self.enums = enums

        src = ''

        # looking for cStyle, flags
        src += f'''
            attributes: {{'''
        for enumName, enum in self.enums.getAllEnums().items():
            # TODO: This is Vulkan-specific! Parameterize this:
            attribs = []
            if enum.isCPlusPlus:
                attribs.append('cStyle')
            if 'FlagBits' in enumName:  # This is the Vulkan-specific part
                attribs.append('flags')

            ns = enum.namespaceName
            if ns == '::':
                ns = ''
            if len(attribs) > 0:
                src += f'''
                {ns}{enumName}: [{' '.join(attribs)}]'''

        src += f'''
            }}'''
        
        # looking for prefixes, postfixes
        src += f'''
            modifiers: {{'''
        for enumName, enum in self.enums.getAllEnums().items():
            mods = {}
            if len(enum.values) == 0:
                continue
            
            #if enumName == 'VkStructureType':
            #    breakpoint()

            #breakpoint()
            prefixLen = determineCommonPrePostfixLength(enum.values, False)
            if prefixLen > 0:
                mods['prefix'] = enum.values[0][0][0:prefixLen]

            postfixLen = determineCommonPrePostfixLength(enum.values, True)
            if postfixLen > 0:
                mods['postfix'] = enum.values[0][0][-postfixLen:]
            
            ns = enum.namespaceName
            if ns == '::':
                ns = ''

            if len(mods) > 0:
                src += f'''
                {ns}{enumName}: {{ {' '.join([f'{k}: {v}' for k, v in mods.items()])} }}'''
            
        src += f'''
            }}'''

        print (src)