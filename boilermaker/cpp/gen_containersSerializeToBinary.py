def gen_builtIn(self):
    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<type_traits>')
    self._addInclude('containersSourceLocalIncludes', 'containersHeader')

    it = self.indent()

    src = f'''

{it}template <class T>
{it}struct BinaryFormat : public SerializedFormat<T>
{it}{{
{it}{it}BinaryFormat(T const & t)
{it}{it}: SerializedFormat<T>(t)
{it}{it}{{ }}
{it}}};

{it}template <class T, std::enable_if_t<std::is_integral_v<T>, bool> = true>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<T> const & obj)
{it}{{
{it}{it}auto p = reinterpret_cast<{self.const('char')} *>(&(* obj));
{it}{it}out.write(p, sizeof(T));

{it}{it}return out;
{it}}}

{it}template <class T, std::enable_if_t<std::is_floating_point_v<T>, bool> = true>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<T> const & obj)
{it}{{
{it}{it}auto p = reinterpret_cast<{self.const('char')} *>(&(* obj));
{it}{it}out.write(p, sizeof(T));

{it}{it}return out;
{it}}}

{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::string_view> const & obj);
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::string> const & obj);'''
    self._appendToSection('serializerFormatWrappersDecl', src)

    src = f'''
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::string_view> const & obj)
{it}{{
{it}{it}out << BinaryFormat(obj->size());
{it}{it}out.write(obj->data(), obj->size());

{it}{it}return out;
{it}}}

{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::string> const & obj)
{it}{{
{it}{it}out << BinaryFormat(obj->size());
{it}{it}out.write(obj->data(), obj->size());

{it}{it}return out;
{it}}}'''
    self._appendToSection('serializerFormatWrappersDef', src)



def gen_array(self):
    if 'binary|array' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|array'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<array>')

    self._appendToSection('containerSerializer_array', f'''

{it}template <class T, unsigned long N>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::array<T, N>> const & obj)
{it}{{
{it}{it}for (std::size_t i = 0; i < N; ++i)
{it}{it}  {{ out << BinaryFormat( (* obj)[i] ); }}

{it}{it}return out;
{it}}}''')


def gen_pair(self):
    if 'binary|pair' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|pair'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<utility>')

    self._appendToSection('containerSerializer_pair', f'''

{it}template <class T0, class T1>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::pair<T0, T1>> const & obj)
{it}{{
{it}{it}out << BinaryFormat(obj->first);
{it}{it}out << BinaryFormat(obj->second);

{it}{it}return out;
{it}}}''')


def gen_tuple(self):
    if 'binary|tuple' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|tuple'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<tuple>')

    self._appendToSection('containerSerializer_tuple', f'''

{it}template <class... Ts>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::tuple<Ts...>> const & obj)
{it}{{
{it}{it}std::apply(
{it}{it}{it}[](auto &&... args)
{it}{it}{it}{it}{{ ((std::cout << BinaryFormat(args)), ...); }},
{it}{it}{it}* obj);

{it}{it}return out;
{it}}}''')


def gen_vector(self):
    if 'binary|vector' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|vector'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<vector>')

    self._appendToSection('containerSerializer_vector', f'''

{it}template <class T, class A>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::vector<T, A>> const & obj)
{it}{{
{it}{it}out << BinaryFormat(obj->size());
{it}{it}for (auto const & elem : * obj)
{it}{it}  {{ out << BinaryFormat(elem); }}

{it}{it}return out;
{it}}}''')


def gen_set(self):
    if 'binary|set' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|set'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<set>')

    self._appendToSection('containerSerializer_set', f'''

{it}template <class K, class C, class A>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::set<K, C, A>> const & obj)
{it}{{
{it}{it}out << BinaryFormat(obj->size());
{it}{it}for (auto const & elem : * obj)
{it}{it}  {{ out << BinaryFormat(elem); }}

{it}{it}return out;
{it}}}''')


def gen_unordered_set(self):
    if 'binary|unordered_set' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|unordered_set'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<unordered_set>')

    self._appendToSection('containerSerializer_unordered_set', f'''

{it}template <class K, class H, class E, class A>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::unordered_set<K, H, E, A>> const & obj)
{it}{{
{it}{it}out << BinaryFormat(obj->size());
{it}{it}for (auto const & elem : * obj)
{it}{it}  {{ out << BinaryFormat(elem); }}

{it}{it}return out;
{it}}}''')


def gen_map(self):
    if 'binary|map' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|map'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<map>')

    self._appendToSection('containerSerializer_map', f'''

{it}template <class K, class T, class C, class A>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::map<K, T, C, A>> const & obj)
{it}{{
{it}{it}out << BinaryFormat(obj->size());
{it}{it}for (auto const & [k, v] : * obj)
{it}{it}  {{ out << BinaryFormat(k) << BinaryFormat(v); }}

{it}{it}return out;
{it}}}''')


def gen_unordered_map(self):
    if 'binary|unordered_map' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|unordered_map'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<unordered_map>')

    self._appendToSection('containerSerializer_unordered_map', f'''

{it}template <class K, class T, class H, class E, class A>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::unordered_map<K, T, H, E, A>> const & obj)
{it}{{
{it}{it}out << BinaryFormat(obj->size());
{it}{it}for (auto const & [k, v] : * obj)
{it}{it}  {{ out << BinaryFormat(k) << BinaryFormat(v); }}

{it}{it}return out;
{it}}}''')


def gen_optional(self):
    if 'binary|optional' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|optional'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<optional>')

    self._appendToSection('containerSerializer_optional', f'''

{it}template <class T>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::optional<T>> const & obj)
{it}{{
{it}{it}out << BinaryFormat(obj->has_value());
{it}{it}if (obj->has_value())
{it}{it}  {{ out << BinaryFormat(** obj); }}

{it}{it}return out;
{it}}}''')


def gen_variant(self):
    if 'binary|variant' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|variant'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<variant>')

    self._appendToSection('containerSerializer_variant', f'''

{it}template <class... Ts>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::variant<Ts...>> const & obj)
{it}{{
{it}{it}out << BinaryFormat(obj->index());
{it}{it}std::visit(
{it}{it}{it}[&](auto && o)
{it}{it}{it}{it}{{ out << BinaryFormat(o); }},
{it}{it}{it}* obj);

{it}{it}return out;
{it}}}''')
