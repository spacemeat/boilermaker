#pragma once

#include <humon/humon.hpp>
#include "enums.h"
#include <cstring>

template <>
struct hu::val<::eAnimals>
{
    static inline ::eAnimals extract(hu::Node node) noexcept
    {
        auto nodeVal = node.value().str().data();
        if (std::strncmp(nodeVal, "cat", 3) == 0) { return E_CAT; }
        if (std::strncmp(nodeVal, "dog", 3) == 0) { return E_DOG; }
        if (std::strncmp(nodeVal, "pig", 3) == 0) { return E_PIG; }
        if (std::strncmp(nodeVal, "bug", 3) == 0) { return E_BUG; }
        return {};
    }
};

template <>
struct hu::val<::eBugs>
{
    static inline ::eBugs extract(hu::Node node) noexcept
    {
        auto nodeVal = node.value().str().data();
        if (std::strncmp(nodeVal, "ant", 3) == 0) { return E_ANT; }
        if (std::strncmp(nodeVal, "bee", 3) == 0) { return E_BEE; }
        if (std::strncmp(nodeVal, "fly", 3) == 0) { return E_FLY; }
        return {};
    }
};

namespace shortTest
{
    std::ostream & operator <<(std::ostream & out, ::eAnimals obj);
    std::ostream & operator <<(std::ostream & out, ::eBugs obj);
}
