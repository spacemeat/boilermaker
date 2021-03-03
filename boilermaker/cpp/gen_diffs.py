def gen_builtIn(self):
    if 'builtIn' in self.includeDiffTypes:
        return
    self.includeDiffTypes['builtIn'] = None

    it = self.indent()
    src = f'''
{it}template <class StructType>
{it}struct Diff
{it}{{
{it}{it}Diff() : memberDiffs(false) {{ }}

{it}{it}Diff(StructType const & lhs, StructType const & rhs)
{it}{it}: memberDiffs(lhs != rhs)
{it}{it}{{ }}

{it}{it}bool memberDiffs = false;
{it}}};'''
    self.appendSrc('diffTemplateDecl', src)


def genTypeDiffer(self, t):
    self.gen_diffs.gen_builtIn(self)

    it = self.indent()
    typeDecl = self.makeNative(t.name)

    self.includeOutputFile(f'{t.name}|typeHeader|includes', 'diffsHeader')

    def foreachMemberName():
        for memberName, m in t.members.items():
            memberDecl = self.makeNativeMemberType(m.properties)
            yield (memberName, memberDecl)
    
    def foreachStdMemberName():
        for memberName, m in t.members.items():
            if m.properties['type'] in ['array', 'pair', 'tuple', 'vector', 'set', 'unordered_set', 'map', 'unordered_map', 'optional', 'variant']:
                memberDecl = self.makeNativeMemberType(m.properties)
                yield (memberName, memberDecl)

    self.includeForType(f'{t.name}|differDecl', 'bitset', '#include <bitset>')

    src = f'''

{it}template<>
{it}struct Diff<{typeDecl}>
{it}{{'''
    if len(t.members) > 0:
        src += f'''
{it}{it}enum class Members : std::size_t
{it}{it}{{
'''
        src += '\n'.join([f'{it}{it}{it}{mn},' for mn, md in foreachMemberName()])
        src += f'''
{it}{it}{it}numMembers
{it}{it}}};

{it}{it}Diff() {{ }}
{it}{it}Diff({self.const(typeDecl)} & lhs, {self.const(typeDecl)} & rhs);

{it}{it}std::bitset<static_cast<std::size_t>(Members::numMembers)> memberDiffs;'''
    for memberName, memberDecl in foreachStdMemberName():
        src += f'''
{it}{it}Diff<{memberDecl}> {memberName}_diffs;'''
    src += f'''
{it}}};'''
    self.appendSrc(f'{t.name}|differDecl', src)

    src = f'''
{it}{it}friend Diff<{typeDecl}>::Diff();
{it}{it}friend Diff<{typeDecl}>::Diff({self.const(typeDecl)} & lhs, {self.const(typeDecl)} & rhs);'''
    self.appendSrc(f'{t.name}|diffFriendDecls', src)

    src = f'''

{it}Diff<{typeDecl}>::Diff({self.const(typeDecl)} & lhs, {self.const(typeDecl)} & rhs)'''
    if len(t.members) > 0:
        src += f'''
{it}: memberDiffs('''
        src += f' |\n{it}              '.join([f'(lhs.{memberName} != rhs.{memberName}) << static_cast<int>(Members::{memberName})' for memberName, memberDecl in foreachMemberName()])
        src += ')'
        src +=f''.join([f''',\n{it}  {memberName}_diffs(lhs.{memberName}, rhs.{memberName})''' for memberName, memberDecl in foreachStdMemberName()])
    src += f'''
{it}{{
{it}}}'''
    self.appendSrc(f'{t.name}|differDef', src)

    for memberName, m in t.members.items():
        self.gen_diffs.genSubtypeDiffer(self, t, m.properties)


def genSubtypeDiffer(self, t, properties):
    baseType = properties['type']
    if baseType == 'array':
        self.gen_diffs.genDiff_array(self)
    elif baseType == 'pair':
        self.gen_diffs.genDiff_pair(self)
    elif baseType == 'tuple':
        self.gen_diffs.genDiff_tuple(self)
    elif baseType == 'vector':
        self.gen_diffs.genDiff_vector(self)
    elif baseType == 'set':
        self.gen_diffs.genDiff_set(self)
    elif baseType == 'unordered_set':
        self.gen_diffs.genDiff_unordered_set(self)
    elif baseType == 'map':
        self.gen_diffs.genDiff_map(self)
    elif baseType == 'unordered_map':
        self.gen_diffs.genDiff_unordered_map(self)
    
    ofs = properties.get('of', [])
    for ofn in ofs:
        self.gen_diffs.genSubtypeDiffer(self, t, ofn)


