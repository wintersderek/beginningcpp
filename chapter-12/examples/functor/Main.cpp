/*
Demonstrate the member overload of the subscript operator []
    - Create a Number class
    - Create a linked list for the number class
    - Create a Container/Iterator for the linked list
    - Create the subscript operator on the container
*/
#include <iostream>
#include <iomanip>
#include "MinNumber.h"
#include "Number.h"
#include "NumberContainer.h"


int main()
{

    const size_t count{20};
    NumberContainer numbers{};

    for (size_t i{0}; i < count; ++i)
    {
        numbers.addNumber(std::make_shared<Number>(Number::getRandomNumber()));
    }

    // Get the iterator and print every fifth[]
    std::cout << numbers;

    for (size_t i{0}; i < count; ++i)
    {
        if (i % 5 == 0)
            std::cout << std::setw(5) << *numbers[i];
    }
    std::cout << '\n';

    // Attempt to modify the first item with the second item
    numbers[0] = numbers[1];
    
    std::cout << *numbers[0] << " should equal " << *numbers[1] << '\n';

    MinNumber min_num;
    std::cout << "Minimum Number in container: " << (*min_num(numbers)) << '\n';

    float my_value {*numbers[0]};
    std::cout << "Converted Value: " << my_value << '\n';

    float my_other {static_cast<float>(*numbers[5])};
    std::cout << "Converted Other: " << my_other << '\n';

    std::cout << std::endl;
    return 0;
}