#pragma once
/*  THIS IS A GENERATED FILE. It is a Boilermaker artifact.
    Do not bother modifying this file, as your build process will overwrite
    your changes. */

#include <humon/humon.hpp>
#include <vector>
#include <array>
#include "couple.hpp"
    
namespace std
{
}


namespace txtToBin
{
    class v_of_a_of_couples;
    std::ostream & operator <<(std::ostream & out, v_of_a_of_couples const & obj) noexcept;

    class v_of_a_of_couples
    {
    public:
        v_of_a_of_couples(hu::Node node) noexcept;
        friend std::ostream & operator <<(std::ostream & out, v_of_a_of_couples const & obj) noexcept;
    private:
        std::vector<std::array<couple, 4>> coupleses;
    }; // end class v_of_a_of_couples

}

    
namespace hu
{
    template<>
    struct val<txtToBin::v_of_a_of_couples>
    {
        static inline txtToBin::v_of_a_of_couples extract(Node const & node) noexcept;
    };
}

#include "inl/v_of_a_of_couples.inl.hpp"