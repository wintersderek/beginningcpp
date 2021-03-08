/*
Show how the std::min_element and std::max_element work
*/
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#include "../Iterators/RandomGenerator.h"

std::vector<int> getInts(unsigned count)
{
    std::vector<int> result(count);
    IntGenerator gen {1, 1000};
    for(size_t i {}; i < count; ++i)
    {
        result[i] = gen();
    }
    return result;
}

int main(int argc, char const *argv[])
{
    std::vector<int> values = getInts(50);

    int closest {};
    std::cout << "Enter a number for closest: ";
    std::cin >> closest;
    auto comp = [closest](int x, int y) {
        return std::abs(x - closest) < std::abs(y - closest);
    };

    std::cout << std::left;
    std::cout << "Min: " << *std::min_element(values.begin(), values.end()) << '\n';
    std::cout << "Max: " << *std::max_element(values.begin(), values.end()) << '\n';
    std::cout << "Closest: " 
              << *std::min_element(values.begin(), values.end(), comp) << '\n';
    std::cout << std::endl;
    return 0;
}
