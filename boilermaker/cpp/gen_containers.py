from .. import utilities
from functools import reduce

def genDeserializers(self, t, memo):
    if (not self.dIs('computeTypes') or
        not self.dIs('deserializeFromHumon')):
        return ''
    
    self._addInclude(f'{t.name}|typeHeaderLocalIncludes', 'containersHeader')

    for _, memberObj in t.members.items():
        src = self.gen_containers._genDeserializer(self, t, memberObj.properties, memo)


def _genDeserializer(self, t, mProps, memo):
    it = self.indent()
    endl = '\n'
    src = ''

    self._addInclude(f'{t.name}|typeHeaderIncludes', '<humon/humon.hpp>')

    declType = self.makeNativeMemberType(mProps, True)

    if declType in memo:
        return
    memo[declType] = None

    baseType = mProps['type']
    if baseType in ['array', 'pair', 'tuple', 'vector', 'set', 'unordered_set', 'map', 'unordered_map', 'optional', 'variant']:
        typeArgs = [utilities.dictify(a, 'type') for a in utilities.listify(mProps['of'])]

        for arg in typeArgs:
            self.gen_containers._genDeserializer(self, t, arg, memo)
        
        src = f'''

template <>
struct hu::val<{declType}>
{{
{it}static inline {declType} extract(hu::Node const & node)
{it}{{'''
      
        if baseType == 'array':
            argDeclType = self.makeNativeMemberType(typeArgs[0], True)
            numElems = int(typeArgs[1]['type'])
            src += f'''
{it}{it}return {declType} {{
{f",{endl}".join([f'{it}{it}{it}node / {i} % hu::val<{argDeclType}> {{}}' for i in range(0, numElems)])}
{it}{it}}};'''

        elif baseType == 'pair':
            ept0 = self.makeNativeMemberType(typeArgs[0], True)
            ept1 = self.makeNativeMemberType(typeArgs[1], True)
            src += f'''
{it}{it}return {declType} {{
{it}{it}{it}node / 0 % hu::val<{ept0}> {{ }},
{it}{it}{it}node / 1 % hu::val<{ept1}> {{ }}
{it}{it}}};'''

        elif baseType == 'tuple':
            epts = [self.makeNativeMemberType(typeArg, True) for typeArg in typeArgs]
            src += f'''
{it}{it}return {declType} {{
{f',{endl}'.join([f"{it}{it}{it}node / {i} % hu::val<{epts[i]}> {{ }}" for i in range(0, len(epts))])}
{it}{it}}};'''

        elif baseType == 'vector' or baseType == 'set' or baseType == 'unordered_set':
            elemPlatformType = self.makeNativeMemberType(typeArgs[0], True)
            src += f'''
{it}{it}{declType} rv;
{it}{it}for (size_t i = 0; i < node.numChildren(); ++i)
{it}{it}{{
{it}{it}{it}rv.emplace{'_back' if baseType == 'vector' else ''}(node / i % hu::val<{elemPlatformType}>{{}});
{it}{it}}}
{it}{it}return rv;'''

        elif baseType == 'map' or baseType == 'unordered_map':
            eptkey = self.makeNativeMemberType(typeArgs[0], True)
            eptvalue = self.makeNativeMemberType(typeArgs[1], True)
            src += f'''
{it}{it}{declType} rv;
{it}{it}for (size_t i = 0; i < node.numChildren(); ++i)
{it}{it}{{
{it}{it}{it}hu::Node elemNode = node / i;
{it}{it}{it}rv.emplace(std::move(hu::val<{eptkey}>::extract(elemNode.key().str())),
{it}{it}{it}           std::move(elemNode % hu::val<{eptvalue}>{{}}));
{it}{it}}}
{it}{it}return rv;'''

        elif baseType == 'optional':
            ept = self.makeNativeMemberType(typeArgs[0], True)
            src += f'''
{it}{it}if (! node)
{it}{it}{it}{{ return {{}}; }}
{it}{it}else if (node.kind() == NodeKind::value && node.value().str() == "_")
{it}{it}{it}{{ return {{}}; }}
{it}{it}else
{it}{it}{it}{{ return node % hu::val<{ept}>{{}}; }}'''

        elif baseType == 'variant':
            if self.d('nullVariant') == 'default':
                nullOperation = f'''return {{ }};'''
            else:
                nullOperation = f'''throw std::runtime_error("Variant could not be initialized.");'''
            src += f'''
{it}{it}Token tok = node.annotation("type");
{it}{it}if (! tok)
{it}{it}{it}{{ {nullOperation} }}
{it}{it}std::string_view tokStr = tok.str();'''

            for arg in typeArgs:
                arg = utilities.dictify(arg, 'type')
                argDecl = self.makeNativeMemberType(arg, True)
                alias = arg.get('alias')
                if not alias:
                    alias = arg.get('type')

                src += f'''
{it}{it}if (tokStr == "{alias}")
{it}{it}{it}{{ return node % hu::val<{argDecl}>{{}}; }}'''
            src += f'''
{it}{it}{nullOperation}'''

        src += f'''
{it}}}
}};'''
    
        self._appendToSection(f'{t.name}|containerDeserializerDefs', src)


