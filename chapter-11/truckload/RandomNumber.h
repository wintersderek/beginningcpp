#ifndef HDI_RANDOM
#define HDI_RANDOM

#include <random>

class RandomNumber
{
private:
    std::mt19937 generator;
    std::uniform_int_distribution<int> dist;
public:
    RandomNumber(int min, int max)
    {
        std::random_device rd;
        generator = std::mt19937(rd());
        dist = std::uniform_int_distribution<int>(min, max);
    }

    // Get the next number
    int getNext() { return dist(generator); }
};
#endif