#pragma once

#include <string>
#include <memory>
#include <vector>
#include <utility>
#include <tuple>
#include "observable.hpp"

namespace og
{
    template<class CharT,
             class Traits = std::char_traits<CharT>,
             class Allocator = std::allocator<CharT>>
    class ObservableString : public Observable<ObservableString<CharT, Traits, Allocator>>
    {
    public:
        using string_t                  = std::basic_string<CharT, Traits, Allocator>;
        using obstring_t                = ObservableString<CharT, Traits, Allocator>;
        using traits_type               = typename string_t::traits_type;
        using value_type 	            = typename string_t::value_type;
        using allocator_type 	        = typename string_t::allocator_type;
        using size_type 	            = typename string_t::size_type;
        using difference_type 	        = typename string_t::difference_type;
        using reference                 = typename string_t::reference;
        using const_reference 	        = typename string_t::const_reference;
        using pointer 	                = typename string_t::pointer;
        using const_pointer 	        = typename string_t::const_pointer;
        using iterator 	                = typename string_t::iterator;
        using const_iterator 	        = typename string_t::const_iterator;
        using reverse_iterator 	        = typename string_t::reverse_iterator;
        using const_reverse_iterator 	= typename string_t::const_reverse_iterator;

        using NotifyFn                  = typename Observable<ObservableString<CharT, Traits, Allocator>>::NotifyFn;

        ObservableString() noexcept(noexcept(Allocator() ))
        : str_(Allocator() ) {}

        explicit ObservableString(Allocator const & alloc) noexcept
        : str_(alloc) { }

        ObservableString(size_type count,
              CharT ch,
              const Allocator& alloc = Allocator() )
        : str_(ch, alloc) { }

        ObservableString(string_t const & other,
              size_type pos,
              const Allocator& alloc = Allocator() )
        : str_(other, pos, alloc) { }

        ObservableString(obstring_t const & other,
              size_type pos,
              const Allocator& alloc = Allocator() )
        : str_(other.str_, pos, alloc) { }

        ObservableString(string_t const & other,
              size_type pos,
              size_type count,
              const Allocator& alloc = Allocator() )
        : str_(other, pos, count, alloc) { }

        ObservableString(obstring_t const & other,
              size_type pos,
              size_type count,
              const Allocator& alloc = Allocator() )
        : str_(other.str_, pos, count, alloc) { }

        ObservableString(CharT const * s,
              size_type count,
              const Allocator& alloc = Allocator() )
        : str_(s, count, alloc) { }

        ObservableString(CharT const * s,
              const Allocator& alloc = Allocator() )
        : str_(s, alloc) { }

        template< class InputIt >
        ObservableString(InputIt first, InputIt last,
              const Allocator& alloc = Allocator() )
        : str_(first, last, alloc) { }

        ObservableString(string_t const & other)
        : str_(other) { }

        ObservableString(obstring_t const & other)
        : Observable<obstring_t>(other), str_(other.str_) { }

        ObservableString(string_t const & other, Allocator const & alloc)
        : str_(other, alloc) { }

        ObservableString(obstring_t const & other, Allocator const & alloc)
        : Observable<obstring_t>(other), str_(other.str_, alloc) { }

        ObservableString(string_t && other) noexcept
        : str_(other) { }

        ObservableString(obstring_t && other) noexcept
        : Observable<obstring_t>(other), str_(other.str_) { }

        ObservableString(string_t && other, Allocator const & alloc)
        : str_(other, alloc) { }

        ObservableString(obstring_t && other, Allocator const & alloc)
        : Observable<obstring_t>(other), str_(other.str_, alloc) { }

        ObservableString(std::initializer_list<CharT> ilist,
              const Allocator& alloc = Allocator() )
        : str_(ilist, alloc) { }
        
        template < class T >
        explicit ObservableString(T const & t, const Allocator& alloc = Allocator() )
        : str_(t, alloc) { }

        template < class T >
        ObservableString(T const & t, size_type pos, size_type n,
              const Allocator& alloc = Allocator() )
        : str_(t, pos, n, alloc) { }

        obstring_t & operator =(string_t const & str)
        {
            str_ = str;
            onChange();
            return * this;
        }

        obstring_t & operator =(obstring_t const & str)
        {
            str_ = str.str_;
            onChange();
            return * this;
        }

        obstring_t & operator =(string_t && str) noexcept(
               std::allocator_traits<Allocator>::propagate_on_container_move_assignment::value
            || std::allocator_traits<Allocator>::is_always_equal::value)
        {
            str_ = str;
            onChange();
            return * this;
        }

        obstring_t & operator =(obstring_t && str) noexcept(
               std::allocator_traits<Allocator>::propagate_on_container_move_assignment::value
            || std::allocator_traits<Allocator>::is_always_equal::value)
        {
            str_ = str.str_; // TODO: move or something?
            onChange();
            return * this;
        }

