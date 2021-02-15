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

    couple::couple(couple && rhs) noexcept
    {
        using std::swap;
        swap(a, rhs.a);
        swap(bee, rhs.bee);
    }

    couple & couple::operator =(couple && rhs) noexcept
    {
        using std::swap;
        swap(a, rhs.a);
        swap(bee, rhs.bee);
        return * this;
    }

    couple::~couple()
    { }

    void swap(couple & lhs, couple & rhs) noexcept
    {
        using std::swap;
        swap(lhs.a, rhs.a);
        swap(lhs.bee, rhs.bee);
    }

    std::ostream & operator <<(std::ostream & out, couple const & obj)
    {
        out << '{';
        out << " a: " << obj.a;
        out << " bee: " << obj.bee;
        out << '}';
        return out;
    }

    bool operator ==(couple const & lhs, couple const & rhs)
    {
        return lhs.a == rhs.a
            && lhs.bee == rhs.bee;
    }

    bool operator !=(couple const & lhs, couple const & rhs)
    {
        return !(lhs == rhs);
    }

    Diff<couple>::Diff(couple const & lhs, couple const & rhs)
    : memberDiffs((lhs.a != rhs.a) << static_cast<int>(Members::a) |
                  (lhs.bee != rhs.bee) << static_cast<int>(Members::bee))
    {
    }
}
