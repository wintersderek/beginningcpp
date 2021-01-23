/*

*/

#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include "Array.h"

//Construct an Array<std::string>
Array<std::string> buildStringArray(const size_t size)
{
    Array<std::string> result {size};
    for (size_t i {}; i < size; ++i)
    {
        result[i] = "You should learn from your competitor, but never copy. Copy and you die.";
    }
    return result;
}

int main(int argc, char const *argv[])
{
    const size_t numArrays {10};
    const size_t numStringsPerArray {1000};

    std::vector<Array<std::string>> vectorOfArrays;
    vectorOfArrays.reserve(numArrays);

    // Collect start measurement
    auto begin {std::chrono::high_resolution_clock::now()};
    for (size_t i {}; i < numArrays; ++i)
    {
        vectorOfArrays.push_back(buildStringArray(numStringsPerArray));
    }
    // Collect end measurement
    auto end {std::chrono::high_resolution_clock::now()};
    auto elapsed {std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin)};

    std::cout << "Total Time: " << elapsed.count();
    std::cout << std::endl;
    return 0;
}
