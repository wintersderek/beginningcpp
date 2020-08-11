/*
Definition of compare namespace functions
*/
#include <limits>
#include "compare.h"

//Define max
double compare::max(std::vector<double>& data)
{
    double retVal {-std::numeric_limits<double>::infinity()};

    for (const auto& value : data)
    {
        if (value > retVal)
        {
            retVal = value;
        }
    }
    return retVal;
}

//Define min
double compare::min(std::vector<double>& data)
{
    double retVal {std::numeric_limits<double>::infinity()};

    for (const auto& value : data)
    {
        if (value < retVal)
        {
            retVal = value;
        }
    }
    return retVal;
}