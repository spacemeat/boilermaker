#pragma once
/*  THIS IS A GENERATED FILE. It is a Boilermaker artifact.
    Do not bother modifying this file, as your build process will overwrite
    your changes. */
#include <vector>
#include <array>
#include "couple.inl.hpp"
#include "containers.inl.hpp"

namespace txtToBin
{
    class v_of_a_of_couples;
    std::ostream & operator <<(std::ostream & out, v_of_a_of_couples const & obj) noexcept;

    class v_of_a_of_couples
    {
        friend std::ostream & operator <<(std::ostream & out, v_of_a_of_couples const & obj) noexcept;
    private:
        std::vector<std::array<couple, 4>> coupleses;
    }; // end class v_of_a_of_couples

    std::ostream & operator <<(std::ostream & out, v_of_a_of_couples const & obj) noexcept
    {
        out << '{';
        out << " coupleses: " << obj.coupleses;
        out << '}';
        return out;
    }
}