def genDiff_array(self):
    if not self.dIs('diffable'):
        return

    if 'array' in self.includeDiffTypes:
        return
    self.includeDiffTypes['array'] = None

    self.includeForType('diffArray', 'array', '#include <array>')
    self.includeForType('diffArray', 'vector', '#include <vector>')
    self.includeForType('diffArray', 'pair', '#include <utility>')
    self.includeForType('diffArray', 'bitset', '#include <bitset>')

    it = self.indent()

    src = f'''


{it}template <class T, std::size_t Size>
{it}struct Diff<std::array<T, Size>>
{it}{{
{it}{it}Diff() {{ }}

{it}{it}Diff(std::array<T, Size> const & lhs, std::array<T, Size> const & rhs)
{it}{it}{{
{it}{it}{it}for (std::size_t i = 0; i < lhs.size(); ++i)
{it}{it}{it}{{
{it}{it}{it}{it}if (lhs[i] != rhs[i])
{it}{it}{it}{it}{{
{it}{it}{it}{it}{it}elementDiffs.emplace_back(i, Diff<T> {{ lhs[i], rhs[i] }});
{it}{it}{it}{it}}}
{it}{it}{it}}}
{it}{it}}}

{it}{it}std::vector<std::pair<std::size_t, Diff<T>>> elementDiffs;
{it}}};'''
    self.appendSrc('diffArray', src)


def genDiff_pair(self):
    if not self.dIs('diffable'):
        return

    if 'pair' in self.includeDiffTypes:
        return
    self.includeDiffTypes['pair'] = None

    self.includeForType('diffPair', 'pair', '#include <utility>')
    self.includeForType('diffPair', 'bitset', '#include <bitset>')

    it = self.indent()

    src = f'''


{it}template <class TF, class TS>
{it}struct Diff<std::pair<TF, TS>>
{it}{{
{it}{it}Diff() {{ }}

{it}{it}Diff(std::pair<TF, TS> const & lhs, std::pair<TF, TS> const & rhs)
{it}{it}: memberDiffs((lhs.first != rhs.first) << 0 | (lhs.second != rhs.second) << 1),
{it}{it}  diffObjects(Diff<TF>(lhs.first, rhs.first), Diff<TS>(lhs.second, rhs.second))
{it}{it}{{ }}

{it}{it}std::bitset<2> memberDiffs;
{it}{it}std::pair<Diff<TF>, Diff<TS>> diffObjects;
{it}}};'''
    self.appendSrc('diffPair', src)


def genDiff_tuple(self):
    if not self.dIs('diffable'):
        return

    if 'tuple' in self.includeDiffTypes:
        return
    self.includeDiffTypes['tuple'] = None

    self.includeForType('diffTuple', 'tuple', '#include <tuple>')
    self.includeForType('diffTuple', 'invoke', '#include <functional>')
    self.includeForType('diffTuple', 'bitset', '#include <bitset>')

    it = self.indent()

    src = f'''


{it}// Calls func with tuple element.
{it}// https://stackoverflow.com/questions/28997271/c11-way-to-index-tuple-at-runtime-without-using-switch
{it}template <class Func, class Tuple, size_t N = 0>
{it}void setCompareBit(Func func, Tuple const & tup0, Tuple const & tup1, size_t idx)
{it}{{
{it}{it}if (N == idx)
{it}{it}{{
{it}{it}{it}std::invoke(func, std::get<N>(tup0), std::get<N>(tup1), idx);
{it}{it}{it}return;
{it}{it}}}

{it}{it}if constexpr (N + 1 < std::tuple_size_v<Tuple>)
{it}{it}{{
{it}{it}{it}return setCompareBit<Func, Tuple, N + 1>(func, tup0, tup1, idx);
{it}{it}}}
{it}}}


{it}template <class ... Args>
{it}struct Diff<std::tuple<Args...>>{it}
{it}{{
{it}{it}Diff() {{ }}

{it}{it}Diff(std::tuple<Args...> const & lhs, std::tuple<Args...> const & rhs)
{it}{it}: diffObjects {{ Diff<Args>(std::get<Args>(lhs), std::get<Args>(rhs))... }}
{it}{it}{{
{it}{it}{it}for (std::size_t i = 0; i < sizeof...(Args); ++i)
{it}{it}{it}{{
{it}{it}{it}{it}setCompareBit(
{it}{it}{it}{it}{it}[this](auto const & a, auto const & b, std::size_t idx)
{it}{it}{it}{it}{it}{it}{{ memberDiffs[idx] = a != b; }}, 
{it}{it}{it}{it}{it}lhs, rhs, i);
{it}{it}{it}}}
{it}{it}}}

{it}{it}std::bitset<sizeof...(Args)> memberDiffs;
{it}{it}std::tuple<Diff<Args>...> diffObjects;
{it}}};'''
    self.appendSrc('diffTuple', src)


