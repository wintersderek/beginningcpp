#ifndef FINDER_H
#define FINDER_H

#include <optional>
#include <vector>

class Finder
{
public:
    double getSearchNumber() const { return number_to_search_for; };
    void setSearchNumber(double n) { number_to_search_for = n; };
    std::optional<double> findNearest(const std::vector<double>& values) const;
private:
    double number_to_search_for {};
};

#endif