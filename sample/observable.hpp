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

        Observable(Observable<T> const & rhs)
        : notify(rhs.notify)
        { }

        Observable(Observable<T> && rhs) noexcept
        : notify(std::move(rhs.notify))
        { }

        Observable<T> & operator =(Observable<T> const & rhs)
        {
            notify = rhs.notify;
        }

        Observable<T> & operator =(Observable<T> && rhs)
        {
            using std::swap;
            swap(notify, rhs.notify);
        }

    private:
        NotifyFn notify = nullptr;
    };
}
