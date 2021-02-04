import os
import pathlib
import subprocess
from humon import humon, enums as humonEnums
from . import ansi


def doShellCommand(cmd):
    #print (f"{ansi.lt_black_fg}{cmd}{ansi.all_off}")
    return subprocess.run(cmd, shell=True, check=True, encoding='utf-8', capture_output=True)


#TODO: Move all os.path things to pathlib things
def getBuiltinDefsPath(defsName):
    bomaSrcDir = os.path.dirname(__file__)
    if defsName == 'boilermaker':
        return os.path.join(bomaSrcDir, 'default.hu')
    elif defsName == 'c++':
        return os.path.join(bomaSrcDir, 'cpp', 'default.hu')


#TODO: Move all os.path things to pathlib things
def makeRelativeDir(sourcePath, destinationPath):
    '''sourcePath and destinationPath may include filenames, which are ignored.'''
    sourceDir = os.path.dirname(sourcePath)
    destinationDir = os.path.dirname(destinationPath)
    common = os.path.commonpath([sourceDir, destinationDir])
    relativePath = ''
    while str(sourceDir) != str(common):
        sourceDir = str(pathlib.PurePath(sourceDir).parent)
        relativePath += '../'
    return os.path.join(relativePath, str(pathlib.PurePath(destinationDir).relative_to(common)))

#TODO: Move all os.path things to pathlib things
def makeRelativePath(sourceDir, destinationPath):
    sourceDir = os.path.dirname(sourceDir)
    destinationDir = os.path.dirname(destinationPath)
    common = os.path.commonpath([sourceDir, destinationDir])
    relativePath = ''
    while str(sourceDir) != str(common):
        sourceDir = str(pathlib.PurePath(sourceDir).parent)
        relativePath += '../'
    return os.path.join(relativePath, str(pathlib.PurePath(destinationPath).relative_to(common)))


def getLanguageVersionParts(name):
    tokens = name.split('|')
    language = tokens[0].lower()
    version = ''
    if len(tokens) > 1:
        version = tokens[1].lower()
    return (language, version)


def findPlatformFile(language, platform, filename, defsPath):
    if language == 'c': languages = ['c', 'cFamily']
    elif language == 'c++': languages = ['c++', 'cFamily']
    else: languages = [language]

    # ~/src/project/boma/c/platforms/vulkan/enums.hu
    for language in languages:
        d = os.path.join( defsPath, language, 'platforms', platform, filename )
        if os.path.isfile(d):
            return d

    # ~/src/project/boma/platforms/vulkan/enums.hu
    d = os.path.join( defsPath, 'platforms', platform, filename )
    if os.path.isfile(d):
        return d

    # ~/src/project/boma/vulkan/enums.hu
    d = os.path.join( defsPath, platform, filename )
    if os.path.isfile(d):
        return d

    # ~/src/boma/.venv/boma/lib/python3.8/site-packages/boilermaker/c/platforms/vulkan/enums.hu
    for language in languages:
        d = os.path.join( os.path.dirname(__file__), language, 'platforms', platform, filename )
        if os.path.isfile(d):
            return d

    raise RuntimeError(f'Could not find platform file {language}/{platform}/{filename}.')


def loadHumonFile(defsFile):
    '''Load a humon file and validate the version.'''
    trove = humon.Trove.fromFile(defsFile)

    if not trove.getTroveAnnotations(key="app", value="boma"):
        raise ValueError(f"input file {defsFile} is not a 'boma' file.")

    bomaVersion = (1, 0, 0)
    troveVersion = trove.getTroveAnnotations(key='boma-version')
    if troveVersion:
        bomaVersion = str(troveVersion).split(".")
        if len(bomaVersion) != 3:
            raise ValueError(f"input file {defsFile}: boma-version must be a three-component semver.")

    print (f"{ansi.dk_yellow_fg}Loaded humon file {ansi.lt_yellow_fg}{defsFile}{ansi.dk_yellow_fg}: version: {ansi.lt_yellow_fg}{bomaVersion}{ansi.all_off}")
    return (trove, bomaVersion)


def listify(thing):
    if thing:
        if type(thing) is not list:
            return [thing]
        else:
            return thing
    else:
        return []


def dictify(thing, key):
    if thing:
        if type(thing) is not dict:
            return {key: thing}
        else:
            return thing
    else:
        return {}
