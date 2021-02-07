#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include <chrono>
#include <random>
#include <stdexcept>
#include <vector>

class RandomGenerator
{
public:
    explicit RandomGenerator(double lower, double upper) :
        mt {
            static_cast<unsigned long long>(
                std::chrono::system_clock::now().time_since_epoch().count()
            )
        },
        real_ds {lower, upper},
        int_ds {static_cast<int>(lower), static_cast<int>(upper)}
    {
        if (!(lower < upper))
            throw std::invalid_argument("Upper must be greater than lower bound");
    }

    std::vector<int> getRandoms(unsigned count);
    //std::vector<double> getRandoms(unsigned count);

private:
    std::mt19937_64 mt;
    std::uniform_real_distribution<double> real_ds;
    std::uniform_int_distribution<int> int_ds;
    double lower_bound {};
    double upper_bound {};
};

std::vector<int> RandomGenerator::getRandoms(unsigned count)
{
    std::vector<int> result;
    for(size_t i {}; i < count; ++i)
    {
        result.push_back(int_ds(mt));
    }
    return result;
}
#endif