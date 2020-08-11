/*  Define sum, product, and difference in the fun namespace    */
#include "fun.h"
//#define TESTFUNCTION

#ifdef TESTFUNCTION
    #include <iostream>
#endif

int fun::sum(int a, int b)
{
#ifdef TESTFUNCTION
    std::cout << "Function sum called.\n";
#endif
    return a + b;
}

int fun::product(int a, int b)
{
#ifdef TESTFUNCTION
    std::cout << "Function product called.\n";
#endif
    return a * b;
}

int fun::difference(int a, int b)
{
#ifdef TESTFUNCTION
    std::cout << "Function difference called.\n";
#endif
    return a - b;
}