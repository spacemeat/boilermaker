def gen_builtIn(self):
    if 'binary|builtIn' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|builtIn'] = None

    self.includeFile('serializerFormatWrappersDecl', '<iomanip>')

    it = self.indent()
    caveStream = self.d('caveStream') or 'cout'

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
{it}{{'''

    dbgs = self.d('caveperson')
    if dbgs and 'serializeBinary' in dbgs:
        src += f'''

{it}{it}auto up = reinterpret_cast<{self.const('uint8_t')} *>(&(* obj));
{it}{it}std::{caveStream} << "Writing " << sizeof(T) << " integ bytes: ";
{it}{it}std::{caveStream}.flush();
{it}{it}for (std::size_t i = 0; i < sizeof(T); ++i)
{it}{it}{{
{it}{it}{it}std::{caveStream} << ' ' << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(up[i]) << std::dec;
{it}{it}}}
{it}{it}std::{caveStream} << '\\n';'''

    src += f'''
{it}{it}auto p = reinterpret_cast<{self.const('char')} *>(&(* obj));
{it}{it}out.write(p, sizeof(T));

{it}{it}return out;
{it}}}

{it}template <class T, std::enable_if_t<std::is_floating_point_v<T>, bool> = true>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<T> const & obj)
{it}{{'''

    if dbgs and 'serializeBinary' in dbgs:
        src += f'''
{it}{it}auto up = reinterpret_cast<{self.const('uint8_t')} *>(&(* obj));
{it}{it}std::{caveStream} << "Writing " << sizeof(T) << " float bytes: ";
{it}{it}for (std::size_t i = 0; i < sizeof(T); ++i)
{it}{it}{{
{it}{it}{it}std::{caveStream} << ' ' << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(up[i]) << std::dec;
{it}{it}}}
{it}{it}std::{caveStream} << '\\n';'''

    src += f'''
{it}{it}auto p = reinterpret_cast<{self.const('char')} *>(&(* obj));
{it}{it}out.write(p, sizeof(T));

{it}{it}return out;
{it}}}

{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::string_view> const & obj);
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::string> const & obj);'''
    self.appendSrc('serializerFormatWrappersDecl', src)

    src = f'''

{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::string_view> const & obj)
{it}{{'''

    dbgs = self.d('caveperson')
    if dbgs and 'serializeBinary' in dbgs:
        src += f'''
{it}{it}std::{caveStream} << "Writing string_view:\\n";
{it}{it}out << BinaryFormat(obj->size());
{it}{it}std::{caveStream} << "             -- chars: ";
{it}{it}for (std::size_t i = 0; i < obj->size(); ++i)
{it}{it}{{
{it}{it}{it}std::{caveStream} << ' ' << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>((*obj)[i]) << std::dec;
{it}{it}}}
{it}{it}std::{caveStream} << '\\n';'''
    else:
        src += f'''
{it}{it}out << BinaryFormat(obj->size());'''

    src += f'''
{it}{it}out.write(obj->data(), obj->size());

{it}{it}return out;
{it}}}

{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::string> const & obj)
{it}{{'''

    dbgs = self.d('caveperson')
    if dbgs and 'serializeBinary' in dbgs:
        src += f'''
{it}{it}std::{caveStream} << "Writing string:\\n";
{it}{it}out << BinaryFormat(obj->size());
{it}{it}std::{caveStream} << "             -- chars: ";
{it}{it}for (std::size_t i = 0; i < obj->size(); ++i)
{it}{it}{{
{it}{it}{it}std::{caveStream} << ' ' << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>((*obj)[i]) << std::dec;
{it}{it}}}
{it}{it}std::{caveStream} << '\\n';'''
    else:
        src += f'''
{it}{it}out << BinaryFormat(obj->size());'''

    src += f'''
{it}{it}out.write(obj->data(), obj->size());

{it}{it}return out;
{it}}}'''
    self.appendSrc('binary|serializersDef', src)



def gen_array(self):
    if 'binary|array' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|array'] = None

    it = self.indent()

    self.includeForType('binary|serializersDecl', 'array', '#include <array>')
    self.includeForType('binary|serializersDecl', 'ostream', '#include <iostream>')
    self.includeOutputFile('binary|serializersDecl', 'commonHeader')

    src = f'''