def genDiff_vector(self):
    if not self.dIs('diffable'):
        return

    if 'vector' in self.includeDiffTypes:
        return
    self.includeDiffTypes['vector'] = None

    self.includeForType('diffVector', 'vector', '#include <vector>')
    self.includeForType('diffVector', 'tuple', '#include <tuple>')
    self.includeForType('diffVector', 'bitset', '#include <bitset>')

    it = self.indent()

    src = f'''


{it}template <class T>
{it}struct Diff<std::vector<T>>
{it}{{
{it}{it}enum class DiffKind {{ added, replaced, removed }};

{it}{it}Diff() {{ }}

{it}{it}Diff(std::vector<T> const & lhs, std::vector<T> const & rhs)
{it}{it}{{
{it}{it}{it}for (std::size_t i = 0; i < lhs.size(); ++i)
{it}{it}{it}{{
{it}{it}{it}{it}if (rhs.size() >= i)
{it}{it}{it}{it}{{
{it}{it}{it}{it}{it}if (lhs[i] != rhs[i])
{it}{it}{it}{it}{it}{{
{it}{it}{it}{it}{it}{it}elementDiffs.emplace_back(i, DiffKind::replaced, Diff<T>(lhs[i], rhs[i]));
{it}{it}{it}{it}{it}}}
{it}{it}{it}{it}}}
{it}{it}{it}{it}else
{it}{it}{it}{it}{{
{it}{it}{it}{it}{it}elementDiffs.emplace_back(i, DiffKind::removed, Diff<T>());
{it}{it}{it}{it}}}
{it}{it}{it}}}

{it}{it}{it}for (std::size_t i = lhs.size(); i < rhs.size(); ++i)
{it}{it}{it}{{
{it}{it}{it}{it}elementDiffs.emplace_back(i, DiffKind::added, Diff<T>());
{it}{it}{it}}}
{it}{it}}}

{it}{it}std::vector<std::tuple<std::size_t, DiffKind, Diff<T>>> elementDiffs;
{it}}};'''
    self.appendSrc('diffVector', src)


