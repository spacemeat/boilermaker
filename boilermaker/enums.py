from . import utilities
from .type import Type


class EnumType(Type):
    def __init__(self, name, enumDef, enumProps :dict):
        super().__init__(name)
        vals = []
        if type(enumDef) is list:
            vals = enumDef
        elif type(enumDef) is dict:
            vals = enumDef['values'] or []
            self.enumProps = enumProps.update(enumDef.get('props', {}))
        self.vals = vals

        self.isScoped = enumProps.get('isScoped', True)
        self.flags = enumProps.get('flags', False)
        self.toDecl_prefix = enumProps.get('prefix', '')
        self.toDecl_suffix = enumProps.get('suffix', '')
        self.toDecl_case = enumProps.get('case', '')

        self.alreadyDefined = False
        self.declVals = []


    def provideDeclVals(self, declVals):
        self.alreadyDefined = True
        self.declVals = declVals


    def computeDeclVals(self):
        if self.alreadyDefined:
            return

        def translateEnumVal(enumVal):
            val = f'{self.toDecl_prefix}{enumVal}{self.toDecl_suffix}'
            if self.toDecl_case == 'upper':
                val = val.upper()
            elif self.toDecl_case == 'lower':
                val = val.lower()
            return val

        declVals = []
        cidx = 0
        for v in self.vals:
            declVal = v
            idx = cidx
            if type(v) is list:
                declVal = translateEnumVal(v[0])
                idx = int(v[1])
                cidx = idx
                declVals.append([declVal, idx])
            else:
                declVal = translateEnumVal(declVal)
                declVals.append(declVal)
            cidx += 1

        self.declVals = declVals


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
