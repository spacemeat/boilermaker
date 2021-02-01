class MemberType:
    def __init__(self, name, properties):
        '''properties might be a string (spec the type), or a
           dict (probably with a type member).'''
        self.name = name
        if type(properties) is str:
            self.properties = { 'type': properties }
        else:
            self.properties = properties


class StructType:
    def __init__(self, name, members):
        '''members is always a dict of memberName: memberProperties.'''
        self.name = name
        self.members = {memName: MemberType(memName, memProperties) 
                        for memName, memProperties in members.items()}
