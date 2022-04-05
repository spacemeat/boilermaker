from itertools import accumulate
from pathlib import Path
from ...plugin import Provider, PluginCollection
from ...props import Scribe
from ...ansi import Ansi as a
import subprocess
import os


def ensureDirExists(dir :Path, clearExisting :bool):
    if not dir.is_dir():
        dir.mkdir(parents=True, exist_ok=True)
    if clearExisting:
        for f in os.scandir(dir):
            os.remove(f.path)


class Source:
    def __init__(self, srcPath):
        self.srcPath = Path(srcPath)  # TODO: Explore multiple source files
        self.deps = []
        self.errors = []
        self.buildErrors = ''

    def setWasNotFOund(self):
        self.errors.append('wasNotFound')

    def setCouldNotGetDeps(self):
        self.errors.append('couldNotGetDeps')

    def setMissingDep(self, dep):
        self.errors.append(f'missingDep: ({str(dep)})')

    def setDidNotCompile(self):
        self.errors.append('didNotCompile')


class Dependency:
    def __init__(self, path):
        self.path = Path(path)
        self.errors = []

    def __str__(self):
        return f'{str(self.path)}{";".join([f" {e}" for e in self.errors])}'

    def checkForExistence(self):
        if not self.path.is_file():
            self.errors.append('missingDep')


