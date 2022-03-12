from ... import utilities
from ...enums import Enums, Enum, EnumTypedef
from .getSearchPaths_gnu import getSearchPaths as getSearchPaths_gnu
from pathlib import Path
import pygccxml
from ...props import Scribe


class CfamilyEnums(Enums):
    def __init__(self, props, enumProps):
        super().__init__(props, enumProps)

        tools = enumProps.get('tools', 'gnu').lower()
        s = Scribe(props)
        projectPath = Path(s.X('projectPath'))

        if tools == 'gnu':
            self.quotedSearchPaths, self.systemSearchPaths  = getSearchPaths_gnu(projectPath.parent)
        else:
            raise RuntimeError(f'Invalid tools for enum defs in {projectPath}.')

        self.enums = {}
        self.enumTypedefs = {}
        src = enumProps.get('source')
        if src != None:
            self.source = src
            self._processSource(src)



class CfamilyEnum(Enum):
    def __init__(self, enumName, pygccxmlEnumVals, isScoped, enumsObject):
        super().__init__(enumName, '.', enumsObject)
        self.isScoped = isScoped

        '''enumVals looks like {"r4g4_unorm_pack8": ("VK_FORMAT_R4G4_UNORM_PACK8", 1), ...}'''
        self.enumVals = self._translateEnumVals(enumName, pygccxmlEnumVals)


    def _translateEnumVals(self, enumName, pygccxmlEnumVals):
        declStringValues = [val[0] for val in pygccxmlEnumVals]
        self._computeAttributes(enumName, declStringValues)

        enums = {}
        for valName, valNumber in pygccxmlEnumVals:
            newEnumVal = self._translateEnumVal(valName)
            enums[newEnumVal] = (valName, valNumber)

        return enums
