from pathlib import Path
from .. import utilities
from ..project import Project as BaseProject


class Project(BaseProject):
    from . import gen_enums
    from . import gen_global

    def __init__(self, defsData):
        super().__init__(defsData)
        self.includes = {}
        self.sections = {}
        self.defsData['headerToInl'] = utilities.makeRelativeDir(self._getPath('mainHeader'), self._getPath('enumInlineSource'))
        self.defsData['srcToHeader'] = utilities.makeRelativeDir(self._getPath('enumSource'), self._getPath('mainHeader'))
        self.defsData['srcToInl'] = utilities.makeRelativeDir(self._getPath('enumSource'), self._getPath('enumInlineSource'))
    

    def _getPath(self, kind, type=None):
        kind = '.'.join([self.d('outputForm'), kind])
        if   kind == 'headerOnly.mainHeader':
            return Path(self.d('defsPath'), self.d('headerDir'), self.d('mainHeaderFile')).resolve()
        elif kind == 'headerOnly.enumInlineSource' or kind == 'headerOnly.enumSource' or kind == 'library.enumInlineSource':
            return Path(self.d('defsPath'), self.d('inlineDir'), self.d('enumInlineHeaderFile')).resolve()
        elif kind == 'library.enumSource':
            return Path(self.d('defsPath'), self.d('sourceDir'), self.d('enumSourceFile')).resolve()
        elif kind == 'headerOnly.typeInlineSource' or kind == 'headerOnly.typeSource' or kind == 'library.typeInlineSource':
            return Path(self.d('defsPath'), self.d('inlineDir'), self.d('typeInlineHeaderFile')).resolve()
        elif kind == 'library.typeSource':
            return Path(self.d('defsPath'), self.d('sourceDir'), self.d('typeSourceFile')).resolve()
        else:
            raise RuntimeError(f'Invalid fileKind: {kind}')


    def _appendToSection(self, section, src):
        if section not in self.sections:
            self.sections[section] = src
        else:
            self.sections[section] += src
    

    def _addInclude(self, kind, includeFile):
        kind = '.'.join([self.d('outputForm'), kind])
        if kind not in self.includes:
            self.includes[kind] = {includeFile: None}
        if includeFile not in self.includes[kind]:
            self.includes[kind][includeFile] = None


    def generateCode(self):
        super().generateCode()

        self.gen_enums.genEnumDeserializers(self)
        self.gen_enums.genEnumSerializers(self)

        self.gen_global.genPragma(self)
        self.gen_global.genTopComment(self)
        self.gen_global.genIncludes(self)

        # spit out the contents
        layout = self.defsData.get('layout', {})
        for formAndKind, layoutSections in layout.items():
            outputForm, kind = formAndKind.split('.')
            if outputForm == self.d('outputForm'):
                path = self._getPath(kind)
                with open(path, 'wt') as f:
                    for layoutSection in layoutSections:
                        content = self.sections.get(layoutSection, None)
                        if content:
                            f.write(content)
                            f.write('\n')
