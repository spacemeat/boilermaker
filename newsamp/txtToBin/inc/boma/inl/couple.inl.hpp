#pragma once
/*  THIS IS A GENERATED FILE. It is a Boilermaker artifact.
    Do not bother modifying this file, as your build process will overwrite
    your changes. */

#include "../couple.hpp"
#include "containers.inl.hpp"

namespace txtToBin
{

    couple::couple(hu::Node node) noexcept
    : a(node / "a" % hu::val<std::string>{}), 
      b(node / "b" % hu::val<::VkResult>{})
    {
    }

    std::ostream & operator <<(std::ostream & out, couple const & obj) noexcept
    {
        out << '{';
        out << " a: " << obj.a;
        out << " b: " << obj.b;
        out << '}';
        return out;
    }
}

    
namespace hu
{
    inline txtToBin::couple val<txtToBin::couple>::extract(Node const & node) noexcept
    {
        return txtToBin::couple(node);
    }
}
