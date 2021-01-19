def getDiff_template(indenter, ind):
    return f'''


{indenter(ind + 0)}template <class PodType>
{indenter(ind + 0)}struct Diff
{indenter(ind + 0)}{{
{indenter(ind + 1)}Diff() {{ }}

{indenter(ind + 1)}Diff(PodType const & lhs, PodType const & rhs)
{indenter(ind + 1)}{{
{indenter(ind + 2)}diff = lhs != rhs;
{indenter(ind + 1)}}}

{indenter(ind + 1)}bool diff = false;
{indenter(ind + 0)}}};'''


def getDiff_array(indenter, ind):
    return f'''


{indenter(ind + 0)}template <class T, std::size_t Size>
{indenter(ind + 0)}struct Diff<std::array<T, Size>>
{indenter(ind + 0)}{{
{indenter(ind + 1)}Diff() {{ }}

{indenter(ind + 1)}Diff(std::array<T, Size> const & lhs, std::array<T, Size> const & rhs)
{indenter(ind + 1)}{{
{indenter(ind + 2)}for (std::size_t i = 0; i < lhs.size(); ++i)
{indenter(ind + 2)}{{
{indenter(ind + 3)}if (lhs[i] != rhs[i])
{indenter(ind + 3)}{{
{indenter(ind + 4)}diffs.emplace_back(i, Diff<T> {{ lhs[i], rhs[i] }});
{indenter(ind + 3)}}}
{indenter(ind + 2)}}}
{indenter(ind + 1)}}}

{indenter(ind + 1)}std::vector<std::pair<std::size_t, Diff<T>>> diffs;
{indenter(ind + 0)}}};'''


def getDiff_vector(indenter, ind):
    return f'''


    template <class T>
    struct Diff<std::vector<T>>
    {{
        enum class DiffKind {{ added, replaced, removed }};

        Diff() {{ }}

        Diff(std::vector<T> const & lhs, std::vector<T> const & rhs)
        {{
            for (std::size_t i = 0; i < lhs.size(); ++i)
            {{
                if (rhs.size() >= i)
                {{
                    if (lhs[i] != rhs[i])
                    {{
                        diffs.emplace_back(i, DiffKind::replaced, Diff<T>(lhs[i], rhs[i]));
                    }}
                }}
                else
                {{
                    diffs.emplace_back(i, DiffKind::removed, Diff<T>());
                }}
            }}

            for (std::size_t i = lhs.size(); i < rhs.size(); ++i)
            {{
                diffs.emplace_back(i, DiffKind::added, Diff<T>());
            }}
        }}

        std::vector<std::tuple<std::size_t, DiffKind, Diff<T>>> diffs;
    }};'''


def getDiff_set(indenter, ind):
    return f'''


    template <class T>
    struct Diff<std::set<T>>
    {{
        enum class DiffKind {{ added, removed }};

        Diff() {{ }}

        Diff(std::set<T> const & lhs, std::set<T> const & rhs)
        {{
            // figure out diffs in maps
            for (auto const & lelem : lhs)
            {{
                if (auto it = rhs.find(lelem); it == rhs.end())
                {{
                    differenceKeys.emplace_back(lelem, DiffKind::removed, Diff<T> ());
                }}
            }}

            // figure out diffs in maps
            for (auto const & relem : rhs)
            {{
                if (auto it = lhs.find(relem); it == lhs.end())
                {{
                    differenceKeys.emplace_back(relem, DiffKind::added, Diff<T> ());
                }}
            }}
        }}

        std::vector<std::tuple<T, DiffKind, Diff<T>>> differenceKeys;
    }};'''


def getDiff_unordered_set(indenter, ind):
    return getDiff_set(indenter, ind).replace('set', 'unordered_set')


def getDiff_map(indenter, ind):
    return f'''


    template <class Key, class T>
    struct Diff<std::map<Key, T>>
    {{
        enum class DiffKind {{ added, replaced, removed }};

        Diff() {{ }}

        Diff(std::map<Key, T> const & lhs, std::map<Key, T> const & rhs)
        {{
            // figure out diffs in maps
            for (auto const & lkvp : lhs)
            {{
                if (auto it = rhs.find(lkvp.first); it == rhs.end())
                {{
                    differenceKeys.emplace_back(lkvp.first, DiffKind::removed, Diff<T> ());
                }}
            }}

            for (auto const & lkvp : lhs)
            {{
                if (auto it = rhs.find(lkvp.first); it != rhs.end() &&
                    lkvp.second != it->second)
                {{
                    differenceKeys.emplace_back(lkvp.first, DiffKind::replaced, Diff<T> ( lkvp.second, it->second ));
                }}
            }}

            for (auto const & rkvp : rhs)
            {{
                if (auto it = lhs.find(rkvp.first); it != lhs.end() &&
                    rkvp.second != it->second)
                {{
                    differenceKeys.emplace_back(rkvp.first, DiffKind::added, Diff<T> ());
                }}
            }}
        }}
        
        std::vector<std::tuple<Key, DiffKind, Diff<T>>> differenceKeys;
    }};'''


def getDiff_unordered_map(indenter, ind):
    return getDiff_map(indenter, ind).replace('map', 'unordered_map')
