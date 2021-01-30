from . import utilities

# TODO: Make this a plugin thing.
from .enums import Enums as Enums
from .c.enums import Enums as CEnums
from .cpp.enums import Enums as CppEnums

class Project:
    def __init__(self, defsData):
        self.defsData = defsData
        self.makeEnums()


    def data(self, key):
        return self.defsData[key]


    def run(self, op):
        if op == 'report':
            self.generateReport()
        elif op == 'generateCode':
            self.generateCode()


    def makeEnums(self):
        self.enums = []
        for enumDefsData in self.defsData['enums']:
            language, _ = utilities.getLanguageVersionParts(enumDefsData.get('languageVersion', 'c|gnu17'))
            if language == "c":
                self.enums.append(CEnums(self.defsData, enumDefsData))
            elif language == 'c++':
                self.enums.append(CppEnums(self.defsData, enumDefsData))
            else:
                raise RuntimeError(f'Unrecognized enums language: {language}')
        
        for enumsObject in self.enums:
            for enumName, enumObject in enumsObject.enums.items():
                print (f'ENUM: {enumName}:')
                for k, v in enumObject.enumVals.items():
                    print (f'    {k} = ({v[0]}, {v[1]})')


    def generateReport(self):
        var = self.data('variant')
        print (f'Report on {var}:')
        for k, v in self.defsData.items():
            print (f'  {k}: {v}')


    def generateCode(self):
        var = self.data('variant')
        print (f'Generate code for {var}')

