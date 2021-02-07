#ifndef NEAR_H
#define NEAR_H

#include <cmath>
#include <type_traits>

template <typename T>
class Near
{
    // Only number types can use this template currently
    static_assert(std::is_arithmetic_v<T>, 
                  "Nearer currently only supports arithmetic types");

private:
    T target {};
public:
    Near(T value) : target{value} {};
    
    bool operator()(const T& a, const T& b) const;
};

template <typename T>
bool Near<T>::operator()(const T& a, const T& b) const
{
    if (std::abs(a - target) < std::abs(b - target))
    {
        return true;
    }
    else
    {
        return false;
    }    
}

#endif