#pragma once
/*  THIS IS A GENERATED FILE. It is a Boilermaker artifact.
    Do not bother modifying this file, as your build process will overwrite
    your changes. */

#include <humon/humon.hpp>
#include <string>
    
namespace std
{
}


namespace shortTest
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
        int b;
    }; // end class couple

}

template<>
struct hu::val<shortTest::couple>
{
    inline shortTest::couple extract(hu::Node const & node) noexcept
    {
        return shortTest::couple(node);
    }
};
#include "inl/couple.inl.hpp"