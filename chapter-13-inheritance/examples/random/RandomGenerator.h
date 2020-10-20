#pragma once
#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <chrono>
#include <iostream>
#include <random>


class RandomGenerator
{
private:
    double lower_bound;
    double upper_bound;
    std::mt19937_64 generator;
    std::uniform_real_distribution<double> distribution;

    RandomGenerator(double lower, double upper) : 
        lower_bound {lower},
        upper_bound {upper},
        generator { 
            static_cast<unsigned long long>(
                std::chrono::system_clock::now().time_since_epoch().count()
            )
        },
        distribution {lower, upper}
    {
        std::cout << "RandomGenerator(double, double)\n";
    }

public:
    RandomGenerator(const RandomGenerator& x) = delete;

    double getNext()
    {
        return distribution(generator);
    }

    static RandomGenerator getGenerator(double lower, double upper)
    {
        return RandomGenerator(lower, upper);
    }
};

#endif