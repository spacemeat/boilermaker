from ...plugin import Provider
from ...props import Scribe, Props, PropertyBag
from ...enums import EnumType
from .getSearchPaths_gnu import getSearchPaths as getSearchPaths_gnu
import pygccxml
from pathlib import Path


class grokCppProvider(Provider):
    def start(self, runDefs, props):
        print (f'starting grokCppProvider')
        self.runDefs = runDefs
        self.props = props


    def do(self, op, seq):
        print (f'grokCppProvider doing op {op} at sequence {seq}')
        if op == 'makeEnums':
            self._parseSources()


    def stop(self):
        print (f'stopping grokCppProvider')


    def _parseSources(self):
        s = Scribe(self.props)
        projectDir = Path(s.getXProp('projectDir'))

        self.quotedSearchPaths, self.systemSearchPaths  = getSearchPaths_gnu(projectDir)

        sources = self.runDefs['sources']
        if type(sources) is str:
            sources = [sources]
            self.runDefs['sources'] = sources

        # at some point this might be like
        # enums = {} / types = {} / e, t = self._processSource(source)
        enums = {}
        for source in sources:
            enums.update(self._processSource(source))

        # update the boma enums dict with the new enums
        bomaEnums = self.props.getProp('bomaEnums')
        bomaEnums.update(enums)


    def _processSource(self, sourceFilename):
        s = Scribe(self.props)
        tools = s.X(self.runDefs.get('tools', ''))

        generator_path, generator_name = pygccxml.utils.find_xml_generator()

        isSystemInclude = sourceFilename.startswith('<') and sourceFilename.endswith('>')
        isLocalInclude = sourceFilename.startswith('"') and sourceFilename.endswith('"')
        if isSystemInclude or isLocalInclude:
            sourceFilename = sourceFilename[1:len(sourceFilename) - 1]

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
        decls = pygccxml.parser.parse([sourceFilename], xml_generator_config)

        # Get access to the global namespace
        global_namespace = pygccxml.declarations.get_global_namespace(decls)

        return self._processNamespace(global_namespace, language == 'c++')


    def _processNamespace(self, ns, isScoped):
        accruedEnums = {}
        for decl in ns.declarations:
            if hasattr(decl, "elaborated_type_specifier"):
                if decl.elaborated_type_specifier == "enum":
                    enumType = decl.partial_decl_string.replace('::', '.')
                    #self.enums[enumType] = CfamilyEnum(enumType, decl.values, isScoped, self)
                    # instead of above, just make the EnumType object, and then .provideDefinition
                    e = self._extractEnum(decl, isScoped)
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

        return accruedEnums


    def _extractEnum(self, pygccxmlDecl, isScoped):
        bomaEnumName = pygccxmlDecl.name
        bomaNamespace = pygccxmlDecl.partial_decl_string[:-len(bomaEnumName)].replace('::', '.')
        declVals = []
        bomaVals = []
        cidx = 0
        for val in pygccxmlDecl.values:
            idx = val[1]
            if idx != cidx:
                bomaVals.append([val[0], idx])
                cidx = idx
            else:
                bomaVals.append(val[0])
            declVals.append([val[0], val[1]])

        bomaVals, flags = self._translateDeclValsToBomaVals(bomaEnumName, declVals)
        isScoped = (self.runDefs.get('isScoped', False) or
                    self.runDefs.get('language', 'c++') == 'c++')

        props = self.props
        anchors = self.props.getProp('anchors')
        if anchors and 'anchors' in anchors:
            anch = props['anchors']
            if 'vulkanEnums' in anch:
                props = anch['vulkanEnums']

        propBag = props.props
        newBag = PropertyBag({
            'enumisScoped': isScoped,
            'enumflags': flags,
            'enumCodeCase': '',
            'enumCodePrefix': '',
            'enumCodeSuffix': ''
        })
        newBag.inherit(propBag)
        e = EnumType({'name': bomaEnumName, 'values': bomaVals}, Props(newBag))
        e.namespace = bomaNamespace
        e.include = self.runDefs.get('sources', [])
        e.codeDecl = bomaEnumName
        e.fullCodeDecl = f'{bomaNamespace}{e.codeDecl}'.replace('.', '::')
        self._provideDeclValsToEnum(e, declVals)
        return e


    def _translateDeclValsToBomaVals(self, enumName, declVals):
        declValStrings = [v[0] if type(v) is list else v for v in declVals]
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

        bomaVals = []
        cidx = 0
        for val in declVals:
            idx = val[1]
            if idx != cidx:
                bomaVals.append([translateEnumVal(val[0]), idx])
                cidx = idx
            else:
                bomaVals.append(translateEnumVal(val[0]))
            cidx += 1

        return (bomaVals, eva.flags)


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


    def _provideDeclValsToEnum(self, enum :EnumType, declVals):
        enum.alreadyDefined = True
        for i in range(0, len(declVals)):
            declVal = declVals[i]
            if enum.vals[i].numberValue != declVal[1]:
                raise RuntimeError(f'declVal / enum val mismatch')
            enum.vals[i].codeDecl = declVal[0]
            enum.vals[i].fullCodeDecl = f'{enum.namespace}{declVal[0]}'.replace('.', '::')


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
            l = grokCppProvider.determineCommonPrefixAndSuffixLengthBetweenTwo(cev, ev, postfix, delimit)
            if l < commonLength:
                commonLength = l
            if commonLength == 0:
                break
        return commonLength
