/*
RandomGenerators
*/
#ifndef RANDOM_GENERATORS_H
#define RANDOM_GENERATORS_H
#include <random>
#include <chrono>

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

std::vector<int> getInts(unsigned count);

#endif