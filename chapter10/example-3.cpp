#include <iostream>
#include <iomanip>
#include <string>
#include "power.hpp"

int main (int argc, char* argv[])
{
    double number {std::stod(argv[1])};
    int exponent {std::stoi(argv[2])};

    for (int i {-exponent}; i <= exponent; i++)
    {
        std::cout << std::setw(15) << power(number, i);

        if (i % 4 == 0)
        {
            std::cout << "\n";
        }
    }
    std::cout << std::endl;    
}