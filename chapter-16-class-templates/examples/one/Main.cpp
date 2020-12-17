#include <iostream>
#include "Array.h"

int main(int argc, char* argv[])
{
    size_t mySize {10};
    Array<double> myArray {mySize};

    for(size_t i {0}; i < mySize; ++i)
    {
        myArray[i] = i;
    }

    Array<double> second {5};
    second[0] = 1.5;
    second[1] = 2.5;
    second[2] = 3.5;
    second[3] = 4.5;
    second[4] = 5.5;
    myArray = second;

    for(size_t i {}; i < myArray.getSize(); ++i)
    {
        std::cout << myArray[i] << '\n';
    }

    std::cout << std::endl;
    return EXIT_SUCCESS;
}