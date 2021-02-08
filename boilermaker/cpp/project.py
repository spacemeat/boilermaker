from pathlib import Path
import os
from .. import utilities
from ..project import Project as BaseProject


class Project(BaseProject):
    from . import gen_enums
    from . import gen_global
    from . import gen_types
    from . import gen_containers

    def __init__(self, defsData):
        super().__init__(defsData)
        self.includes = {}
        self.sections = {}
        
        self.defsData['headerToInl'] = os.path.relpath(self.d('inlineDir'), self.d('headerDir'))
        self.defsData['srcToHeader'] = os.path.relpath(self.d('headerDir'), self.d('sourceDir'))
        self.defsData['srcToInl'] = os.path.relpath(self.d('inlineDir'), self.d('sourceDir'))

        #self.defsData['headerToInl'] = utilities.makeRelativeDir(self.d('headerDir'), self.d('inlineDir'))
        #self.defsData['srcToHeader'] = utilities.makeRelativeDir(self.d('sourceDir'), self.d('headerDir'))
        #self.defsData['srcToInl'] = utilities.makeRelativeDir(self.d('sourceDir'), self.d('inlineDir'))
    

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
                        #self.defsData['type'] = typeName
                        self.writeFile(kind, kindInfo, typeName)
                        #self.defsData['type'] = None
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

        if typeName == 'typesSource': breakpoint()
        sourcePath = kindInfo.get('sourcePath')
        if not sourcePath:
            raise RuntimeError(f'Bad value for {kind}/sourcePath: {sourcePath}')

        # we do this twice to resolve an arg replaced with a more different arg
        sourcePath = self.replaceArgs(sourcePath)

        repl = None if not typeName else { 'type': typeName }
        sourcePath = self.replaceArgs(sourcePath, repl)

        return Path(sourcePath)

        '''
        path = [self.d('defsPath')]
        if sourceType == 'header':
            path.append(self.d('headerDir'))
            if kind == 'mainHeader':
                path.append(self.d('mainHeaderFile'))
            if kind == 'enumHeader':
                path.append(self.d('enumHeaderFile'))


        elif sourceType == 'inline':
            path.append(self.d('inlineDir'))
        elif sourceType == 'source':
            path.append(self.d('sourceDir'))
        else:
            raise RuntimeError(f'invalid sourceType: {sourceType}')


        if self.d('outputForm') == 'headerOnly':
            if   kind == 'mainHeader':
                return Path(self.d('defsPath'), self.d('headerDir'), self.d('mainHeaderFile')).resolve()
            elif kind == 'enumHeader':
                return Path(self.d('defsPath'), self.d('inlineDir'), self.d('enumHeaderFile')).resolve()
            elif kind == 'enumSource':
                return Path(self.d('defsPath'), self.d('inlineDir'), self.d('enumInlineFile')).resolve()
            elif (kind == 'headerOnly.enumHeader' or 
                kind == 'headerOnly.enumSource' or 
                kind == 'library.enumInlineSource'):
                return Path(self.d('defsPath'), self.d('inlineDir'), self.d('enumHeaderFile')).resolve()
            elif (kind == 'headerOnly.typeInlineSource' or 
                kind == 'headerOnly.typeSource' or 
                kind == 'library.typeInlineSource'):
                return Path(self.d('defsPath'), self.d('inlineDir'), self.d('typeHeaderFile', typeLookup)).resolve()
            elif (kind == 'headerOnly.containersInlineSource' or 
                kind == 'headerOnly.containersSource' or 
                kind == 'library.containersInlineSource'):
                return Path(self.d('defsPath'), self.d('inlineDir'), self.d('containersHeaderFile')).resolve()
        elif self.d('outputForm') == 'compiled':
            if   kind == 'headerOnly.mainHeader':
                return Path(self.d('defsPath'), self.d('headerDir'), self.d('mainHeaderFile')).resolve()
            elif (kind == 'headerOnly.enumInlineSource' or 
                kind == 'headerOnly.enumSource' or 
                kind == 'library.enumInlineSource'):
                return Path(self.d('defsPath'), self.d('inlineDir'), self.d('enumInlineHeaderFile')).resolve()
            elif (kind == 'headerOnly.typeInlineSource' or 
                kind == 'headerOnly.typeSource' or 
                kind == 'library.typeInlineSource'):
                return Path(self.d('defsPath'), self.d('inlineDir'), self.d('typeInlineHeaderFile', typeLookup)).resolve()
            elif (kind == 'headerOnly.containersInlineSource' or 
                kind == 'headerOnly.containersSource' or 
                kind == 'library.containersInlineSource'):
                return Path(self.d('defsPath'), self.d('inlineDir'), self.d('containersInlineHeaderFile')).resolve()
            elif kind == 'library.enumSource':
                return Path(self.d('defsPath'), self.d('sourceDir'), self.d('enumSourceFile')).resolve()
            elif kind == 'library.typeSource':
                return Path(self.d('defsPath'), self.d('sourceDir'), self.d('typeSourceFile', typeLookup)).resolve()
            elif kind == 'library.containersSource':
                return Path(self.d('defsPath'), self.d('sourceDir'), self.d('containersSourceFile')).resolve()
        else:
            raise RuntimeError(f'Invalid fileKind: {kind}')
        '''
