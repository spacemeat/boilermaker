from pathlib import Path
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
        self.defsData['headerToInl'] = utilities.makeRelativeDir(self._getPath('mainHeader'), self._getPath('enumInlineSource'))
        self.defsData['srcToHeader'] = utilities.makeRelativeDir(self._getPath('enumSource'), self._getPath('mainHeader'))
        self.defsData['srcToInl'] = utilities.makeRelativeDir(self._getPath('enumSource'), self._getPath('enumInlineSource'))
    

    def _getPath(self, kind):
        '''kind is like 'mainHeader' or 'typeInlineSource' '''
        kind = '.'.join([self.d('outputForm'), kind])
        if   kind == 'headerOnly.mainHeader':
            return Path(self.d('defsPath'), self.d('headerDir'), self.d('mainHeaderFile')).resolve()
        elif (kind == 'headerOnly.enumInlineSource' or 
              kind == 'headerOnly.enumSource' or 
              kind == 'library.enumInlineSource'):
            return Path(self.d('defsPath'), self.d('inlineDir'), self.d('enumInlineHeaderFile')).resolve()
        elif (kind == 'headerOnly.typeInlineSource' or 
              kind == 'headerOnly.typeSource' or 
              kind == 'library.typeInlineSource'):
            return Path(self.d('defsPath'), self.d('inlineDir'), self.d('typeInlineHeaderFile')).resolve()
        elif (kind == 'headerOnly.containersInlineSource' or 
              kind == 'headerOnly.containersSource' or 
              kind == 'library.containersInlineSource'):
            return Path(self.d('defsPath'), self.d('inlineDir'), self.d('containersInlineHeaderFile')).resolve()
        elif kind == 'library.enumSource':
            return Path(self.d('defsPath'), self.d('sourceDir'), self.d('enumSourceFile')).resolve()
        elif kind == 'library.typeSource':
            return Path(self.d('defsPath'), self.d('sourceDir'), self.d('typeSourceFile')).resolve()
        elif kind == 'library.containersSource':
            return Path(self.d('defsPath'), self.d('sourceDir'), self.d('containersSourceFile')).resolve()
        else:
            raise RuntimeError(f'Invalid fileKind: {kind}')


    def _appendToSection(self, section, src):
        if section not in self.sections:
            self.sections[section] = src
        else:
            self.sections[section] += src
    

    def _addInclude(self, kind, includeFile, section, systemOnly=False):
        kind = '.'.join([self.d('outputForm'), kind])
        if kind not in self.includes:
            self.includes[kind] = {includeFile: section}
        else:
            self.includes[kind][includeFile] = section
    

    def makeNative(self, bomaName):
        if bomaName in ['size_t', 'string', 'string_view', 'array', 'pair', 'tuple', 'vector', 'set', 'unordered_set', 'map', 'unordered_map', 'optional', 'variant']:
            return 'std::' + bomaName
        return bomaName.replace('.', '::')


    def makeNativeMemberType(self, properties):
        def recurse(properties):
            builtType = self.makeNative(properties['type'])
            of = properties.get('of')
            if of:
                builtType += '<'
                if type(of) is list:
                    builtType += ', '.join([recurse(utilities.dictify(ch, 'type')) for ch in of])
                elif type(of) is dict:
                    builtType += recurse(of)
                else:
                    builtType += self.makeNative(of)
                builtType += '>'
            return builtType
        return recurse(utilities.dictify(properties, 'type'))


    def generateCode(self):
        super().generateCode()

        self.gen_enums.genDeserializers(self)
        self.gen_enums.genSerializers(self)

        for typeName, t in self.types.items():
            self.defsData['type'] = typeName
            self.gen_types.genForwardClassDecl(self, t)
            self.gen_types.genClassBegin(self, t)
            self.gen_types.genClassEnd(self, t)
            self.gen_types.genSerializer(self, t)
            self.gen_types.genMembers(self, t)
            self.defsData['type'] = None

        for typeName, t in self.types.items():
            memo = {}
            self.gen_containers.genSerializers(self, t, memo)


        # we're doing globals last, since any other gen_ can add to includes.
        self.gen_global.genNamespaces(self)
        self.gen_global.genPragma(self)
        self.gen_global.genTopComment(self)
        self.gen_global.genIncludes(self)

        self.writeCode()


    def writeCode(self):
        # spit out the contents
        layout = self.defsData.get('layout', {})
        for formAndKind, layoutSections in layout.items():
            outputForm, kind = formAndKind.split('.', 2)
            if outputForm == self.d('outputForm'):
                if (kind == 'typeInlineSource' or
                    kind == 'typeSource'):
                    for typeName, typeObj in self.types.items():
                        self.defsData['type'] = typeName
                        self.writeFile(layoutSections, kind)
                else:
                    self.defsData['type'] = None
                    self.writeFile(layoutSections, kind)


    def writeFile(self, layoutSections, kind):
        # path will have $<> replacements done.
        path = self._getPath(kind)
        with open(path, 'wt') as f:
            for layoutSection in layoutSections:
                # replace $<type> in section names
                layoutSection = self.replaceArgs(layoutSection)
                content = self.sections.get(layoutSection)
                if content:
                    f.write(content)
