/*
Demonstrate the ability of lambdas to access variables in their definition
scope.
*/

#include <iostream>

int main(int argc, const char* argv[])
{
    int five {5};

    auto plus_five {[=](int x){ /*five += x;*/ return x + five; }};

    for(size_t i {}; i < 10; ++i)
    {
        std::cout << i << " + 5 = " << plus_five(i) << '\n';
    }

    std::cout << std::endl;
    return EXIT_SUCCESS;
}