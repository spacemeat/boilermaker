def genAll(self):
    self.includeOutputFile('mainHeaderIncludes', 'commonHeader')


def genPragma(self):
    src = f'#pragma once\n'
    self.setSrc('pragma', src)


def genTopComment(self):
    self.setSrc('mainHeaderTopComment', self.d('mainHeaderTopComment'))
    self.setSrc('headerTopComment', self.d('headerTopComment'))
    self.setSrc('inlineTopComment', self.d('inlineTopComment'))
    self.setSrc('sourceTopComment', self.d('sourceTopComment'))


def genDecls(self):
    return
    for kind, includes in self.includes.items():
        outputForm, kind = kind.split('.', 1)
        if outputForm != self.d('outputForm'):
            continue

        src = ''
        for includeFile, section in includes.items():
            src += f'#include {includeFile}\n'
        self._appendToSection(section, src)


def genNamespaces(self):
    src = f'''

namespace {self.d('namespace')}
{{'''
    self.setSrc('namespaceOpen', src)

    src = f'''
    
namespace std
{{'''
    self.setSrc('namespaceStdOpen', src)

    src = f'''
    
namespace hu
{{'''
    self.setSrc('namespaceHuOpen', src)

    src = f'''
}}
'''
    self.setSrc('namespaceClose', src)
