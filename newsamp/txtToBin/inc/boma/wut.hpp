#pragma once

#include <humon/humon.hpp>
#include <vector>
#include <array>
#include <optional>
#include <variant>
#include <utility>
#include <string_view>
#include <tuple>
#include <cstddef>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include "diffs.hpp"
    
namespace std
{
}


namespace txtToBin
{
    class wut;
    void swap(wut & lhs, wut & rhs) noexcept;
    std::ostream & operator <<(std::ostream & out, wut const & obj);
    bool operator ==(wut const & lhs, wut const & rhs);
    bool operator !=(wut const & lhs, wut const & rhs);

    struct IsLess_wut_huh_0_0_0_0_4
    {
        bool operator()(std::unordered_map<std::string_view, int> const & lhs, std::unordered_map<std::string_view, int> const & rhs) const
        {
            return lhs.begin()->second < rhs.begin()->second;
        }
    };

    struct IsLess_wut_huh_0_0_0_0_6_0
    {
        bool operator()(float const & lhs, float const & rhs) const
        {
            return lhs < rhs;
        }
    };

    struct IsLess_wut_huh_0_0_0_0_6
    {
        bool operator()(std::map<float, int, IsLess_wut_huh_0_0_0_0_6_0> const & lhs, std::map<float, int, IsLess_wut_huh_0_0_0_0_6_0> const & rhs) const
        {
            return lhs.begin()->second < rhs.begin()->second;
        }
    };

    template<>
    struct Diff<wut>
    {
        enum class Members : std::size_t
        {
            huh,
            numMembers
        };

        Diff() { }
        Diff(wut const & lhs, wut const & rhs);

        std::bitset<static_cast<std::size_t>(Members::numMembers)> memberDiffs;
        Diff<std::vector<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, IsLess_wut_huh_0_0_0_0_6_0>, IsLess_wut_huh_0_0_0_0_6>>>, 4>>> huh_diffs;
    };

    class wut
    {
    public:
        wut();
        wut(std::vector<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, IsLess_wut_huh_0_0_0_0_6_0>, IsLess_wut_huh_0_0_0_0_6>>>, 4>> const & huh);
        wut(hu::Node node);
        wut(wut const & rhs) = default;
        wut(wut && rhs) noexcept;
        wut & operator =(wut const & rhs) = default;
        wut & operator =(wut && rhs) noexcept;
        virtual ~wut();
        friend void swap(wut & lhs, wut & rhs) noexcept;
        std::vector<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, IsLess_wut_huh_0_0_0_0_6_0>, IsLess_wut_huh_0_0_0_0_6>>>, 4>>         get_huh() &&      { return huh; }
        std::vector<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, IsLess_wut_huh_0_0_0_0_6_0>, IsLess_wut_huh_0_0_0_0_6>>>, 4>> const & get_huh() const & { return huh; }
        std::vector<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, IsLess_wut_huh_0_0_0_0_6_0>, IsLess_wut_huh_0_0_0_0_6>>>, 4>>       & get_huh() &       { return huh; }
        void set_huh(std::vector<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, IsLess_wut_huh_0_0_0_0_6_0>, IsLess_wut_huh_0_0_0_0_6>>>, 4>> new_huh)    { using std::swap; swap(huh, new_huh); }
        void set_huh(std::vector<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, IsLess_wut_huh_0_0_0_0_6_0>, IsLess_wut_huh_0_0_0_0_6>>>, 4>> && new_huh) { using std::swap; swap(huh, new_huh); }
        friend std::ostream & operator <<(std::ostream & out, wut const & obj);
        friend bool operator ==(wut const & lhs, wut const & rhs);
        friend bool operator !=(wut const & lhs, wut const & rhs);
    friend Diff<wut>::Diff();
    friend Diff<wut>::Diff(wut const & lhs, wut const & rhs);

