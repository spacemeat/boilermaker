#pragma once

#include <memory>
#include <vector>
#include <utility>
#include <tuple>
#include "observable.hpp"

namespace og
{
    template<typename T, typename Allocator = std::allocator<T>>
    class ObservableVector : public Observable
    {
    public:
        enum class ChangeType
        {
            ElementChanged,
            ElementAdded,
            ElementRemoved,
            ElementsReplaced
        };

        using vec_t                     = std::vector<T, Allocator>;
        using value_type 	            = typename vec_t::value_type;
        using allocator_type 	        = typename vec_t::allocator_type;
        using size_type 	            = typename vec_t::size_type;
        using difference_type 	        = typename vec_t::difference_type;
        using reference                 = typename vec_t::reference;
        using const_reference 	        = typename vec_t::const_reference;
        using pointer 	                = typename vec_t::pointer;
        using const_pointer 	        = typename vec_t::const_pointer;
        using iterator 	                = typename vec_t::iterator;
        using const_iterator 	        = typename vec_t::const_iterator;
        using reverse_iterator 	        = typename vec_t::reverse_iterator;
        using const_reverse_iterator 	= typename vec_t::const_reverse_iterator;

        using NotifyFn                  = Observable::NotifyFn;
        using ChangeLogEntry            = std::tuple<ChangeType, size_type, size_type>;

        // TODO: Add the NotifyFn to each constructor
        // TODO: Add constructor for Humon pass-through
        ObservableVector<T, Allocator>() noexcept(noexcept(Allocator()))
        : vect() { }

        explicit ObservableVector<T, Allocator>(Allocator const & alloc) noexcept
        : vect(alloc) { }

        ObservableVector<T, Allocator>(size_type count, T const & value, Allocator const & alloc = Allocator())
        : vect(count, value, alloc) { }

        explicit ObservableVector<T, Allocator>(size_type count, Allocator const & alloc = Allocator())
        : vect(count, alloc) { }

        template <class InputIt>
        ObservableVector<T, Allocator>(InputIt first, InputIt last, Allocator const & alloc = Allocator())
        : vect(std::forward<InputIt>(first), std::forward<InputIt>(last), alloc) { }
        ObservableVector<T, Allocator>(ObservableVector<T, Allocator> const & other)
        : vect(other.vect) { }

        ObservableVector<T, Allocator>(ObservableVector<T, Allocator> const & other, Allocator const & alloc)
        : vect(other.vect, alloc) { }

        ObservableVector<T, Allocator>(ObservableVector<T, Allocator> && other) noexcept
        : vect(other.vect) { }  // TODO: std::move(other.vect) ?

        ObservableVector<T, Allocator>(ObservableVector<T, Allocator> && other, Allocator const & alloc)
        : vect(other.vect, alloc) { } // TODO: std::move(other.vect) ?

        ObservableVector<T, Allocator>(std::initializer_list<T> init, Allocator const & alloc = Allocator())
        : vect(init, alloc) { }

        ObservableVector<T, Allocator>(std::vector<T, Allocator> const & other)
        : vect(other) { }

        ObservableVector<T, Allocator>(std::vector<T, Allocator> const & other, Allocator const & alloc)
        : vect(other, alloc) { }

        ObservableVector<T, Allocator>(std::vector<T, Allocator> && other) noexcept
        : vect(other) { }   // TODO: std::move(other) ?

        ObservableVector<T, Allocator>(std::vector<T, Allocator> && other, Allocator const & alloc)
        : vect(other, alloc) { } // TODO: std::move(other) ?

    private:
        void onChange(ChangeType changeType, size_type index = 0, size_type num = 1)
        {
            // record the change
            changeLog.emplace_back(changeType, index, num);

            // essentially reindex the change notifier for new or moved elements
            // TODO: This is for observeChildDiffs only
            if constexpr (std::is_base_of_v<Observable, T>)
            {
                switch(changeType)
                {
                case ChangeType::ElementChanged:
                    vect[index].setNotifyFn([this, index]{ this->onChange(ChangeType::ElementChanged, index, 1); });
                    break;
                case ChangeType::ElementAdded:
                    observeElements(index);
                    break;
                case ChangeType::ElementRemoved:
                    observeElements(index);
                    break;
                case ChangeType::ElementsReplaced:
                    observeElements(index);
                    break;
                }
            }

            // let any observers of this vector know that the vector has changes
            Observable::notifyChange();
        }

