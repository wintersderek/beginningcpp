#include <iomanip>
#include <iostream>
#include "RandomGenerator.h"

int main (int argc, char* argv[])
{
    RandomGenerator rd {RandomGenerator::getGenerator(1.0, 100.0)};

    for (size_t i {0}; i < 100; ++i)
    {
        std::cout << std::setw(10) << rd.getNext();

        if ((i + 1) % 10 == 0)
        {
            std::cout << '\n';
        }
    }

    std::cout << std::endl;
    return EXIT_SUCCESS;
}