    private:
        std::vector<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, IsLess_wut_huh_0_0_0_0_6_0>, IsLess_wut_huh_0_0_0_0_6>>>, 4>> huh;
    };

        
    std::ostream & operator <<(std::ostream & out, std::pair<std::string_view, std::string> const & obj);
        
    std::ostream & operator <<(std::ostream & out, std::tuple<std::size_t, int, double> const & obj);
        
    std::ostream & operator <<(std::ostream & out, std::map<std::string_view, int> const & obj);
        
    std::ostream & operator <<(std::ostream & out, std::unordered_map<std::string_view, int> const & obj);
        
    std::ostream & operator <<(std::ostream & out, std::set<std::unordered_map<std::string_view, int>, IsLess_wut_huh_0_0_0_0_4> const & obj);
        
    std::ostream & operator <<(std::ostream & out, std::unordered_set<std::string_view> const & obj);
        
    std::ostream & operator <<(std::ostream & out, std::map<float, int, IsLess_wut_huh_0_0_0_0_6_0> const & obj);
        
    std::ostream & operator <<(std::ostream & out, std::set<std::map<float, int, IsLess_wut_huh_0_0_0_0_6_0>, IsLess_wut_huh_0_0_0_0_6> const & obj);
        
    std::ostream & operator <<(std::ostream & out, std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, IsLess_wut_huh_0_0_0_0_6_0>, IsLess_wut_huh_0_0_0_0_6>> const & obj);
        
    std::ostream & operator <<(std::ostream & out, std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, IsLess_wut_huh_0_0_0_0_6_0>, IsLess_wut_huh_0_0_0_0_6>>> const & obj);
        
    std::ostream & operator <<(std::ostream & out, std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, IsLess_wut_huh_0_0_0_0_6_0>, IsLess_wut_huh_0_0_0_0_6>>>, 4> const & obj);
        
    std::ostream & operator <<(std::ostream & out, std::vector<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, IsLess_wut_huh_0_0_0_0_6_0>, IsLess_wut_huh_0_0_0_0_6>>>, 4>> const & obj);
}

template<>
struct hu::val<txtToBin::wut>
{
    inline txtToBin::wut extract(hu::Node const & node)
    {
        return txtToBin::wut(node);
    }
};

template <>
struct hu::val<std::pair<std::string_view, std::string>>
{
    static inline std::pair<std::string_view, std::string> extract(hu::Node const & node)
    {
        return std::pair<std::string_view, std::string> {
            node / 0 % hu::val<std::string_view> { },
            node / 1 % hu::val<std::string> { }
        };
    }
};

template <>
struct hu::val<std::tuple<std::size_t, int, double>>
{
    static inline std::tuple<std::size_t, int, double> extract(hu::Node const & node)
    {
        return std::tuple<std::size_t, int, double> {
            node / 0 % hu::val<std::size_t> { },
            node / 1 % hu::val<int> { },
            node / 2 % hu::val<double> { }
        };
    }
};

template <>
struct hu::val<std::map<std::string_view, int>>
{
    static inline std::map<std::string_view, int> extract(hu::Node const & node)
    {
        std::map<std::string_view, int> rv;
        for (size_t i = 0; i < node.numChildren(); ++i)
        {
            hu::Node elemNode = node / i;
            rv.emplace(std::move(hu::val<std::string_view>::extract(elemNode.key().str())),
                       std::move(elemNode % hu::val<int>{}));
        }
        return rv;
    }
};

template <>
struct hu::val<std::unordered_map<std::string_view, int>>
{
    static inline std::unordered_map<std::string_view, int> extract(hu::Node const & node)
    {
        std::unordered_map<std::string_view, int> rv;
        for (size_t i = 0; i < node.numChildren(); ++i)
        {
            hu::Node elemNode = node / i;
            rv.emplace(std::move(hu::val<std::string_view>::extract(elemNode.key().str())),
                       std::move(elemNode % hu::val<int>{}));
        }
        return rv;
    }
};

