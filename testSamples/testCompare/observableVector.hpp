#pragma once

#include <memory>
#include <vector>
#include <utility>
#include <tuple>

namespace og
{
    template<typename T, typename Allocator = std::allocator<T>>
    class ObservableVector
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
        using obvec_t                   = ObservableVector<T, Allocator>;
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

        using NotifyFn                  = typename Observable<obvec_t>::NotifyFn;
        using ChangeLogEntry            = std::tuple<ChangeType, size_type, size_type>;

        ObservableVector(hu::Node node) noexcept
        : vect_(node) { }

        ObservableVector(obvec_t const & other)
        : vect_(other.vect_) { }

        ObservableVector(obvec_t && other) noexcept
        : vect_(std::move(other.vect_)) { }

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
            if constexpr (std::is_base_of_v<Observable<T>, T>)
            {
                for (auto & elem : vect_)
                {
                    elem.forgetChanges();
                }
            }
        }

        obvec_t & operator =(vec_t const & other)
        {
            auto num = vect_.size();
            vect_ = other;
            onChange(ChangeType::ElementsReplaced, 0, num);
            return * this;
        }
        
        obvec_t & operator =(vec_t && other) noexcept(
               std::allocator_traits<allocator_type>::propagate_on_container_move_assignment::value
            || std::allocator_traits<allocator_type>::is_always_equal::value)
        {   // TODO: redo
            auto num = vect_.size();
            vect_ = other;
            onChange(ChangeType::ElementsReplaced, 0, num);
            return * this;
        }
        
        obvec_t & operator =(std::initializer_list<T> ilist)
        {
            auto num = vect_.size();
            vect_ = ilist;
            onChange(ChangeType::ElementsReplaced, 0, num);
            return * this;
        }

        void assign(size_type count, T const & value)
        {
            auto num = vect_.size();
            vect_.assign(count, value);
            onChange(ChangeType::ElementsReplaced, 0, num);
        }

        template <class InputIt>
        void assign(InputIt first, InputIt last)
        {
            auto num = vect_.size();
            vect_.assign(first, last);
            onChange(ChangeType::ElementsReplaced, 0, num);
        }

        void assign(std::initializer_list<T> ilist)
        {
            auto num = vect_.size();
            vect_.assign(ilist);
            onChange(ChangeType::ElementsReplaced, 0, num);
        }

        reference at(size_type pos)
        {
            return vect_.at(pos);
        }

        const_reference at(size_type pos) const
        {
            return vect_.at(pos);
        }

        reference operator[](size_type pos)
        {
            return vect_[pos];
        }

        const_reference operator[](size_type pos) const
        {
            return vect_[pos];
        }

        reference front()
        {
            return vect_.front();
        }

        const_reference front() const
        {
            return vect_.front();
        }

        reference back()
        {
            return vect_.back();
        }

        const_reference back() const
        {
            return vect_.back();
        }

        T * data() noexcept
        {
            return vect_.data();
        }

        T const * data() const noexcept
        {
            return vect_.data();
        }

        iterator begin() noexcept
        {
            return vect_.begin();
        }

        const_iterator begin() const noexcept
        {
            return vect_.begin();
        }

        const_iterator cbegin() const noexcept
        {
            return vect_.cbegin();
        }

        iterator end() noexcept
        {
            return vect_.end();
        }

        const_iterator end() const noexcept
        {
            return vect_.end();
        }

        const_iterator cend() const noexcept
        {
            return vect_.cend();
        }

        reverse_iterator rbegin() noexcept
        {
            return vect_.rbegin();
        }

        const_reverse_iterator rbegin() const noexcept
        {
            return vect_.rbegin();
        }

        const_reverse_iterator crbegin() const noexcept
        {
            return vect_.crbegin();
        }

        reverse_iterator rend() noexcept
        {
            return vect_.rend();
        }

        const_reverse_iterator rend() const noexcept
        {
            return vect_.rend();
        }

        const_reverse_iterator crend() const noexcept
        {
            return vect_.crend();
        }

        bool empty() const noexcept
        {
            return vect_.empty();
        }

        size_type max_size() const noexcept
        {
            return vect_.max_size();
        }

        size_type size() const noexcept
        {
            return vect_.size();
        }

        void reserve(size_type new_cap)
        {
            vect_.reserve(new_cap);
        }

        size_type capacity() const noexcept
        {
            return vect_.capacity();
        }

        void shrink_to_fit()
        {
            vect_.shrink_to_fit();
        }

        void clear() noexcept
        {
            vect_.clear();
            Observable<obvec_t>::notifyChange();
        }

        const_iterator insert(const_iterator pos, T const & value)
        {
            auto index = pos - vect_.begin();
            auto it = vect_.insert(pos, value);
            onChange(ChangeType::ElementAdded, index);
            return it;
        }

        const_iterator insert(const_iterator pos, T && value)
        {
            auto index = pos - vect_.begin();
            auto it = vect_.insert(pos, std::move(value));
            onChange(ChangeType::ElementAdded, index);
            return it;
        }
        
        const_iterator insert(const_iterator pos, size_type count, T const & value)
        {
            auto index = pos - vect_.begin();
            auto it = vect_.insert(pos, count, value);
            onChange(ChangeType::ElementAdded, index, count);
            return it;
        }
        
        const_iterator insert(const_iterator pos, std::initializer_list<T> ilist)
        {
            auto index = pos - vect_.begin();
            auto it = vect_.insert(pos, ilist);
            onChange(ChangeType::ElementAdded, index, ilist.size());
            return it;
        }

        template <class... Args>
        const_iterator emplace(const_iterator pos, Args &&... args)
        {
            auto index = pos - vect_.begin();
            auto it = vect_.emplace(pos, std::forward<Args>(args)...);
            onChange(ChangeType::ElementAdded, index);
            return it;
        }

        const_iterator erase(const_iterator pos)
        {
            auto index = pos - vect_.begin();
            auto it = vect_.erase(pos);
            onChange(ChangeType::ElementRemoved, index);
            return it;
        }

        const_iterator erase(const_iterator first, const_iterator last)
        {
            auto dist = last - first;
            auto index = first - vect_.begin();
            auto it = vect_.erase(first, last);
            onChange(ChangeType::ElementRemoved, index, dist);
            return it;
        }

        template<class... Args>
        reference emplace_back(Args &&... args)
        {
            auto & ref = vect_.emplace_back(std::forward<Args>(args)...);
            onChange(ChangeType::ElementAdded, vect_.size() - 1);
            return ref;
        }

        void push_back(const T & value)
        {
            vect_.push_back(value);
            onChange(ChangeType::ElementAdded, vect_.size() - 1);
        }

        void push_back(T && value)
        {
            vect_.push_back(value);
            onChange(ChangeType::ElementAdded, vect_.size() - 1);
        }

        void pop_back()
        {
            vect_.pop_back();
            onChange(ChangeType::ElementRemoved, vect_.size());
        }

        void resize(size_type count)
        {
            auto originalSize = vect_.size();
            vect_.resize(count);
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
            auto originalSize = vect_.size();
            vect_.resize(count, value);
            if (count < originalSize)
            {
                onChange(ChangeType::ElementRemoved, count, originalSize - count);
            }
            else if (count > originalSize)
            {
                onChange(ChangeType::ElementAdded, originalSize, count - originalSize);
            }
        }

        void swap(obvec_t & other) noexcept(
               std::allocator_traits<allocator_type>::propagate_on_container_swap::value
            || std::allocator_traits<allocator_type>::is_always_equal::value)
        {
            vect_.swap(other.vect_);
            onChange(ChangeType::ElementsReplaced, other.size());
            other.onChange(ChangeType::ElementsReplaced, vect_.size());
        }

    private:
        vec_t vect_;
        std::vector<ChangeLogEntry> changeLog;
    };
}