def genDiff_set(self):
    if not self.dIs('diffable'):
        return

    if 'set' in self.includeDiffTypes:
        return
    self.includeDiffTypes['set'] = None

    self.includeForType('diffSet', 'set', '#include <set>')
    self.includeForType('diffSet', 'vector', '#include <vector>')
    self.includeForType('diffSet', 'tuple', '#include <tuple>')
    self.includeForType('diffSet', 'bitset', '#include <bitset>')

    it = self.indent()

    src = f'''


{it}template <class T>
{it}struct Diff<std::set<T>>
{it}{{
{it}{it}enum class DiffKind {{ added, removed }};

{it}{it}Diff() {{ }}

{it}{it}Diff(std::set<T> const & lhs, std::set<T> const & rhs)
{it}{it}{{
{it}{it}{it}// figure out diffs in maps
{it}{it}{it}for (auto const & lelem : lhs)
{it}{it}{it}{{
{it}{it}{it}{it}if (auto it = rhs.find(lelem); it == rhs.end())
{it}{it}{it}{it}{{
{it}{it}{it}{it}{it}elementDiffs.emplace_back(lelem, DiffKind::removed, Diff<T> ());
{it}{it}{it}{it}}}
{it}{it}{it}}}

{it}{it}{it}// figure out diffs in maps
{it}{it}{it}for (auto const & relem : rhs)
{it}{it}{it}{{
{it}{it}{it}{it}if (auto it = lhs.find(relem); it == lhs.end())
{it}{it}{it}{it}{{
{it}{it}{it}{it}{it}elementDiffs.emplace_back(relem, DiffKind::added, Diff<T> ());
{it}{it}{it}{it}}}
{it}{it}{it}}}
{it}{it}}}

{it}{it}std::vector<std::tuple<T, DiffKind, Diff<T>>> elementDiffs;
{it}}};'''
    self.appendSrc('diffSet', src)


def genDiff_unordered_set(self):
    if not self.dIs('diffable'):
        return

    if 'unordered_set' in self.includeDiffTypes:
        return
    self.includeDiffTypes['unordered_set'] = None

    self.includeForType('diffUnorderedSet', 'unordered_set', '#include <unordered_set>')
    self.includeForType('diffUnorderedSet', 'vector', '#include <vector>')
    self.includeForType('diffUnorderedSet', 'tuple', '#include <tuple>')
    self.includeForType('diffUnorderedSet', 'bitset', '#include <bitset>')

    it = self.indent()

    src = f'''


{it}template <class T>
{it}struct Diff<std::unordered_set<T>>
{it}{{
{it}{it}enum class DiffKind {{ added, removed }};

{it}{it}Diff() {{ }}

{it}{it}Diff(std::unordered_set<T> const & lhs, std::unordered_set<T> const & rhs)
{it}{it}{{
{it}{it}{it}// figure out diffs in maps
{it}{it}{it}for (auto const & lelem : lhs)
{it}{it}{it}{{
{it}{it}{it}{it}if (auto it = rhs.find(lelem); it == rhs.end())
{it}{it}{it}{it}{{
{it}{it}{it}{it}{it}elementDiffs.emplace_back(lelem, DiffKind::removed, Diff<T> ());
{it}{it}{it}{it}}}
{it}{it}{it}}}

{it}{it}{it}// figure out diffs in maps
{it}{it}{it}for (auto const & relem : rhs)
{it}{it}{it}{{
{it}{it}{it}{it}if (auto it = lhs.find(relem); it == lhs.end())
{it}{it}{it}{it}{{
{it}{it}{it}{it}{it}elementDiffs.emplace_back(relem, DiffKind::added, Diff<T> ());
{it}{it}{it}{it}}}
{it}{it}{it}}}
{it}{it}}}

{it}{it}std::vector<std::tuple<T, DiffKind, Diff<T>>> elementDiffs;
{it}}};'''
    self.appendSrc('diffUnorderedSet', src)


