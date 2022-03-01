from ... import utilities
from ...enums import Enums, Enum, EnumTypedef
from .getSearchPaths_gnu import getSearchPaths as getSearchPaths_gnu
from pathlib import Path
import pygccxml


class CfamilyEnums(Enums):
    def __init__(self, props, enumProps):
        super().__init__(props, enumProps)

        tools = self.props.X(enumProps.get('tools', 'gnu')).lower()
        projectPath = Path(props.getXProp('projectPath'))

        if tools == 'gnu':
            self.quotedSearchPaths, self.systemSearchPaths  = getSearchPaths_gnu(projectPath.parent)
        else:
            raise RuntimeError(f'Invalid tools for enum defs in {projectPath}.')

        self.enums = {}
        self.enumTypedefs = {}
        srcs = enumProps.get('source', [])
        if srcs != None:
            if type(srcs) is str:
                srcs = self.props.X(srcs)
                if type(srcs) is str:
                    srcs = [srcs]
            elif type(srcs) is list:
                srcs = [self.props.X(src) for src in srcs]
            else:
                raise RuntimeError('Invalid type for enums[\{source\}]')
            self.sources = srcs
            for sourceFilename in self.sources:
                self._processSource(sourceFilename)


    def _processNamespace(self, enums, ns, isScoped):
        for decl in ns.declarations:
            if hasattr(decl, "elaborated_type_specifier"):
                if decl.elaborated_type_specifier == "enum":
                    enumType = decl.partial_decl_string.replace('::', '.')
                    self.enums[enumType] = CfamilyEnum(enumType, decl.values, isScoped, self)

        for decl in ns.declarations:
            if hasattr(decl, "decl_type"):
                typedefName = decl.partial_decl_string.replace('::', '.')
                declType = decl.decl_type.decl_string.replace('::', '.')
                enum = enums.get(declType)
                if enum:
                    self.enumTypedefs[typedefName] = EnumTypedef(typedefName, declType, ns.name)

        for decl in ns.namespaces(allow_empty=True):
            self._processNamespace(enums, decl, isScoped)


    def _processSource(self, sourceFilename):
        tools = self.props.X(self.enumProps.get('tools', ''))

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
            language = self.props.X(self.enumProps.get('language', ''))
            version = self.props.X(self.enumProps.get('languageVersion', ''))
            languageStandard = self.props.X(self.enumProps.get('languageStandard', ''))
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


class CfamilyEnum(Enum):
    def __init__(self, enumName, pygccxmlEnumVals, isScoped, enumsObject):
        super().__init__(enumName, '.', enumsObject)
        self.isScoped = isScoped

        '''enumVals looks like {"r4g4_unorm_pack8": ("VK_FORMAT_R4G4_UNORM_PACK8", 1), ...}'''
        self.enumVals = self._translateEnumVals(enumName, pygccxmlEnumVals)


    def _translateEnumVals(self, enumName, pygccxmlEnumVals):
        declStringValues = [val[0] for val in pygccxmlEnumVals]
        self._computeAttributes(enumName, declStringValues)

        enums = {}
        for valName, valNumber in pygccxmlEnumVals:
            newEnumVal = self._translateEnumVal(valName)
            enums[newEnumVal] = (valName, valNumber)

        return enums