        obstring_t & operator =(CharT const * s)
        {
            str_ = s;
            onChange();
            return * this;
        }

        obstring_t & operator =(CharT ch)
        {
            str_ = ch;
            onChange();
            return * this;
        }

        obstring_t & operator =(std::initializer_list<CharT> ilist)
        {
            str_ = ilist;
            onChange();
            return * this;
        }

        template<class T>
        obstring_t & operator =(T const & t)
        {
            str_ = t;
            onChange();
            return * this;
        }

    private:
        void onChange()
        {
            changed = true;
            Observable<obstring_t>::notifyChange(*this);
        }
    
    public:
        bool hasChanged() const noexcept
        {
            return changed;
        }

        void forgetChanges() noexcept
        {
            changed = false;
        }

        obstring_t & assign(size_type count, CharT ch)
        {
            str_.assign(count, ch);
            onChange();
            return * this;
        }

        obstring_t & assign(string_t const & str)
        {
            str_.assign(str);
            onChange();
            return * this;
        }

        obstring_t & assign(obstring_t const & str)
        {
            str_.assign(str.str_);
            onChange();
            return * this;
        }

        obstring_t & assign(string_t const & str,
                      size_type pos, size_type count = string_t::npos)
        {
            str_.assign(str, pos, count);
            onChange();
            return * this;
        }

        obstring_t & assign(obstring_t const & str,
                      size_type pos, size_type count = string_t::npos)
        {
            str_.assign(str.str_, pos, count);
            onChange();
            return * this;
        }

        obstring_t & assign(string_t && str) noexcept(
               std::allocator_traits<Allocator>::propagate_on_container_move_assignment::value
            || std::allocator_traits<Allocator>::is_always_equal::value)
        {
            str_.assign(str);
            onChange();
            return * this;
        }

        obstring_t & assign(obstring_t && str) noexcept(
               std::allocator_traits<Allocator>::propagate_on_container_move_assignment::value
            || std::allocator_traits<Allocator>::is_always_equal::value)
        {
            str_.assign(str.str_);
            onChange();
            return * this;
        }

        obstring_t & assign(CharT const * s, size_type count)
        {
            str_.assign(s, count);
            onChange();
            return * this;
        }

        obstring_t & assign(CharT const * s)
        {
            str_.assign(s);
            onChange();
            return * this;
        }

        template< class InputIt >
        obstring_t & assign(InputIt first, InputIt last)
        {
            str_.assign(first, last);
            onChange();
            return * this;
        }

        obstring_t & assign(std::initializer_list<CharT> ilist)
        {
            str_.assign(ilist);
            onChange();
            return * this;
        }

        template < class T >
        obstring_t & assign(T const & t)
        {
            str_.assign(t);
            onChange();
            return * this;
        }

        template < class T >
        obstring_t & assign(T const & t,
                      size_type pos, size_type count = string_t::npos)
        {
            str_.assign(t, pos, count);
            onChange();
            return * this;
        }

        allocator_type get_allocator() const
        {
            return str_.get_allocator();
        }

        // TODO: Should we hide the non-const versions? No for now.
        reference at(size_type pos)
        {
            return str_.at(pos);
        }

        const_reference at(size_type pos) const
        {
            return str_.at(pos);
        }

        reference operator[]( size_type pos)
        {
            return str[pos];
        }

        const_reference operator[]( size_type pos) const
        {
            return str[pos];
        }

        CharT& front()
        {
            return str_.front();
        }

        const CharT& front() const
        {
            return str_.front();
        }

        CharT& back()
        {
            return str_.back();
        }

        const CharT& back() const
        {
            return str_.back();
        }

        const CharT* data() const noexcept
        {
            return str_.data();
        }

        CharT* data() noexcept
        {
            return str_.data();
        }

        const CharT* c_str() const noexcept
        {
            return str_.c_str();
        }

        operator std::basic_string_view<CharT, Traits>() const noexcept
        {
            return str_.operator std::basic_string_view<CharT, Traits>();
        }

        iterator begin() noexcept
        {
            return str_.begin();
        }

        const_iterator begin() const noexcept
        {
            return str_.begin();
        }

        const_iterator cbegin() const noexcept
        {
            return str_.cbegin();
        }

        iterator end() noexcept
        {
            return str_.end();
        }
        
        const_iterator end() const noexcept
        {
            return str_.end();
        }

        const_iterator cend() const noexcept
        {
            return str_.cend();
        }

        iterator rbegin() noexcept
        {
            return str_.rbegin();
        }

        const_iterator rbegin() const noexcept
        {
            return str_.rbegin();
        }

        const_iterator crbegin() const noexcept
        {
            return str_.crbegin();
        }

        iterator rend() noexcept
        {
            return str_.rend();
        }
        
        const_iterator rend() const noexcept
        {
            return str_.rend();
        }

        const_iterator crend() const noexcept
        {
            return str_.crend();
        }

