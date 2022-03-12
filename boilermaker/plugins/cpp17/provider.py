from pathlib import Path
import os
import utilities
from ...plugin import Provider, PluginCollection
from ...props import Scribe
from .project import CppProject
from ...type import Type


class StandardType(Type):
    def __init__(self, code, include, used = False):
        super().__init__(self, code, include, used)


class cpp17Provider(Provider):
    def start(self, run, props):
        print (f'starting cpp17Provider')
        self.run = run

    def do(self, op, seq, props):
        print (f'cpp17Provider doing op {op} at sequence {seq}')
        if op == 'createCppProps':
            s = Scribe(props)
            props.push()
            self.generateProps()

        elif op == 'generateCode':
            self.removeAllFiles()
            s = Scribe(props)
            s.debug = True
            breakpoint()
            scribePath = PluginCollection(s.getXProp('pluginsDir')).locateScribe(self.run['plugin'], self.run['output'])
            print (s.parseText(f'$<in "{scribePath}">'))

    def stop(self, props):
        print (f'stopping cpp17Provider')
        props.pop()


    def removeAllFiles(self):
        def raf(self, direc):
            d = Path(self.P('projectDir'), direc)
            if d.is_dir():
                for f in os.listdir(d):
                    if Path(f).is_file():
                        os.unlink(f)
        raf(self, self.P('headerDir'))
        raf(self, self.P('inlineDir'))
        raf(self, self.P('sourceDir'))


    def generateProps(self):
        self.reset()

        bomaTypes = self.props.getProp('bomaTypes')
        enumTypes = self.props.getProp('enumTypes')
        standardTypes = {
            'string':      StandardType('std::string',             '<string>'),
            'stringView':  StandardType('std::string_view',        '<string_view>'),
            'cstring':     StandardType('',                        '<cstring>' ),
            'array':       StandardType('std::array',              '<array>'),
            'pair':        StandardType('std::pair',               '<utility>'),
            'tuple':       StandardType('std::tuple',              '<tuple>'),
            'vector':      StandardType('std::vector',             '<vector>'),
            'set':         StandardType('std::set',                '<set>'),
            'unorderedSet':StandardType('std::unordered_set',      '<unordered_set>'),
            'map':         StandardType('std::map',                '<map>'),
            'unorderedMap':StandardType('std::unordered_map',      '<unordered_map>'),
            'optional':    StandardType('std::optional',           '<optional>'),
            'variant':     StandardType('std::variant',            '<variant>' )
                # TODO: multisdet, multimap, list, pmr things
        }

        allTypes = [*bomaTypes, *enumTypes, *standardTypes]

        # compute C++ names for all types
        for t in allTypes:
            self.computeDecls(t)

        # allow scribes to access $std.string.used, say
        stdObj = object()
        for k, v in standardTypes.items():
            stdObj.__setattr__(k, v)
        self.props.setProp('std', stdObj)

        # relative paths for local #includes
        self.props.setProp('headerToInl', os.path.relpath(self.P('inlineDir'), self.P('headerDir')))
        self.props.setProp('srcToHeader', os.path.relpath(self.P('headerDir'), self.P('sourceDir')))
        self.props.setProp('srcToInl', os.path.relpath(self.P('inlineDir'), self.P('sourceDir')))

        # convenience function for $const
        def const(decl):
            s = Scribe(self.props)
            return f'{decl} const' if s.X('constStyle', 'west') == 'east' else f'const {decl}'
        self.props.setProp('const', const)

        #self.makeOutputForm()

        headers = set()
        if ('humon' in self.props.getProp('deserializeFrom') or
            'humon' in self.props.getProp('serializeTo')):
            #headers.append('<humon/humon.hpp>')
            pass

        for typeName, strType in bomaTypes.items():
            subtypes = strType.allSubtypes()
            for st in subtypes:
                if st.type in vars(allTypes):
                    getattr(allTypes, st.type).used = True

        #headers.update([st.include for st in standardTypes if st.used])

        self.props.setProp('commonHeaderIncludes', list(headers))

        fwds = set()
        for typeName, strType in bomaTypes.items():
            subtypes = strType.allSubtypesOfIsLessTypes()
            subtypes = [st.type for st in subtypes if st.type in bomaTypes]
            fwds.update(subtypes)
        self.props.setProp('commonHeaderFwdDecls', fwds)

        def computeCodeDecls_rec(subtype):
            subtype.codeDecl = subtype.type
            if subtype.type in vars(standardTypes):
                subtype.codeDecl = getattr(standardTypes, subtype.type).code
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
        self.props.setProp('needVariantTypeNamesBase', needVariantTypeNamesBase)

        # binary reader for std::string needs std::memcpy
        if ('binary' in self.props.getProp('deserializeFrom') and
            standardTypes.string.used):
            standardTypes.cstring.used = True

        # humon reader for enums needs std::strncmp
        if ('humon' in self.props.getProp('deserializeFrom') and
            len(self.props.getProp('enums')) > 0):
            standardTypes.cstring.used = True

        # binary ready for std::variant needs std::optional
        if ('binary' in self.props.getProp('deserializeFrom') and
            standardTypes.variant.used):
            standardTypes.optional.used = True

        #self.gen_global.genAll(self) - DONE

        #self.gen_enums.genAll(self)
        #self.gen_types.genAll(self)
        #self.gen_global.genTypeDecls(self)


    def cleanupProps(self):
        self.props.pop()


    def computeDecl(self, t :Type):
        pass




    def makeNative(self, bomaName, useNamespace=False):
        if bomaName in ['less', 'monostate', 'size_t', 'string', 'string_view', 'array', 'pair', 'tuple', 'vector', 'set', 'unordered_set', 'map', 'unordered_map', 'optional', 'variant']:
            return 'std::' + bomaName
        elif useNamespace and bomaName in self.types:
            bomaName = f'{self.P("namespace")}::{bomaName}'
        return bomaName.replace('.', '::')


    def makeNativeSubtype(self, properties, useNamespace=False):
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


    def makeNativeMemberType(self, properties, useNamespace=False):
        return self.makeNativeSubtype(utilities.dictify(properties, 'type'), useNamespace)


