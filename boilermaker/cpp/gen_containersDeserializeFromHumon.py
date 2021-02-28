def gen_builtIn(self):
    pass


def gen_array(self):
    if 'humon|array' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|array'] = None

    it = self.indent()

    self.includeForType('humon|deserializersDecl', 'array', '#include <array>')
    self.includeForType('humon|deserializersDecl', 'Node', '#include <humon/humon.hpp>')

    self.appendSrc('humon|deserializersDecl', f'''

{it}template <class T, unsigned long N>
{it}struct val<std::array<T, N>>
{it}{{
{it}{it}static inline std::array<T, N> extract({self.const('Node')} & node)
{it}{it}{{
{it}{it}{it}auto maker = [&node]<std::size_t... Seq>(std::index_sequence<Seq...>)
{it}{it}{it}{{
{it}{it}{it}{it}return std::array<T, N> {{ node / Seq % val<T> {{ }}... }};
{it}{it}{it}}};

{it}{it}{it}return maker(std::make_index_sequence<N> {{}});
{it}{it}}}
{it}}};''')


def gen_pair(self):
    if 'humon|pair' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|pair'] = None

    it = self.indent()

    self.includeForType('humon|deserializersDecl', 'pair', '#include <utility>')
    self.includeForType('humon|deserializersDecl', 'Node', '#include <humon/humon.hpp>')

    self.appendSrc('humon|deserializersDecl', f'''

{it}template <class T0, class T1>
{it}struct val<std::pair<T0, T1>>
{it}{{
{it}{it}static inline std::pair<T0, T1> extract({self.const('Node')} & node)
{it}{it}{{
{it}{it}{it}return {{
{it}{it}{it}{it}node / 0 % val<T0> {{ }},
{it}{it}{it}{it}node / 1 % val<T1> {{ }}
{it}{it}{it}}};
{it}{it}}}
{it}}};''')


def gen_tuple(self):
    if 'humon|tuple' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|tuple'] = None

    it = self.indent()

    self.includeForType('humon|deserializersDecl', 'tuple', '#include <tuple>')
    self.includeForType('humon|deserializersDecl', 'Node', '#include <humon/humon.hpp>')

    self.appendSrc('humon|deserializersDecl', f'''

{it}template <class... Ts>
{it}struct val<std::tuple<Ts...>>
{it}{{
{it}{it}static inline std::tuple<Ts...> extract({self.const('Node')} & node)
{it}{it}{{
{it}{it}{it}auto maker = [&node]<std::size_t... Seq>(std::index_sequence<Seq...>)
{it}{it}{it}{{
{it}{it}{it}{it}return std::tuple<Ts...> {{ node / Seq % val<Ts> {{ }}... }};
{it}{it}{it}}};

{it}{it}{it}return maker(std::make_index_sequence<sizeof...(Ts)> {{ }});
{it}{it}}}
{it}}};''')


def gen_vector(self):
    if 'humon|vector' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|vector'] = None

    it = self.indent()

    self.includeForType('humon|deserializersDecl', 'vector', '#include <vector>')
    self.includeForType('humon|deserializersDecl', 'Node', '#include <humon/humon.hpp>')

    self.appendSrc('humon|deserializersDecl', f'''

{it}template <class T, class A>
{it}struct val<std::vector<T, A>>
{it}{{
{it}{it}static inline std::vector<T, A> extract({self.const('Node')} & node)
{it}{it}{{
{it}{it}{it}std::vector<T, A> rv;
{it}{it}{it}for (size_t i = 0; i < node.numChildren(); ++i)
{it}{it}{it}{{
{it}{it}{it}{it}rv.emplace_back(node / i % val<T> {{ }} );
{it}{it}{it}}}
{it}{it}{it}return rv;
{it}{it}}}
{it}}};''')


def gen_set(self):
    if 'humon|set' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|set'] = None

    it = self.indent()

    self.includeForType('humon|deserializersDecl', 'set', '#include <set>')
    self.includeForType('humon|deserializersDecl', 'Node', '#include <humon/humon.hpp>')

    self.appendSrc('humon|deserializersDecl', f'''

{it}template <class K, class C, class A>
{it}struct val<std::set<K, C, A>>
{it}{{
{it}{it}static inline std::set<K, C, A> extract({self.const('Node')} & node)
{it}{it}{{
{it}{it}{it}std::set<K, C, A> rv;
{it}{it}{it}for (size_t i = 0; i < node.numChildren(); ++i)
{it}{it}{it}{{
{it}{it}{it}{it}rv.emplace(node / i % val<T> {{ }} );
{it}{it}{it}}}
{it}{it}{it}return rv;
{it}{it}}}
{it}}};''')


def gen_unordered_set(self):
    if 'humon|unordered_set' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|unordered_set'] = None

    it = self.indent()

    self.includeForType('humon|deserializersDecl', 'unordered_set', '#include <unordered_set>')
    self.includeForType('humon|deserializersDecl', 'Node', '#include <humon/humon.hpp>')

    self.appendSrc('humon|deserializersDecl', f'''

{it}template <class K, class H, class E, class A>
{it}struct val<std::unordered_set<K, H, E, A>>
{it}{{
{it}{it}static inline std::unordered_set<K, H, E, A> extract({self.const('Node')} & node)
{it}{it}{{
{it}{it}{it}std::unordered_set<K, H, E, A> rv;
{it}{it}{it}for (size_t i = 0; i < node.numChildren(); ++i)
{it}{it}{it}{{
{it}{it}{it}{it}rv.emplace(node / i % val<T> {{ }} );
{it}{it}{it}}}
{it}{it}{it}return rv;
{it}{it}}}
{it}}};''')