        // TODO: This is for observeChildDiffs only
        void observeElements(size_type startingAt)
        {
            if constexpr (std::is_base_of_v<Observable, T>)
            {
                T * observableElement = vect.data() + startingAt;
                for (size_type i = startingAt; i < vect.size(); ++i)
                {
                    observableElement->setNotifyFn([this, i]{ this->onChange(ChangeType::ElementChanged, i); });
                }
                observableElement += 1;
            }
        }

    public:
        bool hasChanged() const noexcept
        {
            return changeLog.size() > 0;
        }
        
        std::vector<ChangeLogEntry> const & getChanges() const noexcept
        {
            return changeLog;
        }

        void forgetChanges() noexcept
        {
            changeLog.clear();

            // TODO: only for observeChildDiffs ?
            if constexpr (std::is_base_of_v<Observable, T>)
            {
                for (auto & elem : vect)
                {
                    elem.forgetChanges();
                }
            }
        }

        ObservableVector<T, Allocator> & operator =(ObservableVector<T, Allocator> const & other)
        {
            auto num = vect.size();
            vect = other.vect;
            onChange(ChangeType::ElementsReplaced, 0, num);
            return * this;
        }

        ObservableVector<T, Allocator> & operator =(vec_t const & other)
        {
            auto num = vect.size();
            vect = other;
            onChange(ChangeType::ElementsReplaced, 0, num);
            return * this;
        }
        
        ObservableVector<T, Allocator> & operator =(ObservableVector<T, Allocator> && other) noexcept(
               std::allocator_traits<allocator_type>::propagate_on_container_move_assignment::value
            || std::allocator_traits<allocator_type>::is_always_equal::value)
        {
            auto num = vect.size();
            vect = other.vect;
            onChange(ChangeType::ElementsReplaced, 0, num);
            return * this;
        }
        
        ObservableVector<T, Allocator> & operator =(vec_t && other) noexcept(
               std::allocator_traits<allocator_type>::propagate_on_container_move_assignment::value
            || std::allocator_traits<allocator_type>::is_always_equal::value)
        {
            auto num = vect.size();
            vect = other;
            onChange(ChangeType::ElementsReplaced, 0, num);
            return * this;
        }
        
        ObservableVector<T, Allocator> & operator =(std::initializer_list<T> ilist)
        {
            auto num = vect.size();
            vect = ilist;
            onChange(ChangeType::ElementsReplaced, 0, num);
            return * this;
        }

        void assign(size_type count, T const & value)
        {
            auto num = vect.size();
            vect.assign(count, value);
            onChange(ChangeType::ElementsReplaced, 0, num);
        }

        template <class InputIt>
        void assign(InputIt first, InputIt last)
        {
            auto num = vect.size();
            vect.assign(first, last);
            onChange(ChangeType::ElementsReplaced, 0, num);
        }

        void assign(std::initializer_list<T> ilist)
        {
            auto num = vect.size();
            vect.assign(ilist);
            onChange(ChangeType::ElementsReplaced, 0, num);
        }

        reference at(size_type pos)
        {
            return vect.at(pos);
        }

        const_reference at(size_type pos) const
        {
            return vect.at(pos);
        }

        reference operator[](size_type pos)
        {
            return vect[pos];
        }

        const_reference operator[](size_type pos) const
        {
            return vect[pos];
        }

        reference front()
        {
            return vect.front();
        }

        const_reference front() const
        {
            return vect.front();
        }

        reference back()
        {
            return vect.back();
        }

        const_reference back() const
        {
            return vect.back();
        }

        T * data() noexcept
        {
            return vect.data();
        }

        T const * data() const noexcept
        {
            return vect.data();
        }

        iterator begin() noexcept
        {
            return vect.begin();
        }

        const_iterator begin() const noexcept
        {
            return vect.begin();
        }

        const_iterator cbegin() const noexcept
        {
            return vect.cbegin();
        }

        iterator end() noexcept
        {
            return vect.end();
        }

        const_iterator end() const noexcept
        {
            return vect.end();
        }

        const_iterator cend() const noexcept
        {
            return vect.cend();
        }

        reverse_iterator rbegin() noexcept
        {
            return vect.rbegin();
        }

        const_reverse_iterator rbegin() const noexcept
        {
            return vect.rbegin();
        }

        const_reverse_iterator crbegin() const noexcept
        {
            return vect.crbegin();
        }

        reverse_iterator rend() noexcept
        {
            return vect.rend();
        }

        const_reverse_iterator rend() const noexcept
        {
            return vect.rend();
        }

        const_reverse_iterator crend() const noexcept
        {
            return vect.crend();
        }

        bool empty() const noexcept
        {
            return vect.empty();
        }

