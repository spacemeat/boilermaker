import re
from . import utilities
from .ansi import Ansi as ansi
from .props import Props, PropertyBag, Scribe
from pathlib import Path
from .plugin import PluginCollection
from .type import BomaType
from .enums import EnumType

# read ${captured}, when not preceded by a '\'
defArgumentPattern = r'(?<!\\)\$\s*\<\s*([A-Za-z0-9_.]+?)\s*\>'
defArgumentReg = re.compile(defArgumentPattern)

class Run:
    def __init__(self, runBlock, props):
        self.runBlock = runBlock
        self.props = props


class Project:
    def __init__(self, propsPath, propAdds):
        if type(propsPath) is not Path:
            propsPath = Path(propsPath)
        self.propsPath = propsPath
        self.bomaPath = Path(__file__).parent
        self.loadedProviders = {}
        self.propAdds = propAdds

    def run(self):
        try:
            # Build the property tree from .hu files.
            self.loadProps()

            # Collect all the run operations.
            ops = []
            for runObject in self.props.getProp('bomaRuns').values():
                s = Scribe(self.props)      # NOTE: using self.props, not runObject.props which is well up the parentage
                runDefs = s.parseStructure(runObject.runBlock)
                for op, seq in runDefs['ops'].items():
                    ops.append({
                        'provider': f'{runDefs["plugin"]}.{runDefs["provider"]}',
                        'runDefs': runDefs,
                        'operation': op,
                        'sequence': seq})

            ops.sort(key=lambda op: op['sequence'])

            seenProvs = set()
            startOrder = []
            for op in ops:
                providerName = op['provider']
                if providerName in seenProvs:
                    continue
                seenProvs.add(providerName)
                provider = self.loadProvider(providerName)
                startOrder.append(provider)
                provider.start(op['runDefs'], self.props) # NOTE: using self.props, not runObject.props which is well up the parentage

            for op in ops:
                providerName = op['provider']
                provider = self.loadProvider(providerName)
                provider.do(op['operation'], op['sequence'])

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
        enums = {}
        types = {}
        runs = {}
        anchors = {}
        def rec(bagPath, bag):
            print (f"{ansi.dk_white_fg}Loading props: {ansi.p(bagPath, 'cyan')}")
            trove, defsFileVersion = utilities.loadHumonFile(bagPath)
            propsDict = trove.root.objectify()
            if type(propsDict) is not dict:
                raise RuntimeError(f'Malformed boma props file')

            def recrec(propsDict, bagName, bag):
                #bag = PropertyBag({})
                print (f'bagName: {bagName}')
                bag.setDict(propsDict)
                bag.setProp('name', bagName)
                bag.propsFilePath = bagPath

                if 'types' in propsDict:
                    for typeName, typeBlock in propsDict['types'].items():
                        typeBlock = {'name': typeName, 'members': typeBlock}
                        newBag = PropertyBag({'name': typeName})
                        newBag.inherit(bag)
                        props = Props(newBag)
                        props.push(self.propAdds)
                        types[typeName] = BomaType(typeBlock, props)

                if 'enums' in propsDict:
                    for typeName, typeBlock in propsDict['enums'].items():
                        if type(typeBlock) is list:
                            typeBlock = {'name': typeName, 'values': typeBlock}
                        newBag = PropertyBag({'name': typeName})
                        newBag.inherit(bag)
                        props = Props(newBag)
                        props.push(self.propAdds)
                        enums[typeName] = EnumType(typeBlock, props)

                if 'run' in propsDict:
                    typeBlocks = propsDict['run']
                    if type(typeBlocks) is not list:
                        typeBlocks = [typeBlocks]
                    for typeBlock in typeBlocks:
                        name = typeBlock.get('name', bagPath.stem)
                        typeBlock['name'] = name
                        newBag = PropertyBag({'name': name})
                        newBag.inherit(bag)
                        props = Props(newBag)
                        props.push(self.propAdds)
                        runs[name] = Run(typeBlock, props)

                if 'anchor' in propsDict:
                    anchs = propsDict['anchor']
                    if type(anchs) is not list:
                        anchs = [anchs]
                    for anch in anchs:
                        newBag = PropertyBag({'name': anch})
                        newBag.inherit(bag)
                        props = Props(newBag)
                        props.push(self.propAdds)
                        anchors[anch] = props

                for k, v in propsDict.items():
                    if k.startswith('--'):
                        newBag = PropertyBag({'name': k})
                        newBag.inherit(bag)
                        recrec(v, k[2:], newBag)

                if 'inherit' in propsDict:
                    inhs = propsDict['inherit']
                    if type(inhs) is str:
                        inhs = [inhs]

                    for inh in inhs:
                        newBagPath = self.getPathFromInherit(inh, Path(bagPath))
                        if newBagPath == None:
                            raise RuntimeError(f'Boilermaker file {inh} cannot be opened.')
                        newBag = PropertyBag({})
                        rec(newBagPath, newBag)
                        bag.inherit(newBag)

                return bag

            return recrec(propsDict, bagPath.stem, bag)

        projectBag = PropertyBag({})
        rec(self.propsPath, projectBag)

        # Retarget the main project Props if there's an anchor for that.
        if 'project' in anchors:
            projectBag = anchors['project']
        self.propsPath = projectBag.propsFilePath

        self.props = Props(projectBag)
        self.props.push(self.propAdds)
        self.props.push({'projectPath': self.propsPath,
                         'projectDir': self.propsPath.parent,
                         'bomaDir': Path(__file__).parent,
                         'pluginsDir': Path(__file__).parent / 'plugins',
                         'mainHeaderIncludes': [],
                         'bomaTypes': types,
                         'bomaEnums': enums,
                         'bomaRuns': runs,
                         'anchors': anchors})


    def loadProvider(self, provider):
        pc = PluginCollection(self.bomaPath / 'plugins')
        if provider not in self.loadedProviders:
            self.loadedProviders[provider] = pc.importProvider(provider)

        return self.loadedProviders[provider]
