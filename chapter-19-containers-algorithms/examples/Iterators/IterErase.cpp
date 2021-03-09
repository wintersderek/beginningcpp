/*
Show how to properly erase even numbers using an iterator
*/

#include <iomanip>
#include <iostream>
#include <vector>
#include "RandomGenerator.h"

template <typename Container>
void removeEven(Container& values);

template <typename Container>
void printContainer(const Container& values, unsigned width=5, unsigned per_line=20);

int main(int argc, char const *argv[])
{
    IntGenerator gen {1, 999};
    std::vector<int> values(100);
    for(size_t i {}; i < values.size(); ++i) values[i] = gen();

    printContainer(values);
    removeEven(values);
    std::cout << "\n";
    printContainer(values);

    std::cout << std::endl;
    return 0;
}

template <typename Container>
void removeEven(Container& values)
{
    auto it = values.cbegin();

    while (it != values.cend())
    {
        if (*it % 2 == 0)
        {
            // Get current iterator location
            //size_t current_location = it - values.cbegin();
            // delete current location
            it = values.erase(it);
            // reset iterator to current location
            //it = values.begin() + current_location;
        }
        else
        {
            ++it;
        }
    }
}

template <typename Container>
void printContainer(const Container& values, unsigned width, unsigned per_line)
{
    size_t i {};
    for(const auto& x : values)
    {
        std::cout << std::setw(width) << x;
        if (++i % per_line == 0)
            std::cout << '\n';
    }
    std::cout << '\n';
}