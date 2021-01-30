import os
from pathlib import Path, PurePath

from pygccxml import utils
from pygccxml import declarations
from pygccxml import parser

from humon import humon, enums as humonEnums

from .enums import Enums, Enum

import subprocess

def doShellCommand(cmd):
    #print (f"{ansi.lt_black_fg}{cmd}{ansi.all_off}")
    return subprocess.run(cmd, shell=True, check=True, encoding='utf-8', capture_output=True)


class CplusplusEnums:
    def __init__(self):
        # get the search path
        cp = doShellCommand('cpp -v /dev/null -o /dev/null')
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
            print (self.quotedSearchPaths, self.systemSearchPaths)


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


