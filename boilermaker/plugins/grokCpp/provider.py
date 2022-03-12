from ...plugin import Provider
from ...props import Scribe
from .enums import makeEnums
from .getSearchPaths_gnu import getSearchPaths as getSearchPaths_gnu
import pygccxml
from pathlib import Path


class grokCppProvider(Provider):
    def start(self, runDefs, props):
        print (f'starting grokCppProvider')
        self.runDefs = runDefs

        s = Scribe(props)
        projectDir = Path(s.X('projectDir'))

        self.quotedSearchPaths, self.systemSearchPaths  = getSearchPaths_gnu(projectDir)

        # parse source files here
        sources = runDefs.get('source')
        if type(sources) is str:
            sources = [sources]

        for source in sources:
            self._processSource(source)


    def do(self, op, seq, props):
        print (f'grokCppProvider doing op {op} at sequence {seq}')
        makeEnums(self.runDefs, props)


    def stop(self, props):
        print (f'stopping grokCppProvider')


    def _processSource(self, sourceFilename):
        s = Scribe(self.props)
        tools = s.X(self.enumProps.get('tools', ''))

        enums = {}
        generator_path, generator_name = pygccxml.utils.find_xml_generator()

        isSystemInclude = sourceFilename.startswith('<') and sourceFilename.endswith('>')
        if isSystemInclude:
            sourceFilename = sourceFilename[1:len(sourceFilename) - 1]

        # Configure the xml generator
        if isSystemInclude:
            incPaths = self.systemSearchPaths
        else:
            incPaths = [*self.quotedSearchPaths, *self.systemSearchPaths]

        cflags = ''

        if tools == 'gnu':
            language = s.X(self.enumProps.get('language', ''))
            version = s.X(self.enumProps.get('languageVersion', ''))
            languageStandard = s.X(self.enumProps.get('languageStandard', ''))
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

        xml_generator_config = pygccxml.parser.xml_generator_configuration_t(
            xml_generator_path = generator_path,
            xml_generator = generator_name,
            cflags=cflags,
            include_paths=incPaths)

        # Parse the include file
        decls = pygccxml.parser.parse([sourceFilename], xml_generator_config)

        # Get access to the global namespace
        global_namespace = pygccxml.declarations.get_global_namespace(decls)

        self._processNamespace(enums, global_namespace, language == 'c++')


    def _processNamespace(self, ns, isScoped):
        for decl in ns.declarations:
            if hasattr(decl, "elaborated_type_specifier"):
                if decl.elaborated_type_specifier == "enum":
                    enumType = decl.partial_decl_string.replace('::', '.')
                    self.enums[enumType] = CfamilyEnum(enumType, decl.values, isScoped, self)
                    # instead of above, just make the EnumType object, and then .provideDefinition

        for decl in ns.declarations:
            if hasattr(decl, "decl_type"):
                typedefName = decl.partial_decl_string.replace('::', '.')
                declType = decl.decl_type.decl_string.replace('::', '.')
                enum = self.enums.get(declType)
                if enum:
                    self.enumTypedefs[typedefName] = EnumTypedef(typedefName, declType, ns.name)
                    # instead of above, just find the EnumType object, and then give it an alias
                    # NOTE: Need to make Types.find() that matches type names AND aliases

        for decl in ns.namespaces(allow_empty=True):
            self._processNamespace(decl, isScoped)


    def makeEnums_old(self, props):
        s = Scribe(props)
        self.enums = []
        enumProps = self.run
        for enumPropsList in s.getXPropAll('enums'):
            if type(enumPropsList) is dict:
                enumPropsList = [enumPropsList]
            for enumProps in enumPropsList:
                language = enumProps.get('language', '')
                languageVersion = enumProps.get('languageVersion', '')
                if language == "c" or language == 'c++':
                    self.enums.append(CfamilyEnums(props, enumProps))
                else:
                    raise RuntimeError(f'Unrecognized enums language: {language}')
        props.push({'enums': self.enums})


