import os
from pathlib import Path, PurePath
import subprocess
from humon import humon, enums as humonEnums
from .ansi import Ansi as ansi


def doShellCommand(cmd):
    #print (f"{ansi.lt_black_fg}{cmd}{ansi.all_off}")
    return subprocess.run(cmd, shell=True, check=True, encoding='utf-8', capture_output=True)


def loadHumonFile(defsFile):
    '''Load a humon file and validate the version.'''
    trove = humon.Trove.fromFile(str(defsFile))

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
