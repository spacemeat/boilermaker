from ...plugin import Provider
from ...props import Scribe
from ...type import BomaType
from ...enums import EnumType
#from ..grokCpp.enums import CfamilyEnums


class BomaProvider(Provider):
    def start(self, runDefs, props):
        print (f'starting BomaProvider')
        self.runDefs = runDefs


    def do(self, op, seq, props):
        print (f'BomaProvider doing op {op} at sequence {seq}')
        if op == 'createEnums':
            self.makeEnums(props)

        elif op == 'createTypes':
            self.makeTypes(props)

        elif op == 'createReports':
            self.generateOutput(props)


    def stop(self, props):
        print (f'stopping BomaProvider')


    def makeEnums(self, props):
        s = Scribe(props)
        self.enums = {}
        for enumDefs in s.getXPropAll('enums'):
            enumProps = enumDefs.get('-props', {})
            for enumName, enumDef in enumDefs.items():
                if enumName == '-props':
                    continue
                self.enums[enumName] = EnumType(enumName, s.X('namespace'), enumDef, enumProps)
        props.push({'bomaEnums': self.enums})


    def makeTypes(self, props):
        s = Scribe(props)
        self.types = {}
        for typeValues in s.getXPropAll('types'):
            for (typeName, typeData) in typeValues.items():
                self.types[typeName] = BomaType(typeName, s.X('namespace'), typeData)
        props.push({'bomaTypes': self.types})


    def reportProps(self, props):
        print (str(props))


    def reportEnums(self, props):
        pass

    def reportTypes(self, props):
        for typeName, t in self.types.items():
            print (t)


    def generateOutput(self, props):
        self.reportProps(props)
        self.reportEnums(props)
        self.reportTypes(props)


