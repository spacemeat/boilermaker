from humon import humon, enums as humonEnums
from .loader import loadHumonFile

class PlatformDef:
    def __init__(self, node, backupDef=None):
        '''Make a PlatformDef. Generally should be a base class for a specific platform.'''
        self.node = node
        self.backupDef = backupDef
    

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
        return val


    def getSetting(self, key):
        return self.getValue(f'settings/{key}')


    def getFeature(self, key):
        return self.getValue(f'features/{key}')


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


