/*
Demonstrate the member overload of the subscript operator []
    - Create a Number class
    - Create a linked list for the number class
    - Create a Container/Iterator for the linked list
    - Create the subscript operator on the container
*/
#include <iostream>
#include <iomanip>
#include "Number.h"
#include "NumberContainer.h"

int main()
{

    const size_t count {20};
    NumberContainer numbers {};

    for (size_t i{0}; i < count; ++i)
    {
        numbers.addNumber(std::make_shared<Number>(Number::getRandomNumber()));
    }

    // Get the iterator and print each
    std::cout << numbers;

    for (size_t i {0}; i < count; ++i)
    {
        if (i%2 == 0)
            std::cout << *numbers[i] << '\n';
    }
    
    std::cout << std::endl;
    return 0;
}