def genSerializers(self, t, memo):
    if (not self.dIs('computeTypes') or
        not self.dIs('serializeToHumon')):
        return ''

    for _, memberObj in t.members.items():
        self.gen_containers._genSerializer(self, t, memberObj, memo)


def _genSerializer(self, t, m, memo):
    it = self.indent()

    def recurse(phase, memo, typeDict):
        memberDeclType = self.makeNativeMemberType(typeDict)
        if memberDeclType not in memo:
            memo[memberDeclType] = {phase: None}
        elif phase not in memo[memberDeclType]:
            memo[memberDeclType][phase] = None
        else:
            return ''

        baseType = typeDict['type']

        if baseType == 'size_t':
            self._addInclude(f'{t.name}|typeHeaderIncludes', '<cstddef>')
        elif baseType == 'string':
            self._addInclude(f'{t.name}|typeHeaderIncludes', '<string>')
        elif baseType == 'string_view':
            self._addInclude(f'{t.name}|typeHeaderIncludes', '<string_view>')
        
        # #include the inl for a StructType
        elif baseType in self.types:
            self._addInclude(f'{t.name}|typeHeaderLocalIncludes', f'{baseType}|typeHeader')

        # go until we are at a leaf node (no 'of' subtypes)
        if baseType not in ['array', 'pair', 'tuple', 'vector', 'set', 'unordered_set', 'map', 'unordered_map', 'optional', 'variant']:
            return ''

        if baseType == 'array':
            self._addInclude(f'{t.name}|typeHeaderIncludes', '<array>')
        elif baseType == 'pair':
            self._addInclude(f'{t.name}|typeHeaderIncludes', '<utility>')
        elif baseType == 'tuple':
            self._addInclude(f'{t.name}|typeHeaderIncludes', '<tuple>')
        elif baseType == 'vector':
            self._addInclude(f'{t.name}|typeHeaderIncludes', '<vector>')
        elif baseType == 'set':
            self._addInclude(f'{t.name}|typeHeaderIncludes', '<set>')
        elif baseType == 'unordered_set':
            self._addInclude(f'{t.name}|typeHeaderIncludes', '<unordered_set>')
        elif baseType == 'map':
            self._addInclude(f'{t.name}|typeHeaderIncludes', '<map>')
        elif baseType == 'unordered_map':
            self._addInclude(f'{t.name}|typeHeaderIncludes', '<unordered_map>')
        elif baseType == 'optional':
            self._addInclude(f'{t.name}|typeHeaderIncludes', '<optional>')
        elif baseType == 'variant':
            self._addInclude(f'{t.name}|typeHeaderIncludes', '<variant>')

        ofProps = typeDict.get('of')
        if ofProps:
            for prop in utilities.listify(ofProps):
                recurse(phase, memo, utilities.dictify(prop, 'type'))

        self.gen_containers._genCsBody(self, typeDict)

        return
    
    src = recurse('classDef', memo, m.properties)


