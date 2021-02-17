/*  THIS IS A GENERATED FILE. It is a Boilermaker artifact.
    Do not bother modifying this file, as your build process will overwrite
    your changes. */

#include "../../inc/boma/txtToBin.hpp"

namespace txtToBin
{

    couple::couple()
    { }

    couple::couple(std::string const & a, ::VkResult const & b)
     : a(a), b(b)
    { }

    couple::couple(hu::Node node)
    : a(node / "a" % hu::val<std::string>{}), 
      b(node / "b" % hu::val<::VkResult>{})
    {
    }

    couple::couple(couple && rhs) noexcept
    {
        using std::swap;
        swap(a, rhs.a);
        swap(b, rhs.b);
    }

    couple & couple::operator =(couple && rhs) noexcept
    {
        using std::swap;
        swap(a, rhs.a);
        swap(b, rhs.b);
        return * this;
    }

    couple::~couple()
    { }

    void swap(couple & lhs, couple & rhs) noexcept
    {
        using std::swap;
        swap(lhs.a, rhs.a);
        swap(lhs.b, rhs.b);
    }

    std::ostream & operator <<(std::ostream & out, couple const & obj)
    {
        out << '{';
        out << " a: " << obj.a;
        out << " b: " << obj.b;
        out << '}';
        return out;
    }

    bool operator ==(couple const & lhs, couple const & rhs)
    {
        return lhs.a == rhs.a
            && lhs.b == rhs.b;
    }

    bool operator !=(couple const & lhs, couple const & rhs)
    {
        return !(lhs == rhs);
    }

    Diff<couple>::Diff(couple const & lhs, couple const & rhs)
    : memberDiffs((lhs.a != rhs.a) << static_cast<int>(Members::a) |
                  (lhs.b != rhs.b) << static_cast<int>(Members::b))
    {
    }
}
