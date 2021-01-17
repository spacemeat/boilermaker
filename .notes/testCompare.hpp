#pragma once

// THIS IS A GENERATED FILE. It is a Boilermaker artifact.
// Do not bother modifying this file, as your build process will overwrite
// your changes.

#include <cstring>
#include <type_traits>
#include <unordered_map>
#include <string>
#include <vector>
#include <array>
#include <humon/humon.hpp>
#include "../../testCompare.hpp"


#include <bitset>
#include <tuple>

namespace testCompare
{
    template <class T>
    struct buildIn_diff
    {
        buildIn_diff() { }

        buildIn_diff(T const & lhs, T const & rhs)
        {
            diff = lhs != rhs;
        }
        bool diff = false;
    };

    template <class T, std::size_t Size, class DiffType>
    struct array_diff
    {
        array_diff() { }

        array_diff(std::array<T, Size> const & lhs, std::array<T, Size> const & rhs)
        {
            for (std::size_t i = 0; i < lhs.size(); ++i)
            {
                if (lhs[i] != rhs[i])
                {
                    diffs.emplace_back(i, DiffType { lhs[i], rhs[i] });
                }
            }
        }
        std::vector<std::pair<std::size_t, DiffType>> diffs;
    };

    template <class T, class DiffType>
    struct vector_diff
    {
        enum class DiffKind { replaced, added, removed };

        vector_diff() { }

        vector_diff(std::vector<T> const & lhs, std::vector<T> const & rhs)
        {
            for (std::size_t i = 0; i < lhs.size(); ++i)
            {
                if (rhs.size() >= i)
                {
                    if (lhs[i] != rhs[i])
                    {
                        diffs.emplace_back(i, DiffKind::replaced, DiffType(lhs[i], rhs[i]));
                    }
                }
                else
                {
                    diffs.emplace_back(i, DiffKind::removed, DiffType());
                }
            }

            for (std::size_t i = lhs.size(); i < rhs.size(); ++i)
            {
                diffs.emplace_back(i, DiffKind::added, DiffType());
            }
        }
        std::vector<std::tuple<std::size_t, DiffKind, DiffType>> diffs;
    };

    template <class Key, class T, class DiffType>
    struct unordered_map_diff
    {
        enum class DiffKind { replaced, added, removed };

        unordered_map_diff() { }

        unordered_map_diff(std::unordered_map<Key, T> const & lhs, std::unordered_map<Key, T> const & rhs)
        {
            // figure out diffs in maps
            for (auto const & lkvp : lhs)
            {
                if (auto it = rhs.find(lkvp.first); it == rhs.end())
                {
                    differenceKeys.emplace_back(lkvp.first, DiffKind::removed, DiffType ());
                }
            }

            for (auto const & lkvp : lhs)
            {
                if (auto it = rhs.find(lkvp.first); it != rhs.end() &&
                    lkvp.second != it->second)
                {
                    differenceKeys.emplace_back(lkvp.first, DiffKind::replaced, DiffType ( lkvp.second, it->second ));
                }
            }

            for (auto const & rkvp : rhs)
            {
                if (auto it = lhs.find(rkvp.first); it != lhs.end() &&
                    rkvp.second != it->second)
                {
                    differenceKeys.emplace_back(rkvp.first, DiffKind::added, DiffType ());
                }
            }
        }
        
        std::vector<std::tuple<T, DiffKind, DiffType>> differenceKeys;
    };


    class bomaStream
    {
    public:
        friend std::ostream & operator <<(std::ostream & out, bomaStream)
        {
            out << std::boolalpha;
            return out;
        }
    };


    inline std::ostream & operator <<(std::ostream & out, std::unordered_map<std::string, std::string> const & obj) noexcept
    {
        out << '{';
        bool firstTime = true;
        for (auto & elem : obj)
        {
            if (firstTime)
                { firstTime = false; }
            else
                { out << ' '; }
            out << elem.first << ": " << elem.second;
        }
        out << '}';
        return out;
    }


    class achievement;
    void swap(achievement & lhs, achievement & rhs) noexcept;
    std::ostream & operator <<(std::ostream & out, achievement const & obj) noexcept;
    bool operator ==(achievement const & lhs, achievement const & rhs) noexcept;
    bool operator !=(achievement const & lhs, achievement const & rhs) noexcept;

    struct achievement_diff
    {
        enum class Members {
            titleId, id, when, timeToEarn, metatags
        };

