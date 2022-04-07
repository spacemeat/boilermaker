from pathlib import Path
import os
from ...plugin import Provider, PluginCollection
from ...props import Scribe
from ...type import Type


class StandardType(Type):
    def __init__(self, name, namespace, declName, include):
        super().__init__(name, namespace)
        self.codeDecl = declName
        self.fullCodeDecl = declName
        self.alreadyDefined = True
        if type(include) is str:
            self.include = [include]
        else:
            self.include = include


class cpp17Provider(Provider):
    def start(self, runDefs, props):
        print (f'starting cpp17Provider')
        self.runDefs = runDefs
        self.props = props


    def do(self, op, seq):
        print (f'cpp17Provider doing op {op} at sequence {seq}')
        if op == 'createCppProps':
            self.generateProps()

        elif op == 'generateCode':
            self.removeAllFiles()
            s = Scribe(self.props)
            scribePath = PluginCollection(s.getXProp('pluginsDir')).locateScribe(self.runDefs['plugin'], self.runDefs['output'])
            print (s.X(f'$<in "{scribePath}">'))


    def stop(self):
        print (f'stopping cpp17Provider')


    def removeAllFiles(self):
        s = Scribe(self.props)
        def raf(self, direc):
            d = Path(s.X('$projectDir'), direc)
            if d.is_dir():
                for f in os.listdir(d):
                    if Path(f).is_file():
                        os.unlink(f)
        raf(self, s.X('$headerDir'))
        raf(self, s.X('$inlineDir'))
        raf(self, s.X('$sourceDir'))


    def generateProps(self):
        self.props.push()
        s = Scribe(self.props)

        self.props.setProp('scope', '')

        self.props.setProp('namespaceForFs', s.getXProp('namespace').replace('.', '_'))
        self.props.setProp('namespace', s.getXProp('namespace').replace('.', '::'))

        # convenience function for namespace/scoping
        def rescope(type):
            # TODO: This is probably lousy perf
            s = Scribe(self.props)
            currentScope = s.getXProp('scope').split('::')
            fullName = type.fullCodeDecl.split('::')
            # find first n common names; the rest is the qualified name
            skip = 0
            for i in range(min(len(currentScope), len(fullName))):
                if currentScope[i] == fullName[i]:
                    skip += 1
            return '::'.join(fullName[skip:])
        self.props.setProp('rescope', rescope)

        bomaEnums = {}
        for enumsCluster in s.getXPropAll('bomaEnums'):
            bomaEnums.update(enumsCluster)
        self.props.setProp('enums', bomaEnums)

        bomaTypes = {}
        for typesCluster in s.getXPropAll('bomaTypes'):
            bomaTypes.update(typesCluster)
        self.props.setProp('types', bomaTypes)

        standardTypes = {
            'string':      StandardType('string',       'std', 'std::string',             '<string>'),
            'stringView':  StandardType('stringView',   'std', 'std::string_view',        '<string_view>'),
            'cstring':     StandardType('cstring',      'std', '',                        '<cstring>' ),
            'array':       StandardType('array',        'std', 'std::array',              '<array>'),
            'pair':        StandardType('pair',         'std', 'std::pair',               '<utility>'),
            'tuple':       StandardType('tuple',        'std', 'std::tuple',              '<tuple>'),
            'vector':      StandardType('vector',       'std', 'std::vector',             '<vector>'),
            'set':         StandardType('set',          'std', 'std::set',                '<set>'),
            'unorderedSet':StandardType('unorderedSet', 'std', 'std::unordered_set',      '<unordered_set>'),
            'map':         StandardType('map',          'std', 'std::map',                '<map>'),
            'unorderedMap':StandardType('unorderedMap', 'std', 'std::unordered_map',      '<unordered_map>'),
            'optional':    StandardType('optional',     'std', 'std::optional',           '<optional>'),
            'variant':     StandardType('variant',      'std', 'std::variant',            '<variant>' )
                # TODO: multisdet, multimap, list, pmr things
        }

        allTypes = {**bomaTypes, **bomaEnums, **standardTypes}

        # compute C++ names for all types
        for _, t in allTypes.items():
            self.computeDecl(t)

        # compute translated names for enums that aren't already defined
        for _, e in bomaEnums.items():
            e.computeDeclVals(lambda val: f'{e.namespace}::{val.codeDecl}')

        # allow scribes to access $std.string.usedInBomaType, say
        class AllStandardObjects:
            def __init__(self):
                pass
        stdObj = AllStandardObjects()
        for k, v in standardTypes.items():
            setattr(stdObj, k, v)
        self.props.setProp('std', stdObj)

        # relative paths for local #includes
        self.props.setProp('headerToInl',    os.path.relpath(s.X('$inlineDir'), s.X('$headerDir')))
        self.props.setProp('srcToHeader',    os.path.relpath(s.X('$headerDir'), s.X('$sourceDir')))
        self.props.setProp('srcToInl',       os.path.relpath(s.X('$inlineDir'), s.X('$sourceDir')))

        # convenience function for $const
        def const(decl):
            s = Scribe(self.props)
            return f'{decl} const' if s.X('$constStyle') == 'east' else f'const {decl}'
        self.props.setProp('const', const)

        # binary reader for std::string needs std::memcpy
        if ('binary' in s.X('$deserializeFrom') and
            stdObj.string.usedInBomaType):
            stdObj.cstring.usedInBomaType = True

        # humon reader for enums needs std::strncmp
        if ('humon' in s.X('$deserializeFrom') and
            len(self.props.getProp('enums')) > 0):
            stdObj.cstring.usedInBomaType = True

        # binary ready for std::variant needs std::optional
        if ('binary' in s.X('$deserializeFrom') and
            stdObj.variant.usedInBomaType):
            stdObj.optional.usedInBomaType = True

        headers = set()

        if len(s.X('$cave') or []) > 0:
            headers.add('<iostream>')

        if ('humon' in s.X('$deserializeFrom') or
            'humon' in s.X('$serializeTo')):
            headers.add('<humon/humon.hpp>')

        allEnumHeaders = set()
        for bomaEnum in bomaEnums.values():
            enumHeaders = set()
            if bomaEnum.alreadyDefined:
                for inc in bomaEnum.include:
                   enumHeaders.add(inc)
            else:
                bomaEnum.include = ['"' + s.X('$enumsHeaderFile') + '"']
            bomaEnum.dependencyIncludes = list(enumHeaders)
            allEnumHeaders.update(enumHeaders)
        self.props.setProp('enumHeaderIncludes', list(allEnumHeaders))

        for bomaType in bomaTypes.values():
            if bomaType.alreadyDefined == False:
                self.props.push({'t': bomaType})
                bomaType.include = ['"' + s.X('$typeHeaderFile') + '"']
                self.props.pop()

        for bomaType in bomaTypes.values():
            typeHeaders = set()
            subtypes = bomaType.allSubtypes()
            for st in subtypes:
                if st.type in allTypes: # TODO: This isn't finding all the types it should
                    allTypes[st.type].usedInBomaType = True
                    for inc in allTypes[st.type].include:
                        typeHeaders.add(inc)
            bomaType.dependencyIncludes = list(typeHeaders)

        for stdType in standardTypes.values():
            for inc in stdType.include:
                if stdType.usedInBomaType:
                    headers.add(inc)

        self.props.setProp('commonHeaderIncludes', list(headers))

        fwds = set()
        for typeName, bomaType in bomaTypes.items():
            subtypes = bomaType.allSubtypesOfIsLessTypes()
            subtypes = [st.type for st in subtypes if st.type in bomaTypes]
            fwds.update(subtypes)
        self.props.setProp('commonHeaderFwdDecls', fwds)

        def computeCodeDecls_rec(subtype):
            subtype.codeDecl = subtype.type.replace('.', '::')
            if subtype.type in standardTypes:
                subtype.codeDecl = standardTypes[subtype.type].codeDecl
            elif subtype.type in bomaEnums:
                subtype.codeDecl = bomaEnums[subtype.type].codeDecl
            if subtype.subtypes:
                templateArgs = [computeCodeDecls_rec(st) for st in subtype.subtypes]
                if subtype.isLess:
                    templateArgs.insert(2, f'IsLess_{subtype.name}')
                subtype.codeDecl += '<' + ', '.join(templateArgs) + '>'
            return subtype.codeDecl

        def computeFullCodeDecls_rec(subtype, parentDecl):
            fcd = parentDecl + '::' + subtype.codeDecl
            subtype.fullCodeDecl = fcd
            for st in subtype.subtypes:
                computeFullCodeDecls_rec(st, fcd)

        for tn, t in bomaTypes.items():
            for mn, m in t.members.items():
                computeCodeDecls_rec(m.type)
                computeFullCodeDecls_rec(m.type, '')

        for bomaType in bomaTypes.values():
            for member in bomaType.members.values():
                member.makeDefaulValue(bomaEnums)

        needVariantTypeNamesBase = False
        for tn, t in bomaTypes.items():
            if len(t.allVariantSubtypes()) > 0:
                needVariantTypeNamesBase = True
        self.props.setProp('needVariantTypeNamesBase', needVariantTypeNamesBase)


    def computeDecl(self, t :Type):
        if t.alreadyDefined:
            return
        s = Scribe(self.props)
        t.codeDecl = t.name.replace('.', '::')
        t.fullCodeDecl = '::' + s.X('$namespace') + '::' + t.name.replace('.', '::')