        bool empty() const noexcept
        {
            return str_.empty();
        }

        size_type size() const noexcept
        {
            return str_.size();
        }

        size_type length() const noexcept
        {
            return str_.length();
        }

        size_type max_size() const noexcept
        {
            return str_.max_size();
        }

        void reserve(size_type new_cap = 0)
        {
            return str_.reserve(new_cap);
        }

        size_type capacity() const noexcept
        {
            return str_.capacity();
        }

        void shrink_to_fit()
        {
            str_.strink_to_fit();
        }

        void clear() noexcept
        {
            str_.clear();
            onChange();
        }

        obstring_t & insert(size_type index, size_type count, CharT ch)
        {
            str_.insert(index, count, ch);
            onChange();
            return * this;
        }

        obstring_t & insert(size_type index, CharT const * s)
        {
            str_.insert(index, s);
            onChange();
            return * this;
        }

        obstring_t & insert(size_type index, CharT const * s, size_type count)
        {
            str_.insert(index, s, count);
            onChange();
            return * this;
        }

        obstring_t & insert(size_type index, string_t const & str)
        {
            str_.insert(index, str);
            onChange();
            return * this;
        }

        obstring_t & insert(size_type index, obstring_t const & str)
        {
            str_.insert(index, str.str_);
            onChange();
            return * this;
        }

        obstring_t & insert(size_type index, string_t const & str,
                      size_type index_str, size_type count = string_t::npos)
        {
            str_.insert(index, str, index_str, count);
            onChange();
            return * this;
        }
        
        obstring_t & insert(size_type index, obstring_t const & str,
                      size_type index_str, size_type count = string_t::npos)
        {
            str_.insert(index, str.str_, index_str, count);
            onChange();
            return * this;
        }
        
        iterator insert(const_iterator pos, CharT ch)
        {
            str_.insert(pos, ch);
            onChange();
            return * this;
        }

        iterator insert(const_iterator pos, size_type count, CharT ch)
        {
            str_.insert(pos, count, ch);
            onChange();
            return * this;
        }

        template< class InputIt >
        iterator insert(const_iterator pos, InputIt first, InputIt last)
        {
            str_.insert(pos, first, last);
            onChange();
            return * this;
        }

        iterator insert(const_iterator pos, std::initializer_list<CharT> ilist)
        {
            str_.insert(pos, ilist);
            onChange();
            return * this;
        }

        template < class T >
        obstring_t & insert(size_type pos, T const & t)
        {
            str_.insert(pos, t);
            onChange();
            return * this;
        }

        template < class T >
        obstring_t & insert(size_type index, T const & t,
                      size_type index_str, size_type count = string_t::npos)
        {
            str_.insert(index, t, index_str, count);
            onChange();
            return * this;
        }
        
        obstring_t & erase(size_type index = 0, size_type count = string_t::npos)
        {
            str_.erase(index, count);
            onChange();
            return * this;
        }

        iterator erase(const_iterator position)
        {
            str_.erase(position);
            onChange();
            return * this;
        }

        iterator erase(const_iterator first, const_iterator last)
        {
            str_.erase(first, last);
            onChange();
            return * this;
        }

        void push_back(CharT ch)
        {
            str_.push_back(ch);
            onChange();
        }

        void pop_back()
        {
            str_.pop_back();
            onChange();
        }

        obstring_t & append(size_type count, CharT ch)
        {
            str_.append(count, ch);
            onChange();
            return * this;
        }

        obstring_t & append(string_t const & str)
        {
            str_.append(str);
            onChange();
            return * this;
        }

        obstring_t & append(obstring_t const & str)
        {
            str_.append(str.str_);
            onChange();
            return * this;
        }

        obstring_t & append(string_t const & str,
                      size_type pos, size_type count = string_t::npos)
        {
            str_.append(str, pos, count);
            onChange();
            return * this;
        }
        
        obstring_t & append(obstring_t const & str,
                      size_type pos, size_type count = string_t::npos)
        {
            str_.append(str.str_, pos, count);
            onChange();
            return * this;
        }
        
        obstring_t & append(CharT const * s, size_type count)
        {
            str_.append(s, count);
            onChange();
            return * this;
        }

        obstring_t & append(CharT const * s)
        {
            str_.append(s);
            onChange();
            return * this;
        }

        template< class InputIt >
        obstring_t & append(InputIt first, InputIt last)
        {
            str_.append(first, last);
            onChange();
            return * this;
        }

        obstring_t & append(std::initializer_list<CharT> ilist)
        {
            str_.append(ilist);
            onChange();
            return * this;
        }

        template < class T >
        obstring_t & append(T const & t)
        {
            str_.append(t);
            onChange();
            return * this;
        }

        template < class T >
        obstring_t & append(T const & t,
                      size_type pos, size_type count = string_t::npos)
        {
            str_.append(t, pos, count);
            onChange();
            return * this;
        }
        