template <>
struct hu::val<std::set<std::unordered_map<std::string_view, int>, txtToBin::IsLess_wut_huh_0_0_0_0_4>>
{
    static inline std::set<std::unordered_map<std::string_view, int>, txtToBin::IsLess_wut_huh_0_0_0_0_4> extract(hu::Node const & node)
    {
        std::set<std::unordered_map<std::string_view, int>, txtToBin::IsLess_wut_huh_0_0_0_0_4> rv;
        for (size_t i = 0; i < node.numChildren(); ++i)
        {
            rv.emplace(node / i % hu::val<std::unordered_map<std::string_view, int>>{});
        }
        return rv;
    }
};

template <>
struct hu::val<std::unordered_set<std::string_view>>
{
    static inline std::unordered_set<std::string_view> extract(hu::Node const & node)
    {
        std::unordered_set<std::string_view> rv;
        for (size_t i = 0; i < node.numChildren(); ++i)
        {
            rv.emplace(node / i % hu::val<std::string_view>{});
        }
        return rv;
    }
};

template <>
struct hu::val<std::map<float, int, txtToBin::IsLess_wut_huh_0_0_0_0_6_0>>
{
    static inline std::map<float, int, txtToBin::IsLess_wut_huh_0_0_0_0_6_0> extract(hu::Node const & node)
    {
        std::map<float, int, txtToBin::IsLess_wut_huh_0_0_0_0_6_0> rv;
        for (size_t i = 0; i < node.numChildren(); ++i)
        {
            hu::Node elemNode = node / i;
            rv.emplace(std::move(hu::val<float>::extract(elemNode.key().str())),
                       std::move(elemNode % hu::val<int>{}));
        }
        return rv;
    }
};

template <>
struct hu::val<std::set<std::map<float, int, txtToBin::IsLess_wut_huh_0_0_0_0_6_0>, txtToBin::IsLess_wut_huh_0_0_0_0_6>>
{
    static inline std::set<std::map<float, int, txtToBin::IsLess_wut_huh_0_0_0_0_6_0>, txtToBin::IsLess_wut_huh_0_0_0_0_6> extract(hu::Node const & node)
    {
        std::set<std::map<float, int, txtToBin::IsLess_wut_huh_0_0_0_0_6_0>, txtToBin::IsLess_wut_huh_0_0_0_0_6> rv;
        for (size_t i = 0; i < node.numChildren(); ++i)
        {
            rv.emplace(node / i % hu::val<std::map<float, int, txtToBin::IsLess_wut_huh_0_0_0_0_6_0>>{});
        }
        return rv;
    }
};

template <>
struct hu::val<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, txtToBin::IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, txtToBin::IsLess_wut_huh_0_0_0_0_6_0>, txtToBin::IsLess_wut_huh_0_0_0_0_6>>>
{
    static inline std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, txtToBin::IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, txtToBin::IsLess_wut_huh_0_0_0_0_6_0>, txtToBin::IsLess_wut_huh_0_0_0_0_6>> extract(hu::Node const & node)
    {
        Token tok = node.annotation("type");
        if (! tok)
            { throw std::runtime_error("Variant could not be initialized."); }
        std::string_view tokStr = tok.str();
        if (tokStr == "pair")
            { return node % hu::val<std::pair<std::string_view, std::string>>{}; }
        if (tokStr == "tuple")
            { return node % hu::val<std::tuple<std::size_t, int, double>>{}; }
        if (tokStr == "map")
            { return node % hu::val<std::map<std::string_view, int>>{}; }
        if (tokStr == "unordered_map")
            { return node % hu::val<std::unordered_map<std::string_view, int>>{}; }
        if (tokStr == "set")
            { return node % hu::val<std::set<std::unordered_map<std::string_view, int>, txtToBin::IsLess_wut_huh_0_0_0_0_4>>{}; }
        if (tokStr == "unordered_set")
            { return node % hu::val<std::unordered_set<std::string_view>>{}; }
        if (tokStr == "setOfMaps")
            { return node % hu::val<std::set<std::map<float, int, txtToBin::IsLess_wut_huh_0_0_0_0_6_0>, txtToBin::IsLess_wut_huh_0_0_0_0_6>>{}; }
        throw std::runtime_error("Variant could not be initialized.");
    }
};

