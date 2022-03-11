from tkinter import E
from . import utilities, ansi

# TODO: Make this a plugin thing.
from .enums import Enums as Enums
from .plugins.grokCpp.enums import CfamilyEnums
import re
from .props import Props, PropertyBag, Scribe
from pathlib import Path
from .plugin import PluginCollection

# TODO: Make this a plugin thing. Nice info: https://realpython.com/python-import/
from .plugins.cpp17.project import CppProject

# read ${captured}, when not preceded by a '\'
defArgumentPattern = r'(?<!\\)\$\s*\<\s*([A-Za-z0-9_.]+?)\s*\>'
defArgumentReg = re.compile(defArgumentPattern)


class Project:
    def __init__(self, A, propsPath):
        if type(propsPath) is not Path:
            propsPath = Path(propsPath)
        self.propsPath = propsPath
        self.bomaPath = Path(__file__).parent
        self.enumsMade = False
        self.loadedProviders = {}

    def run(self):
        try:
            self.loadProps()

            s = Scribe(self.props)
            runs = s.getXPropAll('run')
            ops = []
            for run in runs:
                for op, seq in run['ops'].items():
                    ops.append((f'{run["plugin"]}.{run["provider"]}', run, op, seq))
            ops.sort(key=lambda op: op[3])

            seenProvs = set()
            for op in ops:
                providerName = op[0]
                if providerName in seenProvs:
                    continue
                seenProvs.add(providerName)
                provider = self.loadProvider(providerName)
                provider.start(op[1], self.props)

            for op in ops:
                providerName = op[0]
                provider = self.loadProvider(providerName)
                provider.do(op[2], op[3], self.props)

            seenProvs = set()
            for op in ops:
                providerName = op[0]
                if providerName in seenProvs:
                    continue
                seenProvs.add(providerName)
                provider = self.loadProvider(providerName)
                provider.stop(self.props)

            return True

        except BaseException as e:
            print (f'Encountered an error: {e}')
            raise e
            return False


    def getPathFromInherit(self, inh :str, originPath :Path):
        #if path := utilities.getBuiltinDefsPath(inh):
        #    return path
        inhPath = originPath.parent / 'inh.hu'
        if inhPath.exists():
            return inhPath
        inhPath = self.bomaPath / 'plugins' / inh / 'props.hu'
        if inhPath.exists():
            return inhPath
        # TODO: Possibly search other paths for boma files


    def loadProps(self):
        def rec(bagPath):
            print (f"Loading bag: {bagPath}")
            trove, defsFileVersion = utilities.loadHumonFile(bagPath)
            propsDict = trove.root.objectify()
            if type(propsDict) is not dict:
                raise RuntimeError(f'Malformed boma props file')

            bag = PropertyBag({})
            bag.setDict(propsDict)
            bag.propsFilePath = bagPath
            bag.propsFileDir = bagPath.parent

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

        topBag = rec(self.propsPath)
        self.props = Props(topBag)
        self.props.push({'projectPath': self.propsPath,
                         'projectDir': self.propsPath.parent,
                         'bomaDir': Path(__file__).parent,
                         'pluginsDir': Path(__file__).parent / 'plugins',
                         'mainHeaderIncludes': []})


    def loadProvider(self, provider):
        pc = PluginCollection(self.bomaPath / 'plugins')
        if provider not in self.loadedProviders:
            self.loadedProviders[provider] = pc.importProvider(provider)

        return self.loadedProviders[provider]
