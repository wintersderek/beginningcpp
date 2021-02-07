#ifndef HDI_RANDOM_H
#define HDI_RANDOM_H

/*
Class for generating random numbers
*/
#include <chrono>
#include <random>
#include <stdexcept>
#include <vector>

class HDIRandom
{

public:
    explicit HDIRandom(double lower, double upper):
        lower_bound {lower}, 
        upper_bound {upper}, 
        engine {
            static_cast<unsigned long long>(
                std::chrono::system_clock::now().time_since_epoch().count()
            )
        },
        distribution {lower, upper} 
    {
        if (lower >= upper)
            throw std::range_error("Lower range of distrubution must be lower than upper range");
    }

    double get_next() { return distribution(engine); }

    std::vector<double> get_values(const size_t);

private:
    std::mt19937_64 engine;
    std::uniform_real_distribution<double> distribution;
    double lower_bound;
    double upper_bound;    
};

#endif