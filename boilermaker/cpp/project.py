from pathlib import Path
import os
from .. import utilities
from ..project import Project as BaseProject


class Project(BaseProject):
    from . import gen_enums
    from . import gen_global
    from . import gen_types
    from . import gen_containers
    from . import gen_diffs

    def __init__(self, defsData):
        super().__init__(defsData)
        self.includes = {}
        self.sections = {}
        self.includeDiffTypes = {}

        self.defsData['headerToInl'] = os.path.relpath(self.d('inlineDir'), self.d('headerDir'))
        self.defsData['srcToHeader'] = os.path.relpath(self.d('headerDir'), self.d('sourceDir'))
        self.defsData['srcToInl'] = os.path.relpath(self.d('inlineDir'), self.d('sourceDir'))
    

    def const(self, type):
        coast = self.d('constCoast', 'west')
        if coast == 'east':
            return f'const {type}'
        else:
            return f'{type} const'
    

    def _appendToSection(self, section, src):
        if section not in self.sections:
            self.sections[section] = src
        else:
            self.sections[section] += src
    

    def _addInclude(self, section, kindToInclude):
        '''section is like 'enumDeserializers' or 'someType|typeInlineSourceLocalIncludes'.'''
        '''kind is like 'containersInlineSource' or 'someType|typesSource'.'''
        if section not in self.includes:
            self.includes[section] = {kindToInclude: None}
        else:
            self.includes[section][kindToInclude] = None
    

    def makeNative(self, bomaName, useNamespace=False):
        if bomaName in ['size_t', 'string', 'string_view', 'array', 'pair', 'tuple', 'vector', 'set', 'unordered_set', 'map', 'unordered_map', 'optional', 'variant']:
            return 'std::' + bomaName
        elif useNamespace and bomaName in self.types:
            bomaName = f'{self.d("namespace")}::{bomaName}'
        return bomaName.replace('.', '::')


    def makeNativeMemberType(self, properties, useNamespace=False):
        def recurse(properties):
            builtType = self.makeNative(properties['type'], useNamespace)
            of = properties.get('of')
            if of:
                builtType += '<'
                if type(of) is list:
                    builtType += ', '.join([recurse(utilities.dictify(ch, 'type')) for ch in of])
                elif type(of) is dict:
                    builtType += recurse(of)
                else:
                    builtType += self.makeNative(of, useNamespace)
                builtType += '>'
            return builtType
        return recurse(utilities.dictify(properties, 'type'))


    def generateCode(self):
        super().generateCode()

        self.gen_enums.genDeserializers(self)
        self.gen_enums.genSerializers(self)
        self.gen_types.genAll(self)
        self.gen_containers.genAll(self)

        # we're doing globals last, since any other gen_ can add to includes.
        self.gen_global.genNamespaces(self)
        self.gen_global.genPragma(self)
        self.gen_global.genTopComment(self)
        self.gen_global.genIncludes(self)

        self.writeCode()


    def writeCode(self):
        # spit out the contents
        output = self.defsData.get('output', {})
        for outputForm, kinds in output.items():
            if outputForm != self.d('outputForm'):
                continue

            for kind, kindInfo in kinds.items():
                if (kind == 'typeHeader' or
                    kind == 'typeSource'):
                    for typeName, typeObj in self.types.items():
                        self.writeFile(kind, kindInfo, typeName)
                elif kind == 'diffsHeader':
                    if len(self.includeDiffTypes) > 0:
                        self.writeFile(kind, kindInfo)
                else:
                    self.writeFile(kind, kindInfo)



    def writeFile(self, kind, kindInfo, typeName = None):
        # path will have $<> replacements done.
        path = self._getPath(kind, kindInfo, typeName)
        path.parent.mkdir(parents=True, exist_ok=True)

        #if typeName: breakpoint()
        with open(path, 'wt') as f:
            for section in kindInfo.get('sections', []):
                # replace $<type> in section names
                section = self.replaceArgs(section, {'type': typeName})
                #if section == 'wut|stdForwardDecls':
                #    breakpoint()

                includeKinds = self.includes.get(section)
                if includeKinds:
                    for incTypeKind in includeKinds.keys():
                        incType, *incKind = incTypeKind.split('|', 1)
                        if len(incKind):
                            incKind = incKind[0]
                        else:
                            incKind = incType
                            incType = None
                        
                        if ((incKind.startswith('<') and incKind.endswith('>')) or
                            (incKind.startswith('"') and incKind.endswith('"'))):
                            relPath = incKind
                        else:
                            incKindInfo = self.defsData['output'][self.d('outputForm')][incKind]
                            incPath = self._getPath(incKind, incKindInfo, incType)
                            relPath = Path(os.path.relpath(incPath.parent, path.parent), incPath.name)
                            relPath = f'"{relPath}"'
                        f.write(f'\n#include {relPath}')

                content = self.sections.get(section)
                if content:
                    f.write(content)


    def _getPath(self, kind, kindInfo, typeName = None):
        '''kind is like 'mainHeader' or 'typesSource' '''

        sourcePath = kindInfo.get('sourcePath')
        if not sourcePath:
            raise RuntimeError(f'Bad value for {kind}/sourcePath: {sourcePath}')

        # we do this twice to resolve an arg replaced with a more different arg
        sourcePath = self.replaceArgs(sourcePath)

        repl = None if not typeName else { 'type': typeName }
        sourcePath = self.replaceArgs(sourcePath, repl)

        return Path(sourcePath)
