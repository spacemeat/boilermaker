from pathlib import Path
import os
from ... import ansi
from ... import utilities
#from ...project import Project as Project
from ...props import Scribe


class DependentTypeDecl:
    def __init__(self, declKind, decl, namespace = ''):
        self.declKind = declKind
        self.decl = decl
        self.namespace = namespace

    def __str__(self):
        dc = ansi.dk_blue_fg
        lc = ansi.lt_blue_fg
        return f'''{lc}{self.declKind}{dc} = {lc}{self.namespace}.{self.decl}{ansi.all_off}'''


class IncludeDecl:
    def __init__(self, isOutputFile, includeText, inPlace=False):
        self.isOutputFile = isOutputFile
        self.includeText = includeText
        self.inPlace = inPlace

    def __str__(self):
        dc = ansi.dk_blue_fg
        lc = ansi.lt_blue_fg
        txt = f'''{dc}local {lc}{self.isOutputFile}{dc} = {lc}{self.includeText}'''
        if self.inPlace:
            txt += f'''{lc}(in place){ansi.all_off}'''
        return txt


class OutputFile:
    def __init__(self, sourcePath, sourceKind, sections):
        self.sourcePath = sourcePath
        self.sourceKind = sourceKind    # one of ['header', 'inline', 'compiled']
        self.sections = sections
        self.dependentTypeDecls = {}    # these are filled in by gen_global.gen_typeDecls()
        self.includes = {}              # these are filled in by gen_global.gen_typeDecls()
        self.forwardDecls = {}          # these are filled in by gen_global.gen_typeDecls()

    def __str__(self):
        dc = ansi.dk_magenta_fg
        lc = ansi.lt_magenta_fg
        db = ansi.dk_blue_fg
        lb = ansi.lt_blue_fg
        txt = f'''
{dc}  File: {lc}{self.sourcePath}{dc}; kind: {lc}{self.sourceKind}{ansi.all_off}'''
        for baseName, dtd in self.dependentTypeDecls.items():
            txt += f'''
{db}    typeDecl: {str(dtd)}{ansi.all_off}'''
        for decl, _ in self.includes.items():
            txt += f'''
{db}    include: {lb}{decl}{ansi.all_off}'''
        for decl, _ in self.forwardDecls.items():
            txt += f'''
{db}    forwardDecl: {lb}{decl}{ansi.all_off}'''
        return txt


class OutputSection:
    def __init__(self, defaultNamespace):
        self.dependentTypeDecls = {}
        self.includes = {}
        self.srcs = []
        self.defaultNamespace = defaultNamespace

    def __str__(self):
        dc = ansi.dk_blue_fg
        lc = ansi.lt_blue_fg
        txt = ''
        for baseName, dtd in self.dependentTypeDecls.items():
            txt += f'''
{dc}  typeDecl: {lc}{baseName}{dc}: {str(dtd)}{ansi.all_off}'''
        for incName, inco in self.includes.items():
            txt += f'''
{dc}  includes: {lc}{incName}{dc}: {str(inco)}{ansi.all_off}'''
        srcLen = sum([len(src[0]) for src in self.srcs])
        if srcLen > 0:
            txt += f'''
{dc}  len: {lc}{srcLen}{ansi.all_off}'''
        return txt

    def forwardDeclareType(self, baseType, decl, namespace):
        self.dependentTypeDecls.setdefault(baseType, DependentTypeDecl('forwardDecl', decl, namespace))

    def includeForType(self, baseType, includeFile):
        self.dependentTypeDecls[baseType] = DependentTypeDecl('include', includeFile)

    def includeOutputFile(self, outputFile, inPlace=False):
        self.includes[outputFile] = IncludeDecl(True, outputFile, inPlace)

    def includeFile(self, path, inPlace=False):
        self.includes[path] = IncludeDecl(False, path, inPlace)

    def setSrc(self, src, namespace):
        self.srcs = [(src, namespace)]

    def setSrcIfEmpty(self, src, namespace):
        if len(self.srcs) == 0:
            self.srcs = [(src, namespace)]

    def appendSrc(self, src, namespace):
        self.srcs.append((src, namespace))

    def hasDecl(self, baseType):
        return baseType in self.dependentTypeDecls


