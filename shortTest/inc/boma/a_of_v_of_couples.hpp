#pragma once

#include <humon/humon.hpp>
#include <array>
#include <vector>
#include "diffs.hpp"
#include "couple.hpp"
    
namespace std
{
}


namespace shortTest
{
    class a_of_v_of_couples;
    void swap(a_of_v_of_couples & lhs, a_of_v_of_couples & rhs) noexcept;
    std::ostream & operator <<(std::ostream & out, a_of_v_of_couples const & obj);
    bool operator ==(a_of_v_of_couples const & lhs, a_of_v_of_couples const & rhs);
    bool operator !=(a_of_v_of_couples const & lhs, a_of_v_of_couples const & rhs);

    template<>
    struct Diff<a_of_v_of_couples>
    {
        enum class Members : std::size_t
        {
            coupleses,
            numMembers
        };

        Diff() { }
        Diff(a_of_v_of_couples const & lhs, a_of_v_of_couples const & rhs);

        std::bitset<static_cast<std::size_t>(Members::numMembers)> memberDiffs;
        Diff<std::array<std::vector<couple>, 4>> coupleses_diffs;
    };

    class a_of_v_of_couples
    {
    public:
        a_of_v_of_couples();
        a_of_v_of_couples(std::array<std::vector<couple>, 4> const & coupleses);
        a_of_v_of_couples(hu::Node node) noexcept;
        a_of_v_of_couples(a_of_v_of_couples const & rhs) = default;
        a_of_v_of_couples(a_of_v_of_couples && rhs) noexcept;
        a_of_v_of_couples & operator =(a_of_v_of_couples const & rhs) = default;
        a_of_v_of_couples & operator =(a_of_v_of_couples && rhs) noexcept;
        virtual ~a_of_v_of_couples();
        friend void swap(a_of_v_of_couples & lhs, a_of_v_of_couples & rhs) noexcept;
        std::array<std::vector<couple>, 4>         get_coupleses() &&      { return coupleses; }
        std::array<std::vector<couple>, 4> const & get_coupleses() const & { return coupleses; }
        std::array<std::vector<couple>, 4>       & get_coupleses() &       { return coupleses; }
        void set_coupleses(std::array<std::vector<couple>, 4> new_coupleses)    { coupleses = std::move(new_coupleses); }
        void set_coupleses(std::array<std::vector<couple>, 4> && new_coupleses)      { using std::swap; swap(coupleses, new_coupleses); }
        friend std::ostream & operator <<(std::ostream & out, a_of_v_of_couples const & obj);
        friend bool operator ==(a_of_v_of_couples const & lhs, a_of_v_of_couples const & rhs);
        friend bool operator !=(a_of_v_of_couples const & lhs, a_of_v_of_couples const & rhs);
    friend Diff<a_of_v_of_couples>::Diff();
    friend Diff<a_of_v_of_couples>::Diff(a_of_v_of_couples const & lhs, a_of_v_of_couples const & rhs);
    private:
        std::array<std::vector<couple>, 4> coupleses;
    };

        
    std::ostream & operator <<(std::ostream & out, std::array<std::vector<couple>, 4> const & obj);
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