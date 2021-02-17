#pragma once

#include <humon/humon.hpp>
#include <vector>
#include <array>
#include "diffs.hpp"
#include "couple.hpp"
    
namespace std
{
}


namespace txtToBin
{
    class v_of_a_of_couples;
    void swap(v_of_a_of_couples & lhs, v_of_a_of_couples & rhs) noexcept;
    std::ostream & operator <<(std::ostream & out, v_of_a_of_couples const & obj);
    bool operator ==(v_of_a_of_couples const & lhs, v_of_a_of_couples const & rhs);
    bool operator !=(v_of_a_of_couples const & lhs, v_of_a_of_couples const & rhs);

    template<>
    struct Diff<v_of_a_of_couples>
    {
        enum class Members : std::size_t
        {
            coupleses,
            numMembers
        };

        Diff() { }
        Diff(v_of_a_of_couples const & lhs, v_of_a_of_couples const & rhs);

        std::bitset<static_cast<std::size_t>(Members::numMembers)> memberDiffs;
        Diff<std::vector<std::array<couple, 4>>> coupleses_diffs;
    };

    class v_of_a_of_couples
    {
    public:
        v_of_a_of_couples();
        v_of_a_of_couples(std::vector<std::array<couple, 4>> const & coupleses);
        v_of_a_of_couples(hu::Node node);
        v_of_a_of_couples(v_of_a_of_couples const & rhs) = default;
        v_of_a_of_couples(v_of_a_of_couples && rhs) noexcept;
        v_of_a_of_couples & operator =(v_of_a_of_couples const & rhs) = default;
        v_of_a_of_couples & operator =(v_of_a_of_couples && rhs) noexcept;
        virtual ~v_of_a_of_couples();
        friend void swap(v_of_a_of_couples & lhs, v_of_a_of_couples & rhs) noexcept;
        std::vector<std::array<couple, 4>>         get_coupleses() &&      { return coupleses; }
        std::vector<std::array<couple, 4>> const & get_coupleses() const & { return coupleses; }
        std::vector<std::array<couple, 4>>       & get_coupleses() &       { return coupleses; }
        void set_coupleses(std::vector<std::array<couple, 4>> new_coupleses)    { using std::swap; swap(coupleses, new_coupleses); }
        void set_coupleses(std::vector<std::array<couple, 4>> && new_coupleses) { using std::swap; swap(coupleses, new_coupleses); }
        friend std::ostream & operator <<(std::ostream & out, v_of_a_of_couples const & obj);
        friend bool operator ==(v_of_a_of_couples const & lhs, v_of_a_of_couples const & rhs);
        friend bool operator !=(v_of_a_of_couples const & lhs, v_of_a_of_couples const & rhs);
    friend Diff<v_of_a_of_couples>::Diff();
    friend Diff<v_of_a_of_couples>::Diff(v_of_a_of_couples const & lhs, v_of_a_of_couples const & rhs);

    private:
        std::vector<std::array<couple, 4>> coupleses;
    };

        
    std::ostream & operator <<(std::ostream & out, std::array<couple, 4> const & obj);
        
    std::ostream & operator <<(std::ostream & out, std::vector<std::array<couple, 4>> const & obj);
}

template<>
struct hu::val<txtToBin::v_of_a_of_couples>
{
    inline txtToBin::v_of_a_of_couples extract(hu::Node const & node)
    {
        return txtToBin::v_of_a_of_couples(node);
    }
};

template <>
struct hu::val<std::array<txtToBin::couple, 4>>
{
    static inline std::array<txtToBin::couple, 4> extract(hu::Node const & node)
    {
        return std::array<txtToBin::couple, 4> {
            node / 0 % hu::val<txtToBin::couple> {},
            node / 1 % hu::val<txtToBin::couple> {},
            node / 2 % hu::val<txtToBin::couple> {},
            node / 3 % hu::val<txtToBin::couple> {}
        };
    }
};

template <>
struct hu::val<std::vector<std::array<txtToBin::couple, 4>>>
{
    static inline std::vector<std::array<txtToBin::couple, 4>> extract(hu::Node const & node)
    {
        std::vector<std::array<txtToBin::couple, 4>> rv;
        for (size_t i = 0; i < node.numChildren(); ++i)
        {
            rv.emplace_back(node / i % hu::val<std::array<txtToBin::couple, 4>>{});
        }
        return rv;
    }
};