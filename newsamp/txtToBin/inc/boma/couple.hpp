#pragma once

#include <humon/humon.hpp>
#include <string>
#include "diffs.hpp"
    
namespace std
{
}


namespace txtToBin
{
    class couple;
    void swap(couple & lhs, couple & rhs) noexcept;
    std::ostream & operator <<(std::ostream & out, couple const & obj);
    bool operator ==(couple const & lhs, couple const & rhs);
    bool operator !=(couple const & lhs, couple const & rhs);

    template<>
    struct Diff<couple>
    {
        enum class Members : std::size_t
        {
            a,
            b,
            numMembers
        };

        Diff() { }
        Diff(couple const & lhs, couple const & rhs);

        std::bitset<static_cast<std::size_t>(Members::numMembers)> memberDiffs;
    };

    class couple
    {
    public:
        couple();
        couple(std::string const & a, ::VkResult const & b);
        couple(hu::Node node);
        couple(couple const & rhs) = default;
        couple(couple && rhs) noexcept;
        couple & operator =(couple const & rhs) = default;
        couple & operator =(couple && rhs) noexcept;
        virtual ~couple();
        friend void swap(couple & lhs, couple & rhs) noexcept;
        std::string         get_a() &&      { return a; }
        std::string const & get_a() const & { return a; }
        std::string       & get_a() &       { return a; }
        ::VkResult          get_b() &&      { return b; }
        ::VkResult const  & get_b() const & { return b; }
        ::VkResult        & get_b() &       { return b; }
        void set_a(std::string new_a)    { using std::swap; swap(a, new_a); }
        void set_a(std::string && new_a) { using std::swap; swap(a, new_a); }
        void set_b(::VkResult new_b)     { using std::swap; swap(b, new_b); }
        void set_b(::VkResult && new_b)  { using std::swap; swap(b, new_b); }
        friend std::ostream & operator <<(std::ostream & out, couple const & obj);
        friend bool operator ==(couple const & lhs, couple const & rhs);
        friend bool operator !=(couple const & lhs, couple const & rhs);
    friend Diff<couple>::Diff();
    friend Diff<couple>::Diff(couple const & lhs, couple const & rhs);

    private:
        std::string a;
        ::VkResult b;
    };

}

template<>
struct hu::val<txtToBin::couple>
{
    inline txtToBin::couple extract(hu::Node const & node)
    {
        return txtToBin::couple(node);
    }
};