        obstring_t & operator +=(string_t const & str)
        {
            str_.operator +=(str);
            onChange();
            return * this;
        }

        obstring_t & operator +=(obstring_t const & str)
        {
            str_.operator +=(str.str_);
            onChange();
            return * this;
        }

        obstring_t & operator +=(CharT ch)
        {
            str_.operator +=(ch);
            onChange();
            return * this;
        }

        obstring_t & operator +=(CharT const * s)
        {
            str_.operator +=(s);
            onChange();
            return * this;
        }

        obstring_t & operator +=(std::initializer_list<CharT> ilist)
        {
            str_.operator +=(ilist);
            onChange();
            return * this;
        }

        template < class T >
        obstring_t & operator +=(T const & t)
        {
            str_.operator +=(t);
            onChange();
            return * this;
        }

        int compare(string_t const & str) const noexcept
        {
            return str_.compare(str);
        }

        int compare(obstring_t const & str) const noexcept
        {
            return str_.compare(str.str_);
        }

        int compare(size_type pos1, size_type count1,
             string_t const & str) const
        {
            return str_.compare(pos1, count1, str);
        }

        int compare(size_type pos1, size_type count1,
             obstring_t const & str) const
        {
            return str_.compare(pos1, count1, str.str_);
        }

        int compare(size_type pos1, size_type count1,
             string_t const & str,
             size_type pos2, size_type count2 = string_t::npos) const
        {
            return str_.compare(pos1, count1, str, pos2, count2);
        }

        int compare(size_type pos1, size_type count1,
             obstring_t const & str,
             size_type pos2, size_type count2 = string_t::npos) const
        {
            return str_.compare(pos1, count1, str.str_, pos2, count2);
        }

        int compare(CharT const * s) const
        {
            return str_.compare(s);
        }

        int compare(size_type pos1, size_type count1,
             CharT const * s) const
        {
            return str_.compare(pos1, count1, s);
        }
        
        int compare(size_type pos1, size_type count1,
             CharT const * s, size_type count2) const
        {
            return str_.compare(pos1, count1, s, count2);
        }
        
        template < class T >
        int compare(T const & t) const noexcept(
            std::is_convertible_v<const T&, std::basic_string_view<CharT, Traits>>)
        {
            return str_.compare(t);
        }
        
        template < class T >
        int compare(size_type pos1, size_type count1,
             T const & t) const
        {
            return str_.compare(pos1, count1, t);
        }
        
        template < class T >
        int compare(size_type pos1, size_type count1,
             T const & t,
             size_type pos2, size_type count2 = string_t::npos) const
        {
            return str_.compare(pos1, count1, t, pos2, count2);
        }
        
        obstring_t & replace(size_type pos, size_type count,
                       string_t const & str)
        {
            str_.replace(pos, count, str);
            onChange();
            return * this;
        }

        obstring_t & replace(size_type pos, size_type count,
                       obstring_t const & str)
        {
            str_.replace(pos, count, str.str_);
            onChange();
            return * this;
        }

        obstring_t & replace(const_iterator first, const_iterator last,
                       string_t const & str)
        {
            str_.replace(first, last, str);
            onChange();
            return * this;
        }

        obstring_t & replace(const_iterator first, const_iterator last,
                       obstring_t const & str)
        {
            str_.replace(first, last, str.str_);
            onChange();
            return * this;
        }

        obstring_t & replace(size_type pos, size_type count,
                       string_t const & str,
                       size_type pos2, size_type count2 = string_t::npos)
        {
            str_.replace(pos, count, str, pos2, count2);
            onChange();
            return * this;
        }

        obstring_t & replace(size_type pos, size_type count,
                       obstring_t const & str,
                       size_type pos2, size_type count2 = string_t::npos)
        {
            str_.replace(pos, count, str.str_, pos2, count2);
            onChange();
            return * this;
        }

        template< class InputIt >
        obstring_t & replace(const_iterator first, const_iterator last,
                       InputIt first2, InputIt last2)
        {
            str_.replace(first, last, first2, last2);
            onChange();
            return * this;
        }

        obstring_t & replace(size_type pos, size_type count,
                       CharT const * cstr, size_type count2)
        {
            str_.replace(pos, count, cstr, count2);
            onChange();
            return * this;
        }

        obstring_t & replace(const_iterator first, const_iterator last,
                       CharT const * cstr, size_type count2)
        {
            str_.replace(first, last, cstr, count2);
            onChange();
            return * this;
        }

        obstring_t & replace(size_type pos, size_type count,
                       CharT const * cstr)
        {
            str_.replace(pos, count, cstr);
            onChange();
            return * this;
        }

        obstring_t & replace(const_iterator first, const_iterator last,
                       CharT const * cstr)
        {
            str_.replace(first, last, cstr);
            onChange();
            return * this;
        }

