from unicodedata import name
from . import utilities
from .ansi import Ansi as ansi
import re

re_cppName = re.compile(r'^[a-zA-Z_][a-zA-Z0-9_]*$')


class Type:
    def __init__(self, name, namespace = ''):
        self.name = name
        self.namespace = namespace
        self.include = []
        self.usedInBomaType = False
        self.aliases = []
        self.alreadyDefined = False
        self.codeDecl = ''
        self.fullCodeDecl = ''


class Types:
    def __init__(self):
        self.types = {}


class BomaSubtype:
    def __init__(self, properties, name):
        if type(properties) is str:
            properties = { 'type': properties }

        self.name = name
        self.type = properties.get('type')
        self.aliases = properties.get('alias')
        self.isLess = properties.get('isLess')
        self.codeDecl = ''
        self.fullCodeDecl = ''

        ofo = properties.get('of')
        if ofo and type(ofo) is not list:
            properties['of'] = [ofo]

        ofo = properties.get('of')
        if ofo:
            self.subtypes = [BomaSubtype(subsubtype, f'{name}_{idx}') for idx, subsubtype in enumerate(ofo)]
        else:
            self.subtypes = []


    def subtypesWithIsLess(self):
        sts = []
        if self.isLess:
            sts.append(self)
        for ofo in self.subtypes:
            sts.extend(ofo.subtypesWithIsLess() or [])
        return sts


    def allSubtypes(self):
        sts = [self]
        for ofo in self.subtypes:
            sts.extend(ofo.allSubtypes() or [])
        return sts


    def allSubtypesOfIsLessTypes(self):
        sts = []
        if self.isLess:
            for ofo in self.subtypes:
                sts.extend(ofo.allSubtypes() or [])
        else:
            for ofo in self.subtypes:
                sts.extend(ofo.allSubtypesOfIsLessTypes() or [])
        return sts


    def allVariantSubtypes(self):
        sts = []
        if self.type == 'variant':
            sts.append(self)
        for ofo in self.subtypes:
            sts.extend(ofo.allVariantSubtypes() or [])
        return sts


class BomaTypeMember:
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
        self.type = BomaSubtype(self.properties, self.fullName)

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

    def subtypesWithIsLess(self):
        return self.type.subtypesWithIsLess()

    def allSubtypes(self):
        return self.type.allSubtypes()

    def allSubtypesOfIsLessTypes(self):
        return self.type.allSubtypesOfIsLessTypes()

    def allVariantSubtypes(self):
        return self.type.allVariantSubtypes()


class BomaType(Type):
    def __init__(self, name, namespace, members):
        super().__init__(name, namespace)
        '''members is always a dict of memberName: memberProperties.'''
        self.members = { memberName: BomaTypeMember(memberName, f'{name}_{memberName}', memProperties)
                         for memberName, memProperties in members.items() if re_cppName.match(memberName) }

    def __repr__(self):
        endl = '\n'
        src = f'name: {ansi.lt_magenta_fg}{self.name}{ansi.all_off}:{endl}'
        for mn, mo in self.members.items():
            src += str(mo)

        return src

    def subtypesWithIsLess(self):
        mts = []
        for _, m in self.members.items():
            if msts := m.subtypesWithIsLess():
                mts.extend(msts)
        return mts

    def allSubtypes(self):
        mts = []
        for _, m in self.members.items():
            mts.extend(m.allSubtypes() or [])
        return mts

    def allSubtypesOfIsLessTypes(self):
        mts = []
        for _, m in self.members.items():
            mts.extend(m.allSubtypesOfIsLessTypes() or [])
        return mts

    def allVariantSubtypes(self):
        mts = []
        for _, m in self.members.items():
            mts.extend(m.allVariantSubtypes() or [])
        return mts
