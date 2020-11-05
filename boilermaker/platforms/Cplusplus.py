import os
from pathlib import Path, PurePath

from pygccxml import utils
from pygccxml import declarations
from pygccxml import parser

from humon import humon, enums as humonEnums
from ..PlatformDef import PlatformDef

from pprint import PrettyPrinter


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


def ind(indentChars, num):
    return indentChars * num


class CplusplusDef(PlatformDef):
    def __init__(self, node, defPath, backupDef=None, podsNode=None):
        super().__init__(node, defPath, backupDef, podsNode)
        self.seenTypes = []


    def getIncludeFiles(self):
        configIncFiles = self.node['includeFiles'].objectify()  # TODO: don't objectify here
        incFiles = []
        for inc in configIncFiles:
            if type(inc) == 'dict':
                incFiles.append((inc['file'], inc['system'] == 'true'))
            else:
                incFiles.append((inc, False))
        return incFiles


    def fixupScope(self, typeName):
        if typeName in ['string', 'string_view', 'array', 'pair', 'tuple', 'vector', 'map', 'unordered_map', 'optional', 'variant']:
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


    def recordUseOfType(self, typeName):
        if typeName not in self.seenTypes:
            self.seenTypes.append(typeName)


    def seeUsedTypesRec(self, typeNode):
        for memberNode in typeNode:
            if memberNode.kind == humonEnums.NodeKind.VALUE:
                self.recordUseOfType(memberNode.value)
            elif memberNode.kind == humonEnums.NodeKind.DICT:
                self.recordUseOfType(memberNode['type'].value)
                for ofNode in memberNode['of']:
                    self.seeUsedTypesRec(ofNode)


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
            elif typeArgsNode.kind == humonEnums.NodeKind.LIST:
                return [tan for tan in typeArgsNode]
        return []


    def genCtorSignature(self, podNode, indentStr):
        namespace = self.getSetting('namespace')
        usingNamespace = namespace != ''
        scope = f'{namespace}::' if usingNamespace else ''

        src = f'{podNode.key}('
        for memberNode in podNode:
            memberName, memberType = memberNode.key, self.getPodMemberPlatformType(memberNode)
            if src[-1] != '(':
                src += ',\n'
            else:
                src += '\n'
            src += f'{indentStr}{self.const(memberType)} & {memberName}'
        src += ')'
        return src


    def generateHeader(self):
        headerOnly = self.getSetting('headerOnly') == 'true'

        indentChars = self.getIndent()
        indent = 0
        nsIndent = ''
        clIndent = indentChars * 1
        memberIndent = indentChars * 2

        ic = self.getIndent()

        eastConst = self.getSetting('const') == 'east'
        noexcept = self.getSetting('noexcept') == 'true'
        noexceptStr = ' noexcept' if noexcept else ''
        namespace = self.getSetting('namespace')
        usingNamespace = namespace != ''

        src = '#include <cstring>\n'

        self.seeUsedTypes()

        for typeName in self.seenTypes:
            if typeName == 'string':
                src += '#include <string>\n'
            if typeName == 'string_view':
                src += '#include <string_view>\n'
            elif typeName == 'array':
                src += '#include <array>\n'
            elif typeName == 'pair':
                src += '#include <utility>\n'
            elif typeName == 'tuple':
                src += '#include <tuple>\n'
            elif typeName == 'vector':
                src += '#include <vector>\n'
            elif typeName == 'map':
                src += '#include <map>\n'
            elif typeName == 'unordered_map':
                src += '#include <unordered_map>\n'
            elif typeName == 'optional':
                src += '#include <optional>\n'
            elif typeName == 'variant':
                src += '#include <variant>\n'

        if self.getFeature('deserialize') == 'true':
                src += '#include <humon/humon.hpp>\n'

        incFiles = self.getIncludeFiles()
        if incFiles:
            for incFile, isSystemInclude in incFiles:
                if isSystemInclude:
                    src += f'#include <{incFile}>\n'
                else:
                    headerDir = os.path.dirname(self.getOutputPath('header'))
                    includePath = os.path.join(os.path.dirname(self.defPath), incFile)
                    relativeIncPath = makeRelativePath(headerDir, includePath)
                    src += f'#include "{relativeIncPath}"\n'
        src += '\n'

        # enum helpers
        for enumName, enum in self.enums.getAllEnums().items():
            # Skip any enums that have a typedef referencing them.
            if enum.isTypedefTarget:
                continue
            # Resolve typedefs to the tag.
            if enum.isTypedef:
                enum = enum.typedefOf
            enumType = enumName.replace('.', '::')
            src += f'''
{ind(ic, indent + 0)}template <>
{ind(ic, indent + 0)}struct hu::val<{enumType}>
{ind(ic, indent + 0)}{{
{ind(ic, indent + 1)}static inline {enumType} extract(hu::Node node){noexceptStr}
{ind(ic, indent + 1)}{{'''
            for enumValName, enumValVal in enum.values:
                prefix = enumType
                if enum.hasAttrib('cStyle'):
                    prefix = prefix[:prefix.rfind('::')]
                
                modifiers = self.getModifiers(enumName)
                modName = enumValName
                modPrefix = modifiers.get('prefix')
                if modPrefix and modName.startswith(modPrefix):
                    modName = modName[len(modPrefix):]
                postfix = modifiers.get('postfix')
                if postfix and modName.endswith(postfix):
                    modName = modName[:len(modName) - len(postfix)]
                case = modifiers.get('case')
                if case == 'toUpper':
                    modName = modName.lower()
                elif case == 'toLower':
                    modName = modName.upper()

                src += f'''
{ind(ic, indent + 2)}if (std::strncmp(node.value().str().data(), "{modName}", {len(modName)}) == 0) {{ return {prefix}::{enumValName}; }}'''

            # TODO: define and extract a default value
            src += f'''
{ind(ic, indent + 2)}return {{}};
{ind(ic, indent + 1)}}}
{ind(ic, indent + 0)}}};

'''

        if usingNamespace:
            src += f'\n{nsIndent}namespace {namespace}\n{nsIndent}{{\n'
            indent += 1
        
        if self.getFeature('serialize'):
            for enumName, enum in self.enums.getAllEnums().items():
                # Skip any enums that have a typedef referencing them.
                if enum.isTypedefTarget:
                    continue
                # Resolve typedefs to the tag.
                if enum.isTypedef:
                    enum = enum.typedefOf
                enumType = enumName.replace('.', '::')
                src += f"""
    inline std::ostream & operator <<(std::ostream & out, {enumType} obj)
    {{
        switch (obj)
        {{"""
                for enumValName, enumValVal in enum.values:
                    prefix = enumType
                    if enum.hasAttrib('cStyle'):
                        prefix = prefix[:prefix.rfind('::')]
                    
                    modifiers = self.getModifiers(enumName)
                    modName = enumValName
                    modPrefix = modifiers.get('prefix')
                    if modPrefix and modName.startswith(modPrefix):
                        modName = modName[len(modPrefix):]
                    postfix = modifiers.get('postfix')
                    if postfix and modName.endswith(postfix):
                        modName = modName[:len(modName) - len(postfix)]
                    case = modifiers.get('case')
                    if case == 'toUpper':
                        modName = modName.lower()
                    elif case == 'toLower':
                        modName = modName.upper()

                    src += f"""
        case {prefix}::{enumValName}:
            out << "{modName}";
            break;"""
                src += f"""
        default:
            out << (int) obj;
            break;
        }}

        return out;
    }}
"""
        # class decl
        memo = set()    # one memo to constrain them all
        for podNode in self.podsNode:
            # static stream inserters for std collections
            if self.getFeature('serialize') == 'true':
                for memberNode in podNode:
                    src += self.generateCollectionStreamInserter(memo, memberNode)

            podName = podNode.key
            src += f'''{clIndent}class {podName}
{clIndent}{{
{clIndent}public:
'''
            if self.getFeature('memberwiseConstructible') == 'true':
                src += f'''
{memberIndent}{self.genCtorSignature(podNode, ind(ic, indent + 2))}{noexceptStr};
'''
            if self.getFeature('defaultConstructible') == 'true':
                src += f'{memberIndent}{podName}(){noexceptStr};\n'

            if self.getFeature('deserialize') == 'true':
                src += f'{memberIndent}{podName}(hu::Node node){noexceptStr};\n'

            needSwap = False

            # copy ctr, copy assignment
            if not self.getFeature('copyable') == 'true':
                src += f'{memberIndent}{podName}({self.const(podName)} & rhs) = delete;\n'
                src += f'{memberIndent}{podName} & operator =({self.const(podName)} & rhs) = delete;\n'
            else:
                src += f'{memberIndent}{podName}({self.const(podName)} & rhs){noexceptStr};\n'
                src += f'{memberIndent}{podName} & operator =({podName} rhs){noexceptStr};\n'
                needSwap = True

            # move ctr, move assignment
            if not self.getFeature('movable') == 'true':
                src += f'{memberIndent}{podName}({podName} && rhs) = delete;\n'
                src += f'{memberIndent}{podName} & operator =({podName} && rhs) = delete;\n'
            else:
                src += f'{memberIndent}{podName}({podName} && rhs){noexceptStr};\n'
                src += f'{memberIndent}{podName} & operator =({podName} && rhs){noexceptStr};\n'
                needSwap = True

            # dtr
            src += f'{memberIndent}{"virtual " if self.getFeature("virtualDestructor") == "true" else ""}~{podName}();\n'

            if needSwap:
                endl = '\n'
                src += f'''
{memberIndent}friend void swap({podName} & lhs, {podName} & rhs){noexceptStr}
{memberIndent}{{
{memberIndent}    using std::swap;
{"".join([f"{memberIndent}    swap(lhs.{v.key}, rhs.{v.key});{endl}" for v in podNode])}{memberIndent}}}

'''

            # member getters
            if self.getFeature('getters') == 'true':
                for memberNode in podNode:
                    memberName, memberType = memberNode.key, self.getPodMemberPlatformType(memberNode)
                    src += f'{memberIndent}{self.const(memberType)} & get_{memberName}() const{noexceptStr};\n'
                    src += f'{memberIndent}{memberType} &       get_{memberName}(){noexceptStr};\n'
                src += '\n'

            # member setters
            if self.getFeature('setters') == 'true':
                for memberNode in podNode:
                    memberName, memberType = memberNode.key, self.getPodMemberPlatformType(memberNode)
                    src += f'{memberIndent}void set_{memberName}({self.const(memberType)} & newVal) noexcept;\n'
                src += '\n'

            # member setByMovers
            if self.getFeature('setByMovers') == 'true':
                for memberNode in podNode:
                    memberName, memberType = memberNode.key, self.getPodMemberPlatformType(memberNode)
                    src += f'{memberIndent}void set_{memberName}({memberType} && newVal) noexcept;\n'
                src += '\n'
            
            # stream inserters
            if self.getFeature('serialize') == 'true':
                src += f'''        friend std::ostream & operator <<(std::ostream & out, {podName} const & obj)
        {{
            out << '{{';'''
                for memberNode in podNode:
                    memberName, memberType = memberNode.key, self.getPodMemberPlatformType(memberNode)
                    mbt = self.getPodMemberBaseType(memberNode)

                    if mbt == 'optional':
                        src += f'''
            if (obj.{memberName}.has_value()) {{ out << " {memberName}: " << obj.{memberName}; }}'''

                    else:
                        src += f'''
            out << " {memberName}: " << obj.{memberName};'''
                src += f'''
            out << '}}';
            return out;
        }}

'''

            # TODO: other features here

            # members
            if self.getFeature('privateMembers') == 'true':
                src += f'{clIndent}private:\n'

            for memberNode in podNode:
                memberName, memberType = memberNode.key, self.getPodMemberPlatformType(memberNode)
                src += f'{memberIndent}{memberType} {memberName};\n'

            # end of class def
            src += f'{clIndent}}};\n\n'
            
            # TODO: Use computed path from defs file
            if headerOnly:
                src += f'#include "inl/_{podName}.inl.hpp"\n'

        if usingNamespace:
            src += f'{nsIndent}}}\n\n'
            indent -= 1

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
}};

