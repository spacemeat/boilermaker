from pathlib import Path
import os
from ... import utilities
from ...plugin import Provider, PluginCollection
from ...props import Scribe
#from .project import CppProject
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


    def do(self, op, seq, props):
        print (f'cpp17Provider doing op {op} at sequence {seq}')
        if op == 'createCppProps':
            self.generateProps(props)

        elif op == 'generateCode':
            self.removeAllFiles(props)
            s = Scribe(props)
            #s.debug = True
            scribePath = PluginCollection(s.getXProp('pluginsDir')).locateScribe(self.runDefs['plugin'], self.runDefs['output'])
            print (s.X(f'$<in "{scribePath}">'))


    def stop(self, props):
        print (f'stopping cpp17Provider')


    def removeAllFiles(self, props):
        s = Scribe(props)
        def raf(self, direc):
            d = Path(s.X('$projectDir'), direc)
            if d.is_dir():
                for f in os.listdir(d):
                    if Path(f).is_file():
                        os.unlink(f)
        raf(self, s.X('$headerDir'))
        raf(self, s.X('$inlineDir'))
        raf(self, s.X('$sourceDir'))


    def generateProps(self, props):
        props.push()

        props.setProp('scope', '')

        # convenience function for namespace/scoping
        def rescope(type):
            # TODO: This is probably losy perf
            s = Scribe(props)
            currentScope = s.getXProp('scope').split('::')
            fullName = type.fullCodeDecl.split('::')
            # find first n common names; the rest is the qualified name
            skip = 0
            for i in range(min(len(currentScope), len(fullName))):
                if currentScope[i] == fullName[i]:
                    skip += 1
            #breakpoint()
            return '::'.join(fullName[skip:])
        props.setProp('rescope', rescope)

        s = Scribe(props)
        bomaEnums = {}
        for enumsCluster in s.getXPropAll('bomaEnums'):
            bomaEnums.update(enumsCluster)
        props.setProp('enums', bomaEnums)

        bomaTypes = {}
        for typesCluster in s.getXPropAll('bomaTypes'):
            bomaTypes.update(typesCluster)
        props.setProp('types', bomaTypes)

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
            self.computeDecl(t, props)

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
        props.setProp('std', stdObj)

        # relative paths for local #includes
        props.setProp('headerToInl',    os.path.relpath(s.X('$inlineDir'), s.X('$headerDir')))
        props.setProp('srcToHeader',    os.path.relpath(s.X('$headerDir'), s.X('$sourceDir')))
        props.setProp('srcToInl',       os.path.relpath(s.X('$inlineDir'), s.X('$sourceDir')))

        # convenience function for $const
        def const(decl):
            s = Scribe(props)
            return f'{decl} const' if s.X('$constStyle') == 'east' else f'const {decl}'
        props.setProp('const', const)

        headers = set()

        if len(s.X('$cave') or []) > 0:
            headers.add('<iostream>')

        if ('humon' in s.X('$deserializeFrom') or
            'humon' in s.X('$serializeTo')):
            headers.add('<humon/humon.hpp>')

        for typeName, strType in bomaTypes.items():
            subtypes = strType.allSubtypes()
            for st in subtypes:
                if st.type in allTypes:
                    allTypes[st.type].usedInBomaType = True
                    for inc in allTypes[st.type].include:
                        headers.add(inc)

        for _, bomaEnum in bomaEnums.items():
            for inc in bomaEnum.include:
                headers.add(inc)

        for _, stdType in standardTypes.items():
            for inc in stdType.include:
                headers.add(inc)

        props.setProp('commonHeaderIncludes', list(headers))

        fwds = set()
        for typeName, strType in bomaTypes.items():
            subtypes = strType.allSubtypesOfIsLessTypes()
            subtypes = [st.type for st in subtypes if st.type in bomaTypes]
            fwds.update(subtypes)
        props.setProp('commonHeaderFwdDecls', fwds)

        def computeCodeDecls_rec(subtype):
            subtype.codeDecl = subtype.type
            if subtype.type in standardTypes:
                subtype.codeDecl = standardTypes[subtype.type].codeDecl
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
                computeCodeDecls_rec(m.subtype)
                computeFullCodeDecls_rec(m.subtype, '')

        needVariantTypeNamesBase = False
        for tn, t in bomaTypes.items():
            if len(t.allVariantSubtypes()) > 0:
                needVariantTypeNamesBase = True
        props.setProp('needVariantTypeNamesBase', needVariantTypeNamesBase)

        # binary reader for std::string needs std::memcpy
        if ('binary' in s.X('$deserializeFrom') and
            stdObj.string.usedInBomaType):
            stdObj.cstring.usedInBomaType = True

        # humon reader for enums needs std::strncmp
        if ('humon' in s.X('$deserializeFrom') and
            len(props.getProp('enums')) > 0):
            stdObj.cstring.usedInBomaType = True

        # binary ready for std::variant needs std::optional
        if ('binary' in s.X('$deserializeFrom') and
            stdObj.variant.usedInBomaType):
            stdObj.optional.usedInBomaType = True


    def computeDecl(self, t :Type, props):
        if t.alreadyDefined:
            return
        s = Scribe(props)
        t.codeDecl = t.name.replace('.', '::')
        t.fullCodeDecl = '::' + s.X('$namespace') + '::' + t.name.replace('.', '::')


    def makeNative_old(self, bomaName, useNamespace=False):
        if bomaName in ['less', 'monostate', 'size_t', 'string', 'string_view', 'array', 'pair', 'tuple', 'vector', 'set', 'unordered_set', 'map', 'unordered_map', 'optional', 'variant']:
            return 'std::' + bomaName
        elif useNamespace and bomaName in self.types:
            bomaName = f'{self.P("namespace")}::{bomaName}'
        return bomaName.replace('.', '::')


    def makeNativeSubtype_old(self, properties, useNamespace=False):
        builtType = self.makeNative(properties['type'], useNamespace)
        of = properties.get('of')
        if of:
            builtType += '<'
            if type(of) is list:
                builtType += ', '.join([self.makeNativeSubtype(utilities.dictify(ch, 'type'), useNamespace) for ch in of])
            elif type(of) is dict:
                builtType += self.makeNativeSubtype(of, useNamespace)
            else:
                builtType += self.makeNative(of, useNamespace)
            if properties['type'] == 'set' or properties['type'] == 'map':
                if 'isLess' in properties:
                    ns = f'{self.P("namespace")}::' if useNamespace else ''
                    builtType += f', {ns}IsLess_{properties["fullName"]}'
            builtType += '>'
        return builtType


    def makeNativeMemberType_old(self, properties, useNamespace=False):
        return self.makeNativeSubtype(utilities.dictify(properties, 'type'), useNamespace)


