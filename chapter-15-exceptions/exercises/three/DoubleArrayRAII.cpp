#include <stdexcept>
#include <string>
#include "DoubleArrayRAII.h"

DoubleArrayRAII::~DoubleArrayRAII()
{
    delete[] doubles;
}

double& DoubleArrayRAII::operator[](size_t i)
{
    if (i > max_index)
        throw std::out_of_range {
            std::to_string(i) + " is beyond the max index of " 
            + std::to_string(max_index)
        };

    return doubles[i];
}

const double& DoubleArrayRAII::operator[](size_t i) const
{
    if (i > max_index)
        throw std::out_of_range{
            std::to_string(i) + " is beyond the max index of " + std::to_string(max_index)};

    return doubles[i];
}

