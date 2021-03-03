def gen_builtIn(self):
    if 'binary|builtIn' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['binary|builtIn'] = None

    self.includeForType('deserializerFormatWrappersDecl', 'istream', '#include <iostream>')

    it = self.indent()
    src = f'''

{it}template <class T>
{it}struct BinaryReader
{it}{{
{it}{it}static inline T extract(std::istream & in)
{it}{it}{{
{it}{it}{it}T t;
{it}{it}{it}in.read(reinterpret_cast<char *>(& t), sizeof(T));
{it}{it}{it}return t;
{it}{it}}}
{it}}};'''
    self.appendSrc('deserializerFormatWrapperBase', src)
    # TODO: Specializations for string, string_view


def gen_array(self):
    if 'binary|array' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['binary|array'] = None

    it = self.indent()

    self.includeForType('binary|deserializersDecl', 'array', '#include <array>')

    self.appendSrc('binary|deserializersDecl', f'''

{it}template <class T, unsigned long N>
{it}struct BinaryReader<std::array<T, N>>
{it}{{
{it}{it}static inline std::array<T, N> extract(std::istream & in)
{it}{it}{{
{it}{it}{it}auto maker = [&]<std::size_t... Seq>(std::index_sequence<Seq...>)
{it}{it}{it}{{
{it}{it}{it}{it}return std::array<T, N> {{ ((void) Seq, BinaryReader<T>::extract(in))... }};
{it}{it}{it}}};

{it}{it}{it}return maker(std::make_index_sequence<N> {{}});
{it}{it}}}
{it}}};''')


def gen_pair(self):
    if 'binary|pair' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['binary|pair'] = None

    it = self.indent()

    self.includeForType('binary|deserializersDecl', 'pair', '#include <utility>')

    self.appendSrc('binary|deserializersDecl', f'''

{it}template <class T0, class T1>
{it}struct BinaryReader<std::pair<T0, T1>>
{it}{{
{it}{it}static inline std::pair<T0, T1> extract(std::istream & in)
{it}{it}{{
{it}{it}{it}return {{
{it}{it}{it}{it}BinaryReader<T0>::extract(in),
{it}{it}{it}{it}BinaryReader<T1>::extract(in)
{it}{it}{it}}};
{it}{it}}}
{it}}};''')


def gen_tuple(self):
    if 'binary|tuple' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['binary|tuple'] = None

    it = self.indent()

    self.includeForType('binary|deserializersDecl', 'tuple', '#include <tuple>')

    self.appendSrc('binary|deserializersDecl', f'''

{it}template <class... Ts>
{it}struct BinaryReader<std::tuple<Ts...>>
{it}{{
{it}{it}static inline std::tuple<Ts...> extract(std::istream & in)
{it}{it}{{
{it}{it}{it}auto maker = [&]<std::size_t... Seq>(std::index_sequence<Seq...>)
{it}{it}{it}{{
{it}{it}{it}{it}return std::tuple<Ts...> {{ ((void) Seq, BinaryReader<Ts>::extract(in))... }};
{it}{it}{it}}};

{it}{it}{it}return maker(std::make_index_sequence<sizeof...(Ts)> {{ }});
{it}{it}}}
{it}}};''')


def gen_vector(self):
    if 'binary|vector' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['binary|vector'] = None

    it = self.indent()

    self.includeForType('binary|deserializersDecl', 'vector', '#include <vector>')

    self.appendSrc('binary|deserializersDecl', f'''

{it}template <class T, class A>
{it}struct BinaryReader<std::vector<T, A>>
{it}{{
{it}{it}static inline std::vector<T, A> extract(std::istream & in)
{it}{it}{{
{it}{it}{it}std::vector<T, A> rv;
{it}{it}{it}auto count = BinaryReader<std::size_t>::extract(in);
{it}{it}{it}for (size_t i = 0; i < count; ++i)
{it}{it}{it}{{
{it}{it}{it}{it}rv.emplace_back(BinaryReader<T>::extract(in));
{it}{it}{it}}}
{it}{it}{it}return rv;
{it}{it}}}
{it}}};''')


def gen_set(self):
    if 'binary|set' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['binary|set'] = None

    it = self.indent()

    self.includeForType('binary|deserializersDecl', 'set', '#include <set>')

    self.appendSrc('binary|deserializersDecl', f'''

{it}template <class K, class C, class A>
{it}struct BinaryReader<std::set<K, C, A>>
{it}{{
{it}{it}static inline std::set<K, C, A> extract(std::istream & in)
{it}{it}{{
{it}{it}{it}std::set<K, C, A> rv;
{it}{it}{it}auto count = BinaryReader<std::size_t>::extract(in);
{it}{it}{it}for (size_t i = 0; i < count; ++i)
{it}{it}{it}{{
{it}{it}{it}{it}rv.emplace(BinaryReader<K>::extract(in));
{it}{it}{it}}}
{it}{it}{it}return rv;
{it}{it}}}
{it}}};''')


def gen_unordered_set(self):
    if 'binary|unordered_set' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['binary|unordered_set'] = None

    it = self.indent()

    self.includeForType('binary|deserializersDecl', 'unordered_set', '#include <unordered_set>')

    self.appendSrc('binary|deserializersDecl', f'''

{it}template <class K, class H, class E, class A>
{it}struct BinaryReader<std::unordered_set<K, H, E, A>>
{it}{{
{it}{it}static inline std::unordered_set<K, H, E, A> extract(std::istream & in)
{it}{it}{{
{it}{it}{it}std::unordered_set<K, H, E, A> rv;
{it}{it}{it}auto count = BinaryReader<std::size_t>::extract(in);
{it}{it}{it}for (size_t i = 0; i < count; ++i)
{it}{it}{it}{{
{it}{it}{it}{it}rv.emplace(BinaryReader<K>::extract(in));
{it}{it}{it}}}
{it}{it}{it}return rv;
{it}{it}}}
{it}}};''')


