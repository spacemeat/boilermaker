/*  THIS IS A GENERATED FILE. It is a Boilermaker artifact.
    Do not bother modifying this file, as your build process will overwrite
    your changes. */

#include "../../inc/boma/shortTest.hpp"

namespace shortTest
{

    couple::couple()
    { }

    couple::couple(std::string const & a, int const & bee)
     : a(a), bee(bee)
    { }

    couple::couple(hu::Node node) noexcept
    : a(node / "a" % hu::val<std::string>{}), 
      bee(node / "bee" % hu::val<int>{})
    {
    }

    virtual couple::~couple()
    { }

    std::ostream & operator <<(std::ostream & out, couple const & obj) noexcept
    {
        out << '{';
        out << " a: " << obj.a;
        out << " bee: " << obj.bee;
        out << '}';
        return out;
    }
}
