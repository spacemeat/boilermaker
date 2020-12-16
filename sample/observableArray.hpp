#pragma once

#include <memory>
#include <vector>
#include <utility>
#include <tuple>
#include <bitset>
#include "observable.hpp"

namespace og
{
    template<typename T, std::size_t N>
    class ObservableArray : public Observable<ObservableArray<T, N>>, public std::array<T, N>
    {
    public:
        using arr_t                     = std::array<T, N>;
        using obarr_t                   = ObservableArray<T, N>;
        using value_type 	            = typename arr_t::value_type;
        using size_type 	            = typename arr_t::size_type;
        using difference_type 	        = typename arr_t::difference_type;
        using reference                 = typename arr_t::reference;
        using const_reference 	        = typename arr_t::const_reference;
        using pointer 	                = typename arr_t::pointer;
        using const_pointer 	        = typename arr_t::const_pointer;
        using iterator 	                = typename arr_t::iterator;
        using const_iterator 	        = typename arr_t::const_iterator;
        using reverse_iterator 	        = typename arr_t::reverse_iterator;
        using const_reverse_iterator 	= typename arr_t::const_reverse_iterator;

        using NotifyFn                  = typename Observable<obarr_t>::NotifyFn;

        template<class... Args>
        ObservableArray(Args &&... args)
        : Observable<obarr_t>(), 
          std::array<T, N>{std::forward<Args>(args)...}
        { observeElements(); }

    private:
        void onChange(size_type index = 0, size_type num = N)
        {
            // record the change
            if (index == 0 && num == N)
            {
                changeBits.set();
            }
            else
            {
                for (auto i = index; i < index + num; ++i)
                {
                    changeBits.set(i);
                }
            }

            // essentially reindex the change notifier for new or moved elements
            // TODO: This is for observeChildDiffs only
            observeElements(index, num);

            // let any observers of this vector know that the vector has changes
            Observable<obarr_t>::notifyChange(*this);
        }

        // TODO: This is for observeChildDiffs only
        void observeElements(size_type startingAt = 0, size_type num = N)
        {
            if constexpr (std::is_base_of_v<Observable<T>, T>)
            {
                T * observableElement = std::array<T, N>::data();
                for (size_type i = startingAt; i < startingAt + num; ++i)
                {
                    std::cout << "observeElements staringAt: " << startingAt << "; index: " << i << "\n";
                    (observableElement + i)->setNotifyFn([this, i](T &){ this->onChange(i, 1); });
                }
            }
        }

    public:
        bool hasChanged() const noexcept
        {
            return changeBits.any();
        }
        
        std::bitset<N> const & getChanges() const noexcept
        {
            return changeBits;
        }

        void forgetChanges() noexcept
        {
            changeBits.reset();

            // TODO: only for observeChildDiffs ?
            if constexpr (std::is_base_of_v<Observable<T>, T>)
            {
                for (auto & elem : static_cast<std::array<T, N>>(*this))
                {
                    elem.forgetChanges();
                }
            }
        }


        obarr_t & operator =(obarr_t const & rhs)
        {
            if (& rhs != this)
            {
                (*this) = static_cast<std::array<T, N>>(rhs);
            }
            onChange();
            return * this;
        }

        obarr_t & operator =(arr_t const & rhs)
        {
            if (& rhs != this)
            {
                (*this) = rhs;
            }
            onChange();
            return * this;
        }

        obarr_t & operator =(obarr_t && rhs)
        {
            if (& rhs != this)
            {
                using std::swap;
                swap((*this), static_cast<std::array<T, N>>(rhs));
            }
            onChange();
            return * this;
        }

        obarr_t & operator =(arr_t && rhs)
        {
            if (& rhs != this)
            {
                using std::swap;
                swap((*this), rhs);
            }
            onChange();
            return * this;
        }

        void fill( const T& value )
        {
            arr_t::fill(value);
            onChange();
        }

        void swap( obarr_t & other ) noexcept(std::is_nothrow_swappable_v<T>)
        {
            arr_t::swap(static_cast<std::array<T, N>>(other));
            onChange();
        }

        void swap( arr_t & other ) noexcept(std::is_nothrow_swappable_v<T>)
        {
            arr_t::swap(other);
            onChange();
        }

    public:
        std::bitset<N> changeBits;
    };
}
