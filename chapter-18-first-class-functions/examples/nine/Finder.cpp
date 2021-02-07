#include <cmath>
#include "Finder.h"
#include "Optimum.h"

std::optional<double>  Finder::findNearest(const std::vector<double>& values) const
{
    if (values.empty())
    {
        return std::nullopt;
    }
    else
    {
        return *(find_optimum(values, [this](double x, double y) {
            return std::abs(x - getSearchNumber()) < std::abs(y - getSearchNumber());
        }));
    }
}