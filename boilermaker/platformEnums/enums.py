class Enums:
    def __init__(self):
        self.enums = {}

    def addEnum(self, platform, enum):
        if platform not in self.enums:
            self.enums[platform] = {enum.name: enum}
        else:
            self.enums[platform][enum.name] = enum

    def getAllPlatformEnums(self, platform):
        return self.enums[platform]
    
    def getAllEnums(self):
        enums = {}
        for es in self.enums.values():
            enums = {**enums, **es}
        return enums

    def getEnum(self, enumName, platform=None):
        if platform:
            if platform in self.enums and enumName in self.enums[platform]:
                return self.enums[platform][enumName]
        else:
            for platform, enums in self.enums.items():
                if enumName in enums:
                    return enums[enumName]
        return None


class Enum:
    def __init__(self, enumName, enumVals=None, typedefOf=None):
        self._name = enumName
        self.typedefOf = typedefOf
        self._values = enumVals
        self._attribs = set()
    
    @property
    def isTypedef(self):
        return bool(self.typedefOf)
    
    @property
    def name(self):
        return self._name

    @property
    def values(self):
        if self.typedefOf:
            return self.typedefOf.values
        return self._values
    
    @property
    def attribs(self):
        if self.isTypedef:
            return self.typedefOf.attribs
        return self._attribs

    def hasAttrib(self, attrib):
        if self.isTypedef:
            return self.typedefOf.hasAttrib(attrib)
        return attrib in self._attribs

    def setAttrib(self, attrib):
        if self.isTypedef:
            return self.typedefOf.setAttrib(attrib)
        self._attribs.add(attrib)
