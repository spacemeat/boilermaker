#pragma once

#include <memory>
#include <map>
#include <utility>
#include <tuple>
#include "observable.hpp"

namespace og
{
    template<typename Key, typename T, 
             typename Compare = std::less<Key>,
             typename Allocator = std::allocator<std::pair<Key const, T>>>
    class ObservableMap : public Observable<ObservableMap<Key, V, Compare, Allocator>>
    {
    public:
        enum class ChangeType
        {
            ElementChanged,
            ElementAdded,
            ElementRemoved,
            ElementsReplaced
        };

        using map_t                     = std::map<Key, V, Compare, Allocator>;
        using obmap_t                   = ObservableMap<Key, V, Compare, Allocator>;
        using key_type                  = typename map_t::key_type;
        using mapped_type               = typename map_t::mapped_type;
        using value_type 	            = typename map_t::value_type;
        using size_type 	            = typename map_t::size_type;
        using difference_type 	        = typename map_t::difference_type;
        using key_compare               = typename map_t::key_compare;
        using allocator_type 	        = typename map_t::allocator_type;
        using reference                 = typename map_t::reference;
        using const_reference 	        = typename map_t::const_reference;
        using pointer 	                = typename map_t::pointer;
        using const_pointer 	        = typename map_t::const_pointer;
        using iterator 	                = typename map_t::iterator;
        using const_iterator 	        = typename map_t::const_iterator;
        using reverse_iterator 	        = typename map_t::reverse_iterator;
        using const_reverse_iterator 	= typename map_t::const_reverse_iterator;
        using node_type                 = typename map_t::node_type;
        using insert_return_type        = typename map_t::insert_return_type;

        using NotifyFn                  = typename Observable<obmap_t>::NotifyFn;
        using ChangeLogEntry            = std::tuple<ChangeType, Key>;

        ObservableMap() noexcept(noexcept(Allocator()))
        : Observable<obmap_t>(), map_() { }

        ObservableMap(std::initializer_list<value_type> init,
                      Compare const & comp = Compare(),
                      Allocator const & alloc = Allocator() )
        : Observable<obmap_t>(), map_(init, comp, alloc) { observeElements(); }

        ObservableMap(std::initializer_list<value_type> init,
                      Allocator const & alloc = Allocator() )
        : Observable<obmap_t>(), map_(init, alloc) { observeElements(); }

        ObservableMap(obmap_t const & rhs)
        : Observable<obmap_t>(), map_(rhs) { observeElements(); }

        ObservableMap(obmap_t && rhs)
        : Observable<obmap_t>(), map_(std::move(rhs)) { observeElements(); }

    private:
        void onChange(ChangeType changeType, key_type key)
        {
            // record the change
            changeLog.emplace_back(changeType, key);

            // essentially reindex the change notifier for new or moved elements
            // TODO: This is for observeChildDiffs only
            observeElements(key);

            // let any observers of this vector know that the vector has changes
            Observable<obvec_t>::notifyChange(*this);
        }

        // TODO: This is for observeChildDiffs only
        void observeElements(key_type const & key)
        {
            if constexpr (std::is_base_of_v<Observable<Key>, Key>)
            {
                auto & kvp = map_[key];
                std::cout << "observeElements key: " << kvp.first << "\n";
                kvp.second.setNotifyFn([this, kvp.first](value_type &){ this->onChange(ChangeType::ElementChanged, key); });
            }
            else
            {
                (void)(startingAt);
                (void)(num);
            }
        }

