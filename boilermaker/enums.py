from . import utilities
from .type import Type


class Enums:
    def __init__(self, props, enumProps):
        self.props = props
        self.enumProps = enumProps
        self.flagsAttribute = self.enumProps.get('flags', {})
        self.prefixAttribute = self.enumProps.get('prefix', {})
        self.suffixAttribute = self.enumProps.get('suffix', {})
        self.caseAttribute = self.enumProps.get('case', {})


class EnumType(Type):
    def __init__(self, name, enumDef, enumProps :dict):
        super().__init__(name)
        self.vals = []
        self.toDict_prefix = enumProps.get('prefix', '')
        self.toDict_suffix = enumProps.get('suffix', '')
        self.toDict_case = enumProps.get('case', '')
        self.toDict_numerics = enumProps.get('allNumerics', False)

        self.alreadyDefined = False
        self.declVals = []

        vals = []
        if type(enumDef) is list:
            vals = enumDef
        elif type(enumDef) is dict:
            vals = enumDef['values'] or []
            self.enumProps = enumProps | enumDef.get('props', {})


    def provideDefinition(self, declVals):
        self.alreadyDefined = True
        self.declVals = declVals


class Enum:
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


    @staticmethod
    def determineCommonPreSuffixLengthBetweenTwo(a, b, postfix, delimit = None):
        # I'm sure there's a pythonic way
        commonLength = 0
        for i in range(0, min(len(a), len(b))):
            idx = i if not postfix else -i - 1
            if a[idx] == b[idx]:
                commonLength += 1
            else:
                break

        # if the prefix ends in a non-delimit, dial it back until we find one
        # (also if postfix starts in a non-_...)
        # TODO: Test multicharacter delimiters. I think this is wrong.

        #if commonLength < len(a):
        if delimit:
            if not postfix:
                idx = commonLength - 1
                while commonLength > 0 and a[idx:idx + len(delimit)] != delimit:
                    commonLength -= 1
                    idx -= 1
            else:
                idx = -commonLength
                while commonLength > 0 and a[idx:idx + len(delimit)] != delimit:
                    commonLength -= 1
                    idx += 1

        return commonLength


    @staticmethod
    def determineCommonPreSuffixLength(strs, postfix, delimit):
        cev = strs[0]
        commonLength = len(cev)
        for ev in strs[1:]:
            l = Enum.determineCommonPreSuffixLengthBetweenTwo(cev, ev, postfix, delimit)
            if l < commonLength:
                commonLength = l
            if commonLength == 0:
                break
        return commonLength


    def _computeAttributes(self, enumName, declStringValues):
        #flags
        self.flags = False
        if len(self.enumsObject.flagsAttribute) > 0:
            for op, value in self.enumsObject.flagsAttribute.items():
                if op == 'nameContains':
                    if value and type(value) is not str:
                        raise RuntimeError(f'platform/flags/nameContains must be a string value.')

                    if enumName.find(value) > 0:
                        self.flags = True
                else:
                    raise RuntimeError(f'platform/flag contains an invalid operation "{op}".')

        #prefix
        self.prefixLen = 0
        if len(self.enumsObject.prefixAttribute) > 0:
            excludeCommon = False
            delimit = ''
            for op, value in self.enumsObject.prefixAttribute.items():
                if op == 'exclude':
                    if value and type(value) is not str:
                        raise RuntimeError(f'platform/prefix/exclude must be a string value.')
                    if value == 'common':
                        excludeCommon = True
                elif op == 'delimit':
                    if value and type(value) is not str:
                        raise RuntimeError(f'platform/prefix/delimit must be a string value.')
                    delimit = value
                else:
                    raise RuntimeError(f'platform/prefix contains an invalid operation "{op}".')

            if excludeCommon and len(declStringValues) > 1:
                self.prefixLen = self.determineCommonPreSuffixLength(declStringValues, False, delimit)
            else:
                self.prefixLen = 0

        #suffix
        self.suffixLen = 0
        if len(self.enumsObject.suffixAttribute) > 0:
            excludeCommon = False
            delimit = ''
            for op, value in self.enumsObject.suffixAttribute.items():
                if op == 'exclude':
                    if value and type(value) is not str:
                        raise RuntimeError(f'platform/suffix/exclude must be a string value.')
                    if value == 'common':
                        excludeCommon = True
                elif op == 'delimit':
                    if value and type(value) is not str:
                        raise RuntimeError(f'platform/suffix/delimit must be a string value.')
                    delimit = value
                else:
                    raise RuntimeError(f'platform/suffix contains an invalid operation "{op}".')

            if excludeCommon and len(declStringValues) > 1:
                self.suffixLen = self.determineCommonPreSuffixLength(declStringValues, True, delimit)
            else:
                self.suffixLen = 0

        #case
        self.case = 'leaveIt'
        if len(self.enumsObject.caseAttribute) > 0:
            for op, value in self.enumsObject.caseAttribute.items():
                if op == 'encode':
                    if value and type(value) is not str:
                        raise RuntimeError(f'platform/case/encode value must be a string value.')

                    if value in ['lower', 'upper', 'leaveIt']:
                        self.case = value
                    else:
                        raise RuntimeError(f'platform/case/encode value must be one of "lower", "upper", or "leaveIt".)')
                else:
                    raise RuntimeError(f'platform/case contains an invalid operation "{op}".')


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



class EnumTypedef:
    def __init__(self, typedefName, enumName, namespaceName):
        self.name = typedefName
        self.enumName = enumName
        self.attribs = set()
        self.namespaceName = namespaceName
