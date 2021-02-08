#pragma once
/*  THIS IS A GENERATED FILE. It is a Boilermaker artifact.
    Do not bother modifying this file, as your build process will overwrite
    your changes. */

#include "../couple.hpp"

namespace shortTest
{

    couple::couple(hu::Node node) noexcept
    : a(node / "a" % hu::val<std::string>{}), 
      b(node / "b" % hu::val<int>{})
    {
    }

    std::ostream & operator <<(std::ostream & out, couple const & obj) noexcept
    {
        out << '{';
        out << " a: " << obj.a;
        out << " b: " << obj.b;
        out << '}';
        return out;
    }
}
