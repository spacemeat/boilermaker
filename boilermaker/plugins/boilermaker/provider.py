from ...plugin import Provider
from ...props import Scribe
from ...plugin import Provider, PluginCollection
from datetime import datetime


class BomaProvider(Provider):
    def start(self, runDefs, props):
        print (f'starting BomaProvider')
        self.runDefs = runDefs
        self.props = props


    def do(self, op, seq):
        print (f'BomaProvider doing op {op} at sequence {seq}')
        if op == 'touchPostFile':
            self.touchPostFile()


    def stop(self):
        print (f'stopping BomaProvider')


    def touchPostFile(self):
        s = Scribe(self.props)
        scribePath = PluginCollection(s.getXProp('pluginsDir')).locateScribe(self.runDefs['plugin'], self.runDefs['output'])
        def getDateTime():
            return str(datetime.now())
        self.props.push({'dateAndTime': getDateTime})
        print (s.X(f'$<in "{scribePath}">'))
        self.props.pop()

