#pragma once

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
        couple();
        couple(std::string const & a, int const & bee);
        couple(hu::Node node) noexcept;
        couple(couple const & rhs) = default;
        couple(couple const && rhs) = delete;
        couple & operator =(couple const & rhs) = default;
        couple & operator =(couple const && rhs) = delete;
        virtual ~couple();
        std::string         couple::get_a() &&        { return a; }
        std::string const & couple::get_a() const &   { return a; }
        std::string       & couple::get_a() &         { return a; }
        int                 couple::get_bee() &&      { return bee; }
        int const         & couple::get_bee() const & { return bee; }
        int               & couple::get_bee() &       { return bee; }
        void   set_a(std::string const & new_a)   { a = new_a; }
        void   set_a(std::string && new_a)        { using std::swap; swap(a, new_a); }
        void set_bee(int const & new_bee)         { bee = new_bee; }
        void set_bee(int && new_bee)              { using std::swap; swap(bee, new_bee); }
        friend std::ostream & operator <<(std::ostream & out, couple const & obj) noexcept;
    private:
        std::string a;
        int bee;
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