def gen_map(self):
    if 'humon|map' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|map'] = None

    it = self.indent()

    self.includeForType('humon|deserializersDecl', 'map', '#include <map>')
    self.includeForType('humon|deserializersDecl', 'Node', '#include <humon/humon.hpp>')

    self.appendSrc('humon|deserializersDecl', f'''

{it}template <class K, class T, class C, class A>
{it}struct val<std::map<K, T, C, A>>
{it}{{
{it}{it}static inline std::map<K, T, C, A> extract({self.const('Node')} & node)
{it}{it}{{
{it}{it}{it}std::map<K, T, C, A> rv;
{it}{it}{it}for (size_t i = 0; i < node.numChildren(); ++i)
{it}{it}{it}{{
{it}{it}{it}{it}Node elemNode = node / i;
{it}{it}{it}{it}rv.emplace(std::move(val<K>::extract(elemNode.key().str())),
{it}{it}{it}{it}           std::move(elemNode i % val<T> {{ }} ));
{it}{it}{it}}}
{it}{it}{it}return rv;
{it}{it}}}
{it}}};''')


def gen_unordered_map(self):
    if 'humon|unordered_map' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|unordered_map'] = None

    it = self.indent()

    self.includeForType('humon|deserializersDecl', 'unordered_map', '#include <unordered_map>')
    self.includeForType('humon|deserializersDecl', 'Node', '#include <humon/humon.hpp>')

    self.appendSrc('humon|deserializersDecl', f'''

{it}template <class K, class T, class H, class E, class A>
{it}struct val<std::unordered_map<K, T, H, E, A>>
{it}{{
{it}{it}static inline std::unordered_map<K, T, H, E, A> extract({self.const('Node')} & node)
{it}{it}{{
{it}{it}{it}std::unordered_map<K, T, H, E, A> rv;
{it}{it}{it}for (size_t i = 0; i < node.numChildren(); ++i)
{it}{it}{it}{{
{it}{it}{it}{it}Node elemNode = node / i;
{it}{it}{it}{it}rv.emplace(std::move(val<K>::extract(elemNode.key().str())),
{it}{it}{it}{it}           std::move(elemNode i % val<T> {{ }} ));
{it}{it}{it}}}
{it}{it}{it}return rv;
{it}{it}}}
{it}}};''')


def gen_optional(self):
    if 'humon|optional' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|optional'] = None

    it = self.indent()

    self.includeForType('humon|deserializersDecl', 'optional', '#include <optional>')
    self.includeForType('humon|deserializersDecl', 'Node', '#include <humon/humon.hpp>')

    self.appendSrc('humon|deserializersDecl', f'''

{it}template <class T>
{it}struct val<std::optional<T>>
{it}{{
{it}{it}static inline std::optional<T> extract({self.const('Node')} & node)
{it}{it}{{
{it}{it}{it}if (! node)
{it}{it}{it}{it}{{ return {{ }}; }}
{it}{it}{it}else if (node.kind() == NodeKind::value && node.value().str() == "_")
{it}{it}{it}{it}{{ return {{ }}; }}
{it}{it}{it}else
{it}{it}{it}{it}{{ return node % val<T>{{}}; }}
{it}{it}}}
{it}}};''')


def gen_variant(self):
    if 'humon|variant' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['humon|variant'] = None

    it = self.indent()

    self.includeForType('humon|deserializersDecl', 'variant', '#include <variant>')
    self.includeForType('humon|deserializersDecl', 'Node', '#include <humon/humon.hpp>')

    self.appendSrc('humon|deserializersDecl', f'''

{it}template <class... Ts>
{it}struct val<std::variant<Ts...>>
{it}{{
{it}{it}// This checks if the type string matches a particular one in the defs.
{it}{it}template <std::size_t I>
{it}{it}static inline bool schecker(std::string_view tokStr, std::optional<std::variant<Ts...>> & obj, {self.const('Node')} & node)
{it}{it}{{
{it}{it}{it}// This holds the type names / aliases for each of the variant types.
{it}{it}{it}auto names = VariantTypeNames<std::variant<Ts...>>::names;
{it}{it}{it}if (obj.has_value() == false && tokStr == names[I]) 
{it}{it}{it}{{
{it}{it}{it}{it}// now we can make the correct variant and give it the node as a ctr arg
{it}{it}{it}{it}obj = std::variant<Ts...> {{ std::in_place_index<I>, node }};
{it}{it}    }}
{it}{it}    return true;
{it}{it}}};

{it}{it}static inline std::variant<Ts...> extract({self.const('Node')} & node)
{it}{it}{{
{it}{it}{it}Token tok = node.annotation("type");
{it}{it}{it}if (! tok)
{it}{it}{it}{it}{{ return {{ }}; }}
{it}{it}{it}auto tokStr = tok.str();

{it}{it}{it}auto maker = [&]<std::size_t... Seq>(std::index_sequence<Seq...>)
{it}{it}{it}{{
{it}{it}{it}{it}// cycle through each type; when we find one we like, set the 
{it}{it}{it}{it}// optional to the correct type.
{it}{it}{it}{it}std::optional<std::variant<Ts...>> v;
{it}{it}{it}{it}// foo is not used; we're relying on ordered initialization
{it}{it}{it}{it}// to set the optional, but the initialization has to init
{it}{it}{it}{it}// something. :)
{it}{it}{it}{it}auto foo = {{ schecker<Seq>(tokStr, v, node)... }};
{it}{it}{it}{it}// whatever schecker found should be in v. Woe betide you if it is not.
{it}{it}{it}{it}return * v;
{it}{it}{it}}};

{it}{it}{it}// We make a sequence of type indices for compile-time tomfoolery.
{it}{it}{it}return maker(std::make_index_sequence<sizeof...(Ts)> {{ }});
{it}{it}}}
{it}}};''')
