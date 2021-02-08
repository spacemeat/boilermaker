#pragma once
/*  THIS IS A GENERATED FILE. It is a Boilermaker artifact.
    Do not bother modifying this file, as your build process will overwrite
    your changes. */

#include <humon/humon.hpp>
#include <iostream>
#include "couple.hpp"
#include "v_of_couples.hpp"
#include "v_of_a_of_couples.hpp"
#include "wut.hpp"
    
namespace hu
{

    template <>
    struct val<std::vector<txtToBin::couple>>
    {
        static inline std::vector<txtToBin::couple> extract(Node const & node) noexcept;
    };

    template <>
    struct val<std::array<txtToBin::couple, 4>>
    {
        static inline std::array<txtToBin::couple, 4> extract(Node const & node) noexcept;
    };

    template <>
    struct val<std::vector<std::array<txtToBin::couple, 4>>>
    {
        static inline std::vector<std::array<txtToBin::couple, 4>> extract(Node const & node) noexcept;
    };

    template <>
    struct val<std::pair<std::string_view, std::string>>
    {
        static inline std::pair<std::string_view, std::string> extract(Node const & node) noexcept;
    };

    template <>
    struct val<std::tuple<std::size_t, int, double>>
    {
        static inline std::tuple<std::size_t, int, double> extract(Node const & node) noexcept;
    };

    template <>
    struct val<std::map<std::string_view, int>>
    {
        static inline std::map<std::string_view, int> extract(Node const & node) noexcept;
    };

    template <>
    struct val<std::unordered_map<std::string_view, int>>
    {
        static inline std::unordered_map<std::string_view, int> extract(Node const & node) noexcept;
    };

    template <>
    struct val<std::set<std::unordered_map<std::string_view, int>>>
    {
        static inline std::set<std::unordered_map<std::string_view, int>> extract(Node const & node) noexcept;
    };

    template <>
    struct val<std::unordered_set<std::string_view, int>>
    {
        static inline std::unordered_set<std::string_view, int> extract(Node const & node) noexcept;
    };

    template <>
    struct val<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>
    {
        static inline std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>> extract(Node const & node) noexcept;
    };

    template <>
    struct val<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>>
    {
        static inline std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>> extract(Node const & node) noexcept;
    };

    template <>
    struct val<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>, 4>>
    {
        static inline std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>, 4> extract(Node const & node) noexcept;
    };

    template <>
    struct val<std::vector<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>, 4>>>
    {
        static inline std::vector<std::array<std::optional<std::variant<std::pair<std::string_view, std::string>, std::tuple<std::size_t, int, double>, std::map<std::string_view, int>, std::unordered_map<std::string_view, int>, std::set<std::unordered_map<std::string_view, int>>, std::unordered_set<std::string_view, int>>>, 4>> extract(Node const & node) noexcept;
    };
}


namespace txtToBin
{
}

#include "inl/containers.inl.hpp"