        void observeElements()
        {
            if constexpr (std::is_base_of_v<Observable<Key>, Key>)
            {
                for (auto & kvp : map_)
                {
                    std::cout << "observeElements key: " << kvp.first << "\n";
                    kvp.second.setNotifyFn([this, kvp.first](value_type &){ this->onChange(ChangeType::ElementChanged, key); });
                }
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
            if constexpr (std::is_base_of_v<Observable<T>, T>)
            {
                for (auto & elem : map_)
                {
                    elem.second.forgetChanges();
                }
            }
        }

        obmap_t & operator =(obmap_t const & rhs)
        {
            if (& rhs != this)
            {
                map_ = rhs.map_;
                onChange(ChangeType::ElementsReplaced, {});
            }
            return * this;
        }

        obmap_t & operator =(map_t const & rhs)
        {
            if (& rhs != & map_)
            {
                map_ = rhs;
                onChange(ChangeType::ElementsReplaced, {});
            }
            return * this;
        }

        obmap_t & operator =(obmap_t && rhs)
        {
            if (& rhs != this)
            {
                using std::swap;
                map_ = swap(map_, rhs.map_);
                onChange(ChangeType::ElementsReplaced, {});
            }
            return * this;
        }

        obmap_t & operator =(map_t && rhs)
        {
            if (& rhs != this)
            {
                using std::swap;
                map_ = swap(map_, rhs);
                onChange(ChangeType::ElementsReplaced, {});
            }
            return * this;
        }

        allocator_type get_allocator() const noexcept
        {
            return map_.get_allocator();
        }

        T& at( const Key& key )
        {
            return map_.at(key);
        }

        const T& at( const Key& key ) const
        {
            return map_.at(key);
        }

        T& operator[]( const Key& key )
        {
            return map[key];
        }

        T& operator[]( Key && key )
        {
            return map[key];
        }

        iterator begin() noexcept
        {
            return map_.begin();
        }

        const_iterator begin() const noexcept
        {
            return map_.begin();
        }

        const_iterator cbegin() const noexcept
        {
            return map_.cbegin();
        }

        iterator end() noexcept
        {
            return map_.end();
        }

        const_iterator end() const noexcept
        {
            return map_.end();
        }

        const_iterator cend() const noexcept
        {
            return map_.cend();
        }

        reverse_iterator rbegin() noexcept
        {
            return map_.rbegin();
        }

        const_reverse_iterator rbegin() const noexcept
        {
            return map_.rbegin();
        }

        const_reverse_iterator crbegin() const noexcept
        {
            return map_.crbegin();
        }

        reverse_iterator rend() noexcept
        {
            return map_.rend();
        }

        const_reverse_iterator rend() const noexcept
        {
            return map_.rend();
        }

        const_reverse_iterator crend() const noexcept
        {
            return map_.crend();
        }

        bool empty() const noexcept
        {
            return map_.empty();
        }

        size_type size() const noexcept
        {
            return map_.size();
        }

        size_type max_size() const noexcept
        {
            return map_.max_size();
        }

        void clear() noexcept
        {
            map_.clear();
            onChange(ChangeType::ElementsReplaced, {});
        }

        std::pair<iterator,bool> insert( const value_type& value )
        {
            map_.insert(value);
            onChange(ChangeType::ElementAdded, value.first);
        }

        template< class P >
        std::pair<iterator,bool> insert( P&& value )
        {
            map_.insert(value);
            onChange(ChangeType::ElementAdded, value.first);
        }

        std::pair<iterator,bool> insert( value_type&& value )
        {
            map_.insert(value);
            onChange(ChangeType::ElementAdded, value.first);
        }

        iterator insert( const_iterator hint, const value_type& value )
        {
            map_.insert(hint, value);
            onChange(ChangeType::ElementAdded, value.first);
        }

        template< class P >
        iterator insert( const_iterator hint, P&& value )
        {
            map_.insert(hint, value);
            onChange(ChangeType::ElementAdded, value.first);
        }

        iterator insert( const_iterator hint, value_type&& value )
        {
            map_.insert(hint, value);
            onChange(ChangeType::ElementAdded, value.first);
        }

        template< class InputIt >
        void insert( InputIt first, InputIt last )
        {
            for (auto it = first; it != last; ++it)
            {
                map_.insert(* it);
                onChange(ChangeType::ElementAdded, it->first);
            }
        }

        void insert( std::initializer_list<value_type> ilist )
        {
            for (auto & elem : ilist)
            {
                map_.insert(elem);
                onChange(ChangeType::ElementAdded, elem.first);
            }
        }

        insert_return_type insert(node_type&& nh)
        {
            map_.insert(nh);
            onChange(ChangeType::ElementAdded, nh.key());
        }

        iterator insert(const_iterator hint, node_type&& nh)
        {
            map_.insert(hint, nh);
            onChange(ChangeType::ElementAdded, nh.key());
        }

        template <class M>
        pair<iterator, bool> insert_or_assign(const key_type& k, M&& obj)
        {
            
        }
        
        template <class M>
        pair<iterator, bool> insert_or_assign(key_type&& k, M&& obj)
        {
            
        }
        
        template <class M>
        iterator insert_or_assign(const_iterator hint, const key_type& k, M&& obj)
        {
            
        }
        
        template <class M>
        iterator insert_or_assign(const_iterator hint, key_type&& k, M&& obj)
        {
            
        }

        template< class... Args >
        std::pair<iterator,bool> emplace( Args&&... args )
        {
            
        }

        template <class... Args>
        iterator emplace_hint( const_iterator hint, Args&&... args )
        {
            
        }

        template <class... Args>
        pair<iterator, bool> try_emplace(const key_type& k, Args&&... args)
        {
            
        }

        template <class... Args>
        pair<iterator, bool> try_emplace(key_type&& k, Args&&... args)
        {
            
        }

        template <class... Args>
        iterator try_emplace(const_iterator hint, const key_type& k, Args&&... args)
        {
            
        }

        template <class... Args>
        iterator try_emplace(const_iterator hint, key_type&& k, Args&&... args)
        {
            
        }

        iterator erase( const_iterator pos )
        {
            
        }
        
        iterator erase( iterator pos )
        {
            
        }

        iterator erase( const_iterator first, const_iterator last )
        {
            
        }

        size_type erase( const key_type& key )
        {
            
        }

        void swap( map& other ) noexcept(
               std::allocator_traits<Allocator>::is_always_equal::value
            && std::is_nothrow_swappable<Compare>::value)
        {
            
        }

        node_type extract( const_iterator position )
        {
            
        }

        node_type extract( const key_type& x )
        {
            
        }

        template<class C2>
        void merge( std::map<Key, T, C2, Allocator>& source )
        {
            
        }

        template<class C2>
        void merge( std::map<Key, T, C2, Allocator>&& source )
        {
            
        }

        template<class C2>
        void merge( std::multimap<Key, T, C2, Allocator>& source )
        {
            
        }

        template<class C2>
        void merge( std::multimap<Key, T, C2, Allocator>&& source )
        {
            
        }

        size_type count( const Key& key ) const
        {
            
        }

        template< class K >
        size_type count( const K& x ) const
        {
            
        }

        iterator find( const Key& key )
        {
            
        }

        const_iterator find( const Key& key ) const
        {
            
        }
        
        template< class K >
        iterator find( const K& x )
        {
            
        }
        
        template< class K >
        const_iterator find( const K& x ) const
        {
            
        }

        std::pair<iterator,iterator> equal_range( const Key& key )
        {
            
        }

        std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
        {
            
        }

        template< class K >
        std::pair<iterator,iterator> equal_range( const K& x )
        {
            
        }

        template< class K >
        std::pair<const_iterator,const_iterator> equal_range( const K& x ) const
        {
            
        }

        iterator lower_bound( const Key& key )
        {
            
        }

        const_iterator lower_bound( const Key& key ) const
        {
            
        }

        template< class K >
        iterator lower_bound(const K& x)
        {
            
        }

        template< class K >
        const_iterator lower_bound(const K& x) const
        {
            
        }

        iterator upper_bound( const Key& key )
        {
            
        }

        const_iterator upper_bound( const Key& key ) const
        {
            
        }

        template< class K >
        iterator upper_bound( const K& x )
        {
            
        }

        template< class K >
        const_iterator upper_bound( const K& x ) const
        {
            
        }

        key_compare key_comp() const
        {
            
        }
	
        std::map::value_compare value_comp() const
        {
            
        }
	
    private:
        std::map<Key, V, Compare, Allocator> map_;
        std::vector<ChangeLogEntry> changeLog;
    };
}
