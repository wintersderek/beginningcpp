#include <iostream>
#include <string>
#include "Array.h"

template <typename T>
void fillArray(Array<T>& fill)
{
    for (size_t i {0}; i < fill.getSize(); ++i)
    {
        fill[i] = i + 10;
    }
}

int main (int argc, char* argv[])
{
    size_t size {10};
    Array<int> myArray {size};

    fillArray(myArray);
    Array<int> second {myArray};
    second[9] = 25;
    myArray = second;
    
    for (size_t i{0}; i < myArray.getSize(); i++)
    {
        std::cout << myArray[i] << ' ';
    }

    std::cout << '\n';
    myArray.push_back(26);
    myArray.push_back(27);

    for (size_t i{0}; i < myArray.getSize(); i++)
    {
        std::cout << myArray[i] << ' ';
    }

    std::cout << '\n';
    Array<std::string> myStrings;
    myStrings.push_back("Hello");
    myStrings.push_back("Derek");
    for(size_t i {}; i < myStrings.getSize(); i++)
    {
        std::cout << myStrings[i] << ' ';
    }

    std::cout << std::endl;
    return EXIT_SUCCESS;
}