def _genCsBody(self, typeDict):
    baseType = typeDict['type']
    if baseType == 'array':
        self.gen_containers.genSerializer_array(self)
    elif baseType == 'pair':
        self.gen_containers.genSerializer_pair(self)
    elif baseType == 'tuple':
        self.gen_containers.genSerializer_tuple(self)
    elif baseType == 'vector':
        self.gen_containers.genSerializer_vector(self)
    elif baseType == 'set':
        self.gen_containers.genSerializer_set(self)
    elif baseType == 'unordered_set':
        self.gen_containers.genSerializer_unordered_set(self)
    elif baseType == 'map':
        self.gen_containers.genSerializer_map(self)
    elif baseType == 'unordered_map':
        self.gen_containers.genSerializer_unordered_map(self)
    elif baseType == 'optional':
        self.gen_containers.genSerializer_optional(self)
    elif baseType == 'variant':
        self.gen_containers.genSerializer_variant(self)
        self.gen_containers.genVariantTypeNames(self, typeDict)


def genVariantTypeNames(self, typeDict):
    typeDecl = self.makeNativeSubtype(typeDict)
    if typeDecl in self.containersVariantTypeNames:
        return
    
    if len(self.containersVariantTypeNames) == 0:
        self.gen_containers.genVariantTypeNamesTemplate(self)
    
    self.containersVariantTypeNames[typeDecl] = None

    it = self.indent()

    subTypes = []
    for subDict in typeDict.get('of', []):
        subType = subDict.get('alias')
        if not subType:
            subType = subDict['type']
        subTypes.append(subType)

    src = f'''

{it}template <>
{it}struct VariantTypeNames<{typeDecl}>
{it}{{
{it}{it}static constexpr char const * names[] = {{ {', '.join([f'"{st}"' for st in subTypes])} }};
{it}{it}static constexpr std::size_t size = {len(subTypes)};
{it}}};'''
    self._appendToSection(f'containerSerializer_variantTypeNames', src)


def genVariantTypeNamesTemplate(self):
    it = self.indent()

    src = f'''

{it}template <class T>
{it}struct VariantTypeNames
{it}{{
{it}{it}static constexpr char const * names[] = {{ }};
{it}{it}static constexpr std::size_t size = 0;
{it}}};'''
    self._appendToSection(f'containerSerializer_variantTypeNames', src)


