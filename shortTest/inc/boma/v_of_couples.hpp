#pragma once
/*  THIS IS A GENERATED FILE. It is a Boilermaker artifact.
    Do not bother modifying this file, as your build process will overwrite
    your changes. */

#include <humon/humon.hpp>
#include <vector>
#include "couple.hpp"
    
namespace std
{
}


namespace shortTest
{
    class v_of_couples;
    std::ostream & operator <<(std::ostream & out, v_of_couples const & obj) noexcept;

    class v_of_couples
    {
    public:
        v_of_couples(hu::Node node) noexcept;
        friend std::ostream & operator <<(std::ostream & out, v_of_couples const & obj) noexcept;
    private:
        std::vector<couple> couples;
    }; // end class v_of_couples

    inline std::ostream & operator <<(std::ostream & out, std::vector<couple> const & obj) noexcept;
}

template<>
struct hu::val<shortTest::v_of_couples>
{
    inline shortTest::v_of_couples extract(hu::Node const & node) noexcept
    {
        return shortTest::v_of_couples(node);
    }
};

template <>
struct hu::val<std::vector<shortTest::couple>>
{
    static inline std::vector<shortTest::couple> extract(hu::Node const & node) noexcept
    {
        std::vector<shortTest::couple> rv;
        for (size_t i = 0; i < node.numChildren(); ++i)
        {
            rv.emplace_back(std::move(node / i % hu::val<shortTest::couple>{}));
        }
        return rv;
    }
};
#include "inl/v_of_couples.inl.hpp"