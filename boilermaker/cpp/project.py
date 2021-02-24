from pathlib import Path
import os
from .. import ansi
from .. import utilities
from ..project import Project as BaseProject


class OutputFile:
    def __init__(self, sourcePath, sourceKind, sections):
        self.sourcePath = sourcePath
        self.sourceKind = sourceKind    # one of ['header', 'inline', 'compiled']
        self.sections = sections


class OutputSection:
    def __init__(self):
        self.dependentTypes = {} 
        '''
        looks like:
                { 'vector': ('forwardDecl', 'std::vector<T, A>') }
            or:
                { 'vector': ('include' '<vector>')}
        '''
        self.includes = {}
        self.src = ''

    def forwardDeclareType(self, baseType, decl):
        self.dependentTypes.setDefault(baseType, ('forwardDecl', decl))

    def includeForType(self, baseType, includeFile):
        self.dependentTypes[baseType] = ('include', includeFile)
    
    def includeOutputFile(self, outputFile, inPlace=False):
        path = outputFile
        # TODO: path = relative path
        self.includes[outputFile] = (path, inPlace)

    def includeFile(self, path, inPlace=False):
        self.includes[path] = (path, inPlace)

    def setSrc(self, src):
        self.src = src
    
    def setSrcIfEmpty(self, src):
        if len(self.src) == 0:
            self.src = src

    def appendSrc(self, src):
        self.src.append(src)

    def hasDecl(self, baseType):
        return baseType in self.dependentTypes
    