        size_type max_size() const noexcept
        {
            return vect.max_size();
        }

        size_type size() const noexcept
        {
            return vect.size();
        }

        void reserve(size_type new_cap)
        {
            vect.reserve(new_cap);
        }

        size_type capacity() const noexcept
        {
            return vect.capacity();
        }

        void shrink_to_fit()
        {
            vect.shrink_to_fit();
        }

        void clear() noexcept
        {
            vect.clear();
            Observable::notifyChange();
        }

        const_iterator insert(const_iterator pos, T const & value)
        {
            auto index = pos - vect.begin();
            auto it = vect.insert(pos, value);
            onChange(ChangeType::ElementAdded, index);
            return it;
        }

        const_iterator insert(const_iterator pos, T && value)
        {
            auto index = pos - vect.begin();
            auto it = vect.insert(pos, value);
            onChange(ChangeType::ElementAdded, index);
            return it;
        }
        
        const_iterator insert(const_iterator pos, size_type count, T const & value)
        {
            auto index = pos - vect.begin();
            auto it = vect.insert(pos, count, value);
            onChange(ChangeType::ElementAdded, index, count);
            return it;
        }
        
        template <class InputIt>
        const_iterator insert(const_iterator pos, InputIt first, InputIt last)
        {
            auto index = pos - vect.begin();
            auto num = last - first;
            auto it = vect.insert(pos, first, last);
            onChange(ChangeType::ElementAdded, index, num);
            return it;
        }
        
        const_iterator insert(const_iterator pos, std::initializer_list<T> ilist)
        {
            auto index = pos - vect.begin();
            auto it = vect.insert(pos, ilist);
            onChange(ChangeType::ElementAdded, index, ilist.size());
            return it;
        }

        template <class... Args>
        const_iterator emplace(const_iterator pos, Args &&... args)
        {
            auto index = pos - vect.begin();
            auto it = vect.emplace(pos, std::forward<Args>(args)...);
            onChange(ChangeType::ElementAdded, index);
            return it;
        }

        const_iterator erase(const_iterator pos)
        {
            auto index = pos - vect.begin();
            auto it = vect.erase(pos);
            onChange(ChangeType::ElementRemoved, index);
            return it;
        }

        const_iterator erase(const_iterator first, const_iterator last)
        {
            auto dist = last - first;
            auto index = first - vect.begin();
            auto it = vect.erase(first, last);
            onChange(ChangeType::ElementRemoved, index, dist);
            return it;
        }

        template<class... Args>
        reference emplace_back(Args &&... args)
        {
            auto & ref = vect.emplace_back(std::forward<Args>(args)...);
            onChange(ChangeType::ElementAdded, vect.size() - 1);
            return ref;
        }

        void push_back(const T & value)
        {
            vect.push_back(value);
            onChange(ChangeType::ElementAdded, vect.size() - 1);
        }

        void push_back(T && value)
        {
            vect.push_back(value);
            onChange(ChangeType::ElementAdded, vect.size() - 1);
        }

        void pop_back()
        {
            vect.pop_back();
            onChange(ChangeType::ElementRemoved, vect.size());
        }

        void resize(size_type count)
        {
            auto originalSize = vect.size();
            vect.resize(count);
            if (count < originalSize)
            {
                onChange(ChangeType::ElementRemoved, count, originalSize - count);
            }
            else if (count > originalSize)
            {
                onChange(ChangeType::ElementAdded, originalSize, count - originalSize);
            }
        }

        void resize(size_type count, value_type const & value)
        {
            auto originalSize = vect.size();
            vect.resize(count, value);
            if (count < originalSize)
            {
                onChange(ChangeType::ElementRemoved, count, originalSize - count);
            }
            else if (count > originalSize)
            {
                onChange(ChangeType::ElementAdded, originalSize, count - originalSize);
            }
        }

        void swap(vec_t & other) noexcept(
               std::allocator_traits<allocator_type>::propagate_on_container_swap::value
            || std::allocator_traits<allocator_type>::is_always_equal::value)
        {
            vect.swap(other);
            onChange(ChangeType::ElementsReplaced, other.size());
        }

        void swap(ObservableVector<T, Allocator> & other) noexcept(
               std::allocator_traits<allocator_type>::propagate_on_container_swap::value
            || std::allocator_traits<allocator_type>::is_always_equal::value)
        {
            vect.swap(other.vect);
            onChange(ChangeType::ElementsReplaced, other.size());
            other.onChange(ChangeType::ElementsReplaced, vect.size());
        }

    private:
        vec_t vect;
        std::vector<ChangeLogEntry> changeLog;
    };
}
