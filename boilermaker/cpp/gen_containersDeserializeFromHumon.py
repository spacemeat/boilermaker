def gen_builtIn(self):
    self._addInclude('containersIncludes', '<iostream>')
    it = self.indent()


def gen_array(self):
    if 'humon|array' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|array'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<array>')

    self._appendToSection('containerDeserializer_array', f'''

{it}template <class T, unsigned long N>
{it}struct hu::val<std::array<T, N>> const & obj)
{it}{{
{it}{it}static inline std::array<T, N> extract(hu::Node const & node)
{it}{it}{{
{it}{it}{it}auto maker = [&node]<std::size_t... Seq>(std::index_sequence<Seq...>)
{it}{it}{it}{{
{it}{it}{it}{it}return std::array<T, N> {{ node / Seq % hu::val<T> {{ }}... }};
{it}{it}{it}}};

{it}{it}{it}return maker(std::make_index_sequence<N> {{}});
{it}{it}}}
{it}}}''')

# Just did: awesome array thing
#  Next: pair, etc.

def gen_pair(self):
    if 'humon|pair' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|pair'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<utility>')

    self._appendToSection('containerDeserializer_pair', f'''

{it}template <class T0, class T1>
{it}struct hu::val<std::pair<T0, T1>> const & obj)
{it}{{
{it}{it}static inline std::pair<T0, T1> extract(hu::Node const & node)
{it}{it}{{
{it}{it}{it}return {{
{it}{it}{it}{it}node / 0 % hu::val<T0> {{ }},
{it}{it}{it}{it}node / 1 % hu::val<T1> {{ }}
{it}{it}{it}}};
{it}{it}}}
{it}}}''')


def gen_tuple(self):
    if 'humon|tuple' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|tuple'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<tuple>')

    self._appendToSection('containerDeserializer_tuple', f'''

{it}template <class... Ts>
{it}struct hu::val<std::tuple<Ts...>> const & obj)
{it}{{
{it}{it}static inline std::tuple<Ts...> extract(hu::Node const & node)
{it}{it}{{
{it}{it}{it}auto maker = [&node]<std::size_t... Seq>(std::index_sequence<Seq...>)
{it}{it}{it}{{
{it}{it}{it}{it}return std::tuple<Ts...> {{ node / Seq % hu::val<Ts> {{ }}... }};
{it}{it}{it}}};

{it}{it}{it}return maker(std::make_index_sequence<sizeof...(Ts)> {{ }});
{it}{it}}}
{it}}}''')


def gen_vector(self):
    if 'humon|vector' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|vector'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<vector>')

    self._appendToSection('containerDeserializer_vector', f'''

{it}template <class T, class A>
{it}struct hu::val<std::vector<T, A> const & obj)
{it}{{
{it}{it}static inline std::vector<T, A> extract(hu::Node const & node)
{it}{it}{{
{it}{it}{it}std::vector<T, A> rv;
{it}{it}{it}for (size_t i = 0; i < node.numChildren(); ++i)
{it}{it}{it}{{
{it}{it}{it}{it}rv.emplace_back(node / i % hu::val<T> {{ }} );
{it}{it}{it}}}
{it}{it}{it}return rv;
{it}{it}}}
{it}}}''')


def gen_set(self):
    if 'humon|set' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|set'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<set>')

    self._appendToSection('containerDeserializer_set', f'''

{it}template <class K, class C, class A>
{it}struct hu::val<std::set<K, C, A> const & obj)
{it}{{
{it}{it}static inline std::set<K, C, A> extract(hu::Node const & node)
{it}{it}{{
{it}{it}{it}std::set<K, C, A> rv;
{it}{it}{it}for (size_t i = 0; i < node.numChildren(); ++i)
{it}{it}{it}{{
{it}{it}{it}{it}rv.emplace(node / i % hu::val<T> {{ }} );
{it}{it}{it}}}
{it}{it}{it}return rv;
{it}{it}}}
{it}}}''')


def gen_unordered_set(self):
    if 'humon|unordered_set' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|unordered_set'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<unordered_set>')

    self._appendToSection('containerDeserializer_unordered_set', f'''

{it}template <class K, class H, class E, class A>
{it}struct hu::val<std::unordered_set<K, H, E, A> const & obj)
{it}{{
{it}{it}static inline std::unordered_set<K, H, E, A> extract(hu::Node const & node)
{it}{it}{{
{it}{it}{it}std::unordered_set<K, H, E, A> rv;
{it}{it}{it}for (size_t i = 0; i < node.numChildren(); ++i)
{it}{it}{it}{{
{it}{it}{it}{it}rv.emplace(node / i % hu::val<T> {{ }} );
{it}{it}{it}}}
{it}{it}{it}return rv;
{it}{it}}}
{it}}}''')


