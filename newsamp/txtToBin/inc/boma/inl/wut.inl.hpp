#pragma once
/*  THIS IS A GENERATED FILE. It is a Boilermaker artifact.
    Do not bother modifying this file, as your build process will overwrite
    your changes. */

#include "../wut.hpp"
#include "containers.inl.hpp"

namespace txtToBin
{

    wut::wut(hu::Node node) noexcept
    : huh(node / "huh" % hu::val<std::vector<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>, 4>>>{})
    {
    }

    std::ostream & operator <<(std::ostream & out, wut const & obj) noexcept
    {
        out << '{';
        out << " huh: " << obj.huh;
        out << '}';
        return out;
    }
}

    
namespace hu
{
    inline txtToBin::wut val<txtToBin::wut>::extract(Node const & node) noexcept
    {
        return txtToBin::wut(node);
    }
}
