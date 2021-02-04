#pragma once
/*  THIS IS A GENERATED FILE. It is a Boilermaker artifact.
    Do not bother modifying this file, as your build process will overwrite
    your changes. */

namespace txtToBin
{
    inline std::ostream & operator <<(std::ostream & out, std::vector<couple> const & obj) noexcept;
    inline std::ostream & operator <<(std::ostream & out, std::array<couple, 4> const & obj) noexcept;
    inline std::ostream & operator <<(std::ostream & out, std::vector<std::array<couple, 4>> const & obj) noexcept;
    inline std::ostream & operator <<(std::ostream & out, std::pair<std::string_view, std::string> const & obj) noexcept;
    inline std::ostream & operator <<(std::ostream & out, std::tuple<std::size_t, int, double> const & obj) noexcept;
    inline std::ostream & operator <<(std::ostream & out, std::map<std::string_view, int> const & obj) noexcept;
    inline std::ostream & operator <<(std::ostream & out, std::unordered_map<std::string_view, int> const & obj) noexcept;
    inline std::ostream & operator <<(std::ostream & out, std::set<std::unordered_map<std::string_view, int>> const & obj) noexcept;
    inline std::ostream & operator <<(std::ostream & out, std::unordered_set<std::string_view, int> const & obj) noexcept;
    inline std::ostream & operator <<(std::ostream & out, std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>> const & obj) noexcept;
    inline std::ostream & operator <<(std::ostream & out, std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>> const & obj) noexcept;
    inline std::ostream & operator <<(std::ostream & out, std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>, 4> const & obj) noexcept;
    inline std::ostream & operator <<(std::ostream & out, std::vector<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>, 4>> const & obj) noexcept;
}

namespace txtToBin
{
    inline std::ostream & operator <<(std::ostream & out, std::vector<couple> const & obj) noexcept
    {
        out << '[';
        bool firstTime = true;
        for (auto const & objmem : obj)
        {
            if (firstTime)
                { firstTime = false; }
            else
                { out << ' '; }
            out << objmem;
        }
        out << ']';
        return out;
    }
    inline std::ostream & operator <<(std::ostream & out, std::array<couple, 4> const & obj) noexcept
    {
        out << '[';
        out << obj[0];
        out << ' ';
        out << obj[1];
        out << ' ';
        out << obj[2];
        out << ' ';
        out << obj[3];
        out << ']';
        return out;
    }
    inline std::ostream & operator <<(std::ostream & out, std::vector<std::array<couple, 4>> const & obj) noexcept
    {
        out << '[';
        bool firstTime = true;
        for (auto const & objmem : obj)
        {
            if (firstTime)
                { firstTime = false; }
            else
                { out << ' '; }
            out << objmem;
        }
        out << ']';
        return out;
    }
    inline std::ostream & operator <<(std::ostream & out, std::pair<std::string_view, std::string> const & obj) noexcept
    {
        out << '[';
        out << std::get<0>(obj);
        out << ' ';
        out << std::get<1>(obj);
        out << ']';
        return out;
    }
    inline std::ostream & operator <<(std::ostream & out, std::tuple<std::size_t, int, double> const & obj) noexcept
    {
        out << '[';
        out << std::get<0>(obj);
        out << ' ';
        out << std::get<1>(obj);
        out << ' ';
        out << std::get<2>(obj);
        out << ']';
        return out;
    }
    inline std::ostream & operator <<(std::ostream & out, std::map<std::string_view, int> const & obj) noexcept
    {
        out << '{';
        bool firstTime = true;
        for (auto & elem : obj)
        {
            if (firstTime)
                { firstTime = false; }
            else
                { out << ' '; }
            out << elem.first << ": " << elem.second;
        }
        out << '}';
        return out;
    }
    inline std::ostream & operator <<(std::ostream & out, std::unordered_map<std::string_view, int> const & obj) noexcept
    {
        out << '{';
        bool firstTime = true;
        for (auto & elem : obj)
        {
            if (firstTime)
                { firstTime = false; }
            else
                { out << ' '; }
            out << elem.first << ": " << elem.second;
        }
        out << '}';
        return out;
    }
    inline std::ostream & operator <<(std::ostream & out, std::set<std::unordered_map<std::string_view, int>> const & obj) noexcept
    {
        out << '[';
        bool firstTime = true;
        for (auto const & objmem : obj)
        {
            if (firstTime)
                { firstTime = false; }
            else
                { out << ' '; }
            out << objmem;
        }
        out << ']';
        return out;
    }
    inline std::ostream & operator <<(std::ostream & out, std::unordered_set<std::string_view, int> const & obj) noexcept
    {
        out << '[';
        bool firstTime = true;
        for (auto const & objmem : obj)
        {
            if (firstTime)
                { firstTime = false; }
            else
                { out << ' '; }
            out << objmem;
        }
        out << ']';
        return out;
    }
    inline std::ostream & operator <<(std::ostream & out, std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>> const & obj) noexcept
    {
        if (auto p = std::get_if<std::pair<std::string_view, std::string>>(& obj); p) { out << *p << " @type: None"; }
        if (auto p = std::get_if<std::tuple<std::size_t, int, double>>(& obj); p) { out << *p << " @type: None"; }
        if (auto p = std::get_if<std::map<std::string_view, int>>(& obj); p) { out << *p << " @type: None"; }
        if (auto p = std::get_if<std::unordered_map<std::string_view, int>>(& obj); p) { out << *p << " @type: None"; }
        if (auto p = std::get_if<std::set<std::unordered_map<std::string_view, int>>>(& obj); p) { out << *p << " @type: None"; }
        if (auto p = std::get_if<std::unordered_set<std::string_view, int>>(& obj); p) { out << *p << " @type: None"; }
        return out;
    }
    inline std::ostream & operator <<(std::ostream & out, std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>> const & obj) noexcept
    {
    if (obj.has_value())
        { out << * obj; }
    else
        { out << '_'; }
        return out;
    }
    inline std::ostream & operator <<(std::ostream & out, std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>, 4> const & obj) noexcept
    {
        out << '[';
        out << obj[0];
        out << ' ';
        out << obj[1];
        out << ' ';
        out << obj[2];
        out << ' ';
        out << obj[3];
        out << ']';
        return out;
    }
    inline std::ostream & operator <<(std::ostream & out, std::vector<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>, 4>> const & obj) noexcept
    {
        out << '[';
        bool firstTime = true;
        for (auto const & objmem : obj)
        {
            if (firstTime)
                { firstTime = false; }
            else
                { out << ' '; }
            out << objmem;
        }
        out << ']';
        return out;
    }
}
