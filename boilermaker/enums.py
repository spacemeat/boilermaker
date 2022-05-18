from .type import Type
from .props import Scribe


class EnumVal:
    def __init__(self, enumType, bomaName, numberValue, isNumberValueSpecified, isDuplicate, props):
        self.enumType = enumType
        self.bomaName = bomaName
        self.props = props
        self.codeDecl = ''
        self.fullCodeDecl = ''
        self.numberValue = numberValue
        self.isNumberValueSpecified = isNumberValueSpecified
        self.isDuplicate = isDuplicate


#   enumVals: [
#       aaa
#       bbb
#       [ccc, 4]            //  set numeric value
#       [ddd, [4, 8]]       //  set numeric flags value 4 | 8       -- note, we do not shift these
#       [eee, aaa]          //  set numeric value previously defined
#       [fff, [bbb, ccc]]   //  sst numeric flags value previously defined
#   ]


class EnumType(Type):
    def __init__(self, typeBlock, props):
        super().__init__(typeBlock['name'], props)
        self.props = props

        s = Scribe(props)
        self.namespace = s.getXProp('namespace')

        isFlags = s.getXProp('enumFlags')

        vals = []
        if type(typeBlock['values']) is list:
            vals = typeBlock['values']

        self.vals = []
        nextAutoVal = 0
        seenNums = set()
        seenVals = dict()

        if isFlags == False:
            name = ''
            num = -1

            for val in vals:
                # val is a string; just record the name with an increasing numeric value
                if type(val) is str:
                    name = val
                    num = nextAutoVal
                    ev = EnumVal(self, name, num, False, num in seenNums, props)
                    self.vals.append(ev)

                # val is a list; we need to set a numeric
                elif type(val) is list:
                    name = val[0]
                    if type(val[1]) is int:
                        num = val[1]
                    elif type(val[1]) is str:
                        if val[1] in seenVals:
                            num = seenVals[val[1]]
                        else:
                            raise RuntimeError(f"Invalid enum value '{val[1]}' in {self.name}")
                    else:
                        raise RuntimeError(f"malformed enum vals in {self.name}")

                    ev = EnumVal(self, name, num, True, num in seenNums, props)
                    self.vals.append(ev)

                seenNums.add(num)
                seenVals[name] = num
                nextAutoVal = num + 1

        else:
            name = ''
            num = -1
            nextFlagVal = 1

            for val in vals:
                # val is a string; just record the name with an increasing numeric value
                if type(val) is str:
                    name = val
                    num = nextFlagVal
                    nextFlagVal *= 2
                    ev = EnumVal(self, name, num, True, num in seenNums, props)
                    self.vals.append(ev)

                # val is a list; we need to set a numeric
                elif type(val) is list:
                    name = val[0]
                    if type(val[1]) is int:
                        num = val[1]
                        nextFlagVal = num * 2
                    elif type(val[1]) is str:
                        if val[1] in seenVals:
                            num = seenVals[val[1]]
                        else:
                            raise RuntimeError(f"Invalid enum value '{val[1]}' in {self.name}")
                    elif type(val[1]) is list:
                        flags = val[1]
                        num = 0
                        for flag in flags:
                            if type(flag) is int:
                                num += flag
                            elif type(flag) is str:
                                if flag in seenVals:
                                    num += seenVals[flag]
                                else:
                                    raise RuntimeError(f"Invalid enum flag value '{flag}' in {self.name}")
                    else:
                        raise RuntimeError(f"malformed enum vals in {self.name}")

                    ev = EnumVal(self, name, num, True, num in seenNums, props)
                    self.vals.append(ev)

                seenNums.add(num)
                seenVals[name] = num
                nextAutoVal = num + 1

        self.alreadyDefined = False


    def isScoped(self):
        s = Scribe(self.props)
        return s.getXProp('enumIsScoped') == True


    def flags(self):
        s = Scribe(self.props)
        return s.getXProp('enumFlags') == True


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
            val = f'{self.toDecl_prefix() or ""}{enumVal}{self.toDecl_suffix() or ""}'
            if self.toDecl_case() == 'upper':
                val = val.upper()
            elif self.toDecl_case() == 'lower':
                val = val.lower()
            return val

        for val in self.vals:
            val.codeDecl = translateEnumVal(val.bomaName)
            val.fullCodeDecl = makeFullDecl(val)
