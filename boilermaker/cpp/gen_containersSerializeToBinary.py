def genSerializerToBinary_array(self):
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

{it}{it}return out;
{it}}}''')


def genSerializerToBinary_pair(self):
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

{it}{it}return out;
{it}}}''')


def genSerializerToBinary_tuple(self):
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

{it}{it}return out;
{it}}}''')


def genSerializerToBinary_vector(self):
    if 'binary|vector' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|vector'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<vector>')

    self._appendToSection('containerSerializer_vector', f'''

{it}template <class T>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::vector<T>> const & obj)
{it}{{

{it}{it}return out;
{it}}}''')


def genSerializerToBinary_set(self):
    if 'binary|set' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|set'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<set>')

    self._appendToSection('containerSerializer_set', f'''

{it}template <class T, class L>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::set<T, L>> const & obj)
{it}{{

{it}{it}return out;
{it}}}''')


def genSerializerToBinary_unordered_set(self):
    if 'binary|unordered_set' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|unordered_set'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<unordered_set>')

    self._appendToSection('containerSerializer_unordered_set', f'''

{it}template <class T, class H>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::unordered_set<T, H>> const & obj)
{it}{{

{it}{it}return out;
{it}}}''')


def genSerializerToBinary_map(self):
    if 'binary|map' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|map'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<map>')

    self._appendToSection('containerSerializer_map', f'''

{it}template <class K, class T, class L>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::map<K, T, L>> const & obj)
{it}{{

{it}{it}return out;
{it}}}''')


def genSerializerToBinary_unordered_map(self):
    if 'binary|unordered_map' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|unordered_map'] = None

    it = self.indent()

    self._addInclude('containersIncludes', '<iostream>')
    self._addInclude('containersIncludes', '<unordered_map>')

    self._appendToSection('containerSerializer_unordered_map', f'''

{it}template <class K, class T, class H>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::unordered_map<K, T, H>> const & obj)
{it}{{

{it}{it}return out;
{it}}}''')


def genSerializerToBinary_optional(self):
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

{it}{it}return out;
{it}}}''')


def genSerializerToBinary_variant(self):
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

{it}{it}return out;
{it}}}''')
