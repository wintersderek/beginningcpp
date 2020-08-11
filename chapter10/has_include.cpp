/*
    Showcase the C++17 macro __has_include()
*/
#include <iostream>
#include <vector>

int main()
{
#if __has_include(<vector>)
    std::cout << "<vector> is included in the compiler." << "\n";
#endif

#if __has_include("compare.h")
    std::cout << "compare.h is accessible by the compiler.\n";
#endif

#if __has_include("invalid.h")
    std::cout << "invalid.h is accessible by the compiler.\n";
#else
    #error("invalid.h is needed to compile.")
#endif

    std::cout << std::endl;
    return 0;
}