        obstring_t & replace(size_type pos, size_type count,
                       size_type count2, CharT ch)
        {
            str_.replace(pos, count, count2, ch);
            onChange();
            return * this;
        }

        obstring_t & replace(const_iterator first, const_iterator last,
                       size_type count2, CharT ch)
        {
            str_.replace(first, last, count2, ch);
            onChange();
            return * this;
        }

        obstring_t & replace(const_iterator first, const_iterator last,
                       std::initializer_list<CharT> ilist)
        {
            str_.replace(first, last, ilist);
            onChange();
            return * this;
        }

        template < class T >
        obstring_t & replace(size_type pos, size_type count,
                       T const & t)
        {
            str_.replace(pos, count, t);
            onChange();
            return * this;
        }

        template < class T >
        obstring_t & replace(const_iterator first, const_iterator last,
                       T const & t)
        {
            str_.replace(first, last, t);
            onChange();
            return * this;
        }

        template < class T >
        obstring_t & replace(size_type pos, size_type count, T const & t,
                       size_type pos2, size_type count2 = string_t::npos)
        {
            str_.replace(pos, count, t, pos2, count2);
            onChange();
            return * this;
        }

        string_t substr(size_type pos = 0, size_type count = string_t::npos) const
        {
            return str_.substr(pos, count);
        }

        size_type copy(CharT* dest, size_type count, size_type pos = 0) const
        {
            return str_.copy(dest, count, pos);
        }

        void resize(size_type count)
        {
            str_.resize(count);
        }

        void resize(size_type count, CharT ch)
        {
            str_.resize(count, ch);
        }

        void swap(string_t & other) noexcept(
               std::allocator_traits<Allocator>::propagate_on_container_swap::value
            || std::allocator_traits<Allocator>::is_always_equal::value)
        {
            str_.swap(other);
            onChange();
        }

        void swap(obstring_t & other) noexcept(
               std::allocator_traits<Allocator>::propagate_on_container_swap::value
            || std::allocator_traits<Allocator>::is_always_equal::value)
        {
            str_.swap(other.str_);
            onChange();
            other.onChange();
        }

        size_type find(string_t const & str, size_type pos = 0) const noexcept
        {
            return str_.find(str, pos);
        }

        size_type find(obstring_t const & str, size_type pos = 0) const noexcept
        {
            return str_.find(str.str_, pos);
        }

        size_type find(CharT const * s, size_type pos, size_type count) const
        {
            return str_.find(s, pos, count);
        }

        size_type find(CharT const * s, size_type pos = 0) const
        {
            return str_.find(s, pos);
        }

        size_type find(CharT ch, size_type pos = 0) const noexcept
        {
            return str_.find(ch, pos);
        }

        template < class T >
        size_type find(T const & t, size_type pos = 0) const noexcept(
            std::is_convertible_v<const T&, std::basic_string_view<CharT, Traits>>)
        {
            return str_.find(t, pos);
        }

        size_type rfind(string_t const & str,
                 size_type pos = string_t::npos) const noexcept
        {
            return str_.rfind(str, pos);
        }
        
        size_type rfind(obstring_t const & str,
                 size_type pos = string_t::npos) const noexcept
        {
            return str_.rfind(str.str_, pos);
        }
        
        size_type rfind(CharT const * s, size_type pos, size_type count) const
        {
            return str_.rfind(s, pos, count);
        }

        size_type rfind(CharT const * s, size_type pos = string_t::npos) const
        {
            return str_.rfind(s, pos);
        }

        size_type rfind(CharT ch, size_type pos = string_t::npos) const noexcept
        {
            return str_.rfind(ch, pos);
        }

        template < class T >
        size_type rfind(T const & t, size_type pos = string_t::npos) const noexcept(
            std::is_convertible_v<const T&, std::basic_string_view<CharT, Traits>>)
        {
            return str_.rfind(t, pos);
        }

        size_type find_first_of(string_t const & str,
                         size_type pos = 0) const noexcept
        {
            return str_.find_first_of(str, pos);
        }
        
        size_type find_first_of(obstring_t const & str,
                         size_type pos = 0) const noexcept
        {
            return str_.find_first_of(str.str_, pos);
        }
        
        size_type find_first_of(CharT const * s, size_type pos, size_type count) const
        {
            return str_.find_first_of(s, pos, count);
        }

        size_type find_first_of(CharT const * s, size_type pos = 0) const
        {
            return str_.find_first_of(s, pos);
        }

        size_type find_first_of(CharT ch, size_type pos = 0) const noexcept
        {
            return str_.find_first_of(ch, pos);
        }

        template < class T >
        size_type find_first_of(T const & t, size_type pos = 0) const noexcept(
            std::is_convertible_v<const T&, std::basic_string_view<CharT, Traits>>)
        {
            return str_.find_first_of(t, pos);
        }

