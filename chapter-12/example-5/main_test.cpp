#include <iostream>
#include <iomanip>
#include <vector>
#include "QuickSort.h"
#include "Random.h"

template <typename T> void printVector(const std::vector<T> values);

int main()
{
    std::vector<int> values {};
    RandomNumber rd {1, 100};

    for (size_t i {0}; i < 400000; i++)
    {
        values.push_back(rd.getNext());
    }

    printVector(values);

    hdi::quick_sort(values);

    printVector(values);

    std::cout << std::endl;
}

template <typename T>
void printVector(const std::vector<T> values)
{
    const int line_max {10};

    for(size_t i {0}; i < values.size(); )
    {
        std::cout << std::setw(4) << values[i];
        if (++i % line_max == 0)
        {
            std::cout << '\n';
        }
    }
    std::cout << '\n';
}