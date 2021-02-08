def genPragma(self):
    src = f'#pragma once\n'
    self._appendToSection('pragma', src)


def genTopComment(self):
    self._appendToSection('mainHeaderTopComment', self.d('headerTopComment'))
    self._appendToSection('inlineTopComment', self.d('inlineTopComment'))

    if self.d('outputForm') == 'library':
        self._appendToSection('sourceTopComment', self.d('sourceTopComment'))


def genIncludes(self):
    return
    for kind, includes in self.includes.items():
        outputForm, kind = kind.split('.', 1)
        if outputForm != self.d('outputForm'):
            continue

        src = ''
        for includeFile, section in includes.items():
            src += f'#include {includeFile}\n'
        #self._appendToFile(src, kind, 'includes')
        breakpoint()
        self._appendToSection(section, src)


def genNamespaces(self):
    src = f'''

namespace {self.d('namespace')}
{{'''
    self._appendToSection('namespaceOpen', src)

    src = f'''
    
namespace std
{{'''
    self._appendToSection('namespaceStdOpen', src)

    src = f'''
    
namespace hu
{{'''
    self._appendToSection('namespaceHuOpen', src)

    src = f'''
}}
'''
    self._appendToSection('namespaceClose', src)


