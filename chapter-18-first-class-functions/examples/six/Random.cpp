#include "Random.h"

std::vector<double> HDIRandom::get_values(size_t size)
{
    std::vector<double> result(size);
    
    for (size_t i {}; i < size; ++i)
    {
        result[i] = get_next();
    }
    return result;
}