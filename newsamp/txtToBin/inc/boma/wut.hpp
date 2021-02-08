#pragma once
/*  THIS IS A GENERATED FILE. It is a Boilermaker artifact.
    Do not bother modifying this file, as your build process will overwrite
    your changes. */

#include <humon/humon.hpp>
#include <vector>
#include <array>
#include <optional>
#include <variant>
#include <utility>
#include <string_view>
#include <string>
#include <tuple>
#include <cstddef>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
    
namespace std
{
}


namespace txtToBin
{
    class wut;
    std::ostream & operator <<(std::ostream & out, wut const & obj) noexcept;

    class wut
    {
    public:
        wut(hu::Node node) noexcept;
        friend std::ostream & operator <<(std::ostream & out, wut const & obj) noexcept;
    private:
        std::vector<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>, 4>> huh;
    }; // end class wut

}

    
namespace hu
{
    template<>
    struct val<txtToBin::wut>
    {
        static inline txtToBin::wut extract(Node const & node) noexcept;
    };
}

#include "inl/wut.inl.hpp"