class ConstructProvider(Provider):
    def start(self, runDefs, props):
        print (f'starting ConstructProvider')
        self.runDefs = runDefs
        self.props = props
        self.substepColor_dk = a.dk_blue_fg
        self.substepColor_lt = a.lt_blue_fg
        self.substepFileColor = 'cyan'
        self.warnColor_dk = a.dk_yellow_fg
        self.warnColor_lt = a.lt_yellow_fg
        self.errorColor_dk = a.dk_red_fg
        self.errorColor_lt = a.lt_red_fg


    def do(self, op, seq):
        print (f'ConstructProvider doing op {op} at sequence {seq}')
        if op == 'buildPoject':
            self.buildPoject()


    def stop(self):
        print (f'stopping ConstructProvider')


    def runShellCommand(self, command, captureStdOut=True, captureStdError=True, combineStdOutAndError=False):
        print (f'{a.lt_black_fg}{command}{a.all_off}')
        stdout = subprocess.DEVNULL
        stderr = subprocess.DEVNULL
        if captureStdOut or combineStdOutAndError:
            stdout = subprocess.PIPE
        if captureStdError and not combineStdOutAndError:
            stderr = subprocess.PIPE
        elif captureStdError and combineStdOutAndError:
            stderr = subprocess.STDOUT
        comp_proc = subprocess.run(command, shell=True, stdout=stdout, stderr=stderr)

        if comp_proc.returncode != 0:
            print (f'{a.dk_red_fg}Command failed with code {a.lt_red_fg}{comp_proc.returncode}{a.dk_red_fg}.{a.all_off}')
            print (f'{a.dk_red_fg}stderror: {a.lt_red_fg}{comp_proc.stderr.decode("utf-8")}{a.dk_red_fg}{a.all_off}\n')

        if captureStdOut and captureStdError and not combineStdOutAndError:
            return (comp_proc.returncode, comp_proc.stdout.decode('utf-8'),
                    comp_proc.stderr.decode('utf-8'))
        if captureStdOut and not captureStdError:
            return (comp_proc.returncode, comp_proc.stdout.decode('utf-8'))
        if not captureStdOut and captureStdError:
            return (comp_proc.returncode, comp_proc.stderr.decode('utf-8'))

        return comp_proc.returncode


    def buildPoject(self):
        self.props.push()

        self.errors = []
        self.buildErrors = ''

        s = Scribe(self.props)
        clearTempDir = s.getXProp('clearTempDir')
        includeDirses = s.getXPropAll('includeDirs')
        includeDirs = set()
        for ids in includeDirses:
            for id in ids:
                includeDirs.add(id)
        includeDirs = list(includeDirs)

        self.generateAllSources()
        self.generateSourceOutputs()

        outputExePath = Path(s.getXProp('outputExePath'))
        ensureDirExists(outputExePath.parent, False)

        outputExeFileTime = 0
        if outputExePath.is_file():
            outputExeFileTime = outputExePath.stat().st_mtime

        # empty the build target dirs
        tempOutputDir = Path(s.getXProp('tempOutputDir'))
        ensureDirExists(tempOutputDir, clearTempDir)

        forceRebuild = s.getXProp('forceRebuild')

        #   create the sequence of commands:
        #   if  wholeProject:
        #       deps = getDependenciesForAllSources()
        #       if newest of deps is newer than outputFile:
        #           makeBuildOutputFileScript()

        if s.getXProp('wholeProject'):
            self.getDependencies(self.sources)
            newestTime = max([source.srcPath.stat().st_mtime for source in self.sources])
            print(f'\n{self.substepColor_dk}Building {a.p(outputExePath, self.substepFileColor)}{self.substepColor_dk} from all sources')

            for source in self.sources:
                if len(source.errors) > 0:
                    print(f'{a.dk_red_fg}{a.p(source.srcPath, "red")}{a.dk_red_fg} has errors')

            if self.hasErrors() == False:
                if newestTime > outputExeFileTime or forceRebuild:
                    cmd = self.makeBuildAllSourcesScript()
                    ret, _, err = self.runShellCommand(cmd)
                    print(f'  {self.substepColor_dk}returned: {a.lt_green_fg if ret == 0 else a.lt_red_fg}{ret}{a.all_off}')
                    if ret != 0:
                        self.errors.append('didNotCompileOrLink')
                    self.buildErrors += err
                else:
                    print(f'  {self.substepColor_lt}{outputExePath}{self.substepColor_dk} already up to date.{a.all_off}')

        #   else:
        #       for src in sources:
        #           deps = getDependenciesForSource(src)
        #           if (deps is newer than .o or
        #               src is newer than .o):
        #               makeBuildObjectScript()
        #       for obj in objects:
        #           if obj is newer than outputFile:
        #               makeLinkObjectsScript()
        else:
            objectPaths = []
            for source in self.sources:
                outputObjectPath = source.objPath
                objectPaths.append(outputObjectPath)
                outputObjectFileTime = 0
                if outputObjectPath.is_file():
                    outputObjectFileTime = outputObjectPath.stat().st_mtime

                self.getDependencies(source)
                newestTime = max([dep.path.stat().st_mtime for dep in source.deps], default=0)
                print(f'\n{self.substepColor_dk}Building {a.p(outputObjectPath, self.substepFileColor)}{self.substepColor_dk}\n    from {a.p(source.srcPath, self.substepFileColor)}{self.substepColor_dk}.{a.all_off}')

                if len(source.errors) == 0:
                    if newestTime > outputObjectFileTime or forceRebuild:
                        cmd = self.makeBuildOneSourceScript(source)
                        ret, _, err = self.runShellCommand(cmd)
                        print(f'  {self.substepColor_dk}returned: {a.lt_green_fg if ret == 0 else a.lt_red_fg}{ret}{a.all_off}')
                        if ret != 0:
                            source.setDidNotCompile()
                        source.buildErrors += err
                    else:
                        print(f'{self.substepColor_lt}Skip it. {a.p(outputObjectPath, self.substepFileColor)}{self.substepColor_dk} already up to date.{a.all_off}')
                else:
                    print(f'{self.substepColor_lt}Skip it. {a.dk_red_fg}{a.p(source.srcPath, "red")}{a.dk_red_fg} has errors.{a.all_off}')

            print(f'\n{self.substepColor_dk}Building {a.p(outputExePath, self.substepFileColor)}{self.substepColor_dk} from {self.substepColor_lt}{len(self.sources)}{self.substepColor_dk} objects.{a.all_off}')
            if self.hasErrors() == False:
                if len(source.errors) == 0:
                    newestTime = max([source.objPath.stat().st_mtime for source in self.sources])
                    if newestTime > outputExeFileTime or forceRebuild:
                        cmd = self.makeLinkAllObjectsScript()
                        ret, _, err = self.runShellCommand(cmd)
                        print(f'  {self.substepColor_dk}returned: {a.lt_green_fg if ret == 0 else a.lt_red_fg}{ret}{a.all_off}')
                        if ret != 0:
                            self.errors.append('didNotLink')
                        self.buildErrors += err
                    else:
                        print(f'{self.substepColor_lt}Skip it. {a.p(outputExePath, self.substepFileColor)}{self.substepColor_dk} already up to date.{a.all_off}')
                else:
                    print(f'{self.substepColor_lt}Skip it. {a.dk_red_fg}{a.p(source.srcPath, "red")}{a.dk_red_fg} has errors.{a.all_off}')
            else:
                print(f'{self.substepColor_lt}Skip it. {a.dk_red_fg}{a.p(outputExePath, "red")}{a.dk_red_fg} has errors.{a.all_off}')

        if self.hasErrors():
            print (f'\nProject has {a.lt_red_fg}errors{a.all_off}:')
            for source in self.sources:
                for error in source.errors:
                    if error == 'wasNotFound':
                        print(f'{a.p(source.srcPath, "red")}{a.dk_red_fg}: source file not found.{a.all_off}')
                    if error == 'missingDep':
                        print(f'{a.p(source.srcPath, "red")}{a.dk_red_fg}: missing dependencies.{a.all_off}')
                    if error == 'didNotCompile':
                        print(f'{a.p(source.srcPath, "red")}{a.dk_red_fg}: did not compile.{a.all_off}')
            for error in self.errors:
                if error == 'didNotCompileOrLink':
                    print(f'{a.p(source.srcPath, "red")}{a.dk_red_fg}: did not build.{a.all_off}')
                if error == 'didNotLink':
                    print(f'{a.p(source.srcPath, "red")}{a.dk_red_fg}: did not link.{a.all_off}')


    def hasErrors(self):
        return any(map(lambda src: len(src.errors) > 0, self.sources)) or len(self.errors) > 0


    def generateAllSources(self):
        s = Scribe(self.props)
        self.sources = list()
        srcses = s.getXPropAll('sources')
        for srcs in srcses:
            for src in srcs:
                # could be multiiple files (*.cpp)
                gsrc = list(Path(s.getXProp('projectDir')).glob(src))
                if len(gsrc) == 0:
                    # a single file passed to glob will return [] if not found
                    # TODO: Be more exact (could be in quotes, etc)
                    if '*' not in src and '?' not in src:
                        # we didn't find a file but we should
                        srcPath = s.getXProp('projectDir') / src
                        srcObj = Source(srcPath)
                        self.sources.append(srcObj)
                        srcObj.setWasNotFOund()

                for sr in gsrc:
                    sr = s.getXProp('projectDir') / sr
                    srcObj = Source(sr)
                    self.sources.append(srcObj)
                    if not sr.is_file():
                        srcObj.setWasNotFOund()

        self.props.push({'sources': self.sources})


    def generateSourceOutputs(self):
        s = Scribe(self.props)
        for source in self.sources:
            self.props.push({'source': source})
            source.objPath = Path(s.getXProp('outputObjectPath'))
            self.props.pop()


    def getDependencies(self, sources):
        if type(sources) is not list:
            sources = [sources]

        for source in sources:
            # return a list of Path objects, for all preprocessor dependencies of all sources.
            cmd = self.computeCommand('getDependencies', source=source)
            print(f'\n{self.substepColor_dk}Getting dependencies for {a.p(source.srcPath, self.substepFileColor)}{self.substepColor_dk}.{a.all_off}')
            if len(source.errors) == 0:
                ret, out, err = self.runShellCommand(cmd)
                print(f'  {self.substepColor_dk}returned: {a.lt_green_fg if ret == 0 else a.lt_red_fg}{ret}{a.all_off}')
                if ret != 0:
                    source.setCouldNotGetDeps()

                out = out.replace('\\\n', '')

                deps = set()
                for line in out.splitlines():
                    paths = line.split(' ')
                    for path in paths[1:]:
                        deps.add(path)
                source.deps = [Dependency(Path(path)) for path in deps]
                for dep in source.deps:
                    dep.checkForExistence()
            else:
                print(f'{self.substepColor_lt}Skip it. {a.dk_red_fg}{a.p(source.srcPath, "red")}{a.dk_red_fg} has errors.{a.all_off}')


    def makeBuildAllSourcesScript(self):
        return self.computeCommand('compileAndLinkFiles', sources=self.sources)


    def makeBuildOneSourceScript(self, source):
        return self.computeCommand('compileFile', source=source)


    def makeLinkAllObjectsScript(self):
        return self.computeCommand('linkObjects', sources=self.sources)


    def computeCommand(self, operation, **kwargs):
        def getAllFromListOfMaybeList(listOfMaybes, unique=True):
            accrued = []
            accruedUnique = set()
            for maybe in listOfMaybes:
                if type(maybe) is list:
                    for elem in maybe:
                        if unique:
                            accruedUnique.add(elem)
                        else:
                            accrued.append(elem)
                else:
                    if unique:
                        accruedUnique.add(maybe)
                    else:
                        accrued.append(maybe)
            if unique:
                return accruedUnique
            else:
                return accrued


        s = Scribe(self.props)
        projectDir = Path(s.getXProp('projectDir'))
        buildKind = s.getXProp('buildKind')
        tools = s.getXProp('tools')
        language = s.getXProp('language')
        languageStandard = s.getXProp('languageStandard')
        includeDirs = getAllFromListOfMaybeList(s.getXPropAll('includeDirs'))
        includeDirs = [f'-I{projectDir / id}' for id in includeDirs]
        libraryDirs = getAllFromListOfMaybeList(s.getXPropAll('libDirs'))
        libraryDirs = [f'-L{projectDir / ld}' for ld in libraryDirs]
        libs = getAllFromListOfMaybeList(s.getXPropAll('libs'))
        libs = [f'-l{l}' for l in libs]
        # TODO: Package stuff here too
        outputExePath = s.getXProp('outputExePath')
        opts = ['-O0', '-g']
        if buildKind != 'debug':
            opts = ['-O3', '-s']
        warnflags = getAllFromListOfMaybeList(s.getXPropAll('warnS'))
        warnflags = [f'-{w}' for w in warnflags]
        cOpts = getAllFromListOfMaybeList(s.getXPropAll('compileOptions'))
        cOpts = [f'-{o}' for o in cOpts]
        lOpts = getAllFromListOfMaybeList(s.getXPropAll('linkOptions'))
        lOpts = [f'-{o}' for o in lOpts]
        clOpts = getAllFromListOfMaybeList(s.getXPropAll('compileAndLinkOptions'))
        clOpts = [f'-{o}' for o in clOpts]

        if tools == 'gnu':
            compilerTool = ''
            if language == 'c':
                compilerTool = 'gcc'
            elif language == 'c++':
                compilerTool = 'g++'
            else:
                raise RuntimeError(f'Unsupported language \'{language}\' for tools \'{tools}\' / tool kind \'{operation}\'.')

            if operation == 'getDependencies':
                source = kwargs.get('source')
                return f'{compilerTool} -std={languageStandard} -E -M {" ".join(includeDirs)} {str(source.srcPath)} {" ".join(clOpts)} {" ".join(cOpts)} {" ".join(lOpts)}'

            elif operation == 'compileFile':
                source = kwargs.get('source')
                dotoPath = source.objPath
                return f'{compilerTool} -std={languageStandard} {" ".join(warnflags)} -c {" ".join(opts)} {" ".join(includeDirs)} {str(source.srcPath)} -o{dotoPath} {" ".join(clOpts)} {" ".join(cOpts)}'

            elif operation == 'compileAndLinkFiles':
                return f'{compilerTool} -std={languageStandard} {" ".join(warnflags)} {" ".join(opts)} {" ".join(includeDirs)} {" ".join([str(s.srcPath) for s in kwargs.get("sources", [])])} -o{outputExePath} {" ".join(libraryDirs)} {" ".join(libs)} {" ".join(clOpts)} {" ".join(cOpts)} {" ".join(lOpts)}'

            elif operation == 'linkObjects':
                return f'{compilerTool} {" ".join(warnflags)} {" ".join(opts)} {" ".join([str(s.objPath) for s in kwargs.get("sources", [])])} -o{outputExePath} {" ".join(libraryDirs)} {" ".join(libs)} {" ".join(clOpts)} {" ".join(lOpts)}'

        elif tools == 'llvm':
            raise RuntimeError(f'Unsupported tools \'{tools}\'. Patience.')

        elif tools == 'vs':
            raise RuntimeError(f'Unsupported tools \'{tools}\'. Patience.')

        else:
            raise RuntimeError(f'Unsupported tools \'{tools}\'.')

