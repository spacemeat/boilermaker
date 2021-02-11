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

    virtual v_of_couples::~v_of_couples()
    { }

    std::ostream & operator <<(std::ostream & out, v_of_couples const & obj) noexcept
    {
        out << '{';
        out << " couples: " << obj.couples;
        out << '}';
        return out;
    }
    std::ostream & operator <<(std::ostream & out, std::vector<couple> const & obj) noexcept
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
