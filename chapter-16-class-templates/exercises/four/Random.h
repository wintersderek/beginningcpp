#ifndef RANDOM_H
#define RANDOM_H

#include <random>

class RandomNumbers
{
private:
    std::mt19937_64 mt;
    std::uniform_int_distribution<unsigned int> dist;

public:
    explicit RandomNumbers(unsigned int low, unsigned int high) : 
        mt {std::random_device{}()}, dist {low, high} {}

    unsigned int getNext()
    {
        return dist(mt);
    }
};

#endif