def genDiff_map(self):
    if not self.dIs('diffable'):
        return

    if 'map' in self.includeDiffTypes:
        return
    self.includeDiffTypes['map'] = None

    self.includeForType('diffMap', 'map', '#include <map>')
    self.includeForType('diffMap', 'vector', '#include <vector>')
    self.includeForType('diffMap', 'tuple', '#include <tuple>')
    self.includeForType('diffMap', 'bitset', '#include <bitset>')

    it = self.indent()

    src = f'''


{it}template <class Key, class T>
{it}struct Diff<std::map<Key, T>>
{it}{{
{it}{it}enum class DiffKind {{ added, replaced, removed }};

{it}{it}Diff() {{ }}

{it}{it}Diff(std::map<Key, T> const & lhs, std::map<Key, T> const & rhs)
{it}{it}{{
{it}{it}{it}// figure out diffs in maps
{it}{it}{it}for (auto const & lkvp : lhs)
{it}{it}{it}{{
{it}{it}{it}{it}if (auto it = rhs.find(lkvp.first); it == rhs.end())
{it}{it}{it}{it}{{
{it}{it}{it}{it}{it}elementDiffs.emplace_back(lkvp.first, DiffKind::removed, Diff<T> ());
{it}{it}{it}{it}}}
{it}{it}{it}}}

{it}{it}{it}for (auto const & lkvp : lhs)
{it}{it}{it}{{
{it}{it}{it}{it}if (auto it = rhs.find(lkvp.first); it != rhs.end() &&
{it}{it}{it}{it}{it}lkvp.second != it->second)
{it}{it}{it}{it}{{
{it}{it}{it}{it}{it}elementDiffs.emplace_back(lkvp.first, DiffKind::replaced, Diff<T> ( lkvp.second, it->second ));
{it}{it}{it}{it}}}
{it}{it}{it}}}

{it}{it}{it}for (auto const & rkvp : rhs)
{it}{it}{it}{{
{it}{it}{it}{it}if (auto it = lhs.find(rkvp.first); it != lhs.end() &&
{it}{it}{it}{it}{it}rkvp.second != it->second)
{it}{it}{it}{it}{{
{it}{it}{it}{it}{it}elementDiffs.emplace_back(rkvp.first, DiffKind::added, Diff<T> ());
{it}{it}{it}{it}}}
{it}{it}{it}}}
{it}{it}}}
{it}{it}
{it}{it}std::vector<std::tuple<Key, DiffKind, Diff<T>>> elementDiffs;
{it}}};'''
    self.appendSrc('diffMap', src)


def genDiff_unordered_map(self):
    if not self.dIs('diffable'):
        return

    if 'unordered_map' in self.includeDiffTypes:
        return
    self.includeDiffTypes['unordered_map'] = None

    self.includeForType('diffUnorderedMap', 'unordered_map', '#include <unordered_map>')
    self.includeForType('diffUnorderedMap', 'vector', '#include <vector>')
    self.includeForType('diffUnorderedMap', 'tuple', '#include <tuple>')
    self.includeForType('diffUnorderedMap', 'bitset', '#include <bitset>')

    it = self.indent()

    src = f'''


{it}template <class Key, class T>
{it}struct Diff<std::unordered_map<Key, T>>
{it}{{
{it}{it}enum class DiffKind {{ added, replaced, removed }};

{it}{it}Diff() {{ }}

{it}{it}Diff(std::unordered_map<Key, T> const & lhs, std::unordered_map<Key, T> const & rhs)
{it}{it}{{
{it}{it}{it}// figure out diffs in maps
{it}{it}{it}for (auto const & lkvp : lhs)
{it}{it}{it}{{
{it}{it}{it}{it}if (auto it = rhs.find(lkvp.first); it == rhs.end())
{it}{it}{it}{it}{{
{it}{it}{it}{it}{it}elementDiffs.emplace_back(lkvp.first, DiffKind::removed, Diff<T> ());
{it}{it}{it}{it}}}
{it}{it}{it}}}

{it}{it}{it}for (auto const & lkvp : lhs)
{it}{it}{it}{{
{it}{it}{it}{it}if (auto it = rhs.find(lkvp.first); it != rhs.end() &&
{it}{it}{it}{it}{it}lkvp.second != it->second)
{it}{it}{it}{it}{{
{it}{it}{it}{it}{it}elementDiffs.emplace_back(lkvp.first, DiffKind::replaced, Diff<T> ( lkvp.second, it->second ));
{it}{it}{it}{it}}}
{it}{it}{it}}}

{it}{it}{it}for (auto const & rkvp : rhs)
{it}{it}{it}{{
{it}{it}{it}{it}if (auto it = lhs.find(rkvp.first); it != lhs.end() &&
{it}{it}{it}{it}{it}rkvp.second != it->second)
{it}{it}{it}{it}{{
{it}{it}{it}{it}{it}elementDiffs.emplace_back(rkvp.first, DiffKind::added, Diff<T> ());
{it}{it}{it}{it}}}
{it}{it}{it}}}
{it}{it}}}
{it}{it}
{it}{it}std::vector<std::tuple<Key, DiffKind, Diff<T>>> elementDiffs;
{it}}};'''
    self.appendSrc('diffUnorderedMap', src)
