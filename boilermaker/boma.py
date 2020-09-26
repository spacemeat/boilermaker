import sys
import os
import os.path
import subprocess
from humon import humon, enums as humonEnums
from . import Cplusplus_1_0 as cpp10


def doShellCommand(cmd):
    print (f"{ansi.lt_black_fg}{cmd}{ansi.all_off}")
    return subprocess.run(cmd, shell=True, check=True).returncode


def reportDecls(decls):
    # Get access to the global namespace
    global_namespace = declarations.get_global_namespace(decls)

    # Get access to the namespace
    ns = global_namespace.namespace("og")

    for decl in ns.declarations:
        print         (f"decl:                {decl}")
        print         (f"attributes:          {decl.attributes}")
        print         (f"decl_string:         {decl.decl_string}")
        print         (f"location:            {decl.location}")
        print         (f"name:                {decl.name}")
        print         (f"parent:              {decl.parent}")
        print         (f"partial_decl_string: {decl.partial_decl_string}")
        print         (f"partial_name:        {decl.partial_name}")
        print         (f"top_parent:          {decl.top_parent}")
        if hasattr(decl, "elaborated_type_specifier"):
            print     (f"elaborated_type_specifier:  {decl.elaborated_type_specifier}")
        if hasattr(decl, "values"):
            for value in decl.values:
                print (f"value:                      {value}")
        if hasattr(decl, "decl_type"):
            print     (f"decl_type:           {decl.decl_type}")
        if hasattr(decl, "is_artificial"):
            print     (f"is_artificial:       {decl.is_artificial}")
        print ("")
    
    #print (dir(ns.declarations[0]))
    #print (dir(ns.declarations[4]))


class Config:
    def __init__(self, version = (1, 0, 0), ppArgs = []):
        self.version = version
        self.preprocessArgs = ppArgs
        self.languages = {}
        

def processTrove_1_0(defEntry, trove, version, ppArgs):
    defEntry['config'] = Config(version, ppArgs)
#    configNode = trove.root['config']
    print (len(trove.root))
    configNode = trove.root['config']
    if configNode:
        argsNode = configNode['args']
        if argsNode:
            defEntry['config'].preprocessArgs.append(argsNode.value)
        langsNode = configNode['languages']
        for i in range(0, len(langsNode)):
            langNode = langsNode[i]
            if str(langNode.key).lower() == "c++":
                defEntry['config'].languages['c++'] = langNode.objectify()
                cpp10.processCplusplus_1_0(defEntry['config'].languages['c++'], langNode)
            else:
                raise ValueError(f"Boilermaker: Unsupported language {langNode}")

    # get types
    typesNode = trove.root['pods']
    
    defEntry['seenTypes'] = {}


    # record lang-agnostic types
    defEntry['pods'] = {}
    defEntry['pods']['data'] = typesNode.objectify()

    # TODO: for each lang, record lang-specific types
    defEntry['seenTypes']['c++'] = []
    defEntry['pods']['c++'] = {}
    cpp10.processCplusplusTypes_1_0(defEntry, typesNode)


def processFile(defs, defsFile, ppArgs):
    trove = humon.Trove.fromFile(defsFile)

    if not trove.getTroveAnnotations(key="app", value="boma"):
        raise ValueError(f"boilermaker: input file {defsFile} is not a 'boma' file.")

    bomaVersion = (1, 0, 0)
    troveVersion = trove.getTroveAnnotations(key='boma-version')
    if troveVersion:
        bomaVersion = str(troveVersion).split(".")
        if len(bomaVersion) != 3:
            raise ValueError(f"boilermaker: input file {defsFile}: boma-version must be a three-component semver.")

    print (f"{defsFile}: version {bomaVersion}")
    defs[defsFile] = {}
    if bomaVersion[0:2] == ['1', '0']:
        processTrove_1_0(defs[defsFile], trove, bomaVersion, ppArgs)


def findPod(defs, nameOfType):
    for defEntry in defs:
        for podKey, podValue in defEntry.pods.items():
            if podKey == nameOfType:
                return (podValue, defsEntry.config)
    
    return (None, None)


def generateCode(defs):
    for defFile, defEntry in defs.items():
        for langKey, langValue in defEntry['config'].languages.items():
            if langKey == "c++":
                # TODO: get c++ lang version from its hu file
                cpp10.generateCplusplusArtifacts(defs, defFile, langValue)


def main():
    defsFiles = []
    troves = []
    ppStart = 0
    for i, arg in enumerate(sys.argv[1:]):
        if arg == "-pp":
            ppstart = i + 1
            break
        else:
            print(f"Gonna read file {arg}")
            defsFiles.append(arg)
    
    ppArgs = []
    if ppStart > 0:
        ppArgs = sys.argv[ppStart:]
    
    defs = {}
    for defsFile in defsFiles:
        print (f"Processing file {defsFile}")
        processFile(defs, defsFile, ppArgs)
    
    print(defs)
    
    generateCode(defs)
