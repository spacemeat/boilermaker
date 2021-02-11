#pragma once
/*  THIS IS A GENERATED FILE. It is a Boilermaker artifact.
    Do not bother modifying this file, as your build process will overwrite
    your changes. */

#include "../v_of_couples.hpp"

namespace boma
{

    v_of_couples::v_of_couples(hu::Node node) noexcept
    : couples(node / "couples" % hu::val<std::vector<couple>>{})
    {
    }

    std::ostream & operator <<(std::ostream & out, v_of_couples const & obj) noexcept
    {
        out << '{';
        out << " couples: " << obj.couples;
        out << '}';
        return out;
    }
}