{it}template <class T, unsigned long N>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::array<T, N>> const & obj)
{it}{{{self.cave('serializeBinary', f'"Writing array"', 'binary|serializersDecl')}
{it}{it}for (std::size_t i = 0; i < N; ++i)
{it}{it}  {{ out << BinaryFormat( (* obj)[i] ); }}

{it}{it}return out;
{it}}}'''
    self.appendSrc('binary|serializersDecl', src)


def gen_pair(self):
    if 'binary|pair' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|pair'] = None

    it = self.indent()

    self.includeForType('binary|serializersDecl', 'pair', '#include <utility>')
    self.includeForType('binary|serializersDecl', 'ostream', '#include <iostream>')
    self.includeOutputFile('binary|serializersDecl', 'commonHeader')

    src = f'''

{it}template <class T0, class T1>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::pair<T0, T1>> const & obj)
{it}{{{self.cave('serializeBinary', f'"Writing pair"', 'binary|serializersDecl')}
{it}{it}out << BinaryFormat(obj->first);
{it}{it}out << BinaryFormat(obj->second);

{it}{it}return out;
{it}}}'''
    self.appendSrc('binary|serializersDecl', src)


def gen_tuple(self):
    if 'binary|tuple' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|tuple'] = None

    it = self.indent()

    self.includeForType('binary|serializersDecl', 'tuple', '#include <tuple>')
    self.includeForType('binary|serializersDecl', 'ostream', '#include <iostream>')
    self.includeOutputFile('binary|serializersDecl', 'commonHeader')

    src = f'''

{it}template <class... Ts>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::tuple<Ts...>> const & obj)
{it}{{{self.cave('serializeBinary', f'"Writing tuple"', 'binary|serializersDecl')}
{it}{it}std::apply(
{it}{it}{it}[&out](auto &&... args)
{it}{it}{it}{it}{{ ((out << BinaryFormat(args)), ...); }},
{it}{it}{it}* obj);

{it}{it}return out;
{it}}}'''
    self.appendSrc('binary|serializersDecl', src)


def gen_vector(self):
    if 'binary|vector' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|vector'] = None

    it = self.indent()

    self.includeForType('binary|serializersDecl', 'vector', '#include <vector>')
    self.includeForType('binary|serializersDecl', 'ostream', '#include <iostream>')
    self.includeOutputFile('binary|serializersDecl', 'commonHeader')

    src = f'''

{it}template <class T, class A>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::vector<T, A>> const & obj)
{it}{{{self.cave('serializeBinary', f'"Writing vector"', 'binary|serializersDecl')}
{it}{it}out << BinaryFormat(obj->size());
{it}{it}for (auto const & elem : * obj)
{it}{it}  {{ out << BinaryFormat(elem); }}

{it}{it}return out;
{it}}}'''
    self.appendSrc('binary|serializersDecl', src)


def gen_set(self):
    if 'binary|set' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|set'] = None

    it = self.indent()

    self.includeForType('binary|serializersDecl', 'set', '#include <set>')
    self.includeForType('binary|serializersDecl', 'ostream', '#include <iostream>')
    self.includeOutputFile('binary|serializersDecl', 'commonHeader')

    src = f'''

{it}template <class K, class C, class A>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::set<K, C, A>> const & obj)
{it}{{{self.cave('serializeBinary', f'"Writing set"', 'binary|serializersDecl')}
{it}{it}out << BinaryFormat(obj->size());
{it}{it}for (auto const & elem : * obj)
{it}{it}  {{ out << BinaryFormat(elem); }}

{it}{it}return out;
{it}}}'''
    self.appendSrc('binary|serializersDecl', src)


def gen_unordered_set(self):
    if 'binary|unordered_set' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|unordered_set'] = None

    it = self.indent()

    self.includeForType('binary|serializersDecl', 'unordered_set', '#include <unordered_set>')
    self.includeForType('binary|serializersDecl', 'ostream', '#include <iostream>')
    self.includeOutputFile('binary|serializersDecl', 'commonHeader')

    src = f'''

