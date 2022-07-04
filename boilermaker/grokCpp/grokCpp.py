from .getSearchPaths_gnu import getSearchPaths as getSearchPaths_gnu
from ..props import Scribe, Props, PropertyBag
from ..enums import BomaEnumVal, BomaEnum
import pygccxml
from pathlib import Path


class GrokCpp:
    def __init__(self, runDefs, props):
        self.props = props
        self.runDefs = runDefs
        s = Scribe(props)
        projectDir = Path(s.getXProp('projectDir'))
        self.quotedSearchPaths, self.systemSearchPaths  = getSearchPaths_gnu(projectDir)


    def processSource(self, includeDecl):
        s = Scribe(self.props)
        tools = s.X(self.runDefs.get('tools', ''))

        generator_path, generator_name = pygccxml.utils.find_xml_generator()

        isSystemInclude = includeDecl.startswith('<') and includeDecl.endswith('>')
        isLocalInclude = includeDecl.startswith('"') and includeDecl.endswith('"')
        if isSystemInclude or isLocalInclude:
            include = includeDecl[1:len(includeDecl) - 1]

        # Configure the xml generator
        if isSystemInclude:
            incPaths = self.systemSearchPaths
        else:
            incPaths = [*self.quotedSearchPaths, *self.systemSearchPaths]

        cflags = ''

        if tools == 'gnu':
            language = s.X(self.runDefs.get('language', ''))
            version = s.X(self.runDefs.get('languageVersion', ''))
            languageStandard = s.X(self.runDefs.get('languageStandard', ''))
            if language == 'c':
                if languageStandard in [
                    'c89', 'c90', 'c99', 'c11', 'c17', 'c18', 'c2x',
                    'gnu89',
                    'iso9899:1990', 'gnu90',
                    'iso9899:199409',
                    'iso9899:1999', 'gnu99',
                    'iso9899:2011', 'gnu11',
                    'iso9899:2017','gnu17',
                    'iso9899:2018', 'gnu18',
                    'gnu2x']:
                    cflags = f'-std=c++98'  # We run C through g++ anyway.
                else:
                    raise RuntimeError(f'Unsupported C language version "{version}".')
            elif language == 'c++':
                if version in ['98', '11', '14', '17', '20']:
                    cflags = f'-std=c++{version}'
                else:
                    raise RuntimeError(f'Unsupported C++ language version "{version}".')
            else:
                raise RuntimeError(f'Unsupported language {language}.')
        else:
            RuntimeError(f'Invalid "tools" value: {tools}. Only "gnu" or "clang" are currently supported.')

        defines = self.runDefs.get('macros', {})
        defines = [f'{m} = {v}' if len(v) > 0 else f'{m}' for m, v in defines.items()]

        xml_generator_config = pygccxml.parser.xml_generator_configuration_t(
            xml_generator_path = generator_path,
            xml_generator = generator_name,
            cflags=cflags,
            include_paths=incPaths,
            define_symbols=defines)

        # Parse the include file
        decls = pygccxml.parser.parse([include], xml_generator_config)

        # Get access to the global namespace
        global_namespace = pygccxml.declarations.get_global_namespace(decls)

        return self._processNamespace(global_namespace, language == 'c++', includeDecl)


    def _processNamespace(self, ns, isScoped, include):
        accruedEnums = {}
        accruedChainStructEnums = {}
        accruedChainStructs = {}

        def findDecl(declName):
            for decl in ns.declarations:
                if decl.name == declName:
                    return decl
            return None

        def captureStruct(declName, structChain):
            def makeSubstructMembers(prefixName, memberVar, members):
                if memberVar.name == 'maxComputeWorkGroupCount':
                    breakpoint()
                numElements = 1
                nestedObj = None
                if hasattr(memberVar.decl_type, "size"):
                    numElements = memberVar.decl_type.size
                    nestedObj = findDecl(memberVar.decl_type.base.decl_string)
                elif hasattr(memberVar.decl_type, "declaration"):
                    nestedObj = findDecl(memberVar.decl_type.declaration.name)

                for i in range(0, numElements):
                    array_elem = f"_{i}" if numElements > 1 else ""
                    if nestedObj:
                        if hasattr(nestedObj, "elaborated_type_specifier"):
                            if nestedObj.elaborated_type_specifier == 'struct':
                                for v in nestedObj.variables():
                                    makeSubstructMembers(f'{prefixName}{memberVar.name}{array_elem}.', v, members)
                    else:
                        members.append((f'{prefixName}{memberVar.name}{array_elem}', memberVar.decl_type.decl_string))

                return members

            if declName == structChain['baseProviderStructName']:
                members = []
                for v in decl.variables():
                    makeSubstructMembers('', v, members)

                #if declName == 'VkPhysicalDeviceProperties':
                #    breakpoint()
                accruedChainStructs[declName] = {'members': members,
                                                 'sType': structChain['mainStructStype'],
                                                 'max': 1}
            elif struc := next((n for n in structChain['chainStructs'] if n['structName'] == declName), None):
                if struc != None:
                    members = []
                    for v in decl.variables():
                        makeSubstructMembers('', v, members)

                    accruedChainStructs[declName] = {'members': members,
                                                    'sType': struc['sType'],
                                                    'max': struc.get('max', 1)}

        for decl in ns.classes().declarations:
            for area, struc in self.runDefs.get('structureChains').items():
                if len(struc):
                    captureStruct(decl.name, struc)

        for name, struc in accruedChainStructs.items():
            e = self._makeChainStructEnum(name + '_members', struc, include)
            accruedChainStructEnums[e.name] = e

        #breakpoint()
        for decl in ns.declarations:
            if hasattr(decl, "elaborated_type_specifier"):
                if decl.elaborated_type_specifier == "enum":
                    enumType = decl.partial_decl_string.replace('::', '.')
                    #self.enums[enumType] = CfamilyEnum(enumType, decl.values, isScoped, self)
                    # instead of above, just make the EnumType object, and then .provideDefinition
                    e = self._extractEnum(decl, isScoped, include)
                    accruedEnums[e.name] = e

        for decl in ns.declarations:
            if hasattr(decl, "decl_type"):
                typedefName = decl.partial_decl_string.replace('::', '.')
                declType = decl.decl_type.decl_string.replace('::', '.')
                if enum := accruedEnums.get(declType):
                    # instead of above, just find the EnumType object, and then give it an alias
                    enum.aliases.append(typedefName)
                    # NOTE: Need to make Types.find() that matches type names AND aliases

        for decl in ns.namespaces(allow_empty=True):
            accruedEnums.update(self._processNamespace(decl, isScoped))

        return (accruedEnums, accruedChainStructEnums, accruedChainStructs)


    def _makeChainStructEnum(self, name, struc, include):
        bomaEnumName = name
        bomaNamespace = None

        bomaVals = []
        for i in range(0, len(struc['members'])):
            memb = struc['members'][i][0]
            if memb == 'sType' or memb == 'pNext':
                continue
            bomaVals.append(BomaEnumVal(memb.replace('.', '_'), len(bomaVals), ''))

        isScoped = True
        if self.runDefs.get('isScoped', None) != None:
            isScoped = self.runDefs['isScoped']

        e = BomaEnum(name=bomaEnumName, values=bomaVals, codeDecl='', include = [include],
                     namespace = bomaNamespace, hasCodeDefs=False, isFlags = False, isScoped = isScoped)

        return e


    def _extractEnum(self, pygccxmlDecl, isScoped, include):
        bomaEnumName = pygccxmlDecl.name
        bomaNamespace = pygccxmlDecl.partial_decl_string[:-len(bomaEnumName)].replace('::', '.')[:-1]

        vals = []
        cidx = 0
        for val in pygccxmlDecl.values:
            idx = val[1]
            if idx != cidx:
                cidx = idx
            vals.append(BomaEnumVal('', idx, val[0]))

        flags = self._translateDeclValsToBomaVals(bomaEnumName, vals)
        isScoped = (self.runDefs.get('isScoped', False) or
                    self.runDefs.get('language', 'c++') == 'c++')

        e = BomaEnum(name=bomaEnumName, values=vals, codeDecl=bomaEnumName.replace('.', '::'), include = [include],
                     namespace = bomaNamespace, hasCodeDefs=True, isFlags = flags, isScoped = isScoped)
        return e


    def _translateDeclValsToBomaVals(self, enumName, vals):
        #breakpoint()
        declValStrings = [v[0].codeDecl if type(v) is list else v.codeDecl for v in vals]
        eva = self._computeAttributes(enumName, declValStrings)

        def translateEnumVal(enumVal):
            val = enumVal
            val = val[eva.prefixLen:]
            if eva.suffixLen > 0:
                val = val[:-eva.suffixLen]
            if eva.case == 'lower':
                val = val.lower()
            elif eva.case == 'upper':
                val = val.upper()
            return val

        for val in vals:
            val.name = translateEnumVal(val.codeDecl)

        return eva.flags


    def _computeAttributes(self, enumName, declStringValues):
        class EnumValAttributes:
            def __init__(self):
                self.flags = False
                self.prefixLen = 0
                self.suffixLen = 0
                self.case = 'leaveIt'

        eva = EnumValAttributes()
        enumProps = self.runDefs.get('enums', {})

        if len(enumProps.get('flags', {})) > 0:
            for op, value in enumProps['flags'].items():
                if op == 'nameContains':
                    if value and type(value) is not str:
                        raise RuntimeError(f'platform/flags/nameContains must be a string value.')

                    if enumName.find(value) > 0:
                        eva.flags = True
                else:
                    raise RuntimeError(f'platform/flag contains an invalid operation "{op}".')

        if len(enumProps.get('prefix', {})) > 0:
            excludeCommon = False
            delimit = ''
            for op, value in enumProps['prefix'].items():
                if op == 'exclude':
                    if value and type(value) is not str:
                        raise RuntimeError(f'platform/prefix/exclude must be a string value.')
                    if value == 'common':
                        excludeCommon = True
                elif op == 'delimit':
                    if value and type(value) is not str:
                        raise RuntimeError(f'platform/prefix/delimit must be a string value.')
                    delimit = value
                else:
                    raise RuntimeError(f'platform/prefix contains an invalid operation "{op}".')

            if excludeCommon and len(declStringValues) > 1:
                eva.prefixLen = self.determineCommonPrefixAndSuffixLength(declStringValues, False, delimit)
            else:
                eva.prefixLen = 0

        if len(enumProps.get('suffix', {})) > 0:
            excludeCommon = False
            delimit = ''
            for op, value in enumProps['suffix'].items():
                if op == 'exclude':
                    if value and type(value) is not str:
                        raise RuntimeError(f'platform/suffix/exclude must be a string value.')
                    if value == 'common':
                        excludeCommon = True
                elif op == 'delimit':
                    if value and type(value) is not str:
                        raise RuntimeError(f'platform/suffix/delimit must be a string value.')
                    delimit = value
                else:
                    raise RuntimeError(f'platform/suffix contains an invalid operation "{op}".')

            if excludeCommon and len(declStringValues) > 1:
                eva.suffixLen = self.determineCommonPrefixAndSuffixLength(declStringValues, True, delimit)
            else:
                eva.suffixLen = 0

        if len(enumProps.get('case', {})) > 0:
            for op, value in enumProps['case'].items():
                if op == 'encode':
                    if value and type(value) is not str:
                        raise RuntimeError(f'platform/case/encode value must be a string value.')

                    if value in ['lower', 'upper', 'leaveIt']:
                        eva.case = value
                    else:
                        raise RuntimeError(f'platform/case/encode value must be one of "lower", "upper", or "leaveIt".)')
                else:
                    raise RuntimeError(f'platform/case contains an invalid operation "{op}".')

        return eva


    def _provideDeclValsToEnum(self, enum, declVals):
        enum.alreadyDefined = True
        for i in range(0, len(declVals)):
            declVal = declVals[i]
            if enum.values[i].numericValue != declVal[1]:
                raise RuntimeError(f'declVal / enum val mismatch')
            enum.values[i].codeDecl = declVal[0]
            s = Scribe(enum.props)
            enum.values[i].fullCodeDecl = f'{s.getXProp("namespaceForCode")}{declVal[0]}'.replace('.', '::')


    @staticmethod
    def determineCommonPrefixAndSuffixLengthBetweenTwo(a, b, postfix, delimit = None):
        # I'm sure there's a pythonic way
        commonLength = 0
        for i in range(0, min(len(a), len(b))):
            idx = i if not postfix else -i - 1
            if a[idx] == b[idx]:
                commonLength += 1
            else:
                break

        # if the prefix ends in a non-delimit, dial it back until we find one
        # (also if postfix starts in a non-_...)
        # TODO: Test multicharacter delimiters. I think this is wrong.

        #if commonLength < len(a):
        if delimit:
            if not postfix:
                idx = commonLength - 1
                while commonLength > 0 and a[idx:idx + len(delimit)] != delimit:
                    commonLength -= 1
                    idx -= 1
            else:
                idx = -commonLength
                while commonLength > 0 and a[idx:idx + len(delimit)] != delimit:
                    commonLength -= 1
                    idx += 1

        return commonLength


    @staticmethod
    def determineCommonPrefixAndSuffixLength(strs, postfix, delimit):
        cev = strs[0]
        commonLength = len(cev)
        for ev in strs[1:]:
            l = GrokCpp.determineCommonPrefixAndSuffixLengthBetweenTwo(cev, ev, postfix, delimit)
            if l < commonLength:
                commonLength = l
            if commonLength == 0:
                break
        return commonLength
