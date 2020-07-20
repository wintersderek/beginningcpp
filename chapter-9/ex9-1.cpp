/*
Exercise 9-1: write a template for clamp(a, b, c).
    - If a is less than b, return b.
    - If a is greater than c, return c.
    - If a is between b and c, return a
*/
#include <iostream>

template <typename T>
const T& clamp(const T& a, const T& b, const T& c);

int main ()
{
    std::cout << "Clamp (5, 6, 7):\t" << clamp(5, 6, 7) << "\n";
    std::cout << "Clamp (7.4, 6.2, 7.39):\t" << clamp(7.4, 6.2, 7.39) << "\n";
    std::cout << "Clamp ('M', 'A', 'Z'):\t" << clamp('M', 'A', 'Z') << "\n";

    std::cout << std::endl;
    return 0;
}

template <typename T>
const T& clamp(const T& a, const T& b, const T& c)
{
    return a < b ? b : a > c ? c : a;
}