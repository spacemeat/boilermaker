from . import utilities
from .type import Type


class EnumVal:
    def __init__(self, bomaName, numberValue, numberValueSpecified, isDuplicate):
        self.bomaName = bomaName
        self.codeDecl = ''
        self.fullCodeDecl = ''
        self.numberValue = numberValue
        self.numberValueSpecified = numberValueSpecified
        self.isDuplicate = isDuplicate


class EnumType(Type):
    def __init__(self, name, namespace, enumDef, enumProps :dict):
        super().__init__(name, namespace)
        vals = []
        if type(enumDef) is list:
            vals = enumDef
        elif type(enumDef) is dict:
            vals = enumDef['values'] or []
            self.enumProps = enumProps.update(enumDef.get('props', {}))

        self.vals = []
        cidx = 0
        seenNums = set()
        for val in vals:
            idx = cidx
            if type(val) is list:
                idx = int(val[1])    # TODO: Allow idx to be a name we've seen earlier
                val = val[0]
                cidx = idx
                ev = EnumVal(val, idx, True, idx in seenNums)
                self.vals.append(ev)
            else:
                ev = EnumVal(val, idx, False, idx in seenNums)
                self.vals.append(ev)
            seenNums.add(idx)
            cidx += 1

        self.isScoped = enumProps.get('isScoped', True)
        self.flags = enumProps.get('flags', False)
        self.toDecl_prefix = enumProps.get('prefix', '')
        self.toDecl_suffix = enumProps.get('suffix', '')
        self.toDecl_case = enumProps.get('case', '')

        self.alreadyDefined = False
        self.declVals = []


    def computeDeclVals(self, makeFullDecl):
        if self.alreadyDefined:
            return

        def translateEnumVal(enumVal):
            val = f'{self.toDecl_prefix}{enumVal}{self.toDecl_suffix}'
            if self.toDecl_case == 'upper':
                val = val.upper()
            elif self.toDecl_case == 'lower':
                val = val.lower()
            return val

        for val in self.vals:
            val.codeDecl = translateEnumVal(val.bomaName)
            val.fullCodeDecl = makeFullDecl(val)


class Enums_old:
    def __init__(self, props, enumProps):
        self.props = props
        self.enumProps = enumProps
        self.flagsAttribute = self.enumProps.get('flags', {})
        self.prefixAttribute = self.enumProps.get('prefix', {})
        self.suffixAttribute = self.enumProps.get('suffix', {})
        self.caseAttribute = self.enumProps.get('case', {})


class Enum_old:
    def __init__(self, enumName, namespaceName, enumsObject):
        super().__init__(self, enumName)
        self.enumName = enumName
        self._values = {}
        self._attribs = set()
        self.namespaceName = namespaceName
        self.enumsObject = enumsObject
        self.props = enumsObject.props
        self.enumProps = enumsObject.enumProps

        self.flags = False
        self.prefixLen = 0
        self.suffixLen = 0
        self.case = 'leaveIt'


    def _translateEnumVal(self, enumVal):
        val = enumVal
        val = val[self.prefixLen:]
        if self.suffixLen > 0:
            val = val[:-self.suffixLen]
        if self.case == 'lower':
            val = val.lower()
        elif self.case == 'upper':
            val = val.upper()
        return val



class EnumTypedef_old:
    def __init__(self, typedefName, enumName, namespaceName):
        self.name = typedefName
        self.enumName = enumName
        self.attribs = set()
        self.namespaceName = namespaceName
