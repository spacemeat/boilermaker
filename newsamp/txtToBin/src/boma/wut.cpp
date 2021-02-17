/*  THIS IS A GENERATED FILE. It is a Boilermaker artifact.
    Do not bother modifying this file, as your build process will overwrite
    your changes. */

#include "../../inc/boma/txtToBin.hpp"

namespace txtToBin
{

    wut::wut()
    { }

    wut::wut(std::vector<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>>>, 4>> const & huh)
     : huh(huh)
    { }

    wut::wut(hu::Node node)
    : huh(node / "huh" % hu::val<std::vector<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>>>, 4>>>{})
    {
    }

    wut::wut(wut && rhs) noexcept
    {
        using std::swap;
        swap(huh, rhs.huh);
    }

    wut & wut::operator =(wut && rhs) noexcept
    {
        using std::swap;
        swap(huh, rhs.huh);
        return * this;
    }

    wut::~wut()
    { }

    void swap(wut & lhs, wut & rhs) noexcept
    {
        using std::swap;
        swap(lhs.huh, rhs.huh);
    }

    std::ostream & operator <<(std::ostream & out, wut const & obj)
    {
        out << '{';
        out << " huh: " << obj.huh;
        out << '}';
        return out;
    }

    bool operator ==(wut const & lhs, wut const & rhs)
    {
        return lhs.huh == rhs.huh;
    }

    bool operator !=(wut const & lhs, wut const & rhs)
    {
        return !(lhs == rhs);
    }

    Diff<wut>::Diff(wut const & lhs, wut const & rhs)
    : memberDiffs((lhs.huh != rhs.huh) << static_cast<int>(Members::huh)),
      huh_diffs(lhs.huh, rhs.huh)
    {
    }
        
    std::ostream & operator <<(std::ostream & out, std::pair<std::string_view, std::string> const & obj)
    {
        out << '[';
        out << std::get<0>(obj);
        out << ' ';
        out << std::get<1>(obj);
        out << ']';
        return out;
    }

        
    std::ostream & operator <<(std::ostream & out, std::tuple<std::size_t, int, double> const & obj)
    {
        out << '[';
        out << std::get<0>(obj);
        out << ' ';
        out << std::get<1>(obj);
        out << ' ';
        out << std::get<2>(obj);
        out << ']';
        return out;
    }

        
    std::ostream & operator <<(std::ostream & out, std::map<std::string_view, int> const & obj)
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

        
    std::ostream & operator <<(std::ostream & out, std::unordered_map<std::string_view, int> const & obj)
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

        
    std::ostream & operator <<(std::ostream & out, std::set<std::unordered_map<std::string_view, int>, IsLess_wut_huh_0_0_0_0_4> const & obj)
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

        
    std::ostream & operator <<(std::ostream & out, std::unordered_set<std::string_view> const & obj)
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

        
    std::ostream & operator <<(std::ostream & out, std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>> const & obj)
    {
        if (auto p = std::get_if<std::pair<std::string_view, std::string>>(& obj); p) { out << *p << " @type: None"; }
        if (auto p = std::get_if<std::tuple<std::size_t, int, double>>(& obj); p) { out << *p << " @type: None"; }
        if (auto p = std::get_if<std::map<std::string_view, int>>(& obj); p) { out << *p << " @type: None"; }
        if (auto p = std::get_if<std::unordered_map<std::string_view, int>>(& obj); p) { out << *p << " @type: None"; }
        if (auto p = std::get_if<std::set<std::unordered_map<std::string_view, int>, IsLess_wut_huh_0_0_0_0_4>>(& obj); p) { out << *p << " @type: None"; }
        if (auto p = std::get_if<std::unordered_set<std::string_view>>(& obj); p) { out << *p << " @type: None"; }
        return out;
    }

        
    std::ostream & operator <<(std::ostream & out, std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>>> const & obj)
    {
    if (obj.has_value())
        { out << * obj; }
    else
        { out << '_'; }
        return out;
    }

        
    std::ostream & operator <<(std::ostream & out, std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>>>, 4> const & obj)
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

        
    std::ostream & operator <<(std::ostream & out, std::vector<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>, IsLess_wut_huh_0_0_0_0_4>, std::unordered_set<std::string_view>>>, 4>> const & obj)
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

}
