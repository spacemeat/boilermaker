#pragma once
/*  THIS IS A GENERATED FILE. It is a Boilermaker artifact.
    Do not bother modifying this file, as your build process will overwrite
    your changes. */

#include <humon/humon.hpp>
#include <string>
    
namespace std
{
}


namespace txtToBin
{
    class couple;
    std::ostream & operator <<(std::ostream & out, couple const & obj) noexcept;

    class couple
    {
    public:
        couple(hu::Node node) noexcept;
        friend std::ostream & operator <<(std::ostream & out, couple const & obj) noexcept;
    private:
        std::string a;
        ::VkResult b;
    }; // end class couple

}

    
namespace hu
{
    template<>
    struct val<txtToBin::couple>
    {
        static inline txtToBin::couple extract(Node const & node) noexcept;
    };
}

#include "inl/couple.inl.hpp"