#include <algorithm>
#include <iomanip>
#include <iostream>
#include <random>
#include "DoubleArrayRAII.h"

int getRandomInt(int lower, int upper);

int main (int argc, char* argv[])
{
    size_t entries {};
    std::cout << "Enter the size of the array: ";
    std::cin >> entries;

    DoubleArrayRAII doubles {entries};
    doubles.fill();

    for (size_t i {}; i < 1000; )
    {
        int testIndex {getRandomInt(0, entries)};
        std::cout << std::setw(5) << testIndex;

        try
        {
            double entry {doubles[testIndex]};
        }
        catch(const std::exception& e)
        {
            std::cerr << '\n' << e.what() << '\n';
        }
        
        //double entry {doubles[testIndex]};
        
        if (++i % 15 == 0)
            std::cout << '\n';
    }

    std::cout << std::endl;
    return EXIT_SUCCESS;
}

int getRandomInt(int lower, int upper)
{
    static int lower_bound {std::min<int>({lower, upper})};
    static int upper_bound {std::max<int>({lower, upper})};
    static std::random_device rd;
    static std::mt19937_64 mt {rd()};
    static std::uniform_int_distribution<int> dist{lower_bound, upper_bound};

    return dist(mt);
}