        achievement_diff() noexcept { }
        achievement_diff(achievement const & lhs, achievement const & rhs) noexcept;

        std::bitset<5> diffs;
        unordered_map_diff<std::string, std::string, buildIn_diff<std::string>> metatags_diffs;
    };

    //achievement_diff getDiff(achievement const & lhs, achievement const & rhs) noexcept;

    class achievement
    {
    public:
        achievement(hu::Node node) noexcept;
        achievement(achievement const & rhs) noexcept;
        achievement & operator =(testCompare::achievement rhs) noexcept;
        achievement(achievement && rhs) noexcept;
        testCompare::achievement & operator =(testCompare::achievement && rhs) noexcept;
        virtual ~achievement();
        friend void testCompare::swap(testCompare::achievement & lhs, testCompare::achievement & rhs) noexcept;
        int const & get_titleId() const noexcept;
        int &       get_titleId() noexcept;
        int const & get_id() const noexcept;
        int &       get_id() noexcept;
        long long const & get_when() const noexcept;
        long long &       get_when() noexcept;
        long long const & get_timeToEarn() const noexcept;
        long long &       get_timeToEarn() noexcept;
        std::unordered_map<std::string, std::string> const & get_metatags() const noexcept;
        std::unordered_map<std::string, std::string> &       get_metatags() noexcept;
        friend std::ostream & operator <<(std::ostream & out, achievement const & obj) noexcept;
        friend bool operator ==(achievement const & lhs, achievement const & rhs) noexcept;
        friend bool operator !=(achievement const & lhs, achievement const & rhs) noexcept;
        friend achievement_diff::achievement_diff() noexcept;
        friend achievement_diff::achievement_diff(achievement const & lhs, achievement const & rhs) noexcept;
    private:
        int titleId;
        int id;
        long long when;
        long long timeToEarn;
        std::unordered_map<std::string, std::string> metatags;
    };


    inline std::ostream & operator <<(std::ostream & out, std::vector<testCompare::achievement> const & obj) noexcept
    {
        out << '[';
        bool firstTime = true;
        for (auto const & objmem : obj)
        {
            if (firstTime)
                { firstTime = false; }
            else
                { out << ' '; }
            out << objmem;
        }
        out << ']';
        return out;
    }


    class user;
    void swap(user & lhs, user & rhs) noexcept;
    std::ostream & operator <<(std::ostream & out, user const & obj) noexcept;
    bool operator ==(user const & lhs, user const & rhs) noexcept;
    bool operator !=(user const & lhs, user const & rhs) noexcept;

    struct user_diff
    {
        enum class Members {
            id, username, lastLoggedIn, lastTitlePlayed, achievements, metatags
        };

        user_diff() noexcept { }
        user_diff(user const & lhs, user const & rhs) noexcept;

        std::bitset<6> diffs;
        vector_diff<achievement, achievement_diff> achievements_diffs;
        unordered_map_diff<std::string, std::string, buildIn_diff<std::string>> metatags_diffs;
    };

    class user
    {
    public:
        user(hu::Node node) noexcept;
        user(user const & rhs) noexcept;
        user & operator =(testCompare::user rhs) noexcept;
        user(user && rhs) noexcept;
        testCompare::user & operator =(testCompare::user && rhs) noexcept;
        virtual ~user();
        friend void testCompare::swap(testCompare::user & lhs, testCompare::user & rhs) noexcept;
        int const & get_id() const noexcept;
        int &       get_id() noexcept;
        std::string const & get_username() const noexcept;
        std::string &       get_username() noexcept;
        long long const & get_lastLoggedIn() const noexcept;
        long long &       get_lastLoggedIn() noexcept;
        int const & get_lastTitlePlayed() const noexcept;
        int &       get_lastTitlePlayed() noexcept;
        std::vector<testCompare::achievement> const & get_achievements() const noexcept;
        std::vector<testCompare::achievement> &       get_achievements() noexcept;
        std::unordered_map<std::string, std::string> const & get_metatags() const noexcept;
        std::unordered_map<std::string, std::string> &       get_metatags() noexcept;
        friend std::ostream & operator <<(std::ostream & out, user const & obj) noexcept;
        friend bool operator ==(user const & lhs, user const & rhs) noexcept;
        friend bool operator !=(user const & lhs, user const & rhs) noexcept;
        friend user_diff::user_diff() noexcept;
        friend user_diff::user_diff(user const & lhs, user const & rhs) noexcept;
    private:
        int id;
        std::string username;
        long long lastLoggedIn;
        int lastTitlePlayed;
        std::vector<testCompare::achievement> achievements;
        std::unordered_map<std::string, std::string> metatags;
    };


