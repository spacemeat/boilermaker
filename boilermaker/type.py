from .ansi import Ansi as ansi
import re
from .props import Scribe

re_cppName = re.compile(r'^[a-zA-Z_][a-zA-Z0-9_]*$')


class Type:
    def __init__(self, name, props):
        self.name = name
        self.props = props
        #self.namespace = ''
        self.include = []
        self.usedInBomaType = False
        self.knows = []
        self.aliases = []
        self.alreadyDefined = False
        self.codeDecl = ''
        self.fullCodeDecl = ''
        self.baseTypeDecl = ''  # only currently used for citing the base type in type header.


class BomaSubtype:
    def __init__(self, typeData, name, props):
        if type(typeData) is str:
            typeData = { 'type': typeData }

        self.name = name
        self.props = props
        self.type = typeData.get('type')
        self.aliases = typeData.get('alias')
        self.isLess = typeData.get('isLess')
        self.codeDecl = ''
        self.fullCodeDecl = ''

        ofo = typeData.get('of')
        if ofo and type(ofo) is not list:
            typeData['of'] = [ofo]

        ofo = typeData.get('of')
        if ofo:
            self.subtypes = [BomaSubtype(subsubtype, f'{name}_{idx}', props) for idx, subsubtype in enumerate(ofo)]
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
    def __init__(self, name, fullName, properties, props):
        '''properties might be a string (spec the type), or a
           dict (probably with a type member).'''
        self.name = name
        self.fullName = fullName
        self.props = props

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
        self.type = BomaSubtype(self.properties, self.fullName, props)


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


    def makeDefaulValue(self, enumTypes):
        self.defaultValue = ''
        defaultValue = self.properties.get('default', None)
        if not defaultValue:
            return

        def isInty(val):
            try: int(val); return True
            except ValueError: return False

        def isFloaty(val):
            try: float(val); return True
            except ValueError: return False

        if self.type.type in enumTypes:
            enumType = enumTypes[self.type.type]

            if enumType.flags:
                allValues = ''
                if type(defaultValue) is list:
                    values = []
                    for dvc in defaultValue:
                        for ev in enumType.bomaEnum.values:
                            if ev.name == dvc:
                                if enumType.isScoped:
                                    values.append(f'static_cast<std::underlying_type<{self.type.fullCodeDecl}>>({ev.fullCodeDecl})')
                                else:
                                    values.append(f'{ev.fullCodeDecl}')
                                break
                    allValues = f'static_cast<{self.type.fullCodeDecl}>(' + ' | '.join(values) + ')'
                else:
                    if isInty(defaultValue):
                        allValues = f'static_cast<{self.type.fullCodeDecl}>({defaultValue})'
                    else:
                        for ev in enumType.bomaEnum.values:
                            if ev.name == defaultValue:
                                allValues = ev.fullCodeDecl
                                break
                self.defaultValue = f'{allValues}'

            elif isInty(defaultValue):
                self.defaultValue = f'static_cast<{self.type.fullCodeDecl}>({defaultValue})'
            else:
                for ev in enumType.bomaEnum.values:
                    if ev.bomaName == defaultValue:
                        self.defaultValue = ev.fullCodeDecl
                        break

        elif isInty(defaultValue) or isFloaty(defaultValue):
            self.defaultValue = defaultValue

        elif (self.type.type == 'string' or
              self.type.type == 'stringView'):
            self.defaultValue = f'"{defaultValue}"'
        else:
            self.defaultValue = defaultValue


    def subtypesWithIsLess(self):
        return self.type.subtypesWithIsLess()


    def allSubtypes(self):
        return self.type.allSubtypes()


    def allSubtypesOfIsLessTypes(self):
        return self.type.allSubtypesOfIsLessTypes()


    def allVariantSubtypes(self):
        return self.type.allVariantSubtypes()


class BomaType(Type):
    def __init__(self, typeBlock, props):
        name = typeBlock.get('name', '')
        super().__init__(name, props)

        #s = Scribe(props)
        #self.namespace = s.X('namespace')

        self.members = dict()
        for memberName, memProperties in typeBlock['members'].items():
            if re_cppName.match(memberName):
                self.members[memberName] = BomaTypeMember(
                    memberName,
                    f'{name}_{memberName}',
                    memProperties,
                    props)
            else:
                if memberName == '-deriveFrom':
                    # TODO: YUCK. We're doing a literal transliteration here.
                    # I'd rather reason about the type and do scoping stuff.
                    self.baseTypeDecl = memProperties
                elif memberName == '-knows':
                    if type(memProperties) is not list:
                        memProperties = [memProperties]
                    self.knows = memProperties


    def __repr__(self):
        endl = '\n'
        src = f'name: {ansi.lt_magenta_fg}{self.name}{ansi.all_off}:{endl}'
        for mo in self.members.values():
            src += str(mo)

        return src

    def subtypesWithIsLess(self):
        mts = []
        for m in self.members.values():
            if msts := m.subtypesWithIsLess():
                mts.extend(msts)
        return mts

    def allSubtypes(self):
        mts = []
        for m in self.members.values():
            mts.extend(m.allSubtypes() or [])
        return mts

    def allSubtypesOfIsLessTypes(self):
        mts = []
        for m in self.members.values():
            mts.extend(m.allSubtypesOfIsLessTypes() or [])
        return mts

    def allVariantSubtypes(self):
        mts = []
        for m in self.members.values():
            mts.extend(m.allVariantSubtypes() or [])
        return mts
