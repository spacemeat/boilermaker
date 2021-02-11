#pragma once

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
        v_of_couples();
        v_of_couples(std::vector<couple> const & couples);
        v_of_couples(hu::Node node) noexcept;
        v_of_couples(v_of_couples const & rhs) = default;
        v_of_couples(v_of_couples const && rhs) = delete;
        v_of_couples & operator =(v_of_couples const & rhs) = default;
        v_of_couples & operator =(v_of_couples const && rhs) = delete;
        virtual ~v_of_couples();
        std::vector<couple>         v_of_couples::get_couples() &&      { return couples; }
        std::vector<couple> const & v_of_couples::get_couples() const & { return couples; }
        std::vector<couple>       & v_of_couples::get_couples() &       { return couples; }
        void set_couples(std::vector<couple> const & new_couples) { couples = new_couples; }
        void set_couples(std::vector<couple> && new_couples)      { using std::swap; swap(couples, new_couples); }
        friend std::ostream & operator <<(std::ostream & out, v_of_couples const & obj) noexcept;
    private:
        std::vector<couple> couples;
    }; // end class v_of_couples

    std::ostream & operator <<(std::ostream & out, std::vector<couple> const & obj) noexcept;
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