        size_type find_first_not_of(string_t const & str,
                             size_type pos = 0) const noexcept
        {
            return str_.find_first_not_of(str, pos);
        }
        
        size_type find_first_not_of(obstring_t const & str,
                             size_type pos = 0) const noexcept
        {
            return str_.find_first_not_of(str.str_, pos);
        }
        
        size_type find_first_not_of(CharT const * s,
                             size_type pos, size_type count) const
        {
            return str_.find_first_not_of(s, pos, count);
        }
        
        size_type find_first_not_of(CharT const * s,
                             size_type pos = 0) const
        {
            return str_.find_first_not_of(s, pos);
        }
        
        size_type find_first_not_of(CharT ch, size_type pos = 0) const noexcept
        {
            return str_.find_first_not_of(ch, pos);
        }

        template < class T >
        size_type find_first_not_of(T const & t, size_type pos = 0) const noexcept(
            std::is_convertible_v<const T&, std::basic_string_view<CharT, Traits>>)
        {
            return str_.find_first_not_of(t, pos);
        }

        constexpr size_type find_last_of(string_t const & str,
                                   size_type pos = string_t::npos) const noexcept
        {
            return str_.find_last_of(str, pos);
        }

        constexpr size_type find_last_of(obstring_t const & str,
                                   size_type pos = string_t::npos) const noexcept
        {
            return str_.find_last_of(str.str_, pos);
        }

        constexpr size_type find_last_of(CharT const * s,
                                  size_type pos, size_type count) const
        {
            return str_.find_last_of(s, pos, count);
        }

        size_type find_last_of(CharT const * s, size_type pos = string_t::npos) const
        {
            return str_.find_last_of(s, pos);
        }

        size_type find_last_of(CharT ch, size_type pos = string_t::npos) const noexcept
        {
            return str_.find_last_of(ch, pos);
        }

        template < class T >
        size_type find_last_of(T const & t, size_type pos = string_t::npos) const noexcept(
            std::is_convertible_v<const T&, std::basic_string_view<CharT, Traits>>)
        {
            return str_.find_last_of(t, pos);
        }

        size_type find_last_not_of(string_t const & str,
                            size_type pos = string_t::npos) const noexcept
        {
            return str_.find_last_not_of(str, pos);
        }

        size_type find_last_not_of(obstring_t const & str,
                            size_type pos = string_t::npos) const noexcept
        {
            return str_.find_last_not_of(str.str_, pos);
        }

        size_type find_last_not_of(CharT const * s,
                            size_type pos, size_type count) const
        {
            return str_.find_last_not_of(s, pos, count);
        }

        size_type find_last_not_of(CharT const * s, size_type pos = string_t::npos) const
        {
            return str_.find_last_not_of(s, pos);
        }

        size_type find_last_not_of(CharT ch, size_type pos = string_t::npos) const noexcept
        {
            return str_.find_last_not_of(ch, pos);
        }

        template < class T >
        size_type find_last_not_of(T const & t, size_type pos = string_t::npos) const noexcept(
            std::is_convertible_v<const T&, std::basic_string_view<CharT, Traits>>)
        {
            return str_.find_last_not_of(t, pos);
        }

        string_t & str()
        {
            return str_;
        }

        string_t const & str() const
        {
            return str_;
        }

    private:

        string_t str_;
        bool changed = false;
    };

    template<class CharT, class Traits, class Alloc, class LhsArg, class RhsArg>
    std::basic_string<CharT, Traits, Alloc> operator +(LhsArg && lhs, LhsArg && rhs)
    {
        return operator +(std::forward<LhsArg>(lhs), std::forward<RhsArg>(rhs));
    }

    template<class CharT, class Traits, class Alloc, class Arg>
    std::basic_string<CharT, Traits, Alloc> operator +(ObservableString<CharT, Traits, Alloc> & lhs, Arg && rhs)
    {
        return operator +(lhs.str(), std::forward<Arg>(rhs));
    }

    template<class CharT, class Traits, class Alloc, class Arg>
    std::basic_string<CharT, Traits, Alloc> operator +(Arg && lhs, ObservableString<CharT, Traits, Alloc> & rhs)
    {
        return operator +(std::forward<Arg>(lhs), rhs.str());
    }

    template<class CharT, class Traits, class Alloc>
    std::basic_string<CharT, Traits, Alloc> operator +(ObservableString<CharT, Traits, Alloc> & lhs, ObservableString<CharT, Traits, Alloc> & rhs)
    {
        return operator +(lhs.str(), rhs.str());
    }

    template< class CharT, class Traits, class Alloc >
    bool operator==( const ObservableString<CharT,Traits,Alloc>& lhs,
                    const std::basic_string<CharT,Traits,Alloc>& rhs ) noexcept
    {
        return lhs.str() == rhs;
    }

    template< class CharT, class Traits, class Alloc >
    bool operator==( const std::basic_string<CharT,Traits,Alloc>& lhs,
                    const ObservableString<CharT,Traits,Alloc>& rhs ) noexcept
    {
        return lhs == rhs.str();
    }

