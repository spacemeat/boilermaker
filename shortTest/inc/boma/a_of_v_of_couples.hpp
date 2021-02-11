#pragma once

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
        a_of_v_of_couples();
        a_of_v_of_couples(std::array<std::vector<couple>, 4> const & coupleses);
        a_of_v_of_couples(hu::Node node) noexcept;
        a_of_v_of_couples(a_of_v_of_couples const & rhs) = default;
        a_of_v_of_couples(a_of_v_of_couples const && rhs) = delete;
        a_of_v_of_couples & operator =(a_of_v_of_couples const & rhs) = default;
        a_of_v_of_couples & operator =(a_of_v_of_couples const && rhs) = delete;
        virtual ~a_of_v_of_couples();
        std::array<std::vector<couple>, 4>         a_of_v_of_couples::get_coupleses() &&      { return coupleses; }
        std::array<std::vector<couple>, 4> const & a_of_v_of_couples::get_coupleses() const & { return coupleses; }
        std::array<std::vector<couple>, 4>       & a_of_v_of_couples::get_coupleses() &       { return coupleses; }
        void set_coupleses(std::array<std::vector<couple>, 4> const & new_coupleses) { coupleses = new_coupleses; }
        void set_coupleses(std::array<std::vector<couple>, 4> && new_coupleses)      { using std::swap; swap(coupleses, new_coupleses); }
        friend std::ostream & operator <<(std::ostream & out, a_of_v_of_couples const & obj) noexcept;
    private:
        std::array<std::vector<couple>, 4> coupleses;
    }; // end class a_of_v_of_couples

    std::ostream & operator <<(std::ostream & out, std::array<std::vector<couple>, 4> const & obj) noexcept;
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