    inline std::ostream & operator <<(std::ostream & out, std::vector<int> const & obj) noexcept
    {
        out << '[';
        bool firstTime = true;
        for (auto const & objmem : obj)
        {
            if (firstTime)
                { firstTime = false; }
            else
                { out << ' '; }
            out << objmem;
        }
        out << ']';
        return out;
    }


    inline std::ostream & operator <<(std::ostream & out, std::array<std::vector<int>, 4> const & obj) noexcept
    {
        out << '[';
        out << obj[0];
        out << ' ';
        out << obj[1];
        out << ' ';
        out << obj[2];
        out << ' ';
        out << obj[3];
        out << ']';
        return out;
    }


    inline std::ostream & operator <<(std::ostream & out, std::vector<testCompare::user> const & obj) noexcept
    {
        out << '[';
        bool firstTime = true;
        for (auto const & objmem : obj)
        {
            if (firstTime)
                { firstTime = false; }
            else
                { out << ' '; }
            out << objmem;
        }
        out << ']';
        return out;
    }


    class testRoot;
    void swap(testRoot & lhs, testRoot & rhs) noexcept;
    std::ostream & operator <<(std::ostream & out, testRoot const & obj) noexcept;
    bool operator ==(testRoot const & lhs, testRoot const & rhs) noexcept;
    bool operator !=(testRoot const & lhs, testRoot const & rhs) noexcept;

    struct testRoot_diff
    {
        enum class Members {
            v_of_ints, a_of_v_of_ints, users
        };

        testRoot_diff() noexcept { }
        testRoot_diff(testRoot const & lhs, testRoot const & rhs) noexcept;

        std::bitset<3> diffs;
        vector_diff<int, buildIn_diff<int>> v_of_ints_diffs;
        array_diff<std::vector<int>, 4, vector_diff<int, buildIn_diff<int>>> a_of_v_of_ints_diffs;
        vector_diff<user, user_diff> users_diffs;
    };

    //testRoot_diff getDiff(testRoot const & lhs, testRoot const & rhs) noexcept;

    class testRoot
    {
    public:
        testRoot(hu::Node node) noexcept;
        testRoot(testRoot const & rhs) noexcept;
        testRoot & operator =(testCompare::testRoot rhs) noexcept;
        testRoot(testRoot && rhs) noexcept;
        testCompare::testRoot & operator =(testCompare::testRoot && rhs) noexcept;
        virtual ~testRoot();
        friend void testCompare::swap(testCompare::testRoot & lhs, testCompare::testRoot & rhs) noexcept;
        std::vector<int> const & get_v_of_ints() const noexcept;
        std::vector<int> &       get_v_of_ints() noexcept;
        std::array<std::vector<int>, 4> const & get_a_of_v_of_ints() const noexcept;
        std::array<std::vector<int>, 4> &       get_a_of_v_of_ints() noexcept;
        std::vector<testCompare::user> const & get_users() const noexcept;
        std::vector<testCompare::user> &       get_users() noexcept;
        friend std::ostream & operator <<(std::ostream & out, testRoot const & obj) noexcept;
        friend bool operator ==(testRoot const & lhs, testRoot const & rhs) noexcept;
        friend bool operator !=(testRoot const & lhs, testRoot const & rhs) noexcept;
        friend testRoot_diff::testRoot_diff() noexcept;
        friend testRoot_diff::testRoot_diff(testRoot const & lhs, testRoot const & rhs) noexcept;
    private:
        std::vector<int> v_of_ints;
        std::array<std::vector<int>, 4> a_of_v_of_ints;
        std::vector<user> users;
    };

}


template<>
struct hu::val<testCompare::achievement>
{
    static inline testCompare::achievement extract(hu::Node const & node) noexcept
    {
        return testCompare::achievement(node);
    }
};


template<>
struct hu::val<testCompare::user>
{
    static inline testCompare::user extract(hu::Node const & node) noexcept
    {
        return testCompare::user(node);
    }
};


template<>
struct hu::val<testCompare::testRoot>
{
    static inline testCompare::testRoot extract(hu::Node const & node) noexcept
    {
        return testCompare::testRoot(node);
    }
};


#include "inl/_achievement.inl.hpp"
#include "inl/_user.inl.hpp"
#include "inl/_testRoot.inl.hpp"