    template< class CharT, class Traits, class Alloc >
    bool operator==( const ObservableString<CharT,Traits,Alloc>& lhs,
                    const ObservableString<CharT,Traits,Alloc>& rhs ) noexcept
    {
        return lhs.str() == rhs.str();
    }

    template< class CharT, class Traits, class Alloc >
    bool operator!=( const ObservableString<CharT,Traits,Alloc>& lhs,
                    const std::basic_string<CharT,Traits,Alloc>& rhs ) noexcept
    {
        return lhs.str() != rhs;
    }

    template< class CharT, class Traits, class Alloc >
    bool operator!=( const std::basic_string<CharT,Traits,Alloc>& lhs,
                    const ObservableString<CharT,Traits,Alloc>& rhs ) noexcept
    {
        return lhs != rhs.str();
    }

    template< class CharT, class Traits, class Alloc >
    bool operator!=( const ObservableString<CharT,Traits,Alloc>& lhs,
                    const ObservableString<CharT,Traits,Alloc>& rhs ) noexcept
    {
        return lhs.str() != rhs.str();
    }

    template< class CharT, class Traits, class Alloc >
    bool operator<( const ObservableString<CharT,Traits,Alloc>& lhs,
                    const std::basic_string<CharT,Traits,Alloc>& rhs ) noexcept
    {
        return lhs.str() < rhs;
    }

    template< class CharT, class Traits, class Alloc >
    bool operator<( const std::basic_string<CharT,Traits,Alloc>& lhs,
                    const ObservableString<CharT,Traits,Alloc>& rhs ) noexcept
    {
        return lhs < rhs.str();
    }

    template< class CharT, class Traits, class Alloc >
    bool operator<( const ObservableString<CharT,Traits,Alloc>& lhs,
                    const ObservableString<CharT,Traits,Alloc>& rhs ) noexcept
    {
        return lhs.str() < rhs.str();
    }

    template< class CharT, class Traits, class Alloc >
    bool operator<=( const ObservableString<CharT,Traits,Alloc>& lhs,
                    const std::basic_string<CharT,Traits,Alloc>& rhs ) noexcept
    {
        return lhs.str() <= rhs;
    }

    template< class CharT, class Traits, class Alloc >
    bool operator<=( const std::basic_string<CharT,Traits,Alloc>& lhs,
                    const ObservableString<CharT,Traits,Alloc>& rhs ) noexcept
    {
        return lhs<= rhs.str();
    }

    template< class CharT, class Traits, class Alloc >
    bool operator<=( const ObservableString<CharT,Traits,Alloc>& lhs,
                    const ObservableString<CharT,Traits,Alloc>& rhs ) noexcept
    {
        return lhs.str() <= rhs.str();
    }

    template< class CharT, class Traits, class Alloc >
    bool operator>( const ObservableString<CharT,Traits,Alloc>& lhs,
                    const std::basic_string<CharT,Traits,Alloc>& rhs ) noexcept
    {
        return lhs.str() > rhs;
    }

    template< class CharT, class Traits, class Alloc >
    bool operator>( const std::basic_string<CharT,Traits,Alloc>& lhs,
                    const ObservableString<CharT,Traits,Alloc>& rhs ) noexcept
    {
        return lhs > rhs.str();
    }

    template< class CharT, class Traits, class Alloc >
    bool operator>( const ObservableString<CharT,Traits,Alloc>& lhs,
                    const ObservableString<CharT,Traits,Alloc>& rhs ) noexcept
    {
        return lhs.str() > rhs.str();
    }

    template< class CharT, class Traits, class Alloc >
    bool operator>=( const ObservableString<CharT,Traits,Alloc>& lhs,
                    const std::basic_string<CharT,Traits,Alloc>& rhs ) noexcept
    {
        return lhs.str() >= rhs;
    }

    template< class CharT, class Traits, class Alloc >
    bool operator>=( const std::basic_string<CharT,Traits,Alloc>& lhs,
                    const ObservableString<CharT,Traits,Alloc>& rhs ) noexcept
    {
        return lhs >= rhs.str();
    }

    template< class CharT, class Traits, class Alloc >
    bool operator>=( const ObservableString<CharT,Traits,Alloc>& lhs,
                    const ObservableString<CharT,Traits,Alloc>& rhs ) noexcept
    {
        return lhs.str() >= rhs.str();
    }

    template< class CharT, class Traits, class Alloc >
    bool operator==( const ObservableString<CharT,Traits,Alloc>& lhs,
                    const CharT* rhs )
    {
        return lhs.str() == rhs;
    }

    template< class CharT, class Traits, class Alloc >
    bool operator==( const CharT* lhs,
                    const ObservableString<CharT,Traits,Alloc>& rhs )
    {
        return lhs == rhs.str();
    }

