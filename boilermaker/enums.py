from .type import Type
from .props import Scribe


class BomaEnumVal:
    def __init__(self, name, numericValue, codeDecl):
        self.name = name
        self.numericValue = numericValue
        self.codeDecl = codeDecl
        self.fullCodeDecl = ''

        self.props = None
        self.isNumberValueSpecified = False
        self.isDuplicate = False


class BomaEnum:
    def __init__(self, name, values, codeDecl, include, namespace, hasCodeDefs, isFlags, isScoped):
        self.name = name
        self.codeDecl = codeDecl
        self.values = values
        self.include = include
        self.namespace = namespace
        self.hasCodeDefs = hasCodeDefs
        self.isFlags = isFlags
        self.isScoped = isScoped
        self.props = None
        self.computeIsNumberValueSpecified()
        self.computeIsDuplicate()

    def computeIsNumberValueSpecified(self):
        expectedValue = 0
        #breakpoint()
        for val in self.values:
            num = val.numericValue
            val.isNumberValueSpecified = (num != expectedValue)
            expectedValue = num + 1

    def computeIsDuplicate(self):
        nums = set()
        for val in self.values:
            if val.numericValue in nums:
                val.isDuplicate = True
            else:
                nums.add(val.numericValue)
                val.isDuplicate = False

    def setProps(self, props):
        self.props = props
        for val in self.values:
            val.props = props
        self.props.setProp('enumIsScoped', self.isScoped)
        self.props.setProp('enumFlags', self.isFlags)


class BomaEnumType(Type):
    def __init__(self, bomaEnum, props):
        self.bomaEnum = bomaEnum
        self.name = bomaEnum.name
        self.props = props
        self.bomaEnum.setProps(props)

        self.alreadyDefined = bomaEnum.hasCodeDefs

        self.codeDecl = bomaEnum.codeDecl
        self.fullCodeDecl = ''

        #if self.name == "VkResult":
        #    breakpoint()
        self.include = self.bomaEnum.include

        if self.bomaEnum.namespace != None:
            self.props.setProp('namespace', self.bomaEnum.namespace)

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

    def translateEnumVal(self, enumVal):
        val = f'{self.toDecl_prefix() or ""}{enumVal}{self.toDecl_suffix() or ""}'
        if self.toDecl_case() == 'upper':
            val = val.upper()
        elif self.toDecl_case() == 'lower':
            val = val.lower()
        return val

