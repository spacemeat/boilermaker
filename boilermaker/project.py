from . import utilities, ansi

# TODO: Make this a plugin thing.
from .enums import Enums as Enums
from .grok.cFamily.enums import CfamilyEnums
from .type import StructType
import re
from .props import Props, PropertyBag
from pathlib import Path, PurePath

# TODO: Make this a plugin thing. Nice info: https://realpython.com/python-import/


# read ${captured}, when not preceded by a '\'
defArgumentPattern = r'(?<!\\)\$\s*\<\s*([A-Za-z0-9_.]+?)\s*\>'
defArgumentReg = re.compile(defArgumentPattern)


class Project:
    def __init__(self, A, propsPath):
        self.props = self.loadProps(propsPath)
        self.props.push({'projectPath': propsPath})
        self.enumsMade = False

    def getPathFromInherit(self, inh :str, originPath :Path):
        if path := utilities.getBuiltinDefsPath(inh):
            return path
        inhPath = originPath.parent / inh
        if inhPath.exists():
            return path
        # TODO: Possibly search other paths for boma files


    def loadProps(self, path):
        def rec(bagPath):
            print (f"Loading bag: {bagPath}")
            trove, defsFileVersion = utilities.loadHumonFile(bagPath)
            propsDict = trove.root.objectify()
            if type(propsDict) is not dict:
                raise RuntimeError(f'Malformed boma props file')

            bag = PropertyBag({})
            bag.setDict(propsDict)

            if 'inherit' in propsDict:
                inhs = propsDict['inherit']
                if type(inhs) is str:
                    inhs = [inhs]

                for inh in inhs:
                    newBagPath = self.getPathFromInherit(inh, Path(bagPath))
                    if newBagPath == None:
                        raise RuntimeError(f'Boilermaker file {inh} cannot be opened.')
                    newBag = rec(newBagPath)
                    bag.inherit(newBag)

            return bag

        topBag = rec(path)
        return Props(topBag)


    def replaceStringArgs(self, val, replacements=None):
        if replacements:
            replacements = {**replacements, **self.props}
        else:
            replacements = self.props

        def replace(key):
            if key in replacements:
                return replacements[key]
            else:
                return self.props.get(key, f'!{key}!')

        # run this until val stops changing; handles nested $<>
        while True:
            newVal = re.sub(defArgumentReg, lambda m: replace(m.group(1)), val)
            if newVal != val:
                val = newVal
            else:
                return newVal


    def replaceObjectArgs(self, val, replacements=None):
        if not replacements:
            replacements = self.props

        if type(val) is str:
            return self.replaceStringArgs(val, replacements)

        elif type(val) is list:
            return [self.replaceObjectArgs(ch, replacements) for ch in val]

        elif type(val) is dict:
            return {self.replaceStringArgs(k, replacements): self.replaceObjectArgs(v, replacements) for k, v in val.items()}


    def d(self, key, replacements=None):
        if not replacements:
            replacements = self.props

        val = self.props.get(key)
        return self.replaceObjectArgs(val)


    def dIs(self, key):
        val = self.props.get(key)
        return val and val.lower() == 'true'


    def indent(self):
        indent = self.props.get('indent', {'type':'space', 'num': '4' } )
        if indent['type'] == 'space':
            return ' ' * (int(indent['num']))
        elif indent['type'] == 'tab':
            return '\t' * (int(indent['num']))
        else:
            raise RuntimeError(f'invalid "indent" value: {indent}')


    def run(self, op):
        variantName = self.d('variant')
        print (f'{ansi.dk_blue_fg}Performing {ansi.lt_blue_fg}{op}{ansi.dk_blue_fg} for project variant {ansi.lt_magenta_fg}{variantName}{ansi.dk_blue_fg}.{ansi.all_off}')

        if op == 'reportDefs':
            self.reportDefs()
        elif op == 'reportEnums':
            self.reportEnums()
        elif op == 'reportTypes':
            self.reportTypes()
        elif op == 'reportOutputs':
            self.reportOutputs()
        elif op == 'writeCode':
            self.write()


    def reportProps(self):
        print (str(self.props))


    def everyEnum(self):
        for enumsObject in self.enums:
            typedefsSeen = set()
            for enumName, enumTypedefObject in enumsObject.enumTypedefs.items():
                typedefsSeen.add(enumTypedefObject.enumName)
                yield (enumName, enumsObject.enums[enumTypedefObject.enumName])
            for enumName, enumObject in enumsObject.enums.items():
                if enumObject.name not in typedefsSeen:
                    yield (enumName, enumObject)


    def makeEnums(self):
        if self.enumsMade:
            return
        self.enums = []
        self.props.ensureList('enums')
        for enumPropsList in self.props.getAll('enums'):
            for enumProps in enumPropsList:
                language = self.props.parseText(enumProps.get('language', ''))
                languageVersion = self.props.parseText(enumProps.get('languageVersion', ''))
                if language == "c" or language == 'c++':
                    self.enums.append(CfamilyEnums(self.props, enumProps))
                else:
                    raise RuntimeError(f'Unrecognized enums language: {language}')
        self.enumsMade = True


    def makeTypes(self):
        self.types = {}
        breakpoint()
        for typeValues in self.props.getAll('types'):
            for (typeName, typeData) in typeValues.items():
                self.types[typeName] = StructType(typeName, typeData)

        #for (typeName, typeData) in [kv.items() for kv in self.props.getAll('types')]:
        #    self.types[typeName] = StructType(typeName, typeData)


    def reportDefs(self):
        var = self.d('variant')
        print (f'Report on {var}:')
        for k, v in self.props.items():
            print (f'  {k}: {v}')


    def reportEnums(self):
        for enumName, enumObject in self.everyEnum():
            print (f'Enum: {enumName}:')
            for k, v in enumObject.enumVals.items():
                print (f'    {k} = ({v[0]}, {v[1]})')


    def reportTypes(self):
        for typeName, t in self.types.items():
            print (t)


    def reportOutputs(self):
        pass


    def write(self):
        pass