{it}template <class K, class H, class E, class A>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::unordered_set<K, H, E, A>> const & obj)
{it}{{{self.cave('serializeBinary', f'"Writing unordered_set"', 'binary|serializersDecl')}
{it}{it}out << BinaryFormat(obj->size());
{it}{it}for (auto const & elem : * obj)
{it}{it}  {{ out << BinaryFormat(elem); }}

{it}{it}return out;
{it}}}'''
    self.appendSrc('binary|serializersDecl', src)


def gen_map(self):
    if 'binary|map' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|map'] = None

    it = self.indent()

    self.includeForType('binary|serializersDecl', 'map', '#include <map>')
    self.includeForType('binary|serializersDecl', 'ostream', '#include <iostream>')
    self.includeOutputFile('binary|serializersDecl', 'commonHeader')

    src = f'''

{it}template <class K, class T, class C, class A>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::map<K, T, C, A>> const & obj)
{it}{{{self.cave('serializeBinary', f'"Writing map"', 'binary|serializersDecl')}
{it}{it}out << BinaryFormat(obj->size());
{it}{it}for (auto const & [k, v] : * obj)
{it}{it}  {{ out << BinaryFormat(k) << BinaryFormat(v); }}

{it}{it}return out;
{it}}}'''
    self.appendSrc('binary|serializersDecl', src)


def gen_unordered_map(self):
    if 'binary|unordered_map' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|unordered_map'] = None

    it = self.indent()

    self.includeForType('binary|serializersDecl', 'unordered_map', '#include <unordered_map>')
    self.includeForType('binary|serializersDecl', 'ostream', '#include <iostream>')
    self.includeOutputFile('binary|serializersDecl', 'commonHeader')

    src = f'''

{it}template <class K, class T, class H, class E, class A>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::unordered_map<K, T, H, E, A>> const & obj)
{it}{{{self.cave('serializeBinary', f'"Writing unordered_map"', 'binary|serializersDecl')}
{it}{it}out << BinaryFormat(obj->size());
{it}{it}for (auto const & [k, v] : * obj)
{it}{it}  {{ out << BinaryFormat(k) << BinaryFormat(v); }}

{it}{it}return out;
{it}}}'''
    self.appendSrc('binary|serializersDecl', src)


def gen_optional(self):
    if 'binary|optional' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|optional'] = None

    it = self.indent()

    self.includeForType('binary|serializersDecl', 'optional', '#include <optional>')
    self.includeForType('binary|serializersDecl', 'ostream', '#include <iostream>')
    self.includeOutputFile('binary|serializersDecl', 'commonHeader')

    src = f'''

{it}template <class T>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::optional<T>> const & obj)
{it}{{{self.cave('serializeBinary', f'"Writing optional"', 'binary|serializersDecl')}
{it}{it}out << BinaryFormat(obj->has_value());
{it}{it}if (obj->has_value())
{it}{it}  {{ out << BinaryFormat(** obj); }}

{it}{it}return out;
{it}}}'''
    self.appendSrc('binary|serializersDecl', src)


def gen_variant(self):
    if 'binary|variant' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|variant'] = None

    it = self.indent()

    self.includeForType('binary|serializersDecl', 'variant', '#include <variant>')
    self.includeForType('binary|serializersDecl', 'ostream', '#include <iostream>')
    self.includeOutputFile('binary|serializersDecl', 'commonHeader')

    src = f'''

{it}template <class... Ts>
{it}std::ostream & operator << (std::ostream & out, BinaryFormat<std::variant<Ts...>> const & obj)
{it}{{{self.cave('serializeBinary', f'"Writing variant"', 'binary|serializersDecl')}
{it}{it}out << BinaryFormat(obj->index());
{it}{it}std::visit(
{it}{it}{it}[&](auto && o)
{it}{it}{it}{it}{{ out << BinaryFormat(o); }},
{it}{it}{it}* obj);

{it}{it}return out;
{it}}}'''
    self.appendSrc('binary|serializersDecl', src)
