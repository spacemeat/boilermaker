/*  THIS IS A GENERATED FILE. It is a Boilermaker artifact.
    Do not bother modifying this file, as your build process will overwrite
    your changes. */

#include "../../inc/boma/shortTest.hpp"

namespace shortTest
{

    a_of_v_of_couples::a_of_v_of_couples()
    { }

    a_of_v_of_couples::a_of_v_of_couples(std::array<std::vector<couple>, 4> const & coupleses)
     : coupleses(coupleses)
    { }

    a_of_v_of_couples::a_of_v_of_couples(hu::Node node) noexcept
    : coupleses(node / "coupleses" % hu::val<std::array<std::vector<couple>, 4>>{})
    {
    }

    a_of_v_of_couples::a_of_v_of_couples(a_of_v_of_couples && rhs) noexcept
    {
        using std::swap;
        swap(coupleses, rhs.coupleses);
    }

    a_of_v_of_couples & a_of_v_of_couples::operator =(a_of_v_of_couples && rhs) noexcept
    {
        using std::swap;
        swap(coupleses, rhs.coupleses);
        return * this;
    }

    a_of_v_of_couples::~a_of_v_of_couples()
    { }

    void swap(a_of_v_of_couples & lhs, a_of_v_of_couples & rhs) noexcept
    {
        using std::swap;
        swap(lhs.coupleses, rhs.coupleses);
    }

    std::ostream & operator <<(std::ostream & out, a_of_v_of_couples const & obj)
    {
        out << '{';
        out << " coupleses: " << obj.coupleses;
        out << '}';
        return out;
    }

    bool operator ==(a_of_v_of_couples const & lhs, a_of_v_of_couples const & rhs)
    {
        return lhs.coupleses == rhs.coupleses;
    }

    bool operator !=(a_of_v_of_couples const & lhs, a_of_v_of_couples const & rhs)
    {
        return !(lhs == rhs);
    }

    Diff<a_of_v_of_couples>::Diff(a_of_v_of_couples const & lhs, a_of_v_of_couples const & rhs)
    : memberDiffs((lhs.coupleses != rhs.coupleses) << static_cast<int>(Members::coupleses)),
      coupleses_diffs(lhs.coupleses, rhs.coupleses)
    {
    }
        
    std::ostream & operator <<(std::ostream & out, std::array<std::vector<couple>, 4> const & obj)
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
