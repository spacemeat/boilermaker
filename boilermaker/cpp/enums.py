from .. import utilities
from ..enums import Enums as BaseEnums, Enum as BaseEnum
from .getSearchPaths_gnu import getSearchPaths as getSearchPaths_gnu
import pygccxml


class Enums(BaseEnums):
    def __init__(self, defsPath, defsData):
        super().__init__(defsData)

        tools = defsData.get('tools', 'gnu').lower()

        if tools == 'gnu':
            self.quotedSearchPaths, self.systemSearchPaths  = getSearchPaths_gnu()
        else:
            raise RuntimeError(f'Invalid tools for enum defs in {defsPath}.')

        self.enums = {}
        self.enumTypedefs = {}
        sources = utilities.listify(defsData.get('source', []))
        for sourceFilename in sources:
            _processSource(sourceFilename)

        attributes = defsData.get('attributes', {})
        


    def _processNamespace(self, enums, ns, isScoped):
        for decl in ns.declarations:
            if hasattr(decl, "elaborated_type_specifier"):
                if decl.elaborated_type_specifier == "enum":
                    enumType = decl.partial_decl_string.replace('::', '.')
                    self.enums[enumType] = Enum(enumType, decl.values, ns.name, isScoped)

        for decl in ns.declarations:
            if hasattr(decl, "decl_type"):
                typedefName = decl.partial_decl_string.replace('::', '.')
                declType = decl.decl_type.decl_string.replace('::', '.')
                enum = enums.getEnum(declType)
                if enum:
                    self.enumTypedefs[typedefName] = EnumTypedef(typedefName, declType, ns.name)
        
        for decl in ns.namespaces(allow_empty=True):
            self._processNamespace(enums, decl, isScoped)


    def _processSource(self, sourceFilename):
        enums = {}
        generator_path, generator_name = pygccxml.utils.find_xml_generator()

        # Configure the xml generator
        if isSystemInclude:
            incPaths = self.systemSearchPaths
        else:
            incPaths = [*self.quotedSearchPaths, *self.systemSearchPaths]
        
        cflags = ''
        languageVersion = self.defsData.get('languageVersion', 'c++17')[3:]
        if languageVersion in ['98', '11', '14', '17', '20']:
            cflags = f'-std=c++{languageVersion}'

        xml_generator_config = pygccxml.parser.xml_generator_configuration_t(
            xml_generator_path = generator_path,
            xml_generator = generator_name,
            cflags=clfags,
            include_paths=incPaths)
        
        # Parse the c++ file
        decls = pygccxml.parser.parse([sourceFilename], xml_generator_config)

        # Get access to the global namespace
        global_namespace = pygccxml.declarations.get_global_namespace(decls)

        self._processNamespace(enums, global_namespace, True)


class Enum(BaseEnum):
    def __init__(self, enumName, enumVals, namespaceName, isScoped, enumDefsData):

        super().__init__(self, enumName)
        self.namespaceName = namespaceName
        self.isScoped = isScoped

        