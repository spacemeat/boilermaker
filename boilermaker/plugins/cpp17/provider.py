from pathlib import Path
import os
from ...plugin import Provider, PluginCollection
from ...props import Scribe
from ...type import Type, BomaSubtype
from ...enums import BomaEnumVal
from ...utilities import getRelativePath


class StandardType(Type):
    def __init__(self, name, namespace, declName, include, props):
        super().__init__(name, props)
        #self.namespace = namespace
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
        # TODO: Go through each type's props to get additional directories


    def generateProps(self):
        self.props.push()
        s = Scribe(self.props)

        self.props.setProp('scope', '')

        # namespace to file system
        def nsToFs(string):
            return string.replace('.', '/')
        self.props.setProp('nsToFs', nsToFs)

        # namespace to code
        def nsToCode(string):
            return string.replace('.', '::')
        self.props.setProp('nsToCode', nsToCode)

        # get relative path from a (dir) to b (file)
        self.props.setProp('getRelativePath', getRelativePath)

        # convenience function for namespace/scoping
        def rescope_old(type):
            # TODO: This is probably lousy perf
            s = Scribe(type.props)
            currentScope = s.getXProp('scope').split('::')
            fullName = type.fullCodeDecl.split('::')
            # find first n common names; the rest is the qualified name
            skip = 0
            for i in range(min(len(currentScope), len(fullName))):
                if currentScope[i] == fullName[i]:
                    skip += 1
                else:
                    break
            return '::'.join(fullName[skip:])

        # assetDb                       -> og::assetDb::assetDb
        # variant<vector<assetDb>, int> -> std::variant<std::vector<og::assetDb::assetDb>, int>
        def rescope(atype, currentScope=''):
            if currentScope == '':
                s = Scribe(atype.props)
                currentScope = s.getXProp('scope').split('::')
            fullName = ''
            if isinstance(atype, Type) or isinstance(atype, BomaEnumVal) or isinstance(atype, BomaSubtype):
                fullName = atype.fullCodeDecl.split('::')
            else:
                fullName = atype.split('::')
            skip = 0
            for i in range(min(len(currentScope), len(fullName))):
                if currentScope[i] == fullName[i]:
                    skip += 1
                else:
                    break
            name = '::'.join(fullName[skip:])
            if len(name) == 0:
                breakpoint()
            if getattr(atype, 'subtypes', False) and len(atype.subtypes) > 0:

                ofos = [rescope(ofo) for ofo in atype.subtypes]
                if atype.isLess:
                    cname = Scribe(atype.props).X('$sharedCodeNamespaceForCode') + f'::IsLess_{atype.name}'
                    scope = Scribe(atype.props).X('$scope')
                    ofos.insert(2, f'{rescope(cname, scope)}')

                name += '<' + ', '.join(ofos) + '>'
            return name
        self.props.setProp('rescope', rescope)

        bomaEnums = self.props.getProp('bomaEnums')
        self.props.setProp('enums', bomaEnums)

        bomaTypes = self.props.getProp('bomaTypes')
        self.props.setProp('types', bomaTypes)

        standardTypes = {
            'string':       StandardType('string',      'std', 'std::string',               '<string>',         self.props),
            'stringView':   StandardType('stringView',  'std', 'std::string_view',          '<string_view>',    self.props),
            'cstring':      StandardType('cstring',     'std', '',                          '<cstring>',        self.props),
            'array':        StandardType('array',       'std', 'std::array',                '<array>',          self.props),
            'pair':         StandardType('pair',        'std', 'std::pair',                 '<utility>',        self.props),
            'tuple':        StandardType('tuple',       'std', 'std::tuple',                '<tuple>',          self.props),
            'vector':       StandardType('vector',      'std', 'std::vector',               '<vector>',         self.props),
            'set':          StandardType('set',         'std', 'std::set',                  '<set>',            self.props),
            'unorderedSet': StandardType('unorderedSet','std', 'std::unordered_set',        '<unordered_set>',  self.props),
            'map':          StandardType('map',         'std', 'std::map',                  '<map>',            self.props),
            'unorderedMap': StandardType('unorderedMap','std', 'std::unordered_map',        '<unordered_map>',  self.props),
            'optional':     StandardType('optional',    'std', 'std::optional',             '<optional>',       self.props),
            'variant':      StandardType('variant',     'std', 'std::variant',              '<variant>',        self.props),
            'function':     StandardType('function',    'std', 'std::function',             '<functional>',     self.props)
                # TODO: multisdet, multimap, list, pmr things
        }

        allTypes = {**bomaTypes, **bomaEnums, **standardTypes}

        # compute C++ names for all types
        for _, t in allTypes.items():
            self.computeDecl(t)

        # compute translated names for enums that aren't already defined
        def computeDeclsForEnumVals(bomaEnum):
            s = Scribe(bomaEnum.props)
            ns = s.X('$namespaceForCode') + '::'
            #if bomaEnum.bomaEnum.hasCodeDefs:
            #    ns = bomaEnum.namespace.replace('.', '::')
            #if bomaEnum.name.find('Result') != -1:
            #    breakpoint()

            #breakpoint()
            for val in bomaEnum.bomaEnum.values:
                if not bomaEnum.bomaEnum.hasCodeDefs:
                    val.codeDecl = bomaEnum.translateEnumVal(val.name)
                val.fullCodeDecl = ns + val.codeDecl

        for e in bomaEnums.values():
            computeDeclsForEnumVals(e)

        # allow scribes to access $std.string.usedInBomaType, say
        class AllStandardObjects:
            def __init__(self):
                pass
        stdObj = AllStandardObjects()
        for k, v in standardTypes.items():
            setattr(stdObj, k, v)
        self.props.setProp('std', stdObj)

        # relative paths for local #includes
        # TODO: Retire these for more precise relpath using utility fn
        self.props.setProp('headerToInl',    os.path.relpath(s.X('$inlineDir'), s.X('$headerDir')))
        self.props.setProp('srcToHeader',    os.path.relpath(s.X('$headerDir'), s.X('$sourceDir')))
        self.props.setProp('srcToInl',       os.path.relpath(s.X('$inlineDir'), s.X('$sourceDir')))

        # convenience function for $const
        def const(decl):
            s = Scribe(self.props)
            return f'{decl} const' if s.X('$constStyle') == 'east' else f'const {decl}'
        self.props.setProp('const', const)

        headers = list()
        allEnumHeaders = list()

        enumDeserializeFrom = set()
        enumSerializeTo = set()
        enumDiffable = False
        for enumType in bomaEnums.values():
            s = Scribe(enumType.props)
            enumDeserializeFrom.update(enumType.props.getProp('deserializeFrom'))
            enumSerializeTo.update(enumType.props.getProp('serializeTo'))
            enumDiffable = enumDiffable or enumType.props.getProp('diffable')

        #breakpoint()
        anyDeserializeFrom = set(enumDeserializeFrom)
        anySerializeTo = set(enumSerializeTo)
        anyDiffable = enumDiffable
        for bomaType in bomaTypes.values():
            s = Scribe(bomaType.props)

            anyDeserializeFrom.update(bomaType.props.getProp('deserializeFrom'))
            anySerializeTo.update(bomaType.props.getProp('serializeTo'))
            anyDiffable = anyDiffable or (bomaType.props.getProp('diffable'))

            # binary reader for std::string needs std::memcpy
            if ('binary' in bomaType.props.getProp('deserializeFrom') and
                stdObj.string.usedInBomaType):
                stdObj.cstring.usedInBomaType = True

            # humon reader for enums needs std::strncmp
            if ('humon' in bomaType.props.getProp('deserializeFrom') and
                len(self.props.getProp('enums')) > 0):
                stdObj.cstring.usedInBomaType = True

            # binary ready for std::variant needs std::optional
            if ('binary' in bomaType.props.getProp('deserializeFrom') and
                stdObj.variant.usedInBomaType):
                stdObj.optional.usedInBomaType = True

            if len(bomaType.props.getProp('caveperson') or []) > 0:
                headers.append('<iostream>')

            if ('humon' in s.X('$deserializeFrom') or
                'humon' in s.X('$serializeTo')):
                headers.append('<humon/humon.hpp>')

            for bomaEnum in bomaEnums.values():
                enumHeaders = list()
                if bomaEnum.alreadyDefined:
                    pass
                    #for inc in bomaEnum.bomaEnum.include:
                    #    enumHeaders.append(inc)
                else:
                    bomaEnum.include = [s.X('$enumsHeaderFile')]
                bomaEnum.dependencyIncludes = list(enumHeaders)
                allEnumHeaders.extend(enumHeaders)
            if len(allEnumHeaders) > 0:
                if 'humon' in bomaType.props.getProp('deserializeFrom'):
                    allEnumHeaders.append('<cstring>')
                #headers.append(f'"{s.getXProp("enumsHeaderFile")}"')

        self.props.setProp('enumHeaderIncludes', list(dict.fromkeys(allEnumHeaders)))
        self.props.setProp('enumDeserializeFrom', list(enumDeserializeFrom))
        self.props.setProp('enumSerializeTo', list(enumSerializeTo))
        self.props.setProp('enumDiffable', enumDiffable)
        self.props.setProp('anyDeserializeFrom', list(anyDeserializeFrom))
        self.props.setProp('anySerializeTo', list(anySerializeTo))
        self.props.setProp('anyDiffable', anyDiffable)

        for bomaType in bomaTypes.values():
            if bomaType.alreadyDefined == False:
                self.props.push({'t': bomaType})
                bomaType.include = [s.X('$typeHeaderFile')]
                self.props.pop()

        for bomaType in bomaTypes.values():
            typeHeaders = list()
            for knownTypeName in bomaType.knows:
                if knownTypeName in bomaEnums:
                    knownType = bomaEnums[knownTypeName]
                    for inc in knownType.include:
                        if inc[0] == '<':
                            typeHeaders.append(inc)
                        else:
                            typeHeaders.append('"' + getRelativePath(Path(Scribe(bomaType.props).getXProp('headerDir')), Path(Scribe(knownType.props).getXProp('sharedCodeHeaderDir')) / inc) + '"')
                elif knownTypeName in bomaTypes:
                    #breakpoint()
                    knownType = bomaTypes[knownTypeName]
                    for inc in knownType.include:
                        if inc[0] == '<':
                            typeHeaders.append(inc)
                        else:
                            typeHeaders.append('"' + getRelativePath(Path(Scribe(bomaType.props).getXProp('headerDir')), Path(Scribe(knownType.props).getXProp('headerDir')) / inc) + '"')

            subtypes = bomaType.allSubtypes()
            for st in subtypes:
                eo = bomaEnums.get(st.type)
                if eo:
                    eo.usedInBomaType = True
                    for inc in eo.bomaEnum.include:
                        if inc[0] == '<':
                            typeHeaders.append(inc)
                        else:
                            typeHeaders.append('"' + getRelativePath(Path(Scribe(bomaType.props).getXProp('headerDir')), Path(s.getXProp('sharedCodeHeaderDir')) / inc) + '"')
                else:
                    to = bomaTypes.get(st.type)
                    if to:
                        to.usedInBomaType = True
                        for inc in to.include:
                            if inc[0] == '<':
                                typeHeaders.append(inc)
                            else:
                                typeHeaders.append('"' + getRelativePath(Path(Scribe(bomaType.props).getXProp('headerDir')), Path(Scribe(to.props).getXProp('headerDir')) / inc) + '"')
                    else:
                        so = standardTypes.get(st.type)
                        if so:
                            so.usedInBomaType = True
                            for inc in so.include:
                                typeHeaders.append(inc)
            bomaType.dependencyIncludes = list(dict.fromkeys(typeHeaders))

        for stdType in standardTypes.values():
            for inc in stdType.include:
                if stdType.usedInBomaType:
                    headers.append(inc)

        incses = s.getXProp('include')
        if type(incses) is not list:
            incses = [incses]
        for beType in [*bomaTypes.values(), *bomaEnums.values()]:
            s = Scribe(beType.props)
            incs = s.getXProp('include')
            if type(incs) is not list:
                incs = [incs]
            for inc in incs:
                incses.append(inc)
        incses = list(dict.fromkeys(incses))
        projectDir = Path(s.X('$projectDir'))
        headerDir = Path(s.X('$headerDir'))
        for inc in incses:
            if not inc:
                continue
            angled = False
            if inc[0] == '"':
                inc = inc[1:-1]
            elif inc[0] == '<':
                angled = True
                inc = inc[1:-1]
            inc = getRelativePath(headerDir, projectDir / inc)
            if not angled:
                inc = f'"{inc}"'
            elif angled:
                inc = f'<{inc}>'
            headers.append(inc)

        self.props.setProp('commonHeaderIncludes', list(dict.fromkeys(headers)))

        fwds = list()
        for typeName, bomaType in bomaTypes.items():
            subtypes = bomaType.allSubtypesOfIsLessTypes()
            subtypes = [st.type for st in subtypes if st.type in bomaTypes]
            fwds.extend(subtypes)
        self.props.setProp('commonHeaderFwdDecls', list(dict.fromkeys(fwds)))

        def computeCodeDecls_rec(subtype):
            subtype.codeDecl = subtype.type.replace('.', '::')
            if subtype.type in standardTypes:
                subtype.codeDecl = standardTypes[subtype.type].codeDecl
            elif subtype.type in bomaEnums:
                subtype.codeDecl = bomaEnums[subtype.type].codeDecl
            if subtype.subtypes:
                if subtype.type in bomaTypes:
                    subtype.codeDecl = bomaTypes[subtype.type].codeDecl
                templateArgs = [computeCodeDecls_rec(st) for st in subtype.subtypes]
                if subtype.isLess:
                    templateArgs.insert(2, f'IsLess_{subtype.name}')
                subtype.codeDeclWithTemplateArgs = subtype.codeDecl + '<' + ', '.join(templateArgs) + '>'
                return subtype.codeDeclWithTemplateArgs
            else:
                return subtype.codeDecl

        def computeFullCodeDecls_rec(subtype):
            subtype.fullCodeDecl = subtype.type.replace('.', '::')
            if subtype.type in standardTypes:
                subtype.fullCodeDecl = standardTypes[subtype.type].fullCodeDecl
            elif subtype.type in bomaEnums:
                subtype.fullCodeDecl = bomaEnums[subtype.type].fullCodeDecl
            elif subtype.type in bomaTypes:
                subtype.fullCodeDecl = bomaTypes[subtype.type].fullCodeDecl
            if subtype.subtypes:
                templateArgs = [computeFullCodeDecls_rec(st) for st in subtype.subtypes]
                if subtype.isLess:
                    templateArgs.insert(2, f'IsLess_{subtype.name}')
                subtype.fullCodeDeclWithTemplateArgs = subtype.fullCodeDecl + '<' + ', '.join(templateArgs) + '>'
                return subtype.fullCodeDeclWithTemplateArgs
            else:
                return subtype.fullCodeDecl

        def computeFullCodeDecls_rec_old(subtype, parentDecl):
            fcd = parentDecl + '::' + subtype.codeDecl
            subtype.fullCodeDecl = fcd
            for st in subtype.subtypes:
                computeFullCodeDecls_rec_old(st, fcd)

        for t in bomaTypes.values():
            for m in t.members.values():
                computeCodeDecls_rec(m.type)
                computeFullCodeDecls_rec(m.type)

        for bomaType in bomaTypes.values():
            for member in bomaType.members.values():
                member.makeDefaulValue(bomaEnums)

        needVariantTypeNamesBase = False
        for t in bomaTypes.values():
            if len(t.allVariantSubtypes()) > 0:
                needVariantTypeNamesBase = True
        self.props.setProp('needVariantTypeNamesBase', needVariantTypeNamesBase)


    def computeDecl(self, t :Type):
        if not t.alreadyDefined:
            t.codeDecl = t.name.replace('.', '::')
        s = Scribe(t.props)
        #if t.name == "VkResult":
        #    breakpoint()
        t.fullCodeDecl = s.getXProp('namespaceForCode') + '::' + t.codeDecl
