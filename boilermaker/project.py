import re
from . import utilities
from .ansi import Ansi as ansi
from .props import Props, PropertyBag, Scribe
from pathlib import Path
from .plugin import PluginCollection
from .type import BomaType
from .enums import BomaEnumVal, BomaEnum, BomaEnumType

# read ${captured}, when not preceded by a '\'
defArgumentPattern = r'(?<!\\)\$\s*\<\s*([A-Za-z0-9_.]+?)\s*\>'
defArgumentReg = re.compile(defArgumentPattern)

class Run:
    def __init__(self, runBlock, props):
        self.runBlock = runBlock
        self.props = props


class Build:
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


    def makeBomaEnum(self, typeBlock, isFlags, isScoped, include):
        vals = []
        if type(typeBlock['values']) is list:
            vals = typeBlock['values']

        bomaVals = []
        nextAutoVal = 0
        seenNums = set()
        seenVals = dict()

        if isFlags == False:
            name = ''
            num = -1

            for val in vals:
                # val is a string; just record the name with an increasing numeric value
                if type(val) is str:
                    name = val
                    num = nextAutoVal
                    ev = BomaEnumVal(name, num, '')
                    bomaVals.append(ev)

                # val is a list; we need to set a numeric
                elif type(val) is list:
                    name = val[0]
                    if type(val[1]) is int:
                        num = val[1]
                    elif type(val[1]) is str:
                        if val[1] in seenVals:
                            num = seenVals[val[1]]
                        else:
                            raise RuntimeError(f"Invalid enum value '{val[1]}' in {self.name}")
                    else:
                        raise RuntimeError(f"malformed enum vals in {self.name}")

                    ev = BomaEnumVal(name, num, '')
                    bomaVals.append(ev)

                seenNums.add(num)
                seenVals[name] = num
                nextAutoVal = num + 1

        else:
            name = ''
            num = -1
            nextFlagVal = 1

            for val in vals:
                # val is a string; just record the name with an increasing numeric value
                if type(val) is str:
                    name = val
                    num = nextFlagVal
                    nextFlagVal *= 2
                    ev = BomaEnumVal(name, num, '')
                    bomaVals.append(ev)

                # val is a list; we need to set a numeric
                elif type(val) is list:
                    name = val[0]
                    if type(val[1]) is int:
                        num = val[1]
                        nextFlagVal = num * 2
                    elif type(val[1]) is str:
                        if val[1] in seenVals:
                            num = seenVals[val[1]]
                        else:
                            raise RuntimeError(f"Invalid enum value '{val[1]}' in {self.name}")
                    elif type(val[1]) is list:
                        flags = val[1]
                        num = 0
                        for flag in flags:
                            if type(flag) is int:
                                num += flag
                            elif type(flag) is str:
                                if flag in seenVals:
                                    num += seenVals[flag]
                                else:
                                    raise RuntimeError(f"Invalid enum flag value '{flag}' in {self.name}")
                    else:
                        raise RuntimeError(f"malformed enum vals in {self.name}")

                    ev = BomaEnumVal(name, num, '')
                    bomaVals.append(ev)

                seenNums.add(num)
                seenVals[name] = num
                nextAutoVal = num + 1

        bomEnum = BomaEnum(typeBlock['name'], bomaVals, '', include, None, False, isFlags, isScoped)
        return bomEnum


    def loadProps(self):
        enums = {}
        types = {}
        runs = {}
        anchors = {}
        builds = {}
        def rec(bagPath, bagg):
            print (f"{ansi.dk_white_fg}Loading props: {ansi.p(bagPath, 'cyan')}")
            trove, defsFileVersion = utilities.loadHumonFile(bagPath)
            propsDict = trove.root.objectify()
            if type(propsDict) is not dict:
                raise RuntimeError(f'Malformed boma props file')

            def recrec(propsDict, bagName, bag):
                bag.setDict(propsDict)
                bag.setProp('name', bagName)
                bag.setProp('propsFilePath', bagPath)

                if 'types' in propsDict:
                    for typeName, typeBlock in propsDict['types'].items():
                        typeBlock = {'name': typeName, 'members': typeBlock}
                        newBag = PropertyBag({'name': typeName})
                        newBag.inherit(bag)
                        props = Props(newBag)
                        props.push({**{'name': 'commandLine'}, **self.propAdds})
                        types[typeName] = BomaType(typeBlock, props)

                if 'enums' in propsDict:
                    for typeName, typeBlock in propsDict['enums'].items():
                        if type(typeBlock) is list:
                            typeBlock = {'name': typeName, 'values': typeBlock}
                        newBag = PropertyBag({'name': typeName})
                        newBag.inherit(bag)
                        props = Props(newBag)
                        props.push({**{'name': 'commandLine'}, **self.propAdds})
                        s = Scribe(props)
                        isFlags = s.getXProp('enumFlags')
                        isScoped = s.getXProp('enumIsScoped')
                        include = bagPath
                        enums[typeName] = BomaEnumType(
                            self.makeBomaEnum(
                                typeBlock, isFlags, isScoped,
                                [str(include)]),
                            props)

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
                        props.push({**{'name': 'commandLine'}, **self.propAdds})
                        runs[name] = Run(typeBlock, props)

                if 'buildType' in propsDict:
                    newBag = PropertyBag()
                    newBag.inherit(bag)
                    props = Props(newBag)
                    name = Scribe(props).getXProp('groupName')
                    newBag.setDict({'name': name})
                    props.push({**{'name': 'commandLine'}, **self.propAdds})
                    builds[name] = Build(propsDict, props)

                if 'anchor' in propsDict:
                    anchs = propsDict['anchor']
                    if type(anchs) is not list:
                        anchs = [anchs]
                    for anch in anchs:
                        #newBag = PropertyBag({'name': anch})
                        #newBag.inherit(bag)
                        #props = Props(newBag)
                        props = Props(bag)
                        #props.push({**{'name': 'commandLine'}, **self.propAdds})
                        anchors[anch] = props

                for k, v in propsDict.items():
                    if k.startswith('--'):
                        groupName = k[2:]
                        parent = bag.props.get("groupName", None)
                        if parent:
                            groupName = f'{parent}.{groupName}'

                        newBag = PropertyBag({'name': k,
                                              'groupName': f'{groupName}'})
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

            recrec(propsDict, bagPath.stem, bagg)

        projectBag = PropertyBag({})
        rec(self.propsPath, projectBag)

        # Retarget the main project Props if there's an anchor for that.
        if 'project' in anchors:
            projectBag = anchors['project'].props
            self.propsPath = projectBag.getProp('propsFilePath')

        self.props = Props(projectBag)
        self.props.push({**{'name': 'commandLine'}, **self.propAdds})
        self.props.push({'projectPath': self.propsPath,
                         'projectDir': self.propsPath.parent,
                         'bomaDir': Path(__file__).parent,
                         'pluginsDir': Path(__file__).parent / 'plugins',
                         'mainHeaderIncludes': [],
                         'bomaTypes': types,
                         'bomaEnums': enums,
                         'bomaRuns': runs,
                         'anchors': anchors,
                         'builds': builds})
        #breakpoint()


    def loadProvider(self, provider):
        pc = PluginCollection(self.bomaPath / 'plugins')
        if provider not in self.loadedProviders:
            self.loadedProviders[provider] = pc.importProvider(provider)

        return self.loadedProviders[provider]
