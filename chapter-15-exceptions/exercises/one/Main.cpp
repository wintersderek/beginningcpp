#include <iomanip>
#include <iostream>
#include <random>
#include "CurveBall.h"

unsigned int getRandom();

int main(int argc, char* argv[])
{
    unsigned int count;

    for (size_t i {0}; i < 1000; ++i)
    {
        try
        {
            if (getRandom() < 25)
                throw CurveBall {};
        }
        catch(const std::exception& e)
        {
            ++count;
        }
    }
    std::cout << "Final count: " << count << std::endl;
    return EXIT_SUCCESS;
}

unsigned int getRandom()
{
    static std::random_device rd;
    static std::mt19937_64 mt{rd()};
    static std::uniform_int_distribution<int> dist {0,100};

    return dist(mt);
}