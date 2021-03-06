def gen_builtIn(self):
    if 'humon|builtIn' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['humon|builtIn'] = None

    it = self.indent()

    src = f'''

{it}template <class T>
{it}struct HumonFormat : public SerializedFormat<T>
{it}{{
{it}{it}HumonFormat(T const & t)
{it}{it}: SerializedFormat<T>(t)
{it}{it}{{ }}
{it}}};

{it}template <class T>
{it}std::ostream & operator << (std::ostream & out, HumonFormat<T> const & obj)
{it}{{
{it}{it}out << * obj;

{it}{it}return out;
{it}}}'''
    self.appendSrc('serializerFormatWrappersDecl', src)


def gen_array(self):
    if 'humon|array' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['humon|array'] = None

    it = self.indent()

    self.includeForType('humon|serializersDecl', 'array', '#include <array>')
    self.includeOutputFile('humon|serializersDecl', 'commonHeader')

    src = f'''

{it}template <class T, unsigned long N>
{it}std::ostream & operator << (std::ostream & out, HumonFormat<std::array<T, N>> const & obj)
{it}{{
{it}{it}out << "[ ";
{it}{it}for (std::size_t i = 0; i < N; ++i)
{it}{it}{{
{it}{it}{it}out << HumonFormat( (* obj)[i] ) << " ";
{it}{it}}}
{it}{it}out << "]";

{it}{it}return out;
{it}}}'''
    self.appendSrc('humon|serializersDecl', src)


def gen_pair(self):
    if 'humon|pair' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['humon|pair'] = None

    it = self.indent()

    self.includeForType('humon|serializersDecl', 'pair', '#include <utility>')
    self.includeForType('humon|serializersDecl', 'ostream', '#include <iostream>')
    self.includeOutputFile('humon|serializersDecl', 'commonHeader')

    src = f'''

{it}template <class T0, class T1>
{it}std::ostream & operator << (std::ostream & out, HumonFormat<std::pair<T0, T1>> const & obj)
{it}{{
{it}{it}out << '[' << HumonFormat(std::get<0>(* obj)) << ' ' << HumonFormat(std::get<1>(* obj)) << ']';

{it}{it}return out;
{it}}}'''
    self.appendSrc('humon|serializersDecl', src)


def gen_tuple(self):
    if 'humon|tuple' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['humon|tuple'] = None

    it = self.indent()

    self.includeForType('humon|serializersDecl', 'tuple', '#include <tuple>')
    self.includeForType('humon|serializersDecl', 'ostream', '#include <iostream>')
    self.includeOutputFile('humon|serializersDecl', 'commonHeader')

    src = f'''

{it}template <class... Ts>
{it}std::ostream & operator << (std::ostream & out, HumonFormat<std::tuple<Ts...>> const & obj)
{it}{{
{it}{it}out << "[ ";
{it}{it}apply(
{it}{it}{it}[&out](auto &&... args)
{it}{it}{it}{it}{{ ((out << HumonFormat(args) << ' '), ...); }},
{it}{it}{it}* obj);
{it}{it}out << "]";

{it}{it}return out;
{it}}}'''
    self.appendSrc('humon|serializersDecl', src)


def gen_vector(self):
    if 'humon|vector' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['humon|vector'] = None

    it = self.indent()

    self.includeForType('humon|serializersDecl', 'vector', '#include <vector>')
    self.includeForType('humon|serializersDecl', 'ostream', '#include <iostream>')
    self.includeOutputFile('humon|serializersDecl', 'commonHeader')

    src = f'''

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
{it}}}'''
    self.appendSrc('humon|serializersDecl', src)


def gen_set(self):
    if 'humon|set' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['humon|set'] = None

    it = self.indent()

    self.includeForType('humon|serializersDecl', 'set', '#include <set>')
    self.includeForType('humon|serializersDecl', 'ostream', '#include <iostream>')
    self.includeOutputFile('humon|serializersDecl', 'commonHeader')

    src = f'''

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
{it}}}'''
    self.appendSrc('humon|serializersDecl', src)


def gen_unordered_set(self):
    if 'humon|unordered_set' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['humon|unordered_set'] = None

    it = self.indent()

    self.includeForType('humon|serializersDecl', 'unordered_set', '#include <unordered_set>')
    self.includeForType('humon|serializersDecl', 'ostream', '#include <iostream>')
    self.includeOutputFile('humon|serializersDecl', 'commonHeader')

    src = f'''

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
{it}}}'''
    self.appendSrc('humon|serializersDecl', src)


def gen_map(self):
    if 'humon|map' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['humon|map'] = None

    it = self.indent()

    self.includeForType('humon|serializersDecl', 'map', '#include <map>')
    self.includeForType('humon|serializersDecl', 'ostream', '#include <iostream>')
    self.includeOutputFile('humon|serializersDecl', 'commonHeader')

    src = f'''

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
{it}}}'''
    self.appendSrc('humon|serializersDecl', src)


def gen_unordered_map(self):
    if 'humon|unordered_map' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['humon|unordered_map'] = None

    it = self.indent()

    self.includeForType('humon|serializersDecl', 'unordered_map', '#include <unordered_map>')
    self.includeForType('humon|serializersDecl', 'ostream', '#include <iostream>')
    self.includeOutputFile('humon|serializersDecl', 'commonHeader')

    src = f'''

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
{it}}}'''
    self.appendSrc('humon|serializersDecl', src)


def gen_optional(self):
    if 'humon|optional' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['humon|optional'] = None

    it = self.indent()

    self.includeForType('humon|serializersDecl', 'optional', '#include <optional>')
    self.includeForType('humon|serializersDecl', 'ostream', '#include <iostream>')
    self.includeOutputFile('humon|serializersDecl', 'commonHeader')

    src = f'''

{it}template <class T>
{it}std::ostream & operator << (std::ostream & out, HumonFormat<std::optional<T>> const & obj)
{it}{{
{it}{it}if (obj->has_value())
{it}{it}{it}{{ out << HumonFormat(** obj); }}
{it}{it}else
{it}{it}{it}{{ out << '_'; }}

{it}{it}return out;
{it}}}'''
    self.appendSrc('humon|serializersDecl', src)


def gen_variant(self):
    if 'humon|variant' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['humon|variant'] = None

    it = self.indent()

    self.includeForType('humon|serializersDecl', 'variant', '#include <variant>')
    self.includeForType('humon|serializersDecl', 'ostream', '#include <iostream>')
    self.includeOutputFile('humon|serializersDecl', 'commonHeader')

    src = f'''

{it}template <class... Ts>
{it}std::ostream & operator << (std::ostream & out, HumonFormat<std::variant<Ts...>> const & obj)
{it}{{
{it}{it}constexpr auto const names =  VariantTypeNames<std::variant<Ts...>>::names;
{it}{it}
{it}{it}std::visit(
{it}{it}{it}[&](auto && o) 
{it}{it}{it}{it}{{ out << HumonFormat(o) << " @type: " << names[obj->index()]; }},
{it}{it}{it}* obj);

{it}{it}return out;
{it}}}'''
    self.appendSrc('humon|serializersDecl', src)
