#pragma once

#include <functional>
#include <utility>

namespace og
{
    class Observable
    {
    public:
        using NotifyFn = std::function<void()>;

        void setNotifyFn(NotifyFn && fn)
        {
            notify = fn;
        }

        void notifyChange() const
        {
            if (notify != nullptr)
                { notify(); }
        }

    private:
        NotifyFn notify = nullptr;
    };
}
