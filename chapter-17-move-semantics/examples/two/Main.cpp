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
    // Test the Assignment operators
    Array<std::string> value_one {2};
    value_one = buildStringArray(3);

    Array<std::string> value_two {4};
    value_two = std::move(value_one);
    
    std::cout << std::endl;
    return 0;
}
