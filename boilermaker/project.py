import re
from . import utilities
from .ansi import Ansi as ansi
from .props import Props, PropertyBag, Scribe
from pathlib import Path
from .plugin import PluginCollection

# read ${captured}, when not preceded by a '\'
defArgumentPattern = r'(?<!\\)\$\s*\<\s*([A-Za-z0-9_.]+?)\s*\>'
defArgumentReg = re.compile(defArgumentPattern)


class Project:
    def __init__(self, propsPath, propAdds):
        if type(propsPath) is not Path:
            propsPath = Path(propsPath)
        self.propsPath = propsPath
        self.bomaPath = Path(__file__).parent
        self.enumsMade = False
        self.loadedProviders = {}
        self.propAdds = propAdds

    def run(self):
        try:
            self.loadProps()

            s = Scribe(self.props)
            runDefses = s.getXPropAll('run')
            ops = []
            for runDefs in runDefses:
                for op, seq in runDefs['ops'].items():
                    ops.append((f'{runDefs["plugin"]}.{runDefs["provider"]}', runDefs, op, seq))
            ops.sort(key=lambda op: op[3])

            seenProvs = set()
            startOrder = []
            for op in ops:
                providerName = op[0]
                if providerName in seenProvs:
                    continue
                seenProvs.add(providerName)
                provider = self.loadProvider(providerName)
                startOrder.append(provider)
                provider.start(op[1], self.props)

            for op in ops:
                providerName = op[0]
                provider = self.loadProvider(providerName)
                provider.do(op[2], op[3])

            for provider in reversed(startOrder):
                provider.stop()

            return True

        except BaseException as e:
            print (f'Encountered an error: {e}')
            raise e
            return False


    def getPathFromInherit(self, inh :str, originPath :Path):
        inhPath = originPath.parent / 'inh.hu'
        if inhPath.exists():
            return inhPath
        inhPath = self.bomaPath / 'plugins' / inh / 'props.hu'
        if inhPath.exists():
            return inhPath
        # TODO: Possibly search other paths for boma files


    def loadProps(self):
        def rec(bagPath):
            print (f"{ansi.dk_white_fg}Loading props: {ansi.p(bagPath, 'cyan')}")
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
        self.props.push(self.propAdds)
        self.props.setDict({'projectPath': self.propsPath,
                            'projectDir': self.propsPath.parent,
                            'bomaDir': Path(__file__).parent,
                            'pluginsDir': Path(__file__).parent / 'plugins',
                            'mainHeaderIncludes': []})


    def loadProvider(self, provider):
        pc = PluginCollection(self.bomaPath / 'plugins')
        if provider not in self.loadedProviders:
            self.loadedProviders[provider] = pc.importProvider(provider)

        return self.loadedProviders[provider]
