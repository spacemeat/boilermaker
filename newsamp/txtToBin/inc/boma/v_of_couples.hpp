#pragma once

#include <humon/humon.hpp>
#include <vector>
#include "couple.hpp"
#include "diffs.hpp"
    
namespace std
{
}


namespace txtToBin
{
    class v_of_couples;
    void swap(v_of_couples & lhs, v_of_couples & rhs) noexcept;
    std::ostream & operator <<(std::ostream & out, v_of_couples const & obj);
    bool operator ==(v_of_couples const & lhs, v_of_couples const & rhs);
    bool operator !=(v_of_couples const & lhs, v_of_couples const & rhs);

    template<>
    struct Diff<v_of_couples>
    {
        enum class Members : std::size_t
        {
            couples,
            numMembers
        };

        Diff() { }
        Diff(v_of_couples const & lhs, v_of_couples const & rhs);

        std::bitset<static_cast<std::size_t>(Members::numMembers)> memberDiffs;
        Diff<std::vector<couple>> couples_diffs;
    };

    class v_of_couples
    {
    public:
        v_of_couples();
        v_of_couples(std::vector<couple> const & couples);
        v_of_couples(hu::Node node);
        v_of_couples(v_of_couples const & rhs) = default;
        v_of_couples(v_of_couples && rhs) noexcept;
        v_of_couples & operator =(v_of_couples const & rhs) = default;
        v_of_couples & operator =(v_of_couples && rhs) noexcept;
        virtual ~v_of_couples();
        friend void swap(v_of_couples & lhs, v_of_couples & rhs) noexcept;
        std::vector<couple>         get_couples() &&      { return couples; }
        std::vector<couple> const & get_couples() const & { return couples; }
        std::vector<couple>       & get_couples() &       { return couples; }
        void set_couples(std::vector<couple> new_couples)    { using std::swap; swap(couples, new_couples); }
        void set_couples(std::vector<couple> && new_couples) { using std::swap; swap(couples, new_couples); }
        friend std::ostream & operator <<(std::ostream & out, v_of_couples const & obj);
        friend bool operator ==(v_of_couples const & lhs, v_of_couples const & rhs);
        friend bool operator !=(v_of_couples const & lhs, v_of_couples const & rhs);
    friend Diff<v_of_couples>::Diff();
    friend Diff<v_of_couples>::Diff(v_of_couples const & lhs, v_of_couples const & rhs);

    private:
        std::vector<couple> couples;
    };

        
    std::ostream & operator <<(std::ostream & out, std::vector<couple> const & obj);
}

template<>
struct hu::val<txtToBin::v_of_couples>
{
    inline txtToBin::v_of_couples extract(hu::Node const & node)
    {
        return txtToBin::v_of_couples(node);
    }
};

template <>
struct hu::val<std::vector<txtToBin::couple>>
{
    static inline std::vector<txtToBin::couple> extract(hu::Node const & node)
    {
        std::vector<txtToBin::couple> rv;
        for (size_t i = 0; i < node.numChildren(); ++i)
        {
            rv.emplace_back(node / i % hu::val<txtToBin::couple>{});
        }
        return rv;
    }
};