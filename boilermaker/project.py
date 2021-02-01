from . import utilities

# TODO: Make this a plugin thing.
from .enums import Enums as Enums
from .cFamily.enums import Enums as CfamilyEnums
from .type import StructType
import re


# read ${captured}, when not preceded by a '\'
defArgumentPattern = r'(?<!\\)\$\s*\<\s*([A-Za-z0-9_.]+?)\s*\>'
defArgumentReg = re.compile(defArgumentPattern)


class Project:    
    def __init__(self, defsData):
        self.defsData = defsData
        self.makeEnums()
        self.makeTypes()


    def replaceArg(self, key):            
        return self.defsData.get(key, f'!{key}!')
    

    def d(self, key):
        val = self.defsData[key]
        if type(val) is str:
            val = re.sub(defArgumentReg, lambda m: self.replaceArg(m.group(1)), val)
        return val
    

    def indent(self):
        indent = self.defsData.get('indent', {'type':'space', 'num': '4' } )
        if indent['type'] == 'space':
            return ' ' * (int(indent['num']))
        elif indent['type'] == 'tab':
            return '\t' * (int(indent['num']))
        else:
            raise RuntimeError(f'invalid "indent" value: {indent}')


    def run(self, op):
        if op == 'report':
            self.generateReport()
        elif op == 'generateCode':
            self.generateCode()
    

    def everyEnum(self):
        for enumsObject in self.enums:
            typedefsSeen = set()
            for enumName, enumTypedefObject in enumsObject.enumTypedefs.items():
                typedefsSeen.add(enumTypedefObject.enumName)
                yield (enumName, enumsObject.enums[enumTypedefObject.enumName])
            for enumName, enumObject in enumsObject.enums.items():
                if enumObject.name not in typedefsSeen:
                    yield (enumName, enumObject)


    def makeEnums(self):
        self.enums = []
        for enumDefsData in self.defsData['enums']:
            language, _ = utilities.getLanguageVersionParts(enumDefsData.get('languageVersion', 'c|gnu17'))
            if language == "c" or language == 'c++':
                self.enums.append( CfamilyEnums(self.defsData, enumDefsData) )
            else:
                raise RuntimeError(f'Unrecognized enums language: {language}')
    

    def makeTypes(self):
        self.types = {}
        for typeName, typeData in self.defsData.get('types', {}).items():
            self.types[typeName] = StructType(typeName, typeData)


    def generateReport(self):
        var = self.d('variant')
        print (f'Report on {var}:')
        for k, v in self.defsData.items():
            print (f'  {k}: {v}')

        for enumName, enumObject in self.everyEnum():
            print (f'ENUM: {enumName}:')
            for k, v in enumObject.enumVals.items():
                print (f'    {k} = ({v[0]}, {v[1]})')
        
        for typeName, typeData in self.types.items():
            print (f'Type: {typeName}')
            for k, v, in typeData.members.items():
                print (f'    member: {k}')
                for kp, vp, in v.properties.items():
                    print (f'        property: {kp} = {vp}')
        

    def generateCode(self):
        var = self.d('variant')
        print (f'Generate code for {var}')

