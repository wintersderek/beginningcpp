#include "Statistics.h"

#ifdef DEBUG
#include <iostream>
#endif

double average(std::vector<double>& data)
{
#ifdef DEBUG
    std::cout << "(a)";
#endif
    double total{0.0};

    for (size_t i{}; i < data.size(); ++i)
    {
        total += data[i];
    }

    return total / data.size();
}

double mean(std::vector<double>& data)
{
#ifdef DEBUG
    std::cout << "(m)";
#endif
    auto mid{std::floor(data.size() / 2)};

    if (data.size() % 2 == 0)
    {
        return static_cast<double>(
            (data[mid - 1] + data[mid]) / 2);
    }
    else
    {
        return static_cast<double>(data[mid]);
    }
}