from .type import Type


class EnumVal:
    def __init__(self, enumType, bomaName, numberValue, numberValueSpecified, isDuplicate):
        self.enumType = enumType
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
            idx = -1
            if type(val) is list and type(val) is not str:
                idx = int(val[1])    # TODO: Allow idx to be a name we've seen earlier
                val = val[0]
                ev = EnumVal(self, val, idx, True, idx in seenNums)
                self.vals.append(ev)
                cidx = idx
            else:
                idx = cidx
                ev = EnumVal(self, val, idx, False, idx in seenNums)
                self.vals.append(ev)
            seenNums.add(idx)
            cidx += 1

        self.isScoped = enumProps.get('isScoped', True)
        self.flags = enumProps.get('flags', False)
        self.toDecl_prefix = enumProps.get('prefix', '')
        self.toDecl_suffix = enumProps.get('suffix', '')
        self.toDecl_case = enumProps.get('case', '')
        self.alreadyDefined = False


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
