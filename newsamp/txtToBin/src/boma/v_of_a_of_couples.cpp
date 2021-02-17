/*  THIS IS A GENERATED FILE. It is a Boilermaker artifact.
    Do not bother modifying this file, as your build process will overwrite
    your changes. */

#include "../../inc/boma/txtToBin.hpp"

namespace txtToBin
{

    v_of_a_of_couples::v_of_a_of_couples()
    { }

    v_of_a_of_couples::v_of_a_of_couples(std::vector<std::array<couple, 4>> const & coupleses)
     : coupleses(coupleses)
    { }

    v_of_a_of_couples::v_of_a_of_couples(hu::Node node)
    : coupleses(node / "coupleses" % hu::val<std::vector<std::array<couple, 4>>>{})
    {
    }

    v_of_a_of_couples::v_of_a_of_couples(v_of_a_of_couples && rhs) noexcept
    {
        using std::swap;
        swap(coupleses, rhs.coupleses);
    }

    v_of_a_of_couples & v_of_a_of_couples::operator =(v_of_a_of_couples && rhs) noexcept
    {
        using std::swap;
        swap(coupleses, rhs.coupleses);
        return * this;
    }

    v_of_a_of_couples::~v_of_a_of_couples()
    { }

    void swap(v_of_a_of_couples & lhs, v_of_a_of_couples & rhs) noexcept
    {
        using std::swap;
        swap(lhs.coupleses, rhs.coupleses);
    }

    std::ostream & operator <<(std::ostream & out, v_of_a_of_couples const & obj)
    {
        out << '{';
        out << " coupleses: " << obj.coupleses;
        out << '}';
        return out;
    }

    bool operator ==(v_of_a_of_couples const & lhs, v_of_a_of_couples const & rhs)
    {
        return lhs.coupleses == rhs.coupleses;
    }

    bool operator !=(v_of_a_of_couples const & lhs, v_of_a_of_couples const & rhs)
    {
        return !(lhs == rhs);
    }

    Diff<v_of_a_of_couples>::Diff(v_of_a_of_couples const & lhs, v_of_a_of_couples const & rhs)
    : memberDiffs((lhs.coupleses != rhs.coupleses) << static_cast<int>(Members::coupleses)),
      coupleses_diffs(lhs.coupleses, rhs.coupleses)
    {
    }
        
    std::ostream & operator <<(std::ostream & out, std::array<couple, 4> const & obj)
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

        
    std::ostream & operator <<(std::ostream & out, std::vector<std::array<couple, 4>> const & obj)
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
