/*
Operator overload for <
*/

#include <iostream>
#include "Box.h"

int main()
{
    const char true_value[] {"true"};
    const char false_value[] {"false"};

    Box one {4.0, 5.0, 3.0};
    Box two {2.0, 7.0, 4.0};
    Box three {10.0, 12.0, 15.0};
    Box four {Box::getRandomBox()};

    std::cout << "Box 1 Volume: " << one.volume() << "\n"
              << "Box 2 Volume: " << two.volume() << "\n"
              << "Box 3 Volume: " << three.volume() << "\n"
              << "Box 4 Volume: " << four.volume() << "\n";

    std::cout << "Box 1 < Box 2: " << ((one < two)? true_value : false_value) 
              << "\n"
              << "Box 1 < Box 3: " << ((one < three)? true_value: false_value)
              << "\n"
              << "Box 3 > Box 2: " << ((three > two)? true_value: false_value)
              << "\n"
              << "Box 2 > Box 1: " << ((two > one)? true_value: false_value)
              << "\n"
              << "Box 4 < Box 1: " << ((four < one)? true_value: false_value);

    std::cout << std::endl;
}