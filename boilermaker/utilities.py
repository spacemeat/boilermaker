import os
from pathlib import Path
import subprocess
#from humon import humon, enums as humonEnums
import humon as h
#from .ansi import Ansi as ansi

# pylint: disable=invalid-name
# pylint: disable=missing-function-docstring missing-class-docstring
# pylint: disable=too-many-nested-blocks too-few-public-methods too-many-statements too-many-branches
# pylint: disable=too-many-locals

def doShellCommand(cmd):
    #print (f"{ansi.lt_black_fg}{cmd}{ansi.all_off}")
    return subprocess.run(cmd, shell=True, check=True, encoding='utf-8', capture_output=True)


def getRelativePath(fromDir, toPath):
    fromDir = Path(fromDir)
    toPath = Path(toPath)
    fromDirParts = fromDir.parts
    toPathParts = toPath.parts
    div = 0
    for cur in range(0, min(len(fromDirParts), len(toPathParts))):
        if fromDirParts[cur] == toPathParts[cur]:
            div = cur + 1
        else:
            break
    relPath = '../' * (len(fromDirParts) - div)
    relPath += '/'.join(toPathParts[div:])
    return relPath


def loadHumonFile(defsFile):
    '''Load a humon file and validate the version.'''
    trove = h.from_file(str(defsFile))

    metatags = trove.metatags
    if metatags.get('app') != 'boma':
    #if not trove.getTroveAnnotations(key="app", value="boma"):
        raise ValueError(f"input file {defsFile} is not a 'boma' file.")

    bomaVersion = (1, 0, 0)
    troveVersion = metatags['boma-version']
    if troveVersion:
        bomaVersion = str(troveVersion).split(".")
        if len(bomaVersion) != 3:
            raise ValueError(f"input file {defsFile}: "
                "boma-version must be a three-component semver.")

    return (trove, bomaVersion)


def objectify_node(node: h.Node):
    ''' Turns a humon Node into a dict. '''
    if node.kind == h.NodeKind.DICT:
        o = {}
        for chi in range(0, node.num_children):
            ch = node[chi]
            o[ch.key] = objectify_node(ch)
        return o
    if node.kind == h.NodeKind.LIST:
        o = []
        for chi in range(0, node.num_children):
            ch = node[chi]
            o.append(objectify_node(ch))
        return o
    if node.kind == h.NodeKind.VALUE:
        return node.value
        try:
            return int(node.value)
        except ValueError:
            try:
                return float(node.value)
            except ValueError:
                return node.value
    else:
        raise ValueError('Null node cannot be objectified.')
