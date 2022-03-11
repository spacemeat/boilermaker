import pkgutil
import os
import inspect
from pathlib import Path
from importlib import import_module
from pydoc import ispackage

class Provider:
    def start(self, props):
        pass

    def doOp(self, op, props):
        pass

    def stop(self):
        pass


class PluginCollection:
    def __init__(self, pluginsPath):
        self.pluginsPath = Path(pluginsPath)


    def locateProps(self, pluginName, propsName):
        pluginPath = self.pluginsPath / pluginName
        if not pluginPath.exists:
            raise RuntimeError(f'Unable to locate plugin {pluginPath}')
        propsPath = pluginPath / (propsName + '.hu')
        return propsPath if propsPath.exists else None


    def importProvider(self, providerName):
        providerModule = import_module(f'.plugins.{providerName}', 'boilermaker')
        classMembers = inspect.getmembers(providerModule, inspect.isclass)
        for (_, providerClass) in classMembers:
            if issubclass(providerClass, Provider) and (providerClass is not Provider):
                provider = providerClass()
                return provider
        return None


    def locateScribe(self, pluginName, scribeName):
        pluginPath = self.pluginsPath / pluginName
        if not pluginPath.exists:
            raise RuntimeError(f'Unable to locate plugin {pluginPath}')
        scribePath = pluginPath / (scribeName + '.scribe')
        return scribePath if scribePath.exists else None
