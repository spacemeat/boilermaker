from . import utilities
from .ansi import Ansi as ansi

import re
re_cppName = re.compile(r'^[a-zA-Z_][a-zA-Z0-9_]*$')


class MemberType:
    def __init__(self, name, fullName, properties):
        '''properties might be a string (spec the type), or a
           dict (probably with a type member).'''
        self.name = name
        self.fullName = fullName

        def normalize(properties, name, idx):
            if type(properties) is str:
                properties = { 'type': properties }
            elif type(properties) is dict:
                properties = properties
            else:
                raise RuntimeError(f'properites of member type {name} must be a str or dict')

            fullName = f'{name}_{idx}'
            properties['fullName'] = fullName

            ofo = properties.get('of')
            if ofo and type(ofo) is not list:
                properties['of'] = [ofo]

            ofo = properties.get('of')
            if ofo:
                properties['of'] = [normalize(oft, fullName, idx) for idx, oft in enumerate(ofo)]

            return properties

        self.properties = normalize(properties, fullName, 0)


    def __repr__(self):
        endl = '\n'
        def recurse(properties, level):
            src = ''
            for pn in ['type', 'fullName', 'of', 'isLess']:
                pv = properties.get(pn)
                if not pv:
                    continue
                if type(pv) is str:
                    src += f'      {" " * level * 2}{ansi.dk_yellow_fg}{pn}{ansi.all_off}: {ansi.lt_yellow_fg}{pv}{ansi.all_off}{endl}'
                elif type(pv) is list:
                    src += f'      {" " * level * 2}{ansi.dk_yellow_fg}{pn}{ansi.all_off}:{endl}'
                    for pvi in pv:
                        src += recurse(pvi, level + 1)
                elif type(pv) is dict:
                    src += f'      {" " * level * 2}{ansi.dk_yellow_fg}{pn}{ansi.all_off}: {ansi.dk_yellow_fg}<some dict>{ansi.all_off}{endl}'
            return src

        for _, p in self.properties.items():
            src = f'    member: {ansi.lt_blue_fg}{self.fullName}{ansi.all_off}:{endl}'

        src += recurse(self.properties, 0)
        return src


class StructType:
    def __init__(self, name, members):
        '''members is always a dict of memberName: memberProperties.'''
        self.name = name
        self.members = {memberName: MemberType(memberName, f'{name}_{memberName}', memProperties)
                        for memberName, memProperties in members.items() if re_cppName.match(memberName)}

    def __repr__(self):
        endl = '\n'
        src = f'name: {ansi.lt_magenta_fg}{self.name}{ansi.all_off}:{endl}'
        for mn, mo in self.members.items():
            src += str(mo)

        return src
