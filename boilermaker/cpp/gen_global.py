from pathlib import Path
import os

def genAll(self):
    self.gen_global.genPragma(self)
    self.gen_global.genTopComment(self)
    self.gen_global.genNamespaces(self)
    self.gen_global.genCommonIncludes(self)


def genPragma(self):
    src = f'#pragma once\n'
    self.setSrc('pragma', src)


def genTopComment(self):
    self.setSrc('mainHeaderTopComment', self.d('mainHeaderTopComment'))
    self.setSrc('headerTopComment', self.d('headerTopComment'))
    self.setSrc('inlineTopComment', self.d('inlineTopComment'))
    self.setSrc('sourceTopComment', self.d('sourceTopComment'))


def genNamespaces(self):
    src = f'''

namespace {self.d('namespace')}
{{'''
    self.setSrc('namespaceOpen', src)

    src = f'''
    
namespace hu
{{'''
    self.setSrc('namespaceHuOpen', src)

    src = f'''
}}
'''
    self.setSrc('namespaceClose', src)


def genCommonIncludes(self):
    self.includeOutputFile('commonSource|includes', 'commonHeader')


def genTypeDecls(self):
    '''This is among the last gen tasks. It uses include data generated by other
    gen tasks to generate appropriate forward decls and #includes.'''

    for outputFileName, outputFile in self.outputFiles.items():
        outputFilePath = Path(self.replaceStringArgs(outputFile.sourcePath))

        # merge in all not-inPlace forwardDecls and includes.
        for sectionName in outputFile.sections:
            section = self.outputSections.get(sectionName)

            # merge all decls to the file level
            for baseTypeName, dependentTypeDecl in section.dependentTypeDecls.items():
                encounteredDecl = outputFile.dependentTypeDecls.get(baseTypeName)
                if encounteredDecl:
                    if (encounteredDecl.declKind == 'forwardDecl' and
                        dependentTypeDecl.declKind == 'include'):
                        outputFile.dependentTypeDecls[baseTypeName] = dependentTypeDecl
                else:
                    outputFile.dependentTypeDecls[baseTypeName] = dependentTypeDecl

            # merge all non-inPlace includes to the file level
            for includeName, include in section.includes.items():
                if not include.inPlace:
                    if include.isOutputFile:
                        if self.validateOutputFile(includeName):
                            # in-place fixup of including another boma-generated file
                            includeFilePathString = self.outputFiles[includeName].sourcePath
                            includeFilePath = Path(self.replaceStringArgs(includeFilePathString))
                            
                            relPath = Path(os.path.relpath(includeFilePath.parent, outputFilePath.parent), includeFilePath.name)
                            # don't #include ourselves
                            if relPath.name != outputFilePath.name:
                                relPath = f'"{relPath}"'
                                outputFile.includes.setdefault(f'#include {relPath}', None)
                    else:
                        outputFile.includes.setdefault(f'#include {includeName}', None)

        # convert dependentTypeDecls to forward decl source and includes
        for baseType, decl in outputFile.dependentTypeDecls.items():
            if decl.declKind == 'include':
                outputFile.includes[decl.decl] = None
            else:
                outputFile.forwardDecls[decl.decl] = None

