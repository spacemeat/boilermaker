from ...plugin import Provider
from ...props import Scribe
from ...type import BomaType
from ...enums import EnumType


## TODO: NOT USED and slated for deletion

class BomaProvider(Provider):
    def start(self, runDefs, props):
        print (f'starting BomaProvider')
        self.runDefs = runDefs
        self.props = props


    def do(self, op, seq):
        print (f'BomaProvider doing op {op} at sequence {seq}')
        #if op == 'createTypes':
        #    self.makeTypes()


    def stop(self):
        print (f'stopping BomaProvider')


    def makeEnums(self):
        s = Scribe(self.props)
        self.enums = {}
        for enumDefs in s.getXPropAll('enums'):
            enumProps = enumDefs.get('-props', {})
            for enumName, enumDef in enumDefs.items():
                if enumName == '-props':
                    continue
                self.enums[enumName] = EnumType(enumName, s.X('namespace'), enumDef, enumProps)
        self.props.push({'bomaEnums': self.enums})


    def makeTypes(self):
        s = Scribe(self.props)
        self.types = {}
        for typeValues in s.getXPropAll('types'):
            for (typeName, typeData) in typeValues.items():
                self.types[typeName] = BomaType(typeName, s.X('namespace'), typeData)
        self.props.push({'bomaTypes': self.types})


