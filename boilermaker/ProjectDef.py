from .loader import loadHumonFile
from .platforms.Cplusplus import CplusplusDef

class ProjectDef:
    def __init__(self, path, platformDefaultDefs):
        '''Make a ProjectDef. platformDefaultDefs should be a dict of str:PlatformDef.'''
        self.path = path
        self.trove, self.version, _ = loadHumonFile(path)
        self.platformDefs = {}
        configNode = self.trove.root['config']
        for platformNode in configNode:
            platformName = platformNode.key
            if platformName == 'c++':
                backup = platformDefaultDefs.get(platformName, None)
                self.platformDefs[platformName] = CplusplusDef(platformNode, path, backup[0])


    def getPlatformValue(self, platformName, nodeAddress):
        if platform in self.platformDefs:
            return self.platformDefs[platformName].getValue(nodeAddress)


    def getOutputPath(self, platformName, fileType = 'header', podName = None):
        val = self.getPlatformValue(platformName, f'outputFiles/{fileType}')
        if val:
            val = str(val).replace('*', podName)
        return val


    def getSetting(self, platformName, key):
        return self.getPlatformValue(platformName, f'settings/{key}')


    def getFeature(self, platformName, key):
        return self.getPlatformValue(platformName, f'features/{key}')


    def getPodsNode(self):
        podsNode = self.trove.getNodeByAddress(f'/pods')
        return podsNode
    

    def preprocess(self):
        for platform in self.platformDefs.values():
            platform.preprocess(self.getPodsNode())
        

    def generateCode(self):
        podsNode = self.getPodsNode()
        for platformName, platform in self.platformDefs.items():
            platform.generateArtifacts()
    