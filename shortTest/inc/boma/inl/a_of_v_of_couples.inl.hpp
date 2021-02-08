#pragma once
/*  THIS IS A GENERATED FILE. It is a Boilermaker artifact.
    Do not bother modifying this file, as your build process will overwrite
    your changes. */

#include "../a_of_v_of_couples.hpp"

namespace shortTest
{

    a_of_v_of_couples::a_of_v_of_couples(hu::Node node) noexcept
    : coupleses(node / "coupleses" % hu::val<std::array<std::vector<couple>, 4>>{})
    {
    }

    std::ostream & operator <<(std::ostream & out, a_of_v_of_couples const & obj) noexcept
    {
        out << '{';
        out << " coupleses: " << obj.coupleses;
        out << '}';
        return out;
    }
    inline std::ostream & operator <<(std::ostream & out, std::array<std::vector<couple>, 4> const & obj) noexcept
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

}
