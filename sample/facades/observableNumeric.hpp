#pragma once

#include <memory>
#include <vector>
#include <utility>
#include <tuple>
#include "observable.hpp"

namespace og
{
    template<typename T, typename std::enable_if<
        std::is_arithmetic_v<T>, T>::type * = nullptr>
    class ObservableNumeric : public Observable<ObservableNumeric<T>>
    {
    public:
        ObservableNumeric() noexcept
        : _value() { }

        template<typename U, typename std::enable_if_t<
            std::is_convertible_v<U, T>, U> * = nullptr>
        ObservableNumeric(U newValue) noexcept
        : _value(newValue) { }

        template<typename U, typename std::enable_if_t<
            std::is_convertible_v<U, T>, U> * = nullptr>
        ObservableNumeric(ObservableNumeric<U> const & other)
        : Observable<ObservableNumeric<T>>(other), _value(other.value()) { }

        template<typename U, typename std::enable_if_t<
            std::is_convertible_v<U, T>, U> * = nullptr>
        ObservableNumeric(ObservableNumeric<U> && other)
        : Observable<ObservableNumeric<T>>(other), _value(other.value()) { }

        template<typename U, typename std::enable_if_t<
            std::is_arithmetic_v<U>, U> * = nullptr>
        ObservableNumeric<T> & operator =(U const & rhs)
        {
            _value = rhs;
            onChange();
            return * this;
        }

        template<typename U, typename std::enable_if_t<
            std::is_convertible_v<U, T>, U> * = nullptr>
        ObservableNumeric<T> & operator =(ObservableNumeric<U> const & rhs)
        {
            _value = rhs._value;
            onChange();
            return * this;
        }

        template<typename U, typename std::enable_if_t<
            std::is_convertible_v<U, T>, U> * = nullptr>
        ObservableNumeric<T> & operator =(ObservableNumeric<U> && rhs)
        {
            using std::swap;
            swap(_value, rhs._value);
            onChange();
            return * this;
        }

        T value() const noexcept { return _value; }