'''

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


    def cavePerson(self, msg):
        if self.getSetting('cavepersonCtrs') == 'true':
            return f'std::cout << "{msg}\\n";\n'
        else:
            return ''


    def makeInitializerDecl(self, src, memberNode):
        memberName, memberType = memberNode.key, self.getPodMemberPlatformType(memberNode)
        memberBomaType = memberNode.value
        if memberNode.kind == humonEnums.NodeKind.DICT:
            memberBomaType = memberNode['type'].value
        return f'{memberName}(node / "{memberName}" % hu::val<{memberType}>{{}})'


    def generateCollectionMaker(self, memo, memberNode):
        src = ''
        mpt = self.getPodMemberPlatformType(memberNode)
        # TODO: memoize to only make one for each unique platform type
        if mpt in memo:
            return ''
        
        memo.add(mpt)

        mbt = self.getPodMemberBaseType(memberNode)
        if mbt in ['array', 'pair', 'tuple', 'vector', 'map', 'unordered_map', 'optional', 'variant']:
            mbpt = self.getPodMemberBasePlatformType(memberNode)
            mtas = self.getPodMemberTypeArgNodes(memberNode)

            noexcept = self.getSetting('noexcept') == 'true'
            noexceptStr = ' noexcept' if noexcept else ''

            for argNode in mtas:
                src += self.generateCollectionMaker(memo, argNode)

            src += f'''
