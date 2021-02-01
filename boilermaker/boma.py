from copy import deepcopy
import os
import sys
from . import utilities


# TODO: Make this a plugin thing. Nice info: https://realpython.com/python-import/
from .project import Project as Project
from .cpp.project import Project as CppProject


def inherit(base, addTo, inheritInherits):
    defsData = deepcopy(base)

    defsData['inherit'] = utilities.listify(defsData.get('inherit'))
    defsData['enums'] = utilities.listify(defsData.get('enums'))
    defsData['types'] = utilities.dictify(defsData.get('types'))

    # inherit inheritance from base data, but not from external DefsFiles
    if inheritInherits:
        defsData['inherit'].extend(utilities.listify(addTo.get('inherit')))
    else:
        defsData['inherit'] = utilities.listify(addTo.get('inherit'))

    # inherit enums
    defsData['enums'].extend(utilities.listify(addTo.get('enums')))

    # inherit types
    defsData['types'].update(utilities.dictify(addTo.get('types')))

    # inherit errything else by override
    for k, v in addTo.items():
        if k not in ['inherit', 'enums', 'types']:
            defsData[k] = v
        
    return defsData


class DefsVariant:
    def __init__(self, defsName, variantName, defsPath, baseDefsData, variantDefsData):
        '''baseDefsData and variantDefsData have both been cleansed of "variant" members.'''

        # normalize 'inherit' elements.
        if variantName == '*':
            self.defsData = inherit(baseDefsData, {}, True)
        else:
            print (f'''Folding base data: {defsName}|{variantName} = {defsName}|* + {defsName}|{variantName}''')
            self.defsData = inherit(baseDefsData, variantDefsData, True)

        self.defsData['variant'] = '|'.join([defsName, variantName])
        self.defsData['defsPath'] = defsPath


class DefsFile:
    cache = {}


    @classmethod
    def make(cls, name, path):
        if path in cls.cache:
            return cls.cache[path]
        else:
            defs = DefsFile(name, path)
            cls.cache[path] = defs
            return defs
            

    @staticmethod
    def getDefNameParts(name):
        tokens = name.split('|')
        defsName = tokens[0]
        variantName = '*'
        if len(tokens) > 1:
            variantName = tokens[1]
        return (defsName, variantName)


    def __init__(self, name, path):
        self.name = name
        self.path = path

        # acquire the trove
        t, defFileVersion = utilities.loadHumonFile(path)
        defsData = t.root.objectify()
        self.variants = {}

        # cache and remove variants
        vdescs = defsData.get('variants')
        if vdescs:
            del defsData['variants']
    
            # variants can't have variants... yet. But, that's intersting, no?
            for vk, vv in vdescs.items():
                if 'variants' in vv:
                    raise RuntimeError(f'Error in variant "{name}|{vk}": Variants cannot have "variant" members.')

        # set the * variant
        self.variants['*'] = DefsVariant(name, '*', path, defsData, {})
        if vdescs:
            # fold in variant data and base data for each variant
            for vk, vv in vdescs.items():
                self.variants[vk] = DefsVariant(name, vk, path, defsData, vv)


    def resolve(self, variantName):
        defsData = self.variants[variantName].defsData
        for inherited in defsData['inherit']:
            # make the inherited DefsFile
            inheritedDefsName, inheritedVariantName = DefsFile.getDefNameParts(inherited.lower())
            inheritedDefsPath = utilities.getBuiltinDefsPath(inheritedDefsName)
            inheritedDefs = DefsFile.make(inheritedDefsName, inheritedDefsPath)

            # recursive call to inherited def's resolve.
            inheritedData = inheritedDefs.resolve(inheritedVariantName)

            print (f'Folding inherited variants: defsData = {inheritedDefsName}|{inheritedVariantName} + defsData')
            defsData = inherit(inheritedData, defsData, False)

            defsData['tools'] = defsData.get('tools', '').lower()
            defsData['targetLanguage'] = defsData.get('targetLanguage', '').lower()
 
        return defsData


def makeProject(defsData):
    if defsData['targetLanguage'] == 'c++':
        return CppProject(defsData)
    else:
        return Project(defsData)


# Use like this, from a project root:
# /src/samples:$ boma ./boma/defs.hu -p newsample

def main():
    defFile = None
    variantsRequested = []
    operations = []
    color = True
    skip = False

    for i in range(0, len(sys.argv)):
        if skip:
            skip = False
            continue
        
        if sys.argv[i] == '-v':
            variantsRequested.append(sys.argv[i + 1])
            skip = True
        elif sys.argv[i] == '-r':
            operations.append('report')
        elif sys.argv[i] == '-g':
            operations.append('generateCode')
        elif sys.argv[i] == '-C':
            color = False
        else:
            defFile = sys.argv[i]

    if len(operations) == 0:
        operations.append('generateCode')
    
    if defFile:
        defsFile = DefsFile.make('defs', os.path.realpath(defFile))
        if len(variantsRequested) == 0:
            variantsRequested = defsFile.variants

        for v in variantsRequested:
            p = makeProject(defsFile.resolve(v))
            for op in operations:
                p.run(op)
