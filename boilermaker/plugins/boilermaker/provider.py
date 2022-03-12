from ...plugin import Provider
from ...props import Scribe
from ...type import BomaType
from ...enums import EnumType
from ..grokCpp.enums import CfamilyEnums


class BomaProvider(Provider):
    def start(self, run, props):
        print (f'starting BomaProvider')
        self.run = run


    def do(self, op, seq, props):
        print (f'BomaProvider doing op {op} at sequence {seq}')
        if op == 'createEnums':
            self.makeEnums(props)

        elif op == 'createTypes':
            self.makeTypes(props)

        elif op == 'output':
            self.generateOutput(props)


    def stop(self, props):
        print (f'stopping BomaProvider')


    def everyEnum_old(self):
        for enumsObject in self.enums:
            typedefsSeen = set()
            for enumName, enumTypedefObject in enumsObject.enumTypedefs.items():
                typedefsSeen.add(enumTypedefObject.enumName)
                yield (enumName, enumsObject.enums[enumTypedefObject.enumName])
            for enumName, enumObject in enumsObject.enums.items():
                if enumObject.name not in typedefsSeen:
                    yield (enumName, enumObject)


    def makeEnums(self, props):
        s = Scribe(props)
        self.enums = {}
        for enumDefs in s.getXPropAll('enums'):
            enumProps = enumDefs.get('-props', {})
            for enumName, enumDef in enumDefs.items():
                if enumName == '-props':
                    continue
                self.enums[enumName] = EnumType(enumName, enumDef, enumProps)
        props.push({'enumTypes': self.enums})


    def makeTypes(self, props):
        s = Scribe(props)
        self.types = {}
        for typeValues in s.getXPropAll('types'):
            for (typeName, typeData) in typeValues.items():
                self.types[typeName] = BomaType(typeName, typeData)
        props.push({'bomaTypes': self.types})


    def reportProps(self, props):
        print (str(props))


    def reportEnums(self, props):
        pass
        for enumName, enumObject in self.everyEnum():
            print (f'Enum: {enumName}:')
            for k, v in enumObject.enumVals.items():
                print (f'    {k} = ({v[0]}, {v[1]})')


    def reportTypes(self, props):
        for typeName, t in self.types.items():
            print (t)


    def generateOutput(self, props):
        self.reportProps(props)
        self.reportEnums(props)
        self.reportTypes(props)



