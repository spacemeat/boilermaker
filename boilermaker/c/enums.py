from .. import utilities
from ..enums import Enums as BaseEnums, Enum as BaseEnum
from ..cpp.getSearchPaths_gnu import getSearchPaths as getSearchPaths_gnu
import pygccxml


class Enums(BaseEnums):
    def __init__(self, defsData, enumDefsData):
        super().__init__(defsData, enumDefsData)

        tools = self.enumDefsData.get('tools', 'gnu').lower()

        if tools == 'gnu':
            self.quotedSearchPaths, self.systemSearchPaths  = getSearchPaths_gnu()
        else:
            raise RuntimeError(f'Invalid tools for enum defs in {defsPath}.')

        self.enums = {}
        self.enumTypedefs = {}
        sources = utilities.listify(enumDefsData.get('source', []))
        for sourceFilename in sources:
            self._processSource(sourceFilename)
        

    def _processNamespace(self, enums, ns):
        for decl in ns.declarations:
            if hasattr(decl, "elaborated_type_specifier"):
                if decl.elaborated_type_specifier == "enum":
                    enumType = decl.partial_decl_string.replace('::', '.')
                    self.enums[enumType] = Enum(enumType, decl.values, False, self)

        for decl in ns.declarations:
            if hasattr(decl, "decl_type"):
                typedefName = decl.partial_decl_string.replace('::', '.')
                declType = decl.decl_type.decl_string.replace('::', '.')
                enum = enums.get(declType)
                if enum:
                    self.enumTypedefs[typedefName] = EnumTypedef(typedefName, declType, ns.name)


    def _processSource(self, sourceFilename):
        tools = self.defsData.get('tools', 'gnu').lower()

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
        languageVersion = self.defsData.get('languageVersion', 'gnu17')[1:]
        if languageVersion in [
                'c89', 'gnu89',
                'c90', 'iso9899:1990', 'gnu90', 
                'iso9899:199409', 
                'c99', 'iso9899:1999', 'gnu99', 
                'c11', 'iso9899:2011', 'gnu11', 
                'c17', 'iso9899:2017','gnu17', 
                'c18', 'iso9899:2018', 'gnu18',
                'c2x', 'gnu2x']:
            cflags = f'-std={languageVersion}'

        xml_generator_config = pygccxml.parser.xml_generator_configuration_t(
            xml_generator_path = generator_path,
            xml_generator = generator_name,
            cflags=cflags,
            include_paths=incPaths)
        
        # Parse the c file
        decls = pygccxml.parser.parse([sourceFilename], xml_generator_config)

        # Get access to the global namespace
        global_namespace = pygccxml.declarations.get_global_namespace(decls)

        self._processNamespace(enums, global_namespace)


class Enum(BaseEnum):
    def __init__(self, enumName, pygccxmlEnumVals, isScoped, enumsObject):
        super().__init__(enumName, '.', enumsObject)
        self.isScoped = isScoped

        '''enumVals looks like {"r4g4_unorm_pack8": ("VK_FORMAT_R4G4_UNORM_PACK8", 1), ...}'''
        self.enumVals = self._translateEnumVals(enumName, pygccxmlEnumVals)


    def _translateEnumVals(self, enumName, pygccxmlEnumVals):
        #breakpoint()
        declStringValues = [val[0] for val in pygccxmlEnumVals]
        self._computeAttributes(enumName, declStringValues)

        enums = {}
        for valName, valNumber in pygccxmlEnumVals:
            newEnumVal = self._translateEnumVal(valName)
            enums[newEnumVal] = (valName, valNumber)

        return enums
