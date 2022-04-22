from .type import Type
from .props import Scribe


class EnumVal:
    def __init__(self, enumType, bomaName, numberValue, numberValueSpecified, isDuplicate, props):
        self.enumType = enumType
        self.bomaName = bomaName
        self.props = props
        self.codeDecl = ''
        self.fullCodeDecl = ''
        self.numberValue = numberValue
        self.numberValueSpecified = numberValueSpecified
        self.isDuplicate = isDuplicate


class EnumType(Type):
    def __init__(self, typeBlock, props):
        super().__init__(typeBlock['name'], props)
        self.props = props

        s = Scribe(props)
        self.namespace = s.getXProp('namespace')

        vals = []
        if type(typeBlock['values']) is list:
            vals = typeBlock['values']

        self.vals = []
        cidx = 0
        seenNums = set()
        seenVals = dict()
        for val in vals:
            idx = -1
            if type(val) is list and type(val) is not str:
                if type(val[1]) is int:
                    idx = int(val[1])    # TODO: Allow idx to be a name we've seen earlier
                #elif type(val[1]) is str:
                #    idx = seenVals.get(val[1], val[1])
                val = val[0]
                ev = EnumVal(self, val, idx, True, idx in seenNums, props)
                self.vals.append(ev)
                cidx = idx
            else:
                idx = cidx
                ev = EnumVal(self, val, idx, False, idx in seenNums, props)
                self.vals.append(ev)
            seenNums.add(idx)
            seenVals[val] = idx
            cidx += 1

        #self.isScoped = enumProps.get('isScoped', True)
        #self.flags = enumProps.get('flags', False)
        #self.toDecl_prefix = enumProps.get('codePrefix', '')
        #self.toDecl_suffix = enumProps.get('codeSuffix', '')
        #self.toDecl_case = enumProps.get('codeCase', '')
        self.alreadyDefined = False


    def isScoped(self):
        s = Scribe(self.props)
        return s.getXProp('enumisScoped') == True


    def flags(self):
        s = Scribe(self.props)
        return s.getXProp('enumflags') == True


    def toDecl_prefix(self):
        s = Scribe(self.props)
        return s.getXProp('enumCodePrefix')


    def toDecl_suffix(self):
        s = Scribe(self.props)
        return s.getXProp('enumCodeSuffix')


    def toDecl_case(self):
        s = Scribe(self.props)
        return s.getXProp('enumCodeCase')


    def computeDeclVals(self, makeFullDecl):
        if self.alreadyDefined:
            return

        def translateEnumVal(enumVal):
            val = f'{self.toDecl_prefix()}{enumVal}{self.toDecl_suffix()}'
            if self.toDecl_case() == 'upper':
                val = val.upper()
            elif self.toDecl_case() == 'lower':
                val = val.lower()
            return val

        for val in self.vals:
            val.codeDecl = translateEnumVal(val.bomaName)
            val.fullCodeDecl = makeFullDecl(val)
