#pragma once

#include <memory>
#include <vector>
#include <utility>
#include <tuple>
#include <bitset>
#include "observable.hpp"

namespace og
{
    template<typename T1, typename T2>
    class ObservablePair : public Observable<ObservablePair<T1, T2>>
    {
    public:
        using pair_t                     = std::pair<T1, T2>;
        using obpair_t                   = ObservablePair<T1, T2>;

        constexpr ObservablePair() { }

        template< class U1, class U2 >
        constexpr ObservablePair(U1 && x, U2 && y)
        : Observable<ObservablePair<T1, T2>>(), _pair{std::move(x), std::move(y)}, first(_pair.first), second(_pair.second)
        { observeElements(0, 2); }

        ObservablePair(obpair_t const & p)
        : Observable<ObservablePair<T1, T2>>(), _pair{p._pair}, first(_pair.first), second(_pair.second)
        { observeElements(0, 2); }

        ObservablePair(obpair_t && p) noexcept
        : Observable<ObservablePair<T1, T2>>(), _pair{std::move(p._pair)}, first(_pair.first), second(_pair.second)
        { observeElements(0, 2); }

    private:
        void onChange(std::size_t index = 0, std::size_t num = 2)
        {
            if (index == 0 && num > 0)
                { changeBits.set(0); }

            if (index + num > 1)
                { changeBits.set(1); }

            observeElements(index, num);

            // let any observers of this vector know that the vector has changes
            Observable<obpair_t>::notifyChange(*this);
        }

        void observeElements(std::size_t index = 0, std::size_t num = 2)
        {
            if constexpr (std::is_base_of_v<Observable<T1>, T1>)
            {
                if (index == 0 && num > 0)
                    { _pair.first.setNotifyFn([this](T1 &){ this->onChange(0, 1); }); }
            }
            if constexpr (std::is_base_of_v<Observable<T2>, T2>)
            {
                if (index + num > 1)
                    { _pair.second.setNotifyFn([this](T2 &){ this->onChange(1, 1); }); }
            }
        }

    public:
        bool hasChanged() const noexcept
        {
            return changeBits.any();
        }
        
        std::bitset<2> const & getChanges() const noexcept
        {
            return changeBits;
        }

        void forgetChanges() noexcept
        {
            changeBits.reset();

            // TODO: only for observeChildDiffs ?
            if constexpr (std::is_base_of_v<Observable<T1>, T1>)
            {
                _pair.first.forgetChanges();
            }

            if constexpr (std::is_base_of_v<Observable<T2>, T2>)
            {
                _pair.second.forgetChanges();
            }
        }

        obpair_t & operator =(obpair_t const & rhs)
        {
            if (& rhs != this)
            {
                _pair = rhs._pair;
                onChange();
            }
            return * this;
        }

        obpair_t & operator =(obpair_t && rhs) noexcept
        {
            if (& rhs != this)
            {
                using std::swap;
                swap(_pair, rhs._pair);
                onChange();
            }
            return * this;
        }

        void swap(obpair_t& other) noexcept(
            std::is_nothrow_swappable_v<T1> &&
            std::is_nothrow_swappable_v<T2>)
        {
            _pair.swap(other._pair);
            onChange();
            other.onChange();
        }

        void swap(pair_t& other) noexcept(
            std::is_nothrow_swappable_v<T1> &&
            std::is_nothrow_swappable_v<T2>)
        {
            _pair.swap(other);
            onChange();
        }

//        T1 & first() { return _pair.first; }
//        T1 const & first() const { return _pair.first; }

//        T2 & second() { return _pair.second; }
//        T2 const & second() const { return _pair.second; }

    private:
        std::pair<T1, T2> _pair;
    public:
        T1 & first;
        T2 & second;
    private:
        std::bitset<2> changeBits;
    };
}
