#include <iomanip>
#include <iostream>
#include "Rational.h"

int main(int argc, char* argv[])
{
    if (argc == 3)
    {
        Rational one{std::stol(argv[1]), std::stol(argv[2])};
        float fValue{static_cast<float>(one)};
        double dValue {static_cast<double>(one)};

        std::cout << std::setprecision(5) << one << " is float(" << fValue 
                  << ") and double(" << dValue << ')';
    }
    else
    {
        std::cout << "Usage: test.exe <number> <number>";
    }
    
    std::cout << std::endl;

    return EXIT_SUCCESS;
}