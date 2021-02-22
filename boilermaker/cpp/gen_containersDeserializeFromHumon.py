def gen_builtIn(self):
    self._addInclude('containersIncludes', '<iostream>')
    it = self.indent()


def gen_array(self):
    if 'humon|array' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|array'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<array>')

    self._appendToSection('containerDerializer_array', f'''

{it}template <class T, unsigned long N>
{it}struct hu::val<std::array<T, N>> const & obj)
{it}{{
{it}{it}static inline std::array<T, N> extract(hu::Node const & node)
{it}{it}{{
{it}{it}{it}auto maker = [&node]<std::size_t... Seq>(std::index_sequence<Seq...>)
{it}{it}{it}{{
{it}{it}{it}{it}return std::array<T, N> {{ node / Seq % hu::val<T>...}};
{it}{it}{it}}};

{it}{it}{it}return maker(std::make_index_sequence<N> {{}});
{it}{it}}}
{it}{it}out << "]";

{it}{it}return out;
{it}}}''')

# Just did: awesome array thing
#  Next: pair, etc.

def gen_pair(self):
    if 'humon|pair' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|pair'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<utility>')

    self._appendToSection('containerSerializer_pair', f'''

{it}template <class T0, class T1>
{it}std::ostream & operator << (std::ostream & out, HumonFormat<std::pair<T0, T1>> const & obj)
{it}{{
{it}{it}out << '[' << HumonFormat(std::get<0>(* obj)) << ' ' << HumonFormat(std::get<1>(* obj)) << ']';

{it}{it}return out;
{it}}}''')


def gen_tuple(self):
    if 'humon|tuple' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|tuple'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<tuple>')

    self._appendToSection('containerSerializer_tuple', f'''

{it}template <class... Ts>
{it}std::ostream & operator << (std::ostream & out, HumonFormat<std::tuple<Ts...>> const & obj)
{it}{{
{it}{it}out << "[ ";
{it}{it}apply(
{it}{it}{it}[](auto &&... args)
{it}{it}{it}{it}{{ ((std::cout << HumonFormat(args) << ' '), ...); }},
{it}{it}{it}* obj);
{it}{it}out << "]";

{it}{it}return out;
{it}}}''')


def gen_vector(self):
    if 'humon|vector' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|vector'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<vector>')

    self._appendToSection('containerSerializer_vector', f'''

{it}template <class T, class A>
{it}std::ostream & operator << (std::ostream & out, HumonFormat<std::vector<T, A>> const & obj)
{it}{{
{it}{it}out << "[ ";
{it}{it}for (auto const & elem : * obj)
{it}{it}{{
{it}{it}{it}out << HumonFormat(elem) << ' ';
{it}{it}}}
{it}{it}out << ']';

{it}{it}return out;
{it}}}''')


def gen_set(self):
    if 'humon|set' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|set'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<set>')

    self._appendToSection('containerSerializer_set', f'''

{it}template <class K, class C, class A>
{it}std::ostream & operator << (std::ostream & out, HumonFormat<std::set<K, C, A>> const & obj)
{it}{{
{it}{it}out << "[ ";
{it}{it}for (auto const & elem : * obj)
{it}{it}{{
{it}{it}{it}out << HumonFormat(elem) << ' ';
{it}{it}}}
{it}{it}out << ']';

{it}{it}return out;
{it}}}''')


def gen_unordered_set(self):
    if 'humon|unordered_set' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|unordered_set'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<unordered_set>')

    self._appendToSection('containerSerializer_unordered_set', f'''

{it}template <class K, class H, class E, class A>
{it}std::ostream & operator << (std::ostream & out, HumonFormat<std::unordered_set<K, H, E, A>> const & obj)
{it}{{
{it}{it}out << "[ ";
{it}{it}for (auto const & elem : * obj)
{it}{it}{{
{it}{it}{it}out << HumonFormat(elem) << ' ';
{it}{it}}}
{it}{it}out << ']';

{it}{it}return out;
{it}}}''')


def gen_map(self):
    if 'humon|map' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|map'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<map>')

    self._appendToSection('containerSerializer_map', f'''

{it}template <class K, class T, class C, class A>
{it}std::ostream & operator << (std::ostream & out, HumonFormat<std::map<K, T, C, A>> const & obj)
{it}{{
{it}{it}out << "{{ ";
{it}{it}for (auto const & elem : * obj)
{it}{it}{{
{it}{it}{it}out << HumonFormat(elem.first) << ": " << HumonFormat(elem.second) << ' ';
{it}{it}}}
{it}{it}out << '}}';

{it}{it}return out;
{it}}}''')


def gen_unordered_map(self):
    if 'humon|unordered_map' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|unordered_map'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<unordered_map>')

    self._appendToSection('containerSerializer_unordered_map', f'''

{it}template <class K, class T, class H, class E, class A>
{it}std::ostream & operator << (std::ostream & out, HumonFormat<std::unordered_map<K, T, H, E, A>> const & obj)
{it}{{
{it}{it}out << "{{ ";
{it}{it}for (auto const & elem : * obj)
{it}{it}{{
{it}{it}{it}out << HumonFormat(elem.first) << ": " << HumonFormat(elem.second) << ' ';
{it}{it}}}
{it}{it}out << '}}';

{it}{it}return out;
{it}}}''')


def gen_optional(self):
    if 'humon|optional' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|optional'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<optional>')

    self._appendToSection('containerSerializer_optional', f'''

{it}template <class T>
{it}std::ostream & operator << (std::ostream & out, HumonFormat<std::optional<T>> const & obj)
{it}{{
{it}{it}if (obj->has_value())
{it}{it}{it}{{ out << HumonFormat(** obj); }}
{it}{it}else
{it}{it}{it}{{ out << '_'; }}

{it}{it}return out;
{it}}}''')


def gen_variant(self):
    if 'humon|variant' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|variant'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<variant>')

    self._appendToSection('containerSerializer_variant', f'''

{it}template <class... Ts>
{it}std::ostream & operator << (std::ostream & out, HumonFormat<std::variant<Ts...>> const & obj)
{it}{{
{it}{it}constexpr auto const names =  VariantTypeNames<std::variant<Ts...>>::names;
{it}{it}
{it}{it}std::visit(
{it}{it}{it}[&](auto && o) 
{it}{it}{it}{it}{{ out << HumonFormat(o) << " @type: " << names[obj->index()] << " /* " << obj->index() << " */"; }},
{it}{it}{it}* obj);

{it}{it}return out;
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
