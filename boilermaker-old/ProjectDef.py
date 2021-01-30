from humon import humon, enums as humonEnums
from .loader import loadHumonFile
from .enums import Enums
from .platforms.Cplusplus import CplusplusDef
#from .platformEnums.Cplusplus import CplusplusEnums

import subprocess

class ProjectDef:
    def __init__(self, path, platformDefaultDefs):
        '''Make a ProjectDef. platformDefaultDefs should be a dict of str:PlatformDef.'''
        self.path = path
        self.trove, self.version, _ = loadHumonFile(path)
        self.enums = Enums()
        defsNode = self.trove.root['defs']
        if defsNode:
            for platformNode in defsNode:
                platformName = platformNode.key
                if platformName == 'c++':
                    platform = CplusplusDef(self, platformNode, path, None, None)
                    platformSourceNodes = [pd for pd in platformNode['sources']]
                    #scanner = CplusplusEnums()
                    for platformSourceNode in platformSourceNodes:
                        if platformSourceNode.kind == humonEnums.NodeKind.DICT:
                            sourceFile = platformSourceNode['file'].value
                            isSystemInclude = platformSourceNode['system'].value == 'true'
                        else:
                            sourceFile = platformSourceNode.value
                            isSystemInclude = False
                        #scanner.processHeader(sourceFile, isSystemInclude, sourceFile.endswith('.h'), self.enums)
                        platform.processHeader(sourceFile, isSystemInclude, sourceFile.endswith('.h'), self.enums)
                    for enumNode in platformNode['attributes']:
                        for attribNode in enumNode:
                            enum = self.enums.getEnum(enumNode.key, platformName)
                            if enum:
                                enum.setAttrib(attribNode.value)
                            else:
                                print (f'Enum attrib node couldn\'t get enum: {enumNode.key}')
        
        self.platformDefs = {}
        configNode = self.trove.root['platforms']
        for platformNode in configNode:
            platformName = platformNode.key
            if platformName == 'c++':
                backup = platformDefaultDefs.get(platformName, None)
                self.platformDefs[platformName] = CplusplusDef(self, platformNode, path, backup[0], self.getPodsNode())


    def loadPlatformDefaults(self, platformName):
        scriptDir = f'{os.path.dirname(os.path.realpath(__file__))}/platforms'
        for huPath in [f'{scriptDir}/{f}' for f in os.listdir(scriptDir) if os.path.isfile(f'{scriptDir}/{f}') and f.endswith('.hu')]:
            trove, version, platformName = loadHumonFile(huPath)
            if platformName == 'c++':
                self.defaultDefs[platformName] = (CplusplusDef(self.platformName, self.project, trove.root, huPath), trove, version)
            else:
                raise RuntimeError(f"Unsupported platform '{platformName}'")

        print(f'{ansi.dk_blue_fg}Default defs: {ansi.lt_blue_fg}{defaultDefs}{ansi.all_off}')


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
    

    def generateCode(self):
        for platformName, platform in self.platformDefs.items():
            platform.generateArtifacts(self.getPodsNode(), self.enums)


    def generateEnumSuggestions(self):
        for platformName, platform in self.platformDefs.items():
            platform.generateEnumSuggestions(self.enums)
