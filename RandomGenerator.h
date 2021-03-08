/*
RandomGenerators
*/
#ifndef RANDOM_GENERATORS_H
#define RANDOM_GENERATORS_H
#include <iomanip>
#include <random>
#include <chrono>
#include <set>
#include <string>
#include <string_view>
#include <vector>

class Generator
{
public:
    using ull = unsigned long long;
    using sc = std::chrono::system_clock;
    Generator() : engine {static_cast<ull>(sc::now().time_since_epoch().count())} {}
    
protected:
    std::mt19937_64 engine;
};

class CharGenerator: public Generator
{
public:
    CharGenerator() : Generator(), distribution{65, 122} {}
    unsigned char operator()() 
    { 
        unsigned char result;
        do
        {
            result = distribution(engine);
        } while (result >= 91  && result <= 96);
        
        return result; 
    }
private:
    std::uniform_int_distribution<unsigned char> distribution;
};

class IntGenerator : public Generator
{
public:
    IntGenerator(int lower, int upper) : Generator(), distribution {lower, upper} {}

    int operator()() { return distribution(engine); }
    
private : 
    std::uniform_int_distribution<int> distribution;
};

class DoubleGenerator: public Generator
{
public:
    DoubleGenerator(double lower, double upper) : 
        Generator(), distribution {lower, upper} {}

    double operator()() { return distribution(engine); }
private:
    std::uniform_real_distribution<double> distribution;
};

/*
        NON-TEMPLATE Functions
*/
std::vector<int> getInts(unsigned count, int low, int high);
std::vector<int> getIntsV2(unsigned count, int low, int high);
std::vector<int> getInts(unsigned count);

std::vector<std::string> getCharStrings(unsigned count, 
                                             unsigned min = 5, 
                                             unsigned max = 10);

std::string getString(unsigned length);

std::vector<double> getDoubleVector(unsigned count, double lower, double upper);

/*
        TEMPLATE Functions
*/
template <typename T>
std::vector<T> copySetToVector(const std::set<T>& values);

template <typename T>
void printVector(const std::vector<T> &values, unsigned width, unsigned perline)
{
    size_t i{};
    for (const auto &x : values)
    {
        std::cout << std::setw(width) << x;
        if (++i % perline == 0)
            std::cout << '\n';
    }
}

#endif