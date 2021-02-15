/*  THIS IS A GENERATED FILE. It is a Boilermaker artifact.
    Do not bother modifying this file, as your build process will overwrite
    your changes. */

#include "../../inc/boma/shortTest.hpp"

namespace shortTest
{

    v_of_couples::v_of_couples()
    { }

    v_of_couples::v_of_couples(std::vector<couple> const & couples)
     : couples(couples)
    { }

    v_of_couples::v_of_couples(hu::Node node) noexcept
    : couples(node / "couples" % hu::val<std::vector<couple>>{})
    {
    }

    v_of_couples::v_of_couples(v_of_couples && rhs) noexcept
    {
        using std::swap;
        swap(couples, rhs.couples);
    }

    v_of_couples & v_of_couples::operator =(v_of_couples && rhs) noexcept
    {
        using std::swap;
        swap(couples, rhs.couples);
        return * this;
    }

    v_of_couples::~v_of_couples()
    { }

    void swap(v_of_couples & lhs, v_of_couples & rhs) noexcept
    {
        using std::swap;
        swap(lhs.couples, rhs.couples);
    }

    std::ostream & operator <<(std::ostream & out, v_of_couples const & obj)
    {
        out << '{';
        out << " couples: " << obj.couples;
        out << '}';
        return out;
    }

    bool operator ==(v_of_couples const & lhs, v_of_couples const & rhs)
    {
        return lhs.couples == rhs.couples;
    }

    bool operator !=(v_of_couples const & lhs, v_of_couples const & rhs)
    {
        return !(lhs == rhs);
    }

    Diff<v_of_couples>::Diff(v_of_couples const & lhs, v_of_couples const & rhs)
    : memberDiffs((lhs.couples != rhs.couples) << static_cast<int>(Members::couples)),
      couples_diffs(lhs.couples, rhs.couples)
    {
    }
        
    std::ostream & operator <<(std::ostream & out, std::vector<couple> const & obj)
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