template <>
struct hu::val<{mpt}>
{{
    static inline {mpt} extract(hu::Node const & node){noexceptStr}
    {{'''

            if mbt == 'array':
                elemPlatformType = self.getPodMemberPlatformType(mtas[0])
                numElems = int(mtas[1].value)
                endl = ',\n'
                src += f'''
        return {mpt} {{
{endl.join([f'            std::move(hu::val<{elemPlatformType}>::extract(node / {i}))' for i in range(0, numElems)])}
        }};'''

            elif mbt == 'pair':
                ept0 = self.getPodMemberPlatformType(mtas[0])
                ept1 = self.getPodMemberPlatformType(mtas[1])
                src += f'''
        return {mpt} {{
            std::move(hu::val<{ept0}>::extract(node / 0)),
            std::move(hu::val<{ept1}>::extract(node / 1))
        }};'''

            elif mbt == 'tuple':
                epts = [self.getPodMemberPlatformType(mta) for mta in mtas]
                endl = ',\n'
                src += f'''
        return {mpt} {{
{endl.join([f"            std::move(hu::val<{epts[i]}>::extract(node / {i}))" for i in range(0, len(epts))])}
        }};'''

            elif mbt == 'vector':
                elemPlatformType = self.getPodMemberPlatformType(mtas[0])
                src += f'''
        {mpt} rv;
        for (hu::size_t i = 0; i < node.numChildren(); ++i)
        {{
            rv.emplace_back(std::move(node / i % hu::val<{elemPlatformType}>{{}}));
        }}
        return rv;'''

            elif mbt == 'map':
                eptkey = self.getPodMemberPlatformType(mtas[0])
                eptvalue = self.getPodMemberPlatformType(mtas[1])
                src += f'''
        {mpt} rv;
        for (hu::size_t i = 0; i < node.numChildren(); ++i)
        {{
            hu::Node elemNode = node / i;
            rv.emplace(std::move(hu::val<{eptkey}>::extract(elemNode.key().str())),
                       std::move(elemNode % hu::val<{eptvalue}>{{}}));
        }}
        return rv;'''

            elif mbt == 'unordered_map':
                eptkey = self.getPodMemberPlatformType(mtas[0])
                eptvalue = self.getPodMemberPlatformType(mtas[1])
                src += f'''
        {mpt} rv;
        for (hu::size_t i = 0; i < node.numChildren(); ++i)
        {{
            hu::Node elemNode = node / i;
            rv.emplace(std::move(hu::val<{eptkey}>::extract(elemNode.key().str())),
                       std::move(elemNode % hu::val<{eptvalue}>{{}}));
        }}
        return rv;'''

            elif mbt == 'optional':
                ept = self.getPodMemberPlatformType(mtas[0])
                src += f'''
        if (! node)
            {{ return {{}}; }}
        else if (node.kind() == hu::NodeKind::value && node.value().str() == "_")
            {{ return {{}}; }}
        else
            {{ return node % hu::val<{ept}>{{}}; }}'''

            elif mbt == 'variant':
                epts = [(self.getPodMemberPlatformType(mta), 
                        mta['alias'].value if mta['alias'] else self.getPodMemberBaseType(mta)) for mta in mtas]
                src += f'''
        hu::Token tok = node.annotation("type");
        if (! tok)
            {{ return {{}}; }}
        std::string_view tokStr;'''
                for ept, alias in epts:
                    src += f'''
        tokStr = tok.str();
        if (tokStr == "{alias}")
            {{ return node % hu::val<{ept}>{{}}; }}'''
                src += f'''
        return {{}};'''

            src += f'''
    }}
}};
'''
        return src


    def generateCollectionStreamInserter(self, memo, memberNode):
        src = ''
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
        if mbt in ['array', 'pair', 'tuple', 'vector', 'map', 'unordered_map', 'optional', 'variant']:
            mbpt = self.getPodMemberBasePlatformType(memberNode)
            mtas = self.getPodMemberTypeArgNodes(memberNode)

            for argNode in mtas:
                src += self.generateCollectionStreamInserter(memo, argNode)

            src += f'''
    inline std::ostream & operator <<(std::ostream & out, {mpt} const & obj){noexceptStr}
    {{'''

            if mbt == 'array':
                elemPlatformType = self.getPodMemberPlatformType(mtas[0])
                mbta0 = self.getPodMemberBaseType(mtas[0])
                numElems = int(mtas[1].value)
                src += f"""
        out << '[';"""
                for i in range(0, numElems):
                    if i != 0:
                        src += f"""
        out << ' ';"""
                    src += f"""
        out << obj[{i}];"""
                src += f"""
        out << ']';"""

            elif mbt == 'pair':
                ept0 = self.getPodMemberPlatformType(mtas[0])
                ept1 = self.getPodMemberPlatformType(mtas[1])
                mbta0 = self.getPodMemberBaseType(mtas[0])
                mbta1 = self.getPodMemberBaseType(mtas[1])
                src += f"""
        out << '[';
        out << std::get<0>(obj);
        out << ' ';
        out << std::get<1>(obj);
        out << ']';"""

            elif mbt == 'tuple':
                epts = [self.getPodMemberPlatformType(mta) for mta in mtas]
                mbtas = [self.getPodMemberBaseType(mta) for mta in mtas]
                src += f"""
        out << '[';"""
                first = True
                for i in range(0, len(mbtas)):
                    mbtan = mbtas[i]
                    if not first:
                        src += f"""
        out << ' ';"""
                    else:
                        first = False
                    src += f"""
        out << std::get<{i}>().value();"""
                src += f"""
        out << ']';"""

            elif mbt == 'vector':
                elemPlatformType = self.getPodMemberPlatformType(mtas[0])
                mbta0 = self.getPodMemberBaseType(mtas[0])
                src += f"""
        out << '[';
        bool firstTime = true;
        for (auto const & objmem : obj)
        {{
            if (firstTime)
                {{ firstTime = false; }}
            else
                {{ out << ' '; }}
            out << objmem;
        }}
        out << ']';"""

            elif mbt == 'map' or mbt == 'unordered_map':
                ept0 = self.getPodMemberPlatformType(mtas[0])
                ept1 = self.getPodMemberPlatformType(mtas[1])
                mbta0 = self.getPodMemberBaseType(mtas[0])
                mbta1 = self.getPodMemberBaseType(mtas[1])
                if mbta0 == 'optional':
                    raise RuntimeError('a map or unordered_map key cannot be optional.')
                src += f"""
        out << '{{';
        bool firstTime = true;
        for (auto & elem : obj)
        {{
            if (firstTime)
                {{ firstTime = false; }}
            else
                {{ out << ' '; }}
            out << elem.first << ": " << elem.second;
        }}
        out << '}}';"""

            elif mbt == 'optional':
                src += f"""
        if (obj.has_value())
            {{ out << * obj; }}
        else
            {{ out << '_'; }}"""

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
        """
                    else:
                        src += f"""
        else """
                    src += f"""if (auto p = std::get_if<{platformType}>(& obj); p) {{ out << *p << " @type: {aliasType}"; }}"""

            src += f'''
        return out;
    }}

