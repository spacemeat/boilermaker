def genSerializerToHumon_array(self):
    if 'humon|array' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['humon|array'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<array>')

    self._appendToSection('containerSerializer_array', f'''

{it}template <class T, unsigned long N>
{it}std::ostream & operator << (std::ostream & out, HumonFormat<std::array<T, N>> const & obj)
{it}{{
{it}{it}out << "[ ";
{it}{it}for (std::size_t i = 0; i < N; ++i)
{it}{it}{{
{it}{it}{it}out << (* obj)[i] << " ";
{it}{it}}}
{it}{it}out << "]";

{it}{it}return out;
{it}}}''')


def genSerializerToHumon_pair(self):
    if 'humon|pair' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['humon|pair'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<utility>')

    self._appendToSection('containerSerializer_pair', f'''

{it}template <class T0, class T1>
{it}std::ostream & operator << (std::ostream & out, HumonFormat<std::pair<T0, T1>> const & obj)
{it}{{
{it}{it}out << '[' << std::get<0>(* obj) << ' ' << std::get<1>(* obj) << ']';

{it}{it}return out;
{it}}}''')


def genSerializerToHumon_tuple(self):
    if 'humon|tuple' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['humon|tuple'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<tuple>')

    self._appendToSection('containerSerializer_tuple', f'''

{it}template <class... Ts>
{it}std::ostream & operator << (std::ostream & out, HumonFormat<std::tuple<Ts...>> const & obj)
{it}{{
{it}{it}out << "[ ";
{it}{it}apply(
{it}{it}{it}[](auto &&... args)
{it}{it}{it}{it}{{ ((std::cout << args << ' '), ...); }},
{it}{it}{it}* obj);
{it}{it}out << "]";

{it}{it}return out;
{it}}}''')


def genSerializerToHumon_vector(self):
    if 'humon|vector' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['humon|vector'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<vector>')

    self._appendToSection('containerSerializer_vector', f'''

{it}template <class T>
{it}std::ostream & operator << (std::ostream & out, HumonFormat<std::vector<T>> const & obj)
{it}{{
{it}{it}out << "[ ";
{it}{it}for (auto const & elem : * obj)
{it}{it}{{
{it}{it}{it}out << elem << ' ';
{it}{it}}}
{it}{it}out << ']';

{it}{it}return out;
{it}}}''')


def genSerializerToHumon_set(self):
    if 'humon|set' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['humon|set'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<set>')

    self._appendToSection('containerSerializer_set', f'''

{it}template <class T, class L>
{it}std::ostream & operator << (std::ostream & out, HumonFormat<std::set<T, L>> const & obj)
{it}{{
{it}{it}out << "[ ";
{it}{it}for (auto const & elem : * obj)
{it}{it}{{
{it}{it}{it}out << elem << ' ';
{it}{it}}}
{it}{it}out << ']';

{it}{it}return out;
{it}}}''')


def genSerializerToHumon_unordered_set(self):
    if 'humon|unordered_set' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['humon|unordered_set'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<unordered_set>')

    self._appendToSection('containerSerializer_unordered_set', f'''

{it}template <class T, class H>
{it}std::ostream & operator << (std::ostream & out, HumonFormat<std::unordered_set<T, H>> const & obj)
{it}{{
{it}{it}out << "[ ";
{it}{it}for (auto const & elem : * obj)
{it}{it}{{
{it}{it}{it}out << elem << ' ';
{it}{it}}}
{it}{it}out << ']';

{it}{it}return out;
{it}}}''')


def genSerializerToHumon_map(self):
    if 'humon|map' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['humon|map'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<map>')

    self._appendToSection('containerSerializer_map', f'''

{it}template <class K, class T, class L>
{it}std::ostream & operator << (std::ostream & out, HumonFormat<std::map<K, T, L>> const & obj)
{it}{{
{it}{it}out << "{{ ";
{it}{it}for (auto const & elem : * obj)
{it}{it}{{
{it}{it}{it}out << elem.first << ": " << elem.second << ' ';
{it}{it}}}
{it}{it}out << '}}';

{it}{it}return out;
{it}}}''')


def genSerializerToHumon_unordered_map(self):
    if 'humon|unordered_map' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['humon|unordered_map'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<unordered_map>')

    self._appendToSection('containerSerializer_unordered_map', f'''

{it}template <class K, class T, class H>
{it}std::ostream & operator << (std::ostream & out, HumonFormat<std::unordered_map<K, T, H>> const & obj)
{it}{{
{it}{it}out << "{{ ";
{it}{it}for (auto const & elem : * obj)
{it}{it}{{
{it}{it}{it}out << elem.first << ": " << elem.second << ' ';
{it}{it}}}
{it}{it}out << '}}';

{it}{it}return out;
{it}}}''')


def genSerializerToHumon_optional(self):
    if 'humon|optional' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['humon|optional'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<optional>')

    self._appendToSection('containerSerializer_optional', f'''

{it}template <class T>
{it}std::ostream & operator << (std::ostream & out, HumonFormat<std::optional<T>> const & obj)
{it}{{
{it}{it}if (obj->has_value())
{it}{it}{it}{{ out << ** obj; }}
{it}{it}else
{it}{it}{it}{{ out << '_'; }}

{it}{it}return out;
{it}}}''')


def genSerializerToHumon_variant(self):
    if 'humon|variant' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['humon|variant'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<variant>')

    self._appendToSection('containerSerializer_variant', f'''

{it}template <class... Ts>
{it}std::ostream & operator << (std::ostream & out, HumonFormat<std::variant<Ts...>> const & obj)
{it}{{
{it}{it}constexpr auto const names =  VariantTypeNames<std::variant<Ts...>>::names;
{it}{it}
{it}{it}std::visit(
{it}{it}{it}[&](auto && o) 
{it}{it}{it}{it}{{ out << o << " @type: " << names[obj->index()] << " /* " << obj->index() << " */"; }},
{it}{it}{it}* obj);

{it}{it}return out;
{it}}}''')
