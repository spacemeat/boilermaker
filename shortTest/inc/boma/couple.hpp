#pragma once

#include <humon/humon.hpp>
#include <string>
#include "diffs.hpp"
    
namespace std
{
}


namespace shortTest
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
            bee,
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
        couple(std::string const & a, int const & bee);
        couple(hu::Node node) noexcept;
        couple(couple const & rhs) = default;
        couple(couple && rhs) noexcept;
        couple & operator =(couple const & rhs) = default;
        couple & operator =(couple && rhs) noexcept;
        virtual ~couple();
        friend void swap(couple & lhs, couple & rhs) noexcept;
        std::string         get_a() &&        { return a; }
        std::string const & get_a() const &   { return a; }
        std::string       & get_a() &         { return a; }
        int                 get_bee() &&      { return bee; }
        int const         & get_bee() const & { return bee; }
        int               & get_bee() &       { return bee; }
        void   set_a(std::string new_a)      { using std::swap; swap(a, new_a); }
        void   set_a(std::string && new_a)   { using std::swap; swap(a, new_a); }
        void set_bee(int new_bee)            { using std::swap; swap(bee, new_bee); }
        void set_bee(int && new_bee)         { using std::swap; swap(bee, new_bee); }
        friend std::ostream & operator <<(std::ostream & out, couple const & obj);
        friend bool operator ==(couple const & lhs, couple const & rhs);
        friend bool operator !=(couple const & lhs, couple const & rhs);
    friend Diff<couple>::Diff();
    friend Diff<couple>::Diff(couple const & lhs, couple const & rhs);

    private:
        std::string a;
        int bee;
    };

}

template<>
struct hu::val<shortTest::couple>
{
    inline shortTest::couple extract(hu::Node const & node) noexcept
    {
        return shortTest::couple(node);
    }
};