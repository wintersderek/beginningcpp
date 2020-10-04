/*
Demonstrate overloading type conversion.
    - Show boolean conversion for a type to be used in logical expressions.
*/

#include <iostream>
#include "Box.h"

int main ()
{
    Box not_empty {7, 7, 7};
    Box empty {0, 0, 0};

    if (not_empty)
    {
        std::cout << "not_empty says TRUE!\n";
    }
    else
    {
        std::cout << "not_empty says FALSE\n";
    }

    if (!not_empty)
    {
        std::cout << "!not_empty says TRUE!\n";
    }
    else
    {
        std::cout << "!not_empty says FALSE!\n";
    }

    if (empty)
    {
        std::cout << "empty says TRUE!\n";
    }
    else
    {
        std::cout << "empty says FALSE\n";
    }
    if (!empty)
    {
        std::cout << "!empty says TRUE!\n";
    }
    else
    {
        std::cout << "!empty says FALSE!\n";
    }

    return EXIT_SUCCESS;
}