    template< class CharT, class Traits, class Alloc >
    bool operator!=( const ObservableString<CharT,Traits,Alloc>& lhs,
                    const CharT* rhs )
    {
        return lhs.str() != rhs;
    }

    template< class CharT, class Traits, class Alloc >
    bool operator!=( const CharT* lhs,
                    const ObservableString<CharT,Traits,Alloc>& rhs )
    {
        return lhs != rhs.str();
    }

    template< class CharT, class Traits, class Alloc >
    bool operator<( const ObservableString<CharT,Traits,Alloc>& lhs,
                    const CharT* rhs )
    {
        return lhs.str() < rhs;
    }

    template< class CharT, class Traits, class Alloc >
    bool operator<( const CharT* lhs,
                    const ObservableString<CharT,Traits,Alloc>& rhs )
    {
        return lhs < rhs.str();
    }

    template< class CharT, class Traits, class Alloc >
    bool operator<=( const ObservableString<CharT,Traits,Alloc>& lhs,
                    const CharT* rhs )
    {
        return lhs.str() <= rhs;
    }

    template< class CharT, class Traits, class Alloc >
    bool operator<=( const CharT* lhs,
                    const ObservableString<CharT,Traits,Alloc>& rhs )
    {
        return lhs <= rhs.str();
    }

    template< class CharT, class Traits, class Alloc >
    bool operator>( const ObservableString<CharT,Traits,Alloc>& lhs,
                    const CharT* rhs )
    {
        return lhs.str() > rhs;
    }

    template< class CharT, class Traits, class Alloc >
    bool operator>( const CharT* lhs,
                    const ObservableString<CharT,Traits,Alloc>& rhs )
    {
        return lhs > rhs.str();
    }

    template< class CharT, class Traits, class Alloc >
    bool operator>=( const ObservableString<CharT,Traits,Alloc>& lhs,
                    const CharT* rhs )
    {
        return lhs.str() >= rhs;
    }

    template< class CharT, class Traits, class Alloc >
    bool operator>=( const CharT* lhs,
                    const ObservableString<CharT,Traits,Alloc>& rhs )
    {
        return lhs == rhs.str();
    }

    template< class CharT, class Traits, class Alloc >
    void swap(ObservableString<CharT, Traits, Alloc> &lhs,
              std::basic_string<CharT, Traits, Alloc> &rhs ) noexcept(noexcept(lhs.str().swap(rhs)))
    {
        using std::swap;
        return swap(lhs.str(), rhs);
    }

    template< class CharT, class Traits, class Alloc >
    void swap(std::basic_string<CharT, Traits, Alloc> &lhs,
              ObservableString<CharT, Traits, Alloc> &rhs ) noexcept(noexcept(lhs.swap(rhs.str())))
    {
        using std::swap;
        return swap(lhs, rhs.str());
    }

    template< class CharT, class Traits, class Alloc >
    void swap(ObservableString<CharT, Traits, Alloc> &lhs,
              ObservableString<CharT, Traits, Alloc> &rhs ) noexcept(noexcept(lhs.str().swap(rhs.str())))
    {
        using std::swap;
        return swap(lhs.str(), rhs.str());
    }

    template <class CharT, class Traits, class Allocator>
    std::basic_ostream<CharT, Traits>&
        operator<<(std::basic_ostream<CharT, Traits>& os,
                const ObservableString<CharT, Traits, Allocator>& str)
    {
        os << str.str();
        return os;
    }

    template <class CharT, class Traits, class Allocator>
    std::basic_istream<CharT, Traits>&
        operator>>(std::basic_istream<CharT, Traits>& is,
                ObservableString<CharT, Traits, Allocator>& str)
    {
        is >> str.str();
    }

    template< class CharT, class Traits, class Allocator >
    std::basic_istream<CharT,Traits>& getline( std::basic_istream<CharT,Traits>& input,
                                            ObservableString<CharT,Traits,Allocator>& str,
                                            CharT delim )
    {
        return std::getline(input, str.str(), delim);
    }

    template< class CharT, class Traits, class Allocator >
    std::basic_istream<CharT,Traits>& getline( std::basic_istream<CharT,Traits>&& input,
                                            ObservableString<CharT,Traits,Allocator>& str,
                                            CharT delim )
    {
        return std::getline(input, str.str(), delim);
    }

    template< class CharT, class Traits, class Allocator >
    std::basic_istream<CharT,Traits>& getline( std::basic_istream<CharT,Traits>& input,
                                            ObservableString<CharT,Traits,Allocator>& str )
    {
        return std::getline(input, str.str());
    }

    template< class CharT, class Traits, class Allocator >
    std::basic_istream<CharT,Traits>& getline( std::basic_istream<CharT,Traits>&& input,
                                            ObservableString<CharT,Traits,Allocator>& str )
    {
        return std::getline(input, str.str());
    }
}