def genSerializer_array(self):
    if 'array' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['array'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<array>')

    self._appendToSection('containerSerializer_array', f'''

{it}template <class T, unsigned long N>
{it}std::ostream & operator << (std::ostream & out, std::array<T, N> const & obj)
{it}{{
{it}{it}out << "[ ";
{it}{it}for (std::size_t i = 0; i < N; ++i)
{it}{it}{{
{it}{it}{it}out << obj[i] << " ";
{it}{it}}}
{it}{it}out << "]";

{it}{it}return out;
{it}}}''')


def genSerializer_pair(self):
    if 'pair' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['pair'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<utility>')

    self._appendToSection('containerSerializer_pair', f'''

{it}template <class T0, class T1>
{it}std::ostream & operator << (std::ostream & out, std::pair<T0, T1> const & obj)
{it}{{
{it}{it}out << '[' << std::get<0>(obj) << ' ' << std::get<1>(obj) << ']';

{it}{it}return out;
{it}}}''')


def genSerializer_tuple(self):
    if 'tuple' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['tuple'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<tuple>')

    self._appendToSection('containerSerializer_tuple', f'''

{it}template <class... Ts>
{it}std::ostream & operator << (std::ostream & out, std::tuple<Ts...> const & obj)
{it}{{
{it}{it}out << "[ ";
{it}{it}apply(
{it}{it}{it}[](auto &&... args)
{it}{it}{it}{it}{{ ((std::cout << args << ' '), ...); }},
{it}{it}{it}obj);
{it}{it}out << "]";

{it}{it}return out;
{it}}}''')


def genSerializer_vector(self):
    if 'vector' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['vector'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<vector>')

    self._appendToSection('containerSerializer_vector', f'''

{it}template <class T>
{it}std::ostream & operator << (std::ostream & out, std::vector<T> const & obj)
{it}{{
{it}{it}out << "[ ";
{it}{it}for (auto const & elem : obj)
{it}{it}{{
{it}{it}{it}out << elem << ' ';
{it}{it}}}
{it}{it}out << ']';

{it}{it}return out;
{it}}}''')


def genSerializer_set(self):
    if 'set' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['set'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<set>')

    self._appendToSection('containerSerializer_set', f'''

{it}template <class T, class L>
{it}std::ostream & operator << (std::ostream & out, std::set<T, L> const & obj)
{it}{{
{it}{it}out << "[ ";
{it}{it}for (auto const & elem : obj)
{it}{it}{{
{it}{it}{it}out << elem << ' ';
{it}{it}}}
{it}{it}out << ']';

{it}{it}return out;
{it}}}''')


def genSerializer_unordered_set(self):
    if 'unordered_set' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['unordered_set'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<unordered_set>')

    self._appendToSection('containerSerializer_unordered_set', f'''

{it}template <class T, class H>
{it}std::ostream & operator << (std::ostream & out, std::unordered_set<T, H> const & obj)
{it}{{
{it}{it}out << "[ ";
{it}{it}for (auto const & elem : obj)
{it}{it}{{
{it}{it}{it}out << elem << ' ';
{it}{it}}}
{it}{it}out << ']';

{it}{it}return out;
{it}}}''')


def genSerializer_map(self):
    if 'map' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['map'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<map>')

    self._appendToSection('containerSerializer_map', f'''

{it}template <class K, class T, class L>
{it}std::ostream & operator << (std::ostream & out, std::map<K, T, L> const & obj)
{it}{{
{it}{it}out << "{{ ";
{it}{it}for (auto const & elem : obj)
{it}{it}{{
{it}{it}{it}out << elem.first << ": " << elem.second << ' ';
{it}{it}}}
{it}{it}out << '}}';

{it}{it}return out;
{it}}}''')


def genSerializer_unordered_map(self):
    if 'unordered_map' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['unordered_map'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<unordered_map>')

    self._appendToSection('containerSerializer_unordered_map', f'''

{it}template <class K, class T, class H>
{it}std::ostream & operator << (std::ostream & out, std::unordered_map<K, T, H> const & obj)
{it}{{
{it}{it}out << "{{ ";
{it}{it}for (auto const & elem : obj)
{it}{it}{{
{it}{it}{it}out << elem.first << ": " << elem.second << ' ';
{it}{it}}}
{it}{it}out << '}}';

{it}{it}return out;
{it}}}''')


def genSerializer_optional(self):
    if 'optional' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['optional'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<optional>')

    self._appendToSection('containerSerializer_optional', f'''

{it}template <class T>
{it}std::ostream & operator << (std::ostream & out, std::optional<T> const & obj)
{it}{{
{it}{it}if (obj.has_value())
{it}{it}{it}{{ out << * obj; }}
{it}{it}else
{it}{it}{it}{{ out << '_'; }}

{it}{it}return out;
{it}}}''')


def genSerializer_variant(self):
    if 'variant' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['variant'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<variant>')

    self._appendToSection('containerSerializer_variant', f'''

{it}template <class... Ts>
{it}std::ostream & operator << (std::ostream & out, std::variant<Ts...> const & obj)
{it}{{
{it}{it}constexpr auto const names =  VariantTypeNames<std::variant<Ts...>>::names;
{it}{it}
{it}{it}std::visit(
{it}{it}{it}[&](auto && o) 
{it}{it}{it}{it}{{ out << o << " @type: " << names[obj.index()] << " /* " << obj.index() << " */"; }},
{it}{it}{it}obj);

{it}{it}return out;
{it}}}''')


def genIsLessStructs(self, t):
    def visit(properties):
        name = properties['fullName']

        for ofo in properties.get('of', []):
            visit(ofo)

        lessCode = properties.get('isLess')
        if lessCode:
            self.gen_containers._genIsLessStruct(self, t, name, properties)


    for memberName, m in t.members.items():
        visit(m.properties)


def _genIsLessStruct(self, t, name, properties):
    it = self.indent()
    lessCode = properties.get('isLess')
    subtypeDecl = ''
    stype = properties.get('type')
    if stype == 'set' or stype == 'map':
        subtypeDecl = self.makeNativeSubtype(properties['of'][0])

    print (f'@@@@@@@ {name}: {subtypeDecl}: {lessCode}')
    src = f'''

{it}struct IsLess_{name}
{it}{{
{it}{it}bool operator()({self.const(subtypeDecl)} & lhs, {self.const(subtypeDecl)} & rhs) const
{it}{it}{{
{it}{it}{it}{lessCode}
{it}{it}}}
{it}}};'''
    self._appendToSection('isLessCode', src)