class CppProject:
    #from . import gen_enums
    #from . import gen_global
    #from . import gen_types

    def __init__(self, props):
        self.props = props
        self.reset()


    def P(self, key, default = None):
        s = Scribe(self.props)
        return s.getXProp(key, default)


    def reset(self):
        # TODO: Remove these if not used
        self.props.setProp('headerToInl', os.path.relpath(self.P('inlineDir'), self.P('headerDir')))
        self.props.setProp('srcToHeader', os.path.relpath(self.P('headerDir'), self.P('sourceDir')))
        self.props.setProp('srcToInl', os.path.relpath(self.P('inlineDir'), self.P('sourceDir')))
        self.outputFiles = {}
        self.outputSections = {}
        self.includeDiffTypes = {}
        self.serializerFormatWrappers = {}
        self.containersSerializerTypes = {}
        self.containersDeserializerTypes = {}
        self.containersVariantTypeNames = {}


    def doingCaveman(self, category):
        dbgs = self.P('caveperson')
        return dbgs and category in dbgs


    def cave(self, category, message, sectionName, tabs=3):
        it = self.indent()
        src = ''
        if self.doingCaveman(category):
            self.includeForType(sectionName, 'ostream', f'''#include <iostream>''')

            caveStream = self.P('caveStream') or 'cout'
            src += f'''
{it * tabs}std::{caveStream} << {message} << "\\n";'''
        return src


    def checkBinaryBuffer(self, sizeValue='sizeof(T)', sizeName = 'size'):
        it = self.indent()
        src = ''
        if self.dIs('checkBinaryOverruns'):
            src = f'''
{it}{it}{it}if ({sizeName} < {sizeValue}) {{ throw std::runtime_error("Binary buffer too small."); }}'''
        return src


    def advanceBinaryBuffer(self, sizeValue='sizeof(T)', bufferName = 'buffer', sizeName = 'size'):
        it = self.indent()
        src = f'''
{it}{it}{it}{bufferName} += {sizeValue};
{it}{it}{it}{sizeName} -= {sizeValue};'''
        return src


    def makeNative(self, bomaName, useNamespace=False):
        if bomaName in ['less', 'monostate', 'size_t', 'string', 'string_view', 'array', 'pair', 'tuple', 'vector', 'set', 'unordered_set', 'map', 'unordered_map', 'optional', 'variant']:
            return 'std::' + bomaName
        elif useNamespace and bomaName in self.types:
            bomaName = f'{self.P("namespace")}::{bomaName}'
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
                    ns = f'{self.P("namespace")}::' if useNamespace else ''
                    builtType += f', {ns}IsLess_{properties["fullName"]}'
            builtType += '>'
        return builtType


    def makeNativeMemberType(self, properties, useNamespace=False):
        return self.makeNativeSubtype(utilities.dictify(properties, 'type'), useNamespace)


    def removeAllFiles(self):
        def removeAllFiles(self, direc):
            d = Path(self.P('defsDir'), direc)
            if d.is_dir():
                for f in os.listdir(d):
                    if Path(f).is_file():
                        os.unlink(f)
        removeAllFiles(self.P('headerDir'))
        removeAllFiles(self.P('inlineDir'))
        removeAllFiles(self.P('sourceDir'))


    def generateProps(self):
        self.reset()
        #self.makeOutputForm()

        #self.gen_global.genAll(self)
        #self.gen_enums.genAll(self)
        #self.gen_types.genAll(self)
        #self.gen_global.genTypeDecls(self)


    def reportOutputs(self):
        self.generateCode()
        dc = ansi.dk_white_fg
        lc = ansi.lt_white_fg
        [print(f'{dc}outputFile {lc}{oun}{dc}: {str(ouf)}') for oun, ouf in self.outputFiles.items()]
        [print(f'{dc}outputSection: {lc}{oun}{dc}: {str(ous)}') for oun, ous in self.outputSections.items()]


    def makeOutputForm(self):
        defsOutput = self.props.get('output', {})
        if not defsOutput or type(defsOutput) is not dict:
            raise RuntimeError('defs/output must be a dict.')

        outputForm = self.P('outputForm')
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

            if defsFileName.find('$<type>') >= 0:
                for typeName in self.types.keys():
                    t_defsFileName = self.replaceStringArgs(defsFileName, {'type': typeName})
                    t_sourcePath = self.replaceStringArgs(defsSourcePath, {'type': typeName})
                    t_sourceKind = self.replaceStringArgs(defsSourceKind, {'type': typeName})
                    t_sections = [self.replaceStringArgs(sec, {'type': typeName}) for sec in defsSections]

                    self.outputFiles[t_defsFileName] = OutputFile(t_sourcePath, t_sourceKind, t_sections)
                    for t_section in t_sections:
                        self.outputSections[t_section] = OutputSection(self.P('namespace'))
            else:
                defsFileName = self.replaceStringArgs(defsFileName)
                sourcePath = self.replaceStringArgs(defsSourcePath)
                sourceKind = self.replaceStringArgs(defsSourceKind)
                sections = [self.replaceStringArgs(sec) for sec in defsSections]

                self.outputFiles[defsFileName] = OutputFile(sourcePath, sourceKind, sections)
                for section in sections:
                    self.outputSections[section] = OutputSection(self.P('namespace'))


    def getSection(self, sectionName, mustNotExist=False):
        '''Returns the OutputSection object for sectionName. If the section
        does not exist yet, a new one is created. If mustNotExist == True,
        however, a new OutputSection is created only if one for sectionName
        does not yet exist. If it does, None is returned. This is useful for
        one-time section content that might get made multiple times.'''
        section = self.outputSections.get(sectionName)
        if section and mustNotExist:
            return None

        if not section:
            section = OutputSection(self.P('namespace'))
            self.outputSections[sectionName] = section

        return section


    def validateOutputFile(self, outputFile):
        if outputFile in self.outputFiles:
            return True
        else:
            print (f'{ansi.lt_yellow_fg}Warning: {ansi.all_off}"{outputFile}" is not a file in outputForm "{self.P("outputForm")}".')
            return False


    def setSrc(self, sectionName, src, namespace='$<namespace>'):
        sectionName = self.replaceStringArgs(sectionName)
        if sectionName in self.outputSections:
            s = self.getSection(sectionName)
            if s:
                namespace = self.replaceStringArgs(namespace)
                s.setSrc(src, namespace)
        else:
            print (f'{ansi.lt_cyan_fg}Note: {ansi.all_off}Section "{sectionName}" has no output in outputForm "{self.P("outputForm")}".')


    def setSrcIfEmpty(self, sectionName, src, namespace='$<namespace>'):
        sectionName = self.replaceStringArgs(sectionName)
        if sectionName in self.outputSections:
            s = self.getSection(sectionName)
            if s:
                namespace = self.replaceStringArgs(namespace)
                s.setSrcIfEmpty(src, namespace)
        else:
            print (f'{ansi.lt_cyan_fg}Note: {ansi.all_off}section "{sectionName}" has no output in outputForm "{self.P("outputForm")}".')


    def appendSrc(self, sectionName, src, namespace='$<namespace>'):
        sectionName = self.replaceStringArgs(sectionName)
        if sectionName in self.outputSections:
            s = self.getSection(sectionName)
            if s:
                namespace = self.replaceStringArgs(namespace)
                s.appendSrc(src, namespace)
        else:
            print (f'{ansi.lt_cyan_fg}Note: {ansi.all_off}section "{sectionName}" has no output in outputForm "{self.P("outputForm")}".')


    def forwardDeclareType(self, sectionName, baseType, decl, namespace='$<namespace>', inPlace=False):
        '''baseType looks like 'vector'. decl looks like 'template <class T, class A> class std::vector<T, A>;'''
        sectionName = self.replaceStringArgs(sectionName)
        if sectionName in self.outputSections:
            s = self.getSection(sectionName)
            if s:
                namespace = self.replaceStringArgs(namespace)
                s.forwardDeclareType(baseType, decl, namespace)
        else:
            print (f'{ansi.lt_cyan_fg}Note: {ansi.all_off}section "{sectionName}" has no output in outputForm "{self.P("outputForm")}".')


    def includeForType(self, sectionName, baseType, includeFile, inPlace=False):
        '''baseType looks like 'vector'. includeFile looks like '#include <vector>'''
        sectionName = self.replaceStringArgs(sectionName)
        if sectionName in self.outputSections:
            s = self.getSection(sectionName)
            if s:
                s.includeForType(baseType, includeFile)
        else:
            print (f'{ansi.lt_cyan_fg}Note: {ansi.all_off}section "{sectionName}" has no output in outputForm "{self.P("outputForm")}".')


    def includeOutputFile(self, sectionName, outputFile, inPlace=False):
        sectionName = self.replaceStringArgs(sectionName)
        outputFile = self.replaceStringArgs(outputFile)
        if sectionName in self.outputSections:
            s = self.getSection(sectionName)
            if s:
                s.includeOutputFile(outputFile, inPlace)
        else:
            print (f'{ansi.lt_cyan_fg}Note: {ansi.all_off}section "{sectionName}" has no output in outputForm "{self.P("outputForm")}".')


    def includeFile(self, sectionName, path, inPlace=False):
        sectionName = self.replaceStringArgs(sectionName)
        if sectionName in self.outputSections:
            s = self.getSection(sectionName)
            if s:
                s.includeFile(path, inPlace)
        else:
            print (f'{ansi.lt_cyan_fg}Note: {ansi.all_off}section "{sectionName}" has no output in outputForm "{self.P("outputForm")}".')


    def removeAllFiles(self, direc):
        d = Path(self.P('defsDir'), direc)
        if d.is_dir():
            for f in os.listdir(d):
                if Path(f).is_file():
                    os.unlink(f)


    def write(self):
        '''By now, all the sections have their includes and forward decls resolved into src.'''
        super().write()

        self.generateCode()

        # clean any files in the target directories
        self.removeAllFiles(self.P('headerDir'))
        self.removeAllFiles(self.P('inlineDir'))
        self.removeAllFiles(self.P('sourceDir'))

        for outputFileName, outputFile in self.outputFiles.items():
            self.writeFile(outputFileName, outputFile)


    def writeFile(self, outputFileName, outputFile):
        path = Path(self.replaceStringArgs(outputFile.sourcePath))
        path.parent.mkdir(parents=True, exist_ok=True)

        print (f'{ansi.dk_blue_fg}Writing {ansi.lt_yellow_fg}{path}{ansi.dk_blue_fg}...{ansi.all_off}')

        with open(path, 'wt') as f:
            currentNamespace = ''
            def updateNamespace(ns):
                nonlocal currentNamespace
                if ns != currentNamespace:
                    if currentNamespace != '':
                        f.write(f'''
}}''')
                    if ns != '':
                        f.write(f'''

namespace {ns}
{{''')
                    currentNamespace = ns

            for sectionName in outputFile.sections:
                if sectionName == f'{outputFileName}|includes':
                    if len(outputFile.includes) > 0:
                        f.write('\n')
                        updateNamespace('')
                        for decl in outputFile.includes.keys():
                            f.write(f'''
{decl}''')
                    if len(outputFile.forwardDecls) > 0:
                        f.write('\n')
                        for decl, namespace in outputFile.forwardDecls.items():
                            updateNamespace(namespace)
                            f.write(f'''
{decl}''')
                else:
                    section = self.outputSections.get(sectionName)

                    # drop in-place #includes here (rarely has any)
                    if len(section.includes) > 0:
                        for decl, include in section.includes.items():
                            if include.inPlace:
                                updateNamespace('')
                                f.write(f'''
{self.dependentTypeDecl.decl}''')

                    for src, ns in section.srcs:
                        updateNamespace(ns)
                        f.write(src)

            updateNamespace('')