class Project(BaseProject):
    from . import gen_enums
    from . import gen_global
    from . import gen_types
    from . import gen_containers
    from . import gen_containersSerializeToHumon
    from . import gen_containersSerializeToBinary
    from . import gen_diffs


    def __init__(self, defsData):
        super().__init__(defsData)
        self.outputFiles = {}
        self.outputSections = {}
        self.includes = {}
        self.sections = {}
        self.includeDiffTypes = {}
        self.serializerFormatWrappers = {}
        self.containersSerializerTypes = {}
        self.containersVariantTypeNames = {}

        self.defsData['headerToInl'] = os.path.relpath(self.d('inlineDir'), self.d('headerDir'))
        self.defsData['srcToHeader'] = os.path.relpath(self.d('headerDir'), self.d('sourceDir'))
        self.defsData['srcToInl'] = os.path.relpath(self.d('inlineDir'), self.d('sourceDir'))


    def const(self, type):
        coast = self.d('constCoast', 'west')
        if coast == 'east':
            return f'const {type}'
        else:
            return f'{type} const'
    

    def makeNative(self, bomaName, useNamespace=False):
        if bomaName in ['less', 'monostate', 'size_t', 'string', 'string_view', 'array', 'pair', 'tuple', 'vector', 'set', 'unordered_set', 'map', 'unordered_map', 'optional', 'variant']:
            return 'std::' + bomaName
        elif useNamespace and bomaName in self.types:
            bomaName = f'{self.d("namespace")}::{bomaName}'
        return bomaName.replace('.', '::')
    

    def makeNativeSubtype(self, properties, useNamespace=False):
        builtType = self.makeNative(properties['type'], useNamespace)
        of = properties.get('of')
        if of:
            builtType += '<'
            if type(of) is list:
                builtType += ', '.join([self.makeNativeSubtype(utilities.dictify(ch, 'type'), useNamespace) for ch in of])
            elif type(of) is dict:
                builtType += self.makeNativeSubtype(of, useNamespace)
            else:
                builtType += self.makeNative(of, useNamespace)
            if properties['type'] == 'set' or properties['type'] == 'map':
                if 'isLess' in properties:
                    ns = f'{self.d("namespace")}::' if useNamespace else ''
                    builtType += f', {ns}IsLess_{properties["fullName"]}'
            builtType += '>'
        return builtType


    def makeNativeMemberType(self, properties, useNamespace=False):
        return self.makeNativeSubtype(utilities.dictify(properties, 'type'), useNamespace)


    def generateCode(self):
        super().generateCode()

        self.makeOutputForm()

        self.gen_enums.genAll(self)
        self.gen_types.genAll(self)
        self.gen_containers.genBuiltInSerializers(self)

        # we're doing globals last, since any other gen_ can add to includes.
        self.gen_global.genNamespaces(self)
        self.gen_global.genPragma(self)
        self.gen_global.genTopComment(self)
        self.gen_global.genDecls(self)

        self.writeCode()


    def makeOutputForm(self):
        defsOutput = self.defsData.get('output', {})
        if not defsOutput or type(defsOutput) is not dict:
            raise RuntimeError('defs/output must be a dict.')

        outputForm = self.d('outputForm')
        defsFiles = defsOutput.get(outputForm)
        if not defsFiles or type(defsFiles) is not dict:
            raise RuntimeError(f'defs/output/{outputForm} must be a dict.')

        for defsFileName, defsFile in defsFiles.items():
            defsSourcePath = defsFile.get('sourcePath')
            if not defsSourcePath or type(defsSourcePath) is not str:
                raise RuntimeError(f'defs/output/{outputForm}/{defsFileName}/sourcePath must be a string.')

            defsSourceKind = defsFile.get('sourceKind')
            if not defsSourceKind or type(defsSourceKind) is not str:
                raise RuntimeError(f'defs/output/{outputForm}/{defsFileName}/defsSourceKind must be a string.')

            defsSections = defsFile.get('sections')
            if not defsSections or type(defsSections) is not list:
                raise RuntimeError(f'defs/output/{outputForm}/{defsFileName}/sections must be a list.')

            if '$<type>' in defsFileName:
                for typeName in self.types.keys():
                    defsFileName = self.replaceStringArgs(defsFileName, {'type:', typeName})
                    sourcePath = self.replaceStringArgs(defsSourcePath, {'type:', typeName})
                    sourceKind = self.replaceStringArgs(defsSourceKind, {'type:', typeName})
                    sections = [self.replaceStringArgs(sec, {'type:', typeName}) for sec in defsSections]

                    self.outputFiles[defsFileName] = OutputFile(sourcePath, sourceKind, sections)
                    for section in sections:
                        self.outputSections[section] = OutputSection()
            else:
                defsFileName = self.replaceStringArgs(defsFileName)
                sourcePath = self.replaceStringArgs(defsSourcePath)
                sourceKind = self.replaceStringArgs(defsSourceKind)
                sections = [self.replaceStringArgs(sec) for sec in defsSections]

                self.outputFiles[defsFileName] = OutputFile(sourcePath, sourceKind, sections)
                for section in sections:
                    self.outputSections[section] = OutputSection()


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


    def validateSection(self, section):
        if section in self.outputSections:
            return True
        else:
            print (f'{ansi.lt_cyan_fg}Note: {ansi.all_off}Section "{section}" has no output in outputForm "{self.d("outputForm")}."')
            return False


    def validateOutputFile(self, outputFile):
        if outputFile in self.outputFiles:
            return True
        else:
            print (f'{ansi.lt_yellow_fg}Warning: {ansi.all_off}"{outputFile}" is not a file in defs/output/"{self.d("outputForm")}."')
            return False


    def setSrc(self, section, src):
        section = self.replaceStringArgs(section)
        if self.validateSection(section):
            self.outputSections[section].setSrc(src)


    def setSrcIfEmpty(self, section, src):
        section = self.replaceStringArgs(section)
        if self.validateSection(section):
            self.outputSections[section].setSrcIfEmpty(src)


    def appendSrc(self, section, src):
        section = self.replaceStringArgs(section)
        if self.validateSection(section):
            self.outputSections[section].appendSrc(src)


    def forwardDeclareType(self, section, baseType, decl):
        '''baseType looks like 'vector'. decl looks like 'template <class T, class A> class std::vector<T, A>;'''
        section = self.replaceStringArgs(section)
        if self.validateSection(section):
            self.outputSections[section].forwardDeclareType(baseType, decl)

    
    def includeForType(self, section, baseType, includeFile):
        '''baseType looks like 'vector'. includeFile looks like '#include <vector>'''
        section = self.replaceStringArgs(section)
        if self.validateSection(section):
            self.outputSections[section].includeForType(baseType, includeFile)
    
    
    def includeOutputFile(self, section, outputFile, inPlace=False):
        section = self.replaceStringArgs(section)
        outputFile = self.replaceStringArgs(outputFile)
        if self.validateSection(section):
            self.outputSections[section].includeOutputFile(outputFile, inPlace)
    

    def includeFile(self, section, path, inPlace=False):
        section = self.replaceStringArgs(section)
        if self.validateSection(section):
            self.outputSections[section].includeFile(path, inPlace)
    

    def removeAllFiles(self, direc):
        d = Path(self.d('defsDir'), direc)
        if d.is_dir():
            for f in os.listdir(d):
                if Path(f).is_file():
                    os.unlink(f)


    def writeCode(self):
        '''By now, all the sections have their includes and forward decls resolved into src.'''

        # clean any files in the target directories
        self.removeAllFiles(self.d('headerDir'))
        self.removeAllFiles(self.d('inlineDir'))
        self.removeAllFiles(self.d('sourceDir'))

        for outputFileName, outputFile in self.outputFiles.items():
            self.writeFile(outputFile)
    

    def writeFile(self, outputFile):
        path = Path(self.replaceStringArgs(outputFile.sourcePath))
        path.parent.mkdir(parents=True, exist_ok=True)

        with open(path, 'wt') as f:
            for sectionName in outputFile.sections:
                section = self.outputSections.get(sectionName)
                f.write(section.src)


    def writeCodeOld(self):
        # clean any files in the target directories
        self.removeAllFiles(self.d('headerDir'))
        self.removeAllFiles(self.d('inlineDir'))
        self.removeAllFiles(self.d('sourceDir'))

        # spit out the contents
        output = self.defsData.get('output', {})
        for outputForm, kinds in output.items():
            if outputForm != self.d('outputForm'):
                continue

            for kind, kindInfo in kinds.items():
                if ('typeHeader' in kind or
                    'typeSource' in kind):
                    for typeName, typeObj in self.types.items():
                        self.writeFile(kind, kindInfo, typeName)
                elif kind == 'diffsHeader':
                    if len(self.includeDiffTypes) > 0:
                        self.writeFile(kind, kindInfo)
                else:
                    self.writeFile(kind, kindInfo)


    def writeFileOld(self, kind, kindInfo, typeName = None):
        # path will have $<> replacements done.
        path = self._getPath(kind, kindInfo, typeName)
        path.parent.mkdir(parents=True, exist_ok=True)

        with open(path, 'wt') as f:
            for section in kindInfo.get('sections', []):
                # replace $<type> in section names
                section = self.replaceStringArgs(section, {'type': typeName})

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
        sourcePath = self.replaceStringArgs(sourcePath)

        repl = None if not typeName else { 'type': typeName }
        sourcePath = self.replaceStringArgs(sourcePath, repl)

        return Path(sourcePath)