def gen_map(self):
    if 'binary|map' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['binary|map'] = None

    it = self.indent()

    self.includeForType('binary|deserializersDecl', 'map', '#include <map>')

    self.appendSrc('binary|deserializersDecl', f'''

{it}template <class K, class T, class C, class A>
{it}struct BinaryReader<std::map<K, T, C, A>>
{it}{{
{it}{it}static inline std::map<K, T, C, A> extract(std::istream & in)
{it}{it}{{
{it}{it}{it}std::map<K, T, C, A> rv;
{it}{it}{it}auto count = BinaryReader<std::size_t>::extract(in);
{it}{it}{it}for (size_t i = 0; i < count; ++i)
{it}{it}{it}{{
{it}{it}{it}{it}rv.emplace(BinaryReader<K>::extract(in),
{it}{it}{it}{it}           BinaryReader<T>::extract(in));
{it}{it}{it}}}
{it}{it}{it}return rv;
{it}{it}}}
{it}}};''')


def gen_unordered_map(self):
    if 'binary|unordered_map' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['binary|unordered_map'] = None

    it = self.indent()

    self.includeForType('binary|deserializersDecl', 'unordered_map', '#include <unordered_map>')

    self.appendSrc('binary|deserializersDecl', f'''

{it}template <class K, class T, class H, class E, class A>
{it}struct BinaryReader<std::unordered_map<K, T, H, E, A>>
{it}{{
{it}{it}static inline std::unordered_map<K, T, H, E, A> extract(std::istream & in)
{it}{it}{{
{it}{it}{it}std::unordered_map<K, T, H, E, A> rv;
{it}{it}{it}auto count = BinaryReader<std::size_t>::extract(in);
{it}{it}{it}for (size_t i = 0; i < count; ++i)
{it}{it}{it}{{
{it}{it}{it}{it}rv.emplace(BinaryReader<K>::extract(in),
{it}{it}{it}{it}           BinaryReader<T>::extract(in));
{it}{it}{it}}}
{it}{it}{it}return rv;
{it}{it}}}
{it}}};''')


def gen_optional(self):
    if 'binary|optional' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['binary|optional'] = None

    it = self.indent()

    self.includeForType('binary|deserializersDecl', 'optional', '#include <optional>')

    self.appendSrc('binary|deserializersDecl', f'''

{it}template <class T>
{it}struct BinaryReader<std::optional<T>>
{it}{{
{it}{it}static inline std::optional<T> extract(std::istream & in)
{it}{it}{{
{it}{it}{it}auto hasValue = BinaryReader<bool>::extract(in);
{it}{it}{it}if (hasValue)
{it}{it}{it}{it}{{ return BinaryReader<T>::extract(in); }}
{it}{it}{it}else
{it}{it}{it}{it}{{ return {{ }}; }}
{it}{it}}}
{it}}};''')


def gen_variant(self):
    if 'binary|variant' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['binary|variant'] = None

    it = self.indent()

    self.includeForType('binary|deserializersDecl', 'variant', '#include <variant>')
    self.includeForType('binary|deserializersDecl', 'index_sequence', '#include <utility>')
    self.includeForType('binary|deserializersDecl', 'tuple', '#include <tuple>')
    self.includeForType('binary|deserializersDecl', 'optional', '#include <optional>')

    self.appendSrc('binary|deserializersDecl', f'''

{it}template <class... Ts>
{it}struct BinaryReader<std::variant<Ts...>>
{it}{{
{it}{it}// This checks if the type string matches a particular one in the defs.
{it}{it}template <std::size_t I>
{it}{it}static inline bool schecker(std::size_t idx, std::optional<std::variant<Ts...>> & obj, std::istream & in)
{it}{it}{{
{it}{it}{it}using IndexedType = typename std::tuple_element<I, std::tuple<Ts...>>::type;
{it}{it}{it}if (obj.has_value() == false && idx == I) 
{it}{it}{it}{{
{it}{it}{it}{it}// now we can make the correct variant
{it}{it}{it}{it}obj = std::variant<Ts...> (std::in_place_index<I>, BinaryReader<IndexedType>::extract(in));
{it}{it}{it}}}
{it}{it}{it}return true;  // we don't actually care about the return value
{it}{it}}};

{it}{it}static inline std::variant<Ts...> extract(std::istream & in)
{it}{it}{{
            auto idx = BinaryReader<std::size_t>::extract(in);

{it}{it}{it}auto maker = [&]<std::size_t... Seq>(std::index_sequence<Seq...>)
{it}{it}{it}{{
{it}{it}{it}{it}// cycle through each type; when we find one we like, set the 
{it}{it}{it}{it}// optional to the correct type.
{it}{it}{it}{it}std::optional<std::variant<Ts...>> v;
{it}{it}{it}{it}// foo is not used; we're relying on ordered initialization
{it}{it}{it}{it}// to set the optional, but the initialization has to init
{it}{it}{it}{it}// something. :)
{it}{it}{it}{it}auto foo = {{ schecker<Seq>(idx, v, in)... }};
{it}{it}{it}{it}(void) foo;
{it}{it}{it}{it}// whatever schecker found should be in v. Woe betide you if it is not.
{it}{it}{it}{it}return * v;
{it}{it}{it}}};

{it}{it}{it}// We make a sequence of type indices for compile-time tomfoolery.
{it}{it}{it}return maker(std::make_index_sequence<sizeof...(Ts)> {{ }});
{it}{it}}}
{it}}};''')
