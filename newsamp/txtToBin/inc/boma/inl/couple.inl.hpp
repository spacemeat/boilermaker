#pragma once
/*  THIS IS A GENERATED FILE. It is a Boilermaker artifact.
    Do not bother modifying this file, as your build process will overwrite
    your changes. */
#include <string>
#include "containers.inl.hpp"

namespace txtToBin
{
    class couple;
    std::ostream & operator <<(std::ostream & out, couple const & obj) noexcept;

    class couple
    {
        friend std::ostream & operator <<(std::ostream & out, couple const & obj) noexcept;
    private:
        std::string a;
        ::VkResult b;
    }; // end class couple

    std::ostream & operator <<(std::ostream & out, couple const & obj) noexcept
    {
        out << '{';
        out << " a: " << obj.a;
        out << " b: " << obj.b;
        out << '}';
        return out;
    }
}
