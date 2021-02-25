from . import utilities, ansi

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
    

    def replaceStringArgs(self, val, replacements=None):
        if replacements:
            replacements = {**replacements, **self.defsData}
        else:
            replacements = self.defsData

        def replace(key):
            if key in replacements:
                return replacements[key]
            else:
                return self.defsData.get(key, f'!{key}!')

        # run this until val stops changing; handles nested $<>
        while True:
            newVal = re.sub(defArgumentReg, lambda m: replace(m.group(1)), val)
            if newVal != val:
                val = newVal
            else:
                return newVal
    

    def replaceObjectArgs(self, val, replacements=None):
        if not replacements:
            replacements = self.defsData

        if type(val) is str:
            return self.replaceStringArgs(val, replacements)

        elif type(val) is list:
            return [self.replaceObjectArgs(ch, replacements) for ch in val]

        elif type(val) is dict:
            return {self.replaceStringArgs(k, replacements): self.replaceObjectArgs(v, replacements) for k, v in val.items()}


    def d(self, key, replacements=None):
        if not replacements:
            replacements = self.defsData

        val = self.defsData.get(key)
        return self.replaceObjectArgs(val)

    
    def dIs(self, key):
        val = self.defsData.get(key)
        return val and val.lower() == 'true'


    def indent(self):
        indent = self.defsData.get('indent', {'type':'space', 'num': '4' } )
        if indent['type'] == 'space':
            return ' ' * (int(indent['num']))
        elif indent['type'] == 'tab':
            return '\t' * (int(indent['num']))
        else:
            raise RuntimeError(f'invalid "indent" value: {indent}')


    def run(self, op):
        variantName = self.d('variant')
        print (f'{ansi.dk_blue_fg}Performing {ansi.lt_blue_fg}{op}{ansi.dk_blue_fg} for project variant {ansi.lt_magenta_fg}{variantName}{ansi.dk_blue_fg}.{ansi.all_off}')

        if op == 'reportDefs':
            self.reportDefs()
        elif op == 'reportEnums':
            self.reportEnums()
        elif op == 'reportTypes':
            self.reportTypes()
        elif op == 'reportOutputs':
            self.reportOutputs()
        elif op == 'writeCode':
            self.writeCode()
    

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


    def reportDefs(self):
        var = self.d('variant')
        print (f'Report on {var}:')
        for k, v in self.defsData.items():
            print (f'  {k}: {v}')


    def reportEnums(self):
        for enumName, enumObject in self.everyEnum():
            print (f'Enum: {enumName}:')
            for k, v in enumObject.enumVals.items():
                print (f'    {k} = ({v[0]}, {v[1]})')
        

    def reportTypes(self):
        for typeName, t in self.types.items():
            print (t)
        

    def reportOutputs(self):
        pass

    
    def writeCode(self):
        pass