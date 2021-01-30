import os.path
from humon import humon, enums as humonEnums
from .loader import loadHumonFile

class PlatformDef:
    def __init__(self, platformName, project, node, defPath, backupDef=None, podsNode=None):
        '''Make a PlatformDef. Generally should be a base class for a specific platform.'''
        self.platformName = platformName
        self.project = project
        self.node = node
        self.defPath = defPath
        self.backupDef = backupDef
        self.podsNode = podsNode
    

    def loadDefaultPlatformDefs(self, platformInit):
        scriptDir = f'{os.path.dirname(os.path.realpath(__file__))}/platforms'
        for huPath in [f'{scriptDir}/{f}' for f in os.listdir(scriptDir) if os.path.isfile(f'{scriptDir}/{f}') and f.endswith('.hu')]:
            trove, version, platformName = loadHumonFile(huPath)
            #if platformName == 'c++':
            defaultDefs[platformName] = (platformInit(self.platformName, self.project, trove.root, huPath), trove, version)
            #else:
            #    raise RuntimeError(f"Unsupported platform '{platformName}'")

        print(f'{ansi.dk_blue_fg}Default defs: {ansi.lt_blue_fg}{defaultDefs}{ansi.all_off}')


    @property
    def project(self):
        return self.project
    

    def getValue(self, nodeAddress):
        backupObj = None
        if self.backupDef:
            backupObj = self.backupDef.getValue(nodeAddress)            

        node = self.node.getNodeByAddress(nodeAddress)
        if node:
            selfObj = node.objectify()
            if backupObj == None:
                return selfObj
            elif isinstance(selfObj, str):
                return selfObj
            elif isinstance(selfObj, list) and isinstance(backupObj, list):
                return [*backupObj, *selfObj]
            elif isinstance(selfObj, dict) and isinstance(backupObj, dict):
                return {**backupObj, **selfObj}
            else:
                raise RuntimeError(f"PlatformDef's value at '{nodeAddress}' has different type than its backup.")
        else:
            return backupObj

    
    def getOutputPath(self, fileType = 'header', podName = None):
        val = self.getValue(f'outputPaths/{fileType}')
        if val:
            val = str(val)
            if podName:
                val = val.replace('*', podName)
        return os.path.join(os.path.dirname(self.defPath), val)


    def getSetting(self, key):
        return self.getValue(f'settings/{key}')


    def getFeature(self, key):
        return self.getValue(f'features/{key}')


    def getModifiers(self, key):
        allMods = self.getValue(f'modifiers/*') or {}
        keyMods = self.getValue(f'modifiers/{key}') or {}
        return {**allMods, **keyMods}


    def getIndent(self):
        indent = self.getSetting('indent')
        if not indent:
            return '    '
        if 'type' in indent:
            if indent['type'].lower() == 'space':
                num = 4
                if 'num' in indent:
                    num = int(indent['num'])
                return ' ' * int(indent['num'])
            elif indent['type'].lower() == 'tab':
                return '\t'


    def getPods(self):
        return self.getValue(f'pods')


    def getPodNode(self, podName):
        '''Return the platform-agnostic type tree.'''
        return self.podsNode[podName]
