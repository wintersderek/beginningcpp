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
    // Test the Assignment operators
    Array<std::string> value_one {2};
    value_one = buildStringArray(3);

    Array<std::string> value_two {4};
    value_two = std::move(value_one);

    std::cout << "Value Two Size: " << value_two.getSize() << '\n';
    value_two.push_back("Back");
    value_two.push_back(getString());
    std::cout << "Value Two Size: " << value_two.getSize() << '\n';
    //std::cout << "Value One [0]: " << value_one[0] << '\n';
    std::cout << std::endl;
    return 0;
}
