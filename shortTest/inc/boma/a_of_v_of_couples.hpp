#pragma once
/*  THIS IS A GENERATED FILE. It is a Boilermaker artifact.
    Do not bother modifying this file, as your build process will overwrite
    your changes. */

#include <humon/humon.hpp>
#include <array>
#include <vector>
#include "couple.hpp"
    
namespace std
{
}


namespace shortTest
{
    class a_of_v_of_couples;
    std::ostream & operator <<(std::ostream & out, a_of_v_of_couples const & obj) noexcept;

    class a_of_v_of_couples
    {
    public:
        a_of_v_of_couples(hu::Node node) noexcept;
        friend std::ostream & operator <<(std::ostream & out, a_of_v_of_couples const & obj) noexcept;
    private:
        std::array<std::vector<couple>, 4> coupleses;
    }; // end class a_of_v_of_couples

    inline std::ostream & operator <<(std::ostream & out, std::array<std::vector<couple>, 4> const & obj) noexcept;
}

template<>
struct hu::val<shortTest::a_of_v_of_couples>
{
    inline shortTest::a_of_v_of_couples extract(hu::Node const & node) noexcept
    {
        return shortTest::a_of_v_of_couples(node);
    }
};

template <>
struct hu::val<std::array<std::vector<shortTest::couple>, 4>>
{
    static inline std::array<std::vector<shortTest::couple>, 4> extract(hu::Node const & node) noexcept
    {
        return std::array<std::vector<shortTest::couple>, 4> {
            std::move(node / 0 % hu::val<std::vector<shortTest::couple>> {}),
            std::move(node / 1 % hu::val<std::vector<shortTest::couple>> {}),
            std::move(node / 2 % hu::val<std::vector<shortTest::couple>> {}),
            std::move(node / 3 % hu::val<std::vector<shortTest::couple>> {})
        };
    }
};
#include "inl/a_of_v_of_couples.inl.hpp"