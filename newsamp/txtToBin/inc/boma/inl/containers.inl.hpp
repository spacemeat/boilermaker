#pragma once
/*  THIS IS A GENERATED FILE. It is a Boilermaker artifact.
    Do not bother modifying this file, as your build process will overwrite
    your changes. */

#include <string>
#include <vector>
#include <array>
#include <optional>
#include <variant>
#include <utility>
#include <string_view>
#include <tuple>
#include <cstddef>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include "../couple.hpp"
    
namespace hu
{

    inline std::vector<txtToBin::couple> val<std::vector<txtToBin::couple>>::extract(Node const & node) noexcept
    {
        std::vector<txtToBin::couple> rv;
        for (size_t i = 0; i < node.numChildren(); ++i)
        {
            rv.emplace_back(std::move(node / i % val<txtToBin::couple>{}));
        }
        return rv;
    }

    inline std::array<txtToBin::couple, 4> val<std::array<txtToBin::couple, 4>>::extract(Node const & node) noexcept
    {
        return std::array<txtToBin::couple, 4> {
            std::move(val<txtToBin::couple>::extract(node / 0)),
            std::move(val<txtToBin::couple>::extract(node / 1)),
            std::move(val<txtToBin::couple>::extract(node / 2)),
            std::move(val<txtToBin::couple>::extract(node / 3))
        };
    }

    inline std::vector<std::array<txtToBin::couple, 4>> val<std::vector<std::array<txtToBin::couple, 4>>>::extract(Node const & node) noexcept
    {
        std::vector<std::array<txtToBin::couple, 4>> rv;
        for (size_t i = 0; i < node.numChildren(); ++i)
        {
            rv.emplace_back(std::move(node / i % val<std::array<txtToBin::couple, 4>>{}));
        }
        return rv;
    }

    inline std::pair<std::string_view, std::string> val<std::pair<std::string_view, std::string>>::extract(Node const & node) noexcept
    {
        return std::pair<std::string_view, std::string> {
            std::move(val<std::string_view>::extract(node / 0)),
            std::move(val<std::string>::extract(node / 1))
        };
    }

    inline std::tuple<std::size_t, int, double> val<std::tuple<std::size_t, int, double>>::extract(Node const & node) noexcept
    {
        return std::tuple<std::size_t, int, double> {
            std::move(val<std::size_t>::extract(node / 0)),
            std::move(val<int>::extract(node / 1)),
            std::move(val<double>::extract(node / 2))
        };
    }

    inline std::map<std::string_view, int> val<std::map<std::string_view, int>>::extract(Node const & node) noexcept
    {
        std::map<std::string_view, int> rv;
        for (size_t i = 0; i < node.numChildren(); ++i)
        {
            Node elemNode = node / i;
            rv.emplace(std::move(val<std::string_view>::extract(elemNode.key().str())),
                       std::move(elemNode % val<int>{}));
        }
        return rv;
    }

    inline std::unordered_map<std::string_view, int> val<std::unordered_map<std::string_view, int>>::extract(Node const & node) noexcept
    {
        std::unordered_map<std::string_view, int> rv;
        for (size_t i = 0; i < node.numChildren(); ++i)
        {
            Node elemNode = node / i;
            rv.emplace(std::move(val<std::string_view>::extract(elemNode.key().str())),
                       std::move(elemNode % val<int>{}));
        }
        return rv;
    }

    inline std::set<std::unordered_map<std::string_view, int>> val<std::set<std::unordered_map<std::string_view, int>>>::extract(Node const & node) noexcept
    {
        std::set<std::unordered_map<std::string_view, int>> rv;
        for (size_t i = 0; i < node.numChildren(); ++i)
        {
            rv.emplace(std::move(node / i % val<std::unordered_map<std::string_view, int>>{}));
        }
        return rv;
    }

    inline std::unordered_set<std::string_view, int> val<std::unordered_set<std::string_view, int>>::extract(Node const & node) noexcept
    {
        std::unordered_set<std::string_view, int> rv;
        for (size_t i = 0; i < node.numChildren(); ++i)
        {
            rv.emplace(std::move(node / i % val<std::string_view>{}));
        }
        return rv;
    }

    inline std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>> val<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>::extract(Node const & node) noexcept
    {
        Token tok = node.annotation("type");
        if (! tok)
            { return { }; }
        std::string_view tokStr = tok.str();
        if (tokStr == "pair")
            { return node % val<std::pair<std::string_view, std::string>>{}; }
        if (tokStr == "tuple")
            { return node % val<std::tuple<std::size_t, int, double>>{}; }
        if (tokStr == "map")
            { return node % val<std::map<std::string_view, int>>{}; }
        if (tokStr == "unordered_map")
            { return node % val<std::unordered_map<std::string_view, int>>{}; }
        if (tokStr == "set")
            { return node % val<std::set<std::unordered_map<std::string_view, int>>>{}; }
        if (tokStr == "unordered_set")
            { return node % val<std::unordered_set<std::string_view, int>>{}; }
        return { };
    }

    inline std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>> val<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>>::extract(Node const & node) noexcept
    {
        if (! node)
            { return {}; }
        else if (node.kind() == NodeKind::value && node.value().str() == "_")
            { return {}; }
        else
            { return node % val<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>{}; }
    }

    inline std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>, 4> val<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>, 4>>::extract(Node const & node) noexcept
    {
        return std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>, 4> {
            std::move(val<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>>::extract(node / 0)),
            std::move(val<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>>::extract(node / 1)),
            std::move(val<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>>::extract(node / 2)),
            std::move(val<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>>::extract(node / 3))
        };
    }

    inline std::vector<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>, 4>> val<std::vector<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>, 4>>>::extract(Node const & node) noexcept
    {
        std::vector<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>, 4>> rv;
        for (size_t i = 0; i < node.numChildren(); ++i)
        {
            rv.emplace_back(std::move(node / i % val<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>, 4>>{}));
        }
        return rv;
    }
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
