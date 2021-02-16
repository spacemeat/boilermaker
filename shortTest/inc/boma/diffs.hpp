#pragma once

#include <bitset>
#include <vector>
#include <tuple>
#include <array>
#include <utility>

namespace shortTest
{
    template <class StructType>
    struct Diff
    {
        Diff() : memberDiffs(false) { }

        Diff(StructType const & lhs, StructType const & rhs)
        : memberDiffs(lhs != rhs)
        { }

        bool memberDiffs = false;
    };



    template <class T, std::size_t Size>
    struct Diff<std::array<T, Size>>
    {
        Diff() { }

        Diff(std::array<T, Size> const & lhs, std::array<T, Size> const & rhs)
        {
            for (std::size_t i = 0; i < lhs.size(); ++i)
            {
                if (lhs[i] != rhs[i])
                {
                    elementDiffs.emplace_back(i, Diff<T> { lhs[i], rhs[i] });
                }
            }
        }

        std::vector<std::pair<std::size_t, Diff<T>>> elementDiffs;
    };


    template <class T>
    struct Diff<std::vector<T>>
    {
        enum class DiffKind { added, replaced, removed };

        Diff() { }

        Diff(std::vector<T> const & lhs, std::vector<T> const & rhs)
        {
            for (std::size_t i = 0; i < lhs.size(); ++i)
            {
                if (rhs.size() >= i)
                {
                    if (lhs[i] != rhs[i])
                    {
                        elementDiffs.emplace_back(i, DiffKind::replaced, Diff<T>(lhs[i], rhs[i]));
                    }
                }
                else
                {
                    elementDiffs.emplace_back(i, DiffKind::removed, Diff<T>());
                }
            }

            for (std::size_t i = lhs.size(); i < rhs.size(); ++i)
            {
                elementDiffs.emplace_back(i, DiffKind::added, Diff<T>());
            }
        }

        std::vector<std::tuple<std::size_t, DiffKind, Diff<T>>> elementDiffs;
    };
}
