import os
from pathlib import Path, PurePath

from pygccxml import utils
from pygccxml import declarations
from pygccxml import parser

from humon import humon, enums as humonEnums

from pprint import PrettyPrinter
from .enums import Enums, Enum


class CplusplusEnums:
    def __init__(self):
        pass

    def processNamespace(self, enums, ns):
        for decl in ns.declarations:
            if hasattr(decl, "elaborated_type_specifier"):
                if decl.elaborated_type_specifier == "enum":
                    enumType = decl.partial_decl_string.replace('::', '.')
                    if enumType[0] == '.':
                        enumType = enumType[1:]
                    enums.addEnum('c++', Enum(enumType, decl.values, None))

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
                    enums.addEnum('c++', Enum(typedefName, None, enum))
        
        for decl in ns.namespaces(allow_empty=True):
            self.processNamespace(enums, decl)


    def processHeader(self, filename, enums):
        # Find the location of the xml generator (castxml or gccxml)
        generator_path, generator_name = utils.find_xml_generator()

        # Configure the xml generator
        xml_generator_config = parser.xml_generator_configuration_t(
            xml_generator_path = generator_path,
            xml_generator = generator_name)

        # Parse the c++ file
        decls = parser.parse([filename], xml_generator_config)

        # Get access to the global namespace
        global_namespace = declarations.get_global_namespace(decls)

        self.processNamespace(enums, global_namespace)

        print ('Enums processed:')
        for enumName, enumVals in enums.getAllEnums().items():
            print(f'  {enumName}:')
            for enumValName, enumValVal in enumVals.values:
                print(f'    {enumValName}: {enumValVal}')
        return enums


