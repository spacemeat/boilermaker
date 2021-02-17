/*  THIS IS A GENERATED FILE. It is a Boilermaker artifact.
    Do not bother modifying this file, as your build process will overwrite
    your changes. */

#include <iostream>
#include "../../inc/boma/enums.hpp"

namespace shortTest
{


    std::ostream & operator <<(std::ostream & out, ::eAnimals obj)
    {
        using enumIntType = std::underlying_type<::eAnimals>::type;
        switch (obj)
        {
        case ::E_CAT: out << "cat"; break;
        case ::E_DOG: out << "dog"; break;
        case ::E_PIG: out << "pig"; break;
        case ::E_BUG: out << "bug"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::eBugs obj)
    {
        using enumIntType = std::underlying_type<::eBugs>::type;
        switch (obj)
        {
        case ::E_ANT: out << "ant"; break;
        case ::E_BEE: out << "bee"; break;
        case ::E_FLY: out << "fly"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }
}
