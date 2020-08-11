/*
Exercise 8: use preprocessing directives to debug a file
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "fun.h"

// Generate a random integer 0 to count -1
size_t local_random(const size_t count)
{
    return static_cast<size_t>(std::rand() / (RAND_MAX / count + 1));
}

int main()
{
#ifdef DEREK
    std::cout << "Derek is defined";
#endif

    const int a {10}, b{5};
    int result;

    const size_t num_functions {3};
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    for (size_t i {}; i < 5; i++)
    {
        size_t select = local_random(num_functions);

#ifndef TESTFUNCTIONS
        std::cout << "Random number = " << select << ' ';
        if (select >= num_functions)
        {
            std::cout << "Invalid random number generated!" << std::endl;
            return 1;
        }
#endif

        switch (select)
        {
        case 0:
            result = fun::sum(a, b);
            break;
        case 1:
            result = fun::product(a, b);
            break;
        case 2:
            result = fun::difference(a, b);
            break;
        default:
            break;
        }
        std::cout << "result = " << result << "\n";
    }
    
    std::cout << std::endl;
    return 0;
}