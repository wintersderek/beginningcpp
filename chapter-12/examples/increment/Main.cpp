/*
Test program for increment operator as a member
*/
#include <iostream>
#include <iomanip>
#include "Angle.h"

int main()
{
    Angle a {5};
    unsigned line_max {20};
    for (size_t i {0}; i < 360; )
    {
        std::cout << std::setw(4) << ++a;

        if (++i % line_max == 0)
        {
            std::cout << '\n';
        }
    }

    std::cout << '\n';

    for (size_t i{0}; i < 360;)
    {
        std::cout << std::setw(4) << --a;

        if (++i % line_max == 0)
        {
            std::cout << '\n';
        }
    }
    std::cout << '\n';

    Angle b{5};
    for (size_t i{0}; i < 360;)
    {
        std::cout << std::setw(4) << b++;

        if (++i % line_max == 0)
        {
            std::cout << '\n';
        }
    }
    std::cout << '\n';

    for (size_t i{0}; i < 360;)
    {
        std::cout << std::setw(4) << a--;

        if (++i % line_max == 0)
        {
            std::cout << '\n';
        }
    }
    return 0;
}