    private:
        void onChange()
        {
            changed = true;
            Observable<ObservableNumeric<T>>::notifyChange(*this);
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

        template<typename U, typename std::enable_if_t<
            std::is_convertible_v<T, U>, U> * = nullptr>
        operator U() const
        { return static_cast<U>(_value); }

        template<typename U, typename std::enable_if_t<
            std::is_convertible_v<T, U>, U> * = nullptr>
        operator ObservableNumeric<U>() const
        { return static_cast<U>(_value); }

        template<typename U, typename std::enable_if_t<
            std::is_arithmetic_v<U>, U> * = nullptr>
        ObservableNumeric<T> & operator +=(U const & rhs)
        {
            _value += rhs;
            onChange();
            return * this;
        }

        template<typename U, typename std::enable_if_t<
            std::is_arithmetic_v<U>, U> * = nullptr>
        ObservableNumeric<T> & operator +=(ObservableNumeric<U> const & rhs)
        {
            _value += rhs._value;
            onChange();
            return * this;
        }

        template<typename U, typename std::enable_if_t<
            std::is_arithmetic_v<U>, U> * = nullptr>
        ObservableNumeric<T> & operator -=(U const & rhs)
        {
            _value -= rhs;
            onChange();
            return * this;
        }

        template<typename U, typename std::enable_if_t<
            std::is_arithmetic_v<U>, U> * = nullptr>
        ObservableNumeric<T> & operator -=(ObservableNumeric<U> const & rhs)
        {
            _value -= rhs._value;
            onChange();
            return * this;
        }

        template<typename U, typename std::enable_if_t<
            std::is_arithmetic_v<U>, U> * = nullptr>
        ObservableNumeric<T> & operator *=(U const & rhs)
        {
            _value *= rhs;
            onChange();
            return * this;
        }

        template<typename U, typename std::enable_if_t<
            std::is_arithmetic_v<U>, U> * = nullptr>
        ObservableNumeric<T> & operator *=(ObservableNumeric<U> const & rhs)
        {
            _value *= rhs._value;
            onChange();
            return * this;
        }

        template<typename U, typename std::enable_if_t<
            std::is_arithmetic_v<U>, U> * = nullptr>
        ObservableNumeric<T> & operator /=(U const & rhs)
        {
            _value /= rhs;
            onChange();
            return * this;
        }

        template<typename U, typename std::enable_if_t<
            std::is_arithmetic_v<U>, U> * = nullptr>
        ObservableNumeric<T> & operator /=(ObservableNumeric<U> const & rhs)
        {
            _value /= rhs._value;
            onChange();
            return * this;
        }

        template<typename U, typename std::enable_if_t<
            std::is_integral_v<T> && std::is_arithmetic_v<U>, U> * = nullptr>
        ObservableNumeric<T> & operator %=(U const & rhs)
        {
            _value %= rhs;
            onChange();
            return * this;
        }

        template<typename U, typename std::enable_if_t<
            std::is_integral_v<T> && std::is_arithmetic_v<U>, U> * = nullptr>
        ObservableNumeric<T> & operator %=(ObservableNumeric<U> const & rhs)
        {
            _value %= rhs._value;
            onChange();
            return * this;
        }

        template<typename U, typename std::enable_if_t<
            std::is_integral_v<T> && std::is_arithmetic_v<U>, U> * = nullptr>
        ObservableNumeric<T> & operator ^=(U const & rhs)
        {
            _value ^= rhs;
            onChange();
            return * this;
        }

        template<typename U, typename std::enable_if_t<
            std::is_integral_v<T> && std::is_arithmetic_v<U>, U> * = nullptr>
        ObservableNumeric<T> & operator ^=(ObservableNumeric<U> const & rhs)
        {
            _value ^= rhs._value;
            onChange();
            return * this;
        }

        template<typename U, typename std::enable_if_t<
            std::is_integral_v<T> && std::is_arithmetic_v<U>, U> * = nullptr>
        ObservableNumeric<T> & operator &=(U const & rhs)
        {
            _value &= rhs;
            onChange();
            return * this;
        }

        template<typename U, typename std::enable_if_t<
            std::is_integral_v<T> && std::is_arithmetic_v<U>, U> * = nullptr>
        ObservableNumeric<T> & operator &=(ObservableNumeric<U> const & rhs)
        {
            _value &= rhs._value;
            onChange();
            return * this;
        }

        template<typename U, typename std::enable_if_t<
            std::is_integral_v<T> && std::is_arithmetic_v<U>, U> * = nullptr>
        ObservableNumeric<T> & operator |=(U const & rhs)
        {
            _value |= rhs;
            onChange();
            return * this;
        }

        template<typename U, typename std::enable_if_t<
            std::is_integral_v<T> && std::is_arithmetic_v<U>, U> * = nullptr>
        ObservableNumeric<T> & operator |=(ObservableNumeric<U> const & rhs)
        {
            _value |= rhs._value;
            onChange();
            return * this;
        }

        template<typename U, typename std::enable_if_t<
            std::is_integral_v<T> && std::is_arithmetic_v<U>, U> * = nullptr>
        ObservableNumeric<T> & operator >>=(U const & rhs)
        {
            _value >>= rhs;
            onChange();
            return * this;
        }

        template<typename U, typename std::enable_if_t<
            std::is_integral_v<T> && std::is_arithmetic_v<U>, U> * = nullptr>
        ObservableNumeric<T> & operator >>=(ObservableNumeric<U> const & rhs)
        {
            _value >>= rhs._value;
            onChange();
            return * this;
        }

        template<typename U, typename std::enable_if_t<
            std::is_integral_v<T> && std::is_arithmetic_v<U>, U> * = nullptr>
        ObservableNumeric<T> & operator <<=(U const & rhs)
        {
            _value <<= rhs;
            onChange();
            return * this;
        }

        template<typename U, typename std::enable_if_t<
            std::is_integral_v<T> && std::is_arithmetic_v<U>, U> * = nullptr>
        ObservableNumeric<T> & operator <<=(ObservableNumeric<U> const & rhs)
        {
            _value <<= rhs._value;
            onChange();
            return * this;
        }

        ObservableNumeric<T> & operator ++()
        {
            _value += 1;
            onChange();
            return * this;
        }

        T operator ++(int)
        {
            T temp(* this);
            operator++();
            onChange();
            return temp;
        }

        ObservableNumeric<T> & operator --()
        {
            _value -= 1;
            onChange();
            return * this;
        }

        T operator --(int)
        {
            T temp(* this);
            operator--();
            onChange();
            return temp;
        }

    private:
        T _value;
        bool changed = false;
    };


        /*
+a
-a
a + b
a - b
a * b
a / b
a % b
~a
a & b
a | b
a ^ b
a << b
a >> b
        */

    template<typename T, 
        typename std::enable_if_t<std::is_arithmetic_v<T>, T> * = nullptr>
    T operator +(ObservableNumeric<T> const & lhs)
    {
        return static_cast<T>(lhs);
    }

    template<typename T, 
        typename std::enable_if_t<std::is_arithmetic_v<T>, T> * = nullptr>
    T operator -(ObservableNumeric<T> const & lhs)
    {
        return - static_cast<T>(lhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    T operator +(ObservableNumeric<T> const & lhs, U const & rhs)
    {
        return static_cast<T>(lhs) + rhs;
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    T operator +(T const & lhs, ObservableNumeric<U> const & rhs)
    {
        return lhs + static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    T operator +(ObservableNumeric<T> const & lhs, ObservableNumeric<U> const & rhs)
    {
        return static_cast<T>(lhs) + static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    T operator -(ObservableNumeric<T> const & lhs, U const & rhs)
    {
        return static_cast<T>(lhs) - rhs;
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    T operator -(T const & lhs, ObservableNumeric<U> const & rhs)
    {
        return lhs - static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    T operator -(ObservableNumeric<T> const & lhs, ObservableNumeric<U> const & rhs)
    {
        return static_cast<T>(lhs) - static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    T operator *(ObservableNumeric<T> const & lhs, U const & rhs)
    {
        return static_cast<T>(lhs) * rhs;
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    T operator *(T const & lhs, ObservableNumeric<U> const & rhs)
    {
        return lhs * static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    T operator *(ObservableNumeric<T> const & lhs, ObservableNumeric<U> const & rhs)
    {
        return static_cast<T>(lhs) * static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    T operator /(ObservableNumeric<T> const & lhs, U const & rhs)
    {
        return static_cast<T>(lhs) / rhs;
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    T operator /(T const & lhs, ObservableNumeric<U> const & rhs)
    {
        return lhs / static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    T operator /(ObservableNumeric<T> const & lhs, ObservableNumeric<U> const & rhs)
    {
        return static_cast<T>(lhs) / static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    T operator %(ObservableNumeric<T> const & lhs, U const & rhs)
    {
        return static_cast<T>(lhs) % rhs;
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    T operator %(T const & lhs, ObservableNumeric<U> const & rhs)
    {
        return lhs % static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    T operator %(ObservableNumeric<T> const & lhs, ObservableNumeric<U> const & rhs)
    {
        return static_cast<T>(lhs) % static_cast<U>(rhs);
    }

    template<typename T, 
        typename std::enable_if_t<std::is_integral_v<T>, T> * = nullptr>
    T operator ~(ObservableNumeric<T> const & lhs)
    {
        return ~ static_cast<T>(lhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_integral_v<T> && std::is_integral_v<U>, T> * = nullptr>
    T operator &(ObservableNumeric<T> const & lhs, U const & rhs)
    {
        return static_cast<T>(lhs) & rhs;
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_integral_v<T> && std::is_integral_v<U>, T> * = nullptr>
    T operator &(T const & lhs, ObservableNumeric<U> const & rhs)
    {
        return lhs & static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_integral_v<T> && std::is_integral_v<U>, T> * = nullptr>
    T operator &(ObservableNumeric<T> const & lhs, ObservableNumeric<U> const & rhs)
    {
        return static_cast<T>(lhs) & static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_integral_v<T> && std::is_integral_v<U>, T> * = nullptr>
    T operator |(ObservableNumeric<T> const & lhs, U const & rhs)
    {
        return static_cast<T>(lhs) | rhs;
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_integral_v<T> && std::is_integral_v<U>, T> * = nullptr>
    T operator |(T const & lhs, ObservableNumeric<U> const & rhs)
    {
        return lhs | static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_integral_v<T> && std::is_integral_v<U>, T> * = nullptr>
    T operator |(ObservableNumeric<T> const & lhs, ObservableNumeric<U> const & rhs)
    {
        return static_cast<T>(lhs) | static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_integral_v<T> && std::is_integral_v<U>, T> * = nullptr>
    T operator ^(ObservableNumeric<T> const & lhs, U const & rhs)
    {
        return static_cast<T>(lhs) ^ rhs;
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_integral_v<T> && std::is_integral_v<U>, T> * = nullptr>
    T operator ^(T const & lhs, ObservableNumeric<U> const & rhs)
    {
        return lhs ^ static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_integral_v<T> && std::is_integral_v<U>, T> * = nullptr>
    T operator ^(ObservableNumeric<T> const & lhs, ObservableNumeric<U> const & rhs)
    {
        return static_cast<T>(lhs) ^ static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_integral_v<T> && std::is_integral_v<U>, T> * = nullptr>
    T operator <<(ObservableNumeric<T> const & lhs, U const & rhs)
    {
        return static_cast<T>(lhs) << rhs;
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_integral_v<T> && std::is_integral_v<U>, T> * = nullptr>
    T operator <<(T const & lhs, ObservableNumeric<U> const & rhs)
    {
        return lhs << static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_integral_v<T> && std::is_integral_v<U>, T> * = nullptr>
    T operator <<(ObservableNumeric<T> const & lhs, ObservableNumeric<U> const & rhs)
    {
        return static_cast<T>(lhs) << static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_integral_v<T> && std::is_integral_v<U>, T> * = nullptr>
    T operator >>(ObservableNumeric<T> const & lhs, U const & rhs)
    {
        return static_cast<T>(lhs) >> rhs;
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_integral_v<T> && std::is_integral_v<U>, T> * = nullptr>
    T operator >>(T const & lhs, ObservableNumeric<U> const & rhs)
    {
        return lhs >> static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_integral_v<T> && std::is_integral_v<U>, T> * = nullptr>
    T operator >>(ObservableNumeric<T> const & lhs, ObservableNumeric<U> const & rhs)
    {
        return static_cast<T>(lhs) >> static_cast<U>(rhs);
    }

/*
    !a
    a && b
    a || b
*/
    template<typename T, 
        typename std::enable_if_t<std::is_arithmetic_v<T>, T> * = nullptr>
    bool operator !(ObservableNumeric<T> const & lhs)
    {
        return ! static_cast<T>(lhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    bool operator &&(ObservableNumeric<T> const & lhs, U const & rhs)
    {
        return static_cast<T>(lhs) && rhs;
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    bool operator &&(T const & lhs, ObservableNumeric<U> const & rhs)
    {
        return lhs && static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    T operator &&(ObservableNumeric<T> const & lhs, ObservableNumeric<U> const & rhs)
    {
        return static_cast<T>(lhs) && static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    bool operator ||(ObservableNumeric<T> const & lhs, U const & rhs)
    {
        return static_cast<T>(lhs) || rhs;
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    bool operator ||(T const & lhs, ObservableNumeric<U> const & rhs)
    {
        return lhs || static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    T operator ||(ObservableNumeric<T> const & lhs, ObservableNumeric<U> const & rhs)
    {
        return static_cast<T>(lhs) || static_cast<U>(rhs);
    }

    /*
    a == b
    a != b
    a < b
    a > b
    a <= b
    a >= b
    */

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    bool operator ==(ObservableNumeric<T> const & lhs, U const & rhs)
    {
        return static_cast<T>(lhs) == rhs;
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    bool operator ==(T const & lhs, ObservableNumeric<U> const & rhs)
    {
        return lhs == static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    bool operator ==(ObservableNumeric<T> const & lhs, ObservableNumeric<U> const & rhs)
    {
        return static_cast<T>(lhs) == static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    bool operator !=(ObservableNumeric<T> const & lhs, U const & rhs)
    {
        return static_cast<T>(lhs) != rhs;
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    bool operator !=(T const & lhs, ObservableNumeric<U> const & rhs)
    {
        return lhs != static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    bool operator !=(ObservableNumeric<T> const & lhs, ObservableNumeric<U> const & rhs)
    {
        return static_cast<T>(lhs) != static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    bool operator <(ObservableNumeric<T> const & lhs, U const & rhs)
    {
        return static_cast<T>(lhs) < rhs;
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    bool operator <(T const & lhs, ObservableNumeric<U> const & rhs)
    {
        return lhs < static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    bool operator <(ObservableNumeric<T> const & lhs, ObservableNumeric<U> const & rhs)
    {
        return static_cast<T>(lhs) < static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    bool operator >(ObservableNumeric<T> const & lhs, U const & rhs)
    {
        return static_cast<T>(lhs) > rhs;
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    bool operator >(T const & lhs, ObservableNumeric<U> const & rhs)
    {
        return lhs > static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    bool operator >(ObservableNumeric<T> const & lhs, ObservableNumeric<U> const & rhs)
    {
        return static_cast<T>(lhs) > static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    bool operator <=(ObservableNumeric<T> const & lhs, U const & rhs)
    {
        return static_cast<T>(lhs) <= rhs;
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    bool operator <=(T const & lhs, ObservableNumeric<U> const & rhs)
    {
        return lhs <= static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    bool operator <=(ObservableNumeric<T> const & lhs, ObservableNumeric<U> const & rhs)
    {
        return static_cast<T>(lhs) <= static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    bool operator >=(ObservableNumeric<T> const & lhs, U const & rhs)
    {
        return static_cast<T>(lhs) >= rhs;
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    bool operator >=(T const & lhs, ObservableNumeric<U> const & rhs)
    {
        return lhs >= static_cast<U>(rhs);
    }

    template<typename T, typename U, 
        typename std::enable_if_t<
            std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, T> * = nullptr>
    bool operator >=(ObservableNumeric<T> const & lhs, ObservableNumeric<U> const & rhs)
    {
        return static_cast<T>(lhs) >= static_cast<U>(rhs);
    }

    template<typename T, typename std::enable_if_t<std::is_arithmetic_v<T>, T> * = nullptr>
    std::ostream & operator <<(std::ostream & out, ObservableNumeric<T> const & arg)
    {
        out << static_cast<T>(arg);
        return out;
    }

    template<typename T, typename std::enable_if_t<std::is_arithmetic_v<T>, T> * = nullptr>
    std::ostream & operator >>(std::ostream & out, ObservableNumeric<T> const & arg)
    {
        T narg;
        out >> narg;
        arg = narg;
        return out;
    }
}