template <>
struct hu::val<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, txtToBin::IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, txtToBin::IsLess_wut_huh_0_0_0_0_6_0>, txtToBin::IsLess_wut_huh_0_0_0_0_6>>>>
{
    static inline std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, txtToBin::IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, txtToBin::IsLess_wut_huh_0_0_0_0_6_0>, txtToBin::IsLess_wut_huh_0_0_0_0_6>>> extract(hu::Node const & node)
    {
        if (! node)
            { return {}; }
        else if (node.kind() == NodeKind::value && node.value().str() == "_")
            { return {}; }
        else
            { return node % hu::val<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, txtToBin::IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, txtToBin::IsLess_wut_huh_0_0_0_0_6_0>, txtToBin::IsLess_wut_huh_0_0_0_0_6>>>{}; }
    }
};

template <>
struct hu::val<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, txtToBin::IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, txtToBin::IsLess_wut_huh_0_0_0_0_6_0>, txtToBin::IsLess_wut_huh_0_0_0_0_6>>>, 4>>
{
    static inline std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, txtToBin::IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, txtToBin::IsLess_wut_huh_0_0_0_0_6_0>, txtToBin::IsLess_wut_huh_0_0_0_0_6>>>, 4> extract(hu::Node const & node)
    {
        return std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, txtToBin::IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, txtToBin::IsLess_wut_huh_0_0_0_0_6_0>, txtToBin::IsLess_wut_huh_0_0_0_0_6>>>, 4> {
            node / 0 % hu::val<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, txtToBin::IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, txtToBin::IsLess_wut_huh_0_0_0_0_6_0>, txtToBin::IsLess_wut_huh_0_0_0_0_6>>>> {},
            node / 1 % hu::val<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, txtToBin::IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, txtToBin::IsLess_wut_huh_0_0_0_0_6_0>, txtToBin::IsLess_wut_huh_0_0_0_0_6>>>> {},
            node / 2 % hu::val<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, txtToBin::IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, txtToBin::IsLess_wut_huh_0_0_0_0_6_0>, txtToBin::IsLess_wut_huh_0_0_0_0_6>>>> {},
            node / 3 % hu::val<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, txtToBin::IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, txtToBin::IsLess_wut_huh_0_0_0_0_6_0>, txtToBin::IsLess_wut_huh_0_0_0_0_6>>>> {}
        };
    }
};

template <>
struct hu::val<std::vector<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, txtToBin::IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, txtToBin::IsLess_wut_huh_0_0_0_0_6_0>, txtToBin::IsLess_wut_huh_0_0_0_0_6>>>, 4>>>
{
    static inline std::vector<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, txtToBin::IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, txtToBin::IsLess_wut_huh_0_0_0_0_6_0>, txtToBin::IsLess_wut_huh_0_0_0_0_6>>>, 4>> extract(hu::Node const & node)
    {
        std::vector<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, txtToBin::IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, txtToBin::IsLess_wut_huh_0_0_0_0_6_0>, txtToBin::IsLess_wut_huh_0_0_0_0_6>>>, 4>> rv;
        for (size_t i = 0; i < node.numChildren(); ++i)
        {
            rv.emplace_back(node / i % hu::val<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, txtToBin::IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>, std::set<std::map<float, int, txtToBin::IsLess_wut_huh_0_0_0_0_6_0>, txtToBin::IsLess_wut_huh_0_0_0_0_6>>>, 4>>{});
        }
        return rv;
    }
};