
#include <iostream>
#include <iomanip>
#include <vector>
#include "QuickSort.h"

template <typename T> void printVector(const std::vector<T>& values);

int main()
{
    std::vector<int> values {7,6,5,4,3,2,1};

    printVector(values);

    hdi::quick_sort(values);

    printVector(values);

    std::cout << std::endl;
}

template <typename T>
void printVector(const std::vector<T>& values)
{
    for(const auto& v : values)
    {
        std::cout << std::setw(4) << v;
    }
    std::cout << "\n";
}