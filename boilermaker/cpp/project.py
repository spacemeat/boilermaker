from pathlib import Path
from ..project import Project as BaseProject


class Project(BaseProject):
    from . import gen_enums

    def __init__(self, defsData):
        super().__init__(defsData)
        self.targetFiles = {}
        self.includes = []
    

    def _getPath(self, fileKind, type=None):
        if fileKind == 'mainInclude':
            return Path(self.d('defsPath'), self.d('headerDir'), self.d('headerFile')).resolve()
        elif fileKind == 'enumSource':
            if self.d('headerOnly'):
                return Path(self.d('defsPath'), self.d('inlineDir'), self.d('inlineFile')).resolve()
            else:
                return Path(self.d('defsPath'), self.d('sourceDir'), self.d('sourceFile')).resolve()
        elif fileKind == 'typeSource':
            if self.d('headerOnly'):
                return Path(self.d('defsPath'), self.d('inlineDir'), self.d('inlineFile')).resolve()
            else:
                return Path(self.d('defsPath'), self.d('sourceDir'), self.d('sourceFile')).resolve()
        else:
            raise RuntimeError(f'Invalid fileKind: {fileKind}')


    def _appendToFile(self, src, kind, section = ''):
        path = self._getPath(kind)

        if path not in self.targetFiles:
            self.targetFiles[path] = { section: src }
        elif section not in self.targetFiles[path]:
            self.targetFiles[path][section] = src
        else:
            self.targetFiles[path][section] += src


    def generateCode(self):
        super().generateCode()

        ''' header layout:
                #pragma once
                // generated file message
                {includes}
                {enumDeserializers}
                {namespace open}
                {enumSerialziers}
                {collectionDiffers}
                {bomaStreamClass}
                {type[]}
                {collectionSerializers}
                {namespace closed}
                {typeDeserializers}
                {inlineIncludes}
        
            header.type layout:
                {friendDecls}
                {differ}
                {typeClassDecl}
                {defaultCtr}
                {memberwiseCtr}
                {humonCtr}
                {copyCtr}
                {moveCtr}
                {copyAssign}
                {moveAssign}
                {destructor}
                {swap}
                {memberGetters}
                {memberSetters}
                {memberSetMovers}
                {serialzier}
                {comparator}
                {differ}
                {members}

            enumInlineHeader/source:
                #pragma once
                // generated file message
                {enumDeserializers}
                {enumSerialziers}
            
            inlineHeader/source:
                #pragma once ?
                // generated file message
                {includes}
                {collectionDeserializers}
                {defaultCtr}
                {memberwiseCtr}
                {humonCtr}
                {copyCtr}
                {moveCtr}
                {copyAssign}
                {moveAssign}
                {destructor}
                {swap}
                {memberGetters}
                {memberSetters}
                {memberSetMovers}
                {serialzier}
                {comparator}
                {differ}
        '''

        self.gen_enums.genEnumDeserializers(self)
        self.gen_enums.genEnumStreamInserters(self)

        breakpoint()
        # spit out the contents
        for path, contents in self.targetFiles.items():
            path = Path(path).resolve()
            path.parent.mkdir(parents=True, exist_ok=True)
            with open(path, 'wt') as f:
                for section, content in contents.items():
                    f.write(content)
        