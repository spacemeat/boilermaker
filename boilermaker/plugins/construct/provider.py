from itertools import accumulate
from pathlib import Path
from ...plugin import Provider, PluginCollection
from ...props import Scribe
from ...ansi import Ansi as a
import subprocess
import os
import operator


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


class Lib:
    def __init__(self, name, path):
        self.name = name
        self.path = Path(path) if path else None
        self.errors = []

    def setWasNotFOund(self):
        self.errors.append('wasNotFound')


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


    def runShellCommands(self, commands, captureStdOut=True, captureStdError=True, combineStdOutAndError=False):
        returns = []
        if type(commands) is not list:
            commands = [commands]
        for command in commands:
            results = self.runShellCommand(command, captureStdOut, captureStdError)
            returns.append(results)
            if type(results) is tuple and results[0] != 0:
                break
            elif results != 0:
                break
        return returns


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
        s = Scribe(self.props)

        builds = self.props.getProp('builds', {})
        # builds has keys like 'assetDb.lib', 'assetDb.test', ...
        targets = s.getXProp('targets', '').split()

        #breakpoint()
        filteredBuilds = []
        if len(targets) == 0:
            filteredBuilds = builds.values()

        # each target can be like '*', 'assetDb.*', ...
        for target in targets:
            targetParts = target.split('.')
            for buildName, build in builds.items():
                bnParts = buildName.split('.')
                for i, tp in enumerate(targetParts):
                    if tp != bnParts[i]:
                        break
                else:
                    filteredBuilds.append(build)

        for build in filteredBuilds:
            self.reset()
            buildType = Scribe(build.props).getXProp('buildType')
            if buildType == 'boilermaker':
                self.buildBoilermaker(build)
            elif buildType == 'staticLib':
                self.buildStaticLib(build)
            elif buildType == 'exe':
                self.buildExe(build)
            elif buildType == 'staticArchive':
                self.buildStaticArchive(build)
            self.reportErrors(build)


    def reset(self):
        self.errors = []
        self.buildErrors = ''
        self.sources = list()
        self.libs = list()


    def buildBoilermaker(self, build):
        self.printProjectMark(build)

        # TODO: Check boma file against .boma-post for staleness
        # TODO: Then run boma if we should oughta


    def buildStaticLib(self, build):
        self.printProjectMark(build)

        s = Scribe(build.props)
        clearTempDir = s.getXProp('clearTempDir')

        self.generateSources(build)
        self.generateSourceOutputs(build)
        self.generateLibSources(build)

        # empty the build target dirs
        tempOutputDir = Path(s.getXProp('tempOutputDir'))
        ensureDirExists(tempOutputDir, clearTempDir)

        if s.getXProp('wholeProject'):
            self._compileMultipleSources(build, False)
            self._archiveLibrary(build)
        else:
            for source in self.sources:
                self._compileSingleSource(build, source)
            self._archiveLibrary(build)


        #   create the sequence of commands:
        #   if  wholeProject:
        #       deps = getDependenciesForAllSources()
        #       if newest of deps is newer than outputFile:
        #           makeBuildOutputFileScript()
        #   else:
        #       for src in sources:
        #           deps = getDependenciesForSource(src)
        #           if (deps is newer than .o or
        #               src is newer than .o):
        #               makeBuildObjectScript()
        #       for obj in objects:
        #           if obj is newer than outputFile:
        #               makeLinkObjectsScript()

    def buildExe(self, build):
        self.printProjectMark(build)

        s = Scribe(build.props)
        clearTempDir = s.getXProp('clearTempDir')

        self.generateSources(build)
        self.generateSourceOutputs(build)
        self.generateLibSources(build)

        # empty the build target dirs
        tempOutputDir = Path(s.getXProp('tempOutputDir'))
        ensureDirExists(tempOutputDir, clearTempDir)

        if s.getXProp('wholeProject'):
            self._compileMultipleSources(build, True)
            self._linkObjects(build)
        else:
            for source in self.sources:
                self._compileSingleSource(build, source)
            self._linkObjects(build)


    def buildStaticArchive(self, build):
        self.printProjectMark(build)

        s = Scribe(build.props)
        clearTempDir = s.getXProp('clearTempDir')

        self.generateLibSources(build)

        # empty the build target dirs
        tempOutputDir = Path(s.getXProp('tempOutputDir'))
        ensureDirExists(tempOutputDir, clearTempDir)

        self._archiveLibrary(build)


    def printProjectMark(self, build):
        print (f'{a.lt_white_fg}--------------------- {Scribe(build.props).getXProp("targetName")}{a.all_off}')


    def reportErrors(self, build):
        if self.hasErrors():
            s = Scribe(build.props)
            projectPath = s.getXProp('projectPath')

            print (f'\nProject {s.getXProp("projectName")}: "{s.getXProp("targetName")}" has {a.lt_red_fg}errors{a.all_off}:')
            for source in self.sources:
                for error in source.errors:
                    if error == 'wasNotFound':
                        print(f'{a.p(source.srcPath, "red")}{a.dk_red_fg}: source file was not found.{a.all_off}')
                    if error == 'missingDep':
                        print(f'{a.p(source.srcPath, "red")}{a.dk_red_fg}: missing dependencies.{a.all_off}')
                    if error == 'didNotCompile':
                        print(f'{a.p(source.srcPath, "red")}{a.dk_red_fg}: did not compile.{a.all_off}')
            for lib in self.libs:
                for error in lib.errors:
                    if error == 'wasNotFound':
                        print(f'{a.lt_red_fg}{lib.name}{a.dk_red_fg}: library was not found.{a.all_off}')
            for error in self.errors:
                if error == 'didNotCompileOrLink':
                    print(f'{a.p(projectPath, "red")}{a.dk_red_fg}: did not build.{a.all_off}')
                if error == 'didNotLink':
                    print(f'{a.p(projectPath, "red")}{a.dk_red_fg}: did not link.{a.all_off}')


    def _compileSingleSource(self, build, source):
        self.printStepMark('compile single source')

        outputObjectPath = source.objPath
        outputObjectFileTime = 0
        if outputObjectPath.is_file():
            outputObjectFileTime = outputObjectPath.stat().st_mtime

        print(f'{self.substepColor_dk}Building {a.p(outputObjectPath, self.substepFileColor)}{self.substepColor_dk}\n    from {a.p(source.srcPath, self.substepFileColor)}{self.substepColor_dk}.{a.all_off}')

        self.getDependencies(build, source)
        newestTime = max([dep.path.stat().st_mtime for dep in source.deps], default=0)

        if len(source.errors) == 0:
            forceRebuild = Scribe(build.props).getXProp('forceRebuild')
            if newestTime > outputObjectFileTime or forceRebuild:
                cmd = self.computeCommand('compileSourceToObject', build, source=source)
                ret, _, err = self.runShellCommand(cmd, True, True)
                print(f'  {self.substepColor_dk}returned: {a.lt_green_fg if ret == 0 else a.lt_red_fg}{ret}{a.all_off}')
                if ret != 0:
                    source.setDidNotCompile()
                source.buildErrors += err
            else:
                print(f'{self.substepColor_lt}Skip it. {a.p(outputObjectPath, self.substepFileColor)}{self.substepColor_dk} already up to date.{a.all_off}')
        else:
            print(f'{self.substepColor_lt}Skip it. {a.dk_red_fg}{a.p(source.srcPath, "red")}{a.dk_red_fg} has errors.{a.all_off}')


    def _linkObjects(self, build):
        self.printStepMark('link objects')

        s = Scribe(build.props)
        outputPath = Path(s.getXProp('outputPath'))
        ensureDirExists(outputPath.parent, False)

        outputFileTime = 0
        if outputPath.is_file():
            outputFileTime = outputPath.stat().st_mtime

        print(f'{self.substepColor_dk}Building {a.p(outputPath, self.substepFileColor)}{self.substepColor_dk} from {self.substepColor_lt}{len(self.sources)}{self.substepColor_dk} objects.{a.all_off}')

        #breakpoint()
        if self.hasErrors() == False:
            forceRebuild = s.getXProp('forceRebuild')
            objs = []
            if s.getXProp('wholeProject'):
                objs = [Path(s.getXProp('outputProjectObjectPath'))]
            else:
                objs = [source.objPath for source in self.sources]
            newestTime = max([o.stat().st_mtime for o in objs], default=0)
            if newestTime > outputFileTime or forceRebuild:
                cmd = self.computeCommand('linkCompiledObjectsToExe', build, sources=objs)
                ret, _, err = self.runShellCommand(cmd, True, True)
                print(f'  {self.substepColor_dk}returned: {a.lt_green_fg if ret == 0 else a.lt_red_fg}{ret}{a.all_off}')
                if ret != 0:
                    self.errors.append('didNotLink')
                self.buildErrors += err
            else:
                print(f'{self.substepColor_lt}Skip it. {a.p(outputPath, self.substepFileColor)}{self.substepColor_dk} already up to date.{a.all_off}')
        else:
            print(f'{self.substepColor_lt}Skip it. {a.dk_red_fg}{a.p(outputPath, "red")}{a.dk_red_fg} has errors.{a.all_off}')


    def _compileMultipleSources(self, build, buildExecutable):
        self.printStepMark('compile multiple sources')

        s = Scribe(build.props)
        outputPath = Path(s.getXProp('outputLibPath'))
        if buildExecutable:
            outputPath = Path(s.getXProp('outputPath'))
        ensureDirExists(outputPath.parent, False)

        outputExeFileTime = 0
        if outputPath.is_file():
            outputExeFileTime = outputPath.stat().st_mtime

        print(f'{self.substepColor_dk}Building {a.p(outputPath, self.substepFileColor)}{self.substepColor_dk} from all sources')

        self.getDependencies(build, self.sources)
        newestTime = max([source.srcPath.stat().st_mtime for source in self.sources], default=0)

        for source in self.sources:
            if len(source.errors) > 0:
                print(f'{a.dk_red_fg}{a.p(source.srcPath, "red")}{a.dk_red_fg} has errors')

        if self.hasErrors() == False:
            forceRebuild = s.getXProp('forceRebuild')
            if newestTime > outputExeFileTime or forceRebuild:
                cmd = ''
                if buildExecutable:
                    cmd = self.computeCommand('compileManySourcesToExe', build, sources=self.sources)
                else:
                    cmd = self.computeCommand('compileManySourcesToObject', build, sources=self.sources)
                ret, _, err = self.runShellCommand(cmd, True, True)
                print(f'  {self.substepColor_dk}returned: {a.lt_green_fg if ret == 0 else a.lt_red_fg}{ret}{a.all_off}')
                if ret != 0:
                    self.errors.append('didNotCompileOrLink' if buildExecutable else 'didNotCompile')
                self.buildErrors += err
            else:
                print(f'  {self.substepColor_lt}{outputPath}{self.substepColor_dk} already up to date.{a.all_off}')
        else:
            print(f'{self.substepColor_lt}Skip it. {a.dk_red_fg}{a.p(outputPath, "red")}{a.dk_red_fg} has errors.{a.all_off}')


    def _archiveLibrary(self, build):
        self.printStepMark('archive objects')

        s = Scribe(build.props)
        outputPath = Path(s.getXProp('outputLibPath'))
        ensureDirExists(outputPath.parent, False)

        outputFileTime = 0
        if outputPath.is_file():
            outputFileTime = outputPath.stat().st_mtime

        print(f'{self.substepColor_dk}Building {a.p(outputPath, self.substepFileColor)}{self.substepColor_dk} from objects.{a.all_off}')

        for lib in self.libs:
            if len(lib.errors) > 0:
                print(f'{a.lt_red_fg}{lib.name}{a.dk_red_fg} has errors')

        if self.hasErrors() == False:
            objs = []
            if s.getXProp('wholeProject'):
                objs = [Path(s.getXProp('outputProjectObjectPath'))]
            else:
                objs = [source.objPath for source in self.sources]
            newestTime = max([o.stat().st_mtime for o in objs], default=0)
            forceRebuild = s.getXProp('forceRebuild')
            if newestTime > outputFileTime or forceRebuild:
                cmd = self.computeCommand('archiveLibs', build, sources=objs)
                ret, _, err = self.runShellCommand(cmd, True, True)
                print(f'  {self.substepColor_dk}returned: {a.lt_green_fg if ret == 0 else a.lt_red_fg}{ret}{a.all_off}')
                if ret != 0:
                    self.errors.append('didNotArchive')
                self.buildErrors += err
            else:
                print(f'  {self.substepColor_lt}{outputPath}{self.substepColor_dk} already up to date.{a.all_off}')
        else:
            print(f'{self.substepColor_lt}Skip it. {a.dk_red_fg}{a.p(outputPath, "red")}{a.dk_red_fg} has errors.{a.all_off}')


    def printStepMark(self, stepName):
        print (f'{a.lt_magenta_fg}--------------------- {stepName}{a.all_off}')


    def hasErrors(self):
        return (any(map(lambda src: len(src.errors) > 0, self.sources))
            or  any(map(lambda lib: len(lib.errors) > 0, self.libs))
            or len(self.errors) > 0)


    def generateSources(self, build):
        s = Scribe(build.props)
        srcs = s.getXProp('sources')
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
                else:
                    # nothing matched the glob, and something probably should
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

        build.props.push({'sources': self.sources})


    # especially for libs; not tested for other uses
    def getBuildAtContext(self, callerProps, requrestedContext):
        comingFrom = Scribe(callerProps).getXProp('targetName')
        builds = self.props.getProp('builds')
        if requrestedContext[0] == '.':
            i = 0
            while requrestedContext[i + 1] == '.':
                i += 1
        addr = '.'.join(comingFrom.split('.')[:-i])
        if len(addr) > 0:
            addr += '.'
        addr += requrestedContext[i + 1:]
        if addr in builds:
            return builds[addr]
        else:
            raise RuntimeError(f'Cannot find context {requrestedContext}.')


    # especially for libs; not tested for other uses
    def getLocalXProp(self, props, value):
        value = value.strip()
        if value[0] == '!':
            colIdx = value[1:].index('!') + 1
            context = value[1:colIdx]
            # now get props for the context
            props = self.getBuildAtContext(props, context).props
            value = value[colIdx + 1:]

        return Scribe(props).X(value)


    def generateLibSources(self, build):
        self.printStepMark('get libs')

        def rindex(lst, value):
            return len(lst) - operator.indexOf(reversed(lst), value) - 1

        print(f'  {self.substepColor_dk}Getting linker search paths.{a.all_off}')
        cmd = self.computeCommand('getLinkerSearchPaths', build)
        ret, stdo, err = self.runShellCommand(cmd, True, True)
        print(f'  {self.substepColor_dk}returned: {a.lt_green_fg if ret == 0 else a.lt_red_fg}{ret}{a.all_off}')
        if ret == 0:
            #if build.props.getProp('groupName') == 'tableau.test':
            #    breakpoint()
            s = Scribe(build.props)
            libs = build.props.getProp('libs')
            libs = [self.getLocalXProp(build.props, lib) for lib in libs]
            libDirs = s.getXProp('libDirs') or []
            libDirs.extend([ld[ld.index('=') + 1 : rindex(ld, '"')] for ld in stdo.strip()[:-1].split(';')])
            for lib in libs:
                for libDir in libDirs:
                    p = Path(s.getXProp('projectDir')) / libDir / f'lib{lib}.a'
                    if p.is_file():
                        self.libs.append(Lib(lib, p))
                        break
                else:
                    p = Path(lib)
                    if p.is_file():
                        self.libs.append(Lib(p.stem[3:], p))  # libfoo.a -> foo
                    else:
                        libObj = Lib(lib, None)
                        self.libs.append(libObj)
                        libObj.errors.append('wasNotFound')
        else:
            self.errors.append('didNotLink')

        self.buildErrors += err
        build.props.push({'libs': self.libs})


    def generateSourceOutputs(self, build):
        s = Scribe(build.props)
        for source in self.sources or []:
            build.props.push({'source': source})
            source.objPath = Path(s.getXProp('outputObjectPath'))
            build.props.pop()


    def getDependencies(self, build, sources):
        self.printStepMark('get header dependencies')

        if type(sources) is not list:
            sources = [sources]

        for source in sources:
            # return a list of Path objects, for all preprocessor dependencies of all sources.
            cmd = self.computeCommand('getHeaderDependencies', build, source=source)
            print(f'  {self.substepColor_dk}Getting dependencies for {a.p(source.srcPath, self.substepFileColor)}{self.substepColor_dk}.{a.all_off}')
            if len(source.errors) == 0:
                ret, out, err = self.runShellCommand(cmd, True, True)
                print(f'  {self.substepColor_dk}returned: {a.lt_green_fg if ret == 0 else a.lt_red_fg}{ret}{a.all_off}')
                if ret != 0:
                    source.setCouldNotGetDeps()
                self.buildErrors += err

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
                print(f'  {self.substepColor_lt}Skip it. {a.dk_red_fg}{a.p(source.srcPath, "red")}{a.dk_red_fg} has errors.{a.all_off}')


    def computeCommand(self, operation, build, **kwargs):
        s = Scribe(build.props)
        projectDir = Path(s.getXProp('projectDir'))
        buildKind = s.getXProp('buildKind')
        tools = s.getXProp('tools')
        language = s.getXProp('language')
        languageStandard = s.getXProp('languageStandard')
        includeDirs = s.getXProp('includeDirs') or []
        if type(includeDirs) is not list:
            includeDirs = [includeDirs]
        includeDirs = [f'-I{projectDir / id}' for id in includeDirs]
        libraryDirs = s.getXProp('libDirs') or []
        if type(libraryDirs) is not list:
            libraryDirs = [libraryDirs]
        libraryDirs = [f'-L{projectDir / ld}' for ld in libraryDirs]
        libs = self.libs
        libs = [f'-l{l.path.stem[3:]}' for l in libs if l.path]
        # TODO: Package stuff here too
        outputPath = s.getXProp('outputPath')
        outputLibPath = s.getXProp('outputLibPath')
        outputProjectObjectPath = s.getXProp('outputProjectObjectPath')
        opts = ['-O0', '-g']
        if buildKind != 'debug':
            opts = ['-O3', '-s']
        warnflags = s.getXProp('warnS') or []
        if type(warnflags) is not list:
            warnflags = [warnflags]
        warnflags = [f'-{w}' for w in warnflags]
        cOpts = s.getXProp('compileOptions') or []
        if type(cOpts) is not list:
            cOpts = [cOpts]
        cOpts = [f'-{o}' for o in cOpts]
        lOpts = s.getXProp('linkOptions') or []
        if type(lOpts) is not list:
            lOpts = [lOpts]
        lOpts = [f'-{o}' for o in lOpts]
        clOpts = s.getXProp('compileAndLinkOptions') or []
        if type(clOpts) is not list:
            clOpts = [clOpts]
        clOpts = [f'-{o}' for o in clOpts]

        if tools == 'gnu':
            compilerTool = ''
            linkerTool = 'ld'
            archiveTool = 'ar'
            if language == 'c':
                compilerTool = 'gcc'
            elif language == 'c++':
                compilerTool = 'g++'
            else:
                raise RuntimeError(f'Unsupported language \'{language}\' for tools \'{tools}\' / tool kind \'{operation}\'.')

            if operation == 'getHeaderDependencies':
                source = kwargs.get('source')
                return f'{compilerTool} -std={languageStandard} -E -M {" ".join(includeDirs)} {str(source.srcPath)} {" ".join(clOpts)} {" ".join(cOpts)} {" ".join(lOpts)}'

            elif operation == 'getLinkerSearchPaths':
                libs = kwargs.get('lib')
                return f'{linkerTool} --verbose | grep SEARCH_DIR'

            elif operation == 'compileSourceToObject':
                source = kwargs.get('source')
                dotoPath = source.objPath
                return f'{compilerTool} -std={languageStandard} {" ".join(warnflags)} -c {" ".join(opts)} {" ".join(includeDirs)} {str(source.srcPath)} -o{dotoPath} {" ".join(clOpts)} {" ".join(cOpts)}'

            elif operation == 'compileManySourcesToObject':
                return f'{compilerTool} -std={languageStandard} {" ".join(warnflags)} -c {" ".join(opts)} {" ".join(includeDirs)} {" ".join([str(s.srcPath) for s in kwargs.get("sources", [])])} -o{outputProjectObjectPath} {" ".join(clOpts)} {" ".join(cOpts)}'

            elif operation == 'linkCompiledObjectsToExe':
                return f'{compilerTool} {" ".join(warnflags)} {" ".join(opts)} {" ".join([str(o) for o in kwargs.get("sources", [])])} -o{outputPath} {" ".join(libraryDirs)} {" ".join(libs)} {" ".join(clOpts)} {" ".join(lOpts)}'

            elif operation == 'compileManySourcesToExe':
                return f'{compilerTool} -std={languageStandard} {" ".join(warnflags)} {" ".join(opts)} {" ".join(includeDirs)} {" ".join([str(s.srcPath) for s in kwargs.get("sources", [])])} -o{outputPath} {" ".join(libraryDirs)} {" ".join(libs)} {" ".join(clOpts)} {" ".join(cOpts)} {" ".join(lOpts)}'

            elif operation == 'archiveLibs':
                return f'{archiveTool} csr  {outputLibPath} {" ".join([str(o) for o in kwargs.get("sources", [])])}'

        elif tools == 'llvm':
            raise RuntimeError(f'Unsupported tools \'{tools}\'. Patience.')

        elif tools == 'vs':
            raise RuntimeError(f'Unsupported tools \'{tools}\'. Patience.')

        else:
            raise RuntimeError(f'Unsupported tools \'{tools}\'.')

