def genPragma(self):
    src = f'#pragma once\n'
    #self._appendToFile(src, 'mainHeader', 'pragma')
    #self._appendToFile(src, 'enumInlineSource', 'pragma')
    #self._appendToFile(src, 'typeInlineSource', 'pragma')

    self._appendToSection('pragma', src)


def genTopComment(self):
    self._appendToSection('mainHeaderTopComment', self.d('headerTopComment'))
    self._appendToSection('inlineTopComment', self.d('inlineTopComment'))

    if self.d('outputForm') == 'library':
        self._appendToSection('sourceTopComment', self.d('sourceTopComment'))


def genIncludes(self):
    for kind, includes in self.includes.items():
        outputForm, kind = kind.split('.')
        if outputForm != self.d('outputForm'):
            continue

        src = ''
        for includeFile in includes:
            src += f'#include {includeFile}\n'
        #self._appendToFile(src, kind, 'includes')
        self._appendToSection(''.join([kind, 'Includes']), src)
