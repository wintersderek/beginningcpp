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

std::string getString()
{
    return std::string("Thsi");
}

int main(int argc, char const *argv[])
{
    Array<Array<std::string>> array_of_arrays;
    std::cout << "*****\n";
    Array<std::string> array{buildStringArray(1'000)};
    std::cout << "*****\n";
    array_of_arrays.push_back(array); // Push an lvalue
    std::cout << "*****\n";
    array.push_back("One more for good measure");
    std::cout << "*****\n";
    array_of_arrays.push_back(std::move(array)); // Push an rvalue
    std::cout << "*****\n";

    std::cout << std::endl;
    return 0;
}