def gen_map(self):
    if 'humon|map' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|map'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<map>')

    self._appendToSection('containerDeserializer_map', f'''

{it}template <class K, class T, class C, class A>
{it}struct hu::val<std::map<K, T, C, A> const & obj)
{it}{{
{it}{it}static inline std::map<K, T, C, A> extract(hu::Node const & node)
{it}{it}{{
{it}{it}{it}std::map<K, T, C, A> rv;
{it}{it}{it}for (size_t i = 0; i < node.numChildren(); ++i)
{it}{it}{it}{{
{it}{it}{it}{it}hu::Node elemNode = node / i;
{it}{it}{it}{it}rv.emplace(std::move(hu::val<K>::extract(elemNode.key().str())),
{it}{it}{it}{it}           std::move(elemNode i % hu::val<T> {{ }} ));
{it}{it}{it}}}
{it}{it}{it}return rv;
{it}{it}}}
{it}}}''')


def gen_unordered_map(self):
    if 'humon|unordered_map' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|unordered_map'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<unordered_map>')

    self._appendToSection('containerDeserializer_unordered_map', f'''

{it}template <class K, class T, class H, class E, class A>
{it}struct hu::val<std::unordered_map<K, T, H, E, A> const & obj)
{it}{{
{it}{it}static inline std::unordered_map<K, T, H, E, A> extract(hu::Node const & node)
{it}{it}{{
{it}{it}{it}std::unordered_map<K, T, H, E, A> rv;
{it}{it}{it}for (size_t i = 0; i < node.numChildren(); ++i)
{it}{it}{it}{{
{it}{it}{it}{it}hu::Node elemNode = node / i;
{it}{it}{it}{it}rv.emplace(std::move(hu::val<K>::extract(elemNode.key().str())),
{it}{it}{it}{it}           std::move(elemNode i % hu::val<T> {{ }} ));
{it}{it}{it}}}
{it}{it}{it}return rv;
{it}{it}}}
{it}}}''')


def gen_optional(self):
    if 'humon|optional' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|optional'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<optional>')

    self._appendToSection('containerDeserializer_optional', f'''

{it}template <class T>
{it}struct hu::val<std::optional<T> const & obj)
{it}{{
{it}{it}static inline std::optional<T> extract(hu::Node const & node)
{it}{it}{{
{it}{it}{it}if (! node)
{it}{it}{it}{it}{{ return {{ }}; }}
{it}{it}{it}else if (node.kind() == NodeKind::value && node.value().str() == "_")
{it}{it}{it}{it}{{ return {{ }}; }}
{it}{it}{it}else
{it}{it}{it}{it}{{ return node % hu::val<T>{{}}; }}
{it}{it}}}
{it}}}''')


def gen_variant(self):
    if 'humon|variant' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|variant'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<variant>')

    self._appendToSection('containerDeserializer_variant', f'''

{it}template <class... Ts>
{it}struct hu::val<std::variant<Ts...> const & obj)
{it}{{
{it}{it}template <std::size_t I>
{it}{it}static inline bool schecker(std::string_view tokStr, char ** names, std::optional<std::variant<Ts...>> & obj, hu::Node const & node)
{it}{it}{{
{it}{it}{it}if (obj.has_value() == false && tokStr == names[I]) 
{it}{it}{it}{{
{it}{it}{it}{it}obj = std::variant<Ts...> {{ std::in_place_index<I>, node }};
{it}{it}    }}
{it}{it}    return true;
{it}{it}}};

{it}{it}static inline std::variant<Ts...> extract(hu::Node const & node)
{it}{it}{{
{it}{it}{it}Token tok = node.annotation("type");
{it}{it}{it}if (! tok)
{it}{it}{it}{it}{{ return {{ }}; }}
{it}{it}{it}auto tokStr = tok.str();
{it}{it}{it}auto names = VariantTypeNames<std::variant<Ts...>>::names;

{it}{it}{it}auto maker = [&]<std::size_t... Seq>(std::index_sequence<Seq...>)
{it}{it}{it}{{
{it}{it}{it}{it}std::optional<std::variant<Ts...>> v;
{it}{it}{it}{it}auto foo = {{ schecker<Seq>(tokStr, names, v, node)... }};
{it}{it}{it}{it}return *v;
{it}{it}{it}}};
{it}{it}{it}return maker(std::make_index_sequence<sizeof...(Ts)> {{ }});
{it}{it}}}
{it}}}''')





def genVariantTypeNames(self, typeDict):
    typeDecl = self.makeNativeSubtype(typeDict)
    if typeDecl in self.containersVariantTypeNames:
        return
    
    if len(self.containersVariantTypeNames) == 0:
        self.gen_containersSerializeToHumon.genVariantTypeNamesTemplate(self)
    
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
    self._appendToSection(f'containerDeserializer_variantTypeNames', src)


def genVariantTypeNamesTemplate(self):
    it = self.indent()

    src = f'''

{it}template <class T>
{it}struct VariantTypeNames
{it}{{
{it}{it}static constexpr char const * names[] = {{ }};
{it}{it}static constexpr std::size_t size = 0;
{it}}};'''
    self._appendToSection(f'containerDeserializer_variantTypeNames', src)
