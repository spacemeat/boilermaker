from ...plugin import Provider

class grokCppProvider(Provider):
    def start(self, run, props):
        print (f'starting grokCppProvider')
        self.run = run

    def do(self, op, seq, props):
        print (f'grokCppProvider doing op {op} at sequence {seq}')

    def stop(self, props):
        print (f'stopping grokCppProvider')
