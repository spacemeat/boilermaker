from ...plugin import Provider, PluginCollection
from ...props import Scribe
from .project import CppProject


class cpp17Provider(Provider):
    def start(self, run, props):
        print (f'starting cpp17Provider')
        self.run = run
        self.cp = CppProject(props)

    def do(self, op, seq, props):
        print (f'cpp17Provider doing op {op} at sequence {seq}')
        if op == 'createCppProps':
            s = Scribe(props)
            props.push()
            self.cp.generateProps()

        elif op == 'generateCode':
            self.cp.removeAllFiles()
            s = Scribe(props)
            s.debug = True
            breakpoint()
            scribePath = PluginCollection(s.getXProp('pluginsDir')).locateScribe(self.run['plugin'], self.run['output'])
            print (s.parseText(f'$<in "{scribePath}">'))

    def stop(self, props):
        print (f'stopping cpp17Provider')
        props.pop()
