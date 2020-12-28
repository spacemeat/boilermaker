#pragma once

#include <functional>
#include <utility>

namespace og
{
    template<class T>
    class Observable
    {
    public:
        using NotifyFn = std::function<void(T &)>;

        void setNotifyFn(NotifyFn && fn)
        {
            notify = fn;
        }

        void notifyChange(T & t) const
        {
            if (notify != nullptr)
                { notify(t); }
        }

        Observable()
        : notify()
        { }

        template<class U>
        Observable(Observable<U> const &)
        : notify() // notify(rhs.notify)
        { } // we specifically do not want to copy notifiers

        template<class U>
        Observable(Observable<U> &&) noexcept
        : notify() // notify(std::move(rhs.notify))
        { } // we specifically do not want to move notifiers

        template<class U>
        Observable<T> & operator =(Observable<U> const &)
        {
            // we specifically do not want to copy notifiers
            return * this;
        }

        template<class U>
        Observable<T> & operator =(Observable<U> &&)
        {
            // we specifically do not want to move notifiers
            return * this;
        }

    private:
        NotifyFn notify = nullptr;
    };
}
