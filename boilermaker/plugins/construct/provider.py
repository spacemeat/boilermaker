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


class ConstructProvider(Provider):
    def start(self, runDefs, props):
        print (f'starting ConstructProvider')
        self.runDefs = runDefs
        self.props = props


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

        s = Scribe(self.props)
        tools = s.getXProp('tools')
        language = s.getXProp('language')
        languageStandard = s.getXProp('languageStandard')
        clearTempDir = s.getXProp('clearTempDir')
        includeDirses = s.getXPropAll('includeDirs')
        includeDirs = set()
        for ids in includeDirses:
            for id in ids:
                includeDirs.add(id)
        includeDirs = list(includeDirs)

        self.generateAllSources()

        outputExePath = Path(s.getXProp('outputExePath'))
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
            deps = set(self.sources)
            deps.update(self.getDependencies(self.sources))
            newestTime = max([dep.stat().st_mtime for dep in deps])
            print(f'{a.dk_blue_fg}Building {a.lt_blue_fg}{outputExePath}{a.dk_blue_fg} from all sources')
            if newestTime > outputExeFileTime or forceRebuild:
                cmd = self.makeBuildAllSourcesScript()
                ret, _, _ = self.runShellCommand(cmd)
                print(f'  {a.dk_blue_fg}returned {a.lt_green_fg if ret == 0 else a.lt_red_fg}{ret}{a.all_off}')
            else:
                print(f'  {a.lt_blue_fg}{outputExePath}{a.dk_blue_fg} already up to date.{a.all_off}')

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
                self.props.push({'source': source})
                outputObjectPath = Path(s.getXProp('outputObjectPath'))
                self.props.pop()
                objectPaths.append(outputObjectPath)
                outputObjectFileTime = 0
                if outputObjectPath.is_file():
                    outputObjectFileTime = outputObjectPath.stat().st_mtime

                deps = set(self.getDependencies(source))
                newestTime = max([dep.stat().st_mtime for dep in deps])
                print(f'{a.dk_blue_fg}Building {a.lt_blue_fg}{outputObjectPath}{a.dk_blue_fg} from source {a.lt_blue_fg}{str(source)}{a.dk_blue_fg}.{a.all_off}')
                if newestTime > outputObjectFileTime or forceRebuild:
                    cmd = self.makeBuildOneSourceScript(source)
                    ret, _, _ = self.runShellCommand(cmd)
                    print(f'  {a.dk_blue_fg}returned {a.lt_green_fg if ret == 0 else a.lt_red_fg}{ret}{a.all_off}')
                else:
                    print(f'  {a.lt_blue_fg}{outputObjectPath}{a.dk_blue_fg} already up to date.{a.all_off}')

            # if any objs aren't there, they failed to build. No buildy the exe.
            print(f'{a.dk_blue_fg}Building {a.lt_blue_fg}{outputExePath}{a.dk_blue_fg} from {a.lt_blue_fg}{len(objectPaths)}{a.dk_blue_fg} objects.{a.all_off}')
            if all([obj.is_file() for obj in objectPaths]):
                newestTime = max([obj.stat().st_mtime for obj in objectPaths])
                if newestTime > outputExeFileTime or forceRebuild:
                    cmd = self.makeLinkAllObjectsScript(objectPaths)
                    ret, _, _ = self.runShellCommand(cmd)
                    print(f'  {a.dk_blue_fg}returned {a.lt_green_fg if ret == 0 else a.lt_red_fg}{ret}{a.all_off}')
                else:
                    print(f'  {a.lt_blue_fg}{outputExePath}{a.dk_blue_fg} already up to date.{a.all_off}')
            else:
                print(f'  {a.lt_blue_fg}{outputExePath}{a.dk_blue_fg} is {a.lt_red_fg}missing dependencies{a.dk_blue_fg} and cannot be built.{a.all_off}')


    def generateAllSources(self):
        s = Scribe(self.props)
        self.sources = set()
        self.errorSources = set()
        srcses = s.getXPropAll('sources')
        for srcs in srcses:
            for src in srcs:
                # could be multiiple files (*.cpp)
                src = list(Path('.').glob(src))
                if type(src) is list:
                    for s in src:
                        if s.is_file():
                            self.sources.add(s)
                        else:
                            self.errorSources.add(s)
                else:
                    if src.is_file():
                        self.sources.add(src)
                    else:
                        self.errorSources.add(src)
        self.sources = list(self.sources)
        self.errorSources = list(self.errorSources)
        self.props.push({'sources': self.sources})


    def getDependencies(self, sources):
        if type(sources) is not list:
            sources = [sources]
        # return a list of Path objects, for all preprocessor dependencies of all sources.
        cmd = self.computeCommand('getDependencies', sources=sources)
        print(f'{a.dk_blue_fg}Getting dependencies for {a.lt_blue_fg}{len(sources)}{a.dk_blue_fg} sources{a.all_off}')
        ret, out, err = self.runShellCommand(cmd)
        if ret != 0:
            raise RuntimeError(f'Shell command {cmd} failed with code {ret} and has ruined everything.\n{err}')
        print(f'  {a.dk_blue_fg}done.{a.all_off}')
        out = out.replace('\\\n', '')

        deps = set()
        for line in out.splitlines():
            paths = line.split(' ')
            for path in paths[1:]:
                # don't include the .cpp files in deps
                if path not in [str(s) for s in self.sources]:
                    deps.add(path)

        return list([Path(p) for p in deps])


    def makeBuildAllSourcesScript(self):
        return self.computeCommand('compileAndLinkFiles', sources=self.sources)


    def makeBuildOneSourceScript(self, source):
        return self.computeCommand('compileFile', source=source)


    def makeLinkAllObjectsScript(self, objectPaths):
        return self.computeCommand('linkObjects', objectPaths=objectPaths)


    def computeCommand(self, operation, **kwargs):
        s = Scribe(self.props)
        buildKind = s.getXProp('buildKind')
        tools = s.getXProp('tools')
        language = s.getXProp('language')
        languageStandard = s.getXProp('languageStandard')
        includeDirses = s.getXPropAll('includeDirs')
        includeDirs = set()
        for ids in includeDirses:
            for id in ids:
                includeDirs.add(id)
        includeDirs = [f'-I{id}' for id in includeDirs]
        libraryDirses = s.getXPropAll('libDirs')
        libraryDirs = set()
        for libs in libraryDirses:
            for lib in libs:
                libraryDirs.add(lib)
        libraryDirs = [f'-L{ld}' for ld in libraryDirs]
        libses = s.getXPropAll('libs')
        libraries = set()
        for libs in libses:
            for lib in libs:
                libraries.add(lib)
        libraries = [f'-l{l}' for l in libraries]
        # TODO: Package stuff here too
        outputExePath = s.getXProp('outputExePath')
        opts = ['-O0', '-g']
        if buildKind == 'release':
            opts = ['-O3', '-s']
        warnflags = set()
        warnses = s.getXPropAll('warns')
        for warns in warnses:
            for warn in warns:
                warnflags.add(warn)
        warnflags = [f'-{w}' for w in warnflags]

        if tools == 'gnu':
            compilerTool = ''
            if language == 'c':
                compilerTool = 'gcc'
            elif language == 'c++':
                compilerTool = 'g++'
            else:
                raise RuntimeError(f'Unsupported language \'{language}\' for tools \'{tools}\' / tool kind \'{operation}\'.')

            if operation == 'getDependencies':
                return f'{compilerTool} -std={languageStandard} -E -M {" ".join(includeDirs)} {" ".join([str(s) for s in kwargs.get("sources", [])])}'

            elif operation == 'compileFile':
                source = kwargs.get('source')
                self.props.push({'source': source})
                dotoPath = s.getXProp('outputObjectPath')
                self.props.pop()
                return f'{compilerTool} -std={languageStandard} {" ".join(warnflags)} -c {" ".join(opts)} {" ".join(includeDirs)} {str(source)} -o{dotoPath} {" ".join(libraryDirs)} {" ".join(libraries)}'

            elif operation == 'compileAndLinkFiles':
                return f'{compilerTool} -std={languageStandard} {" ".join(warnflags)} {" ".join(opts)} {" ".join(includeDirs)} {" ".join([str(s) for s in kwargs.get("sources", [])])} -o{outputExePath} {" ".join(libraryDirs)} {" ".join(libraries)}'

            elif operation == 'linkObjects':
                return f'{compilerTool} -std={languageStandard} {" ".join(warnflags)} {" ".join(opts)} {" ".join([str(s) for s in kwargs.get("objectPaths", [])])} -o{outputExePath} {" ".join(libraryDirs)} {" ".join(libraries)}'
                #if language == 'c' or language == 'c++':
                #    return f'ld {" ".join([str(s) for s in kwargs.get("objectPaths", [])])} -o{outputExePath} {" ".join(libraryDirs)} {" ".join(libraries)}'
                #else:
                #    raise RuntimeError(f'Unsupported language \'{language}\' for tools \'{tools}\' / tool kind \'{operation}\'.')
        elif tools == 'llvm':
            raise RuntimeError(f'Unsupported tools \'{tools}\'. Patience.')
        elif tools == 'vs':
            raise RuntimeError(f'Unsupported tools \'{tools}\'. Patience.')
        else:
            raise RuntimeError(f'Unsupported tools \'{tools}\'.')