'''
        return src


    def generateSrc(self, podName):
        headerOnly = self.getSetting('headerOnly') == 'true'

        indentChars = self.getIndent()
        ind1 =     indentChars * 1
        ind____2 = indentChars * 2

        eastConst = self.getSetting('const') == 'east'
        noexcept = self.getSetting('noexcept') == 'true'
        noexceptStr = ' noexcept' if noexcept else ''
        namespace = self.getSetting('namespace')
        usingNamespace = namespace != ''
        if usingNamespace:
            scope = namespace + '::'

        src = ''
        if self.getSetting('cavepersonCtrs') == 'true':
            src += '#include <iostream>\n'

        if not headerOnly:
            headerPath = self.getOutputPath('header')
            headerFile = os.path.basename(headerPath)
            src += f'#include "../inc/{headerFile}"\n'

        podNode = self.getPodNode(podName)

        # static builders for std collections
        memo = set()
        for memberNode in podNode:
            src += self.generateCollectionMaker(memo, memberNode)

        # constructor
        endl = '\n'
        if self.getFeature('memberwiseConstructible') == 'true':
            src += f'''
{scope}{podName}::{self.genCtorSignature(podNode, "   ")}{noexceptStr}
: {f",{endl}  ".join([f"{v.key}({v.key})" for v in podNode])}
{{
{ind1}{self.cavePerson(f'{scope}{podName}::ctr')}
}}
'''

        if self.getFeature('defaultConstructible') == 'true':
            src += f'''
{scope}{podName}::{podName}(){noexceptStr}
{{
{ind1}{self.cavePerson(f'{scope}{podName}::default ctr')}
}}
'''

        dq = '"'
        if self.getFeature('deserialize') == 'true':
            src += f'''
{scope}{podName}::{podName}(hu::Node node){noexceptStr}
'''
            firstMember = True
            for memberNode in podNode:             
                decl = self.makeInitializerDecl(src, memberNode)
                if decl and len(decl) > 0:
                    if firstMember:
                        src += ': '
                    else:
                        src += ', \n  '
                    src += decl
                    firstMember = False
            src += f'''
{{
{ind1}{self.cavePerson(f'{scope}{podName}::ctr from humon')}
}}
'''

        needSwap = False

        if self.getFeature('copyable') == 'true':
            src += f'''
{scope}{podName}::{podName}({self.const(podName)} & rhs){noexceptStr}
: {f",{endl}  ".join([f"{v.key}(rhs.{v.key})" for v in podNode])}
{{
{ind1}{self.cavePerson(f'{scope}{podName}::copy ctr')}
}}
'''
            src += f'''
{scope}{podName} & {scope}{podName}::operator =({scope}{podName} rhs){noexceptStr}
{{
{ind1}{self.cavePerson(f'{scope}{podName}::copy assign')}
{ind1}using std::swap;    
{ind1}swap(*this, rhs);
{ind1}return *this;
}}
'''
            needSwap = True

        if self.getFeature('movable') == 'true':
            src += f'''
{scope}{podName}::{podName}({scope}{podName} && rhs){noexceptStr}
: {f",{endl}  ".join([f"{v.key}(std::move(rhs.{v.key}))" for v in podNode])}
{{
{ind1}{self.cavePerson(f'{scope}{podName}::move ctr')}
}}
'''
            src += f'''
{scope}{podName} & {scope}{podName}::operator =({scope}{podName} && rhs){noexceptStr}
{{
{ind1}{self.cavePerson(f'{scope}{podName}::move assign')}
{ind1}using std::swap;
{ind1}swap(*this, rhs);
{ind1}return *this;
}}
'''
            needSwap = True

        # dtr
        src += f'''
{"virtual " if self.getFeature("virtualDestructor" == "true") else ""}{scope}{podName}::~{podName}()
{{
{ind1}{self.cavePerson(f'{scope}{podName}::dtr')}
}}
'''

        # member getters
        if self.getFeature('getters') == 'true':
            for memberNode in podNode:
                memberName, memberType = memberNode.key, self.getPodMemberPlatformType(memberNode)
                src += f'''
{self.const(memberType)} & {scope}{podName}::get_{memberName}() const{noexceptStr}
{{
{ind1}return {memberName};
}}
'''
                src += f'''
{memberType} & {scope}{podName}::get_{memberName}(){noexceptStr}
{{
{ind1}return {memberName};
}}
'''
            src += '\n'

        # member setters
        if self.getFeature('setters') == 'true':
            for memberNode in podNode:
                memberName, memberType = memberNode.key, self.getPodMemberPlatformType(memberNode)
                src += f'''
void {scope}{podName}::set_{memberName}({self.const(memberType)} & newVal) noexcept
{{
{ind1}{memberName} = newVal;
}}
'''
            src += '\n'

        # member setByMovers
        if self.getFeature('setByMovers') == 'true':
            for memberNode in podNode:
                memberName, memberType = memberNode.key, self.getPodMemberPlatformType(memberNode)
                src += f'''
void {scope}{podName}::set_{memberName}({memberType} && newVal) noexcept
{{
{ind1}using std::swap;
{ind1}swap({memberName}, newVal);
}}
'''
            src += '\n'
        
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
