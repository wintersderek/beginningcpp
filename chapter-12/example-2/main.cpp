/*
Operator overload for <
*/

#include <iostream>
#include <vector>
#include "Box.h"

void printCompareBoxs(const Box& a, const Box& b);

int main()
{
    const double min_value {18.0};
    const unsigned box_count {10};
    std::vector<Box> boxes {};

    for (size_t i {0}; i < box_count; ++i)
    {
        boxes.push_back(Box::getRandomBox());
    }

/*
    for (size_t i {1}; i < box_count; ++i)
    {
        printCompareBoxs(boxes[i-1], boxes[i]);
    }
*/
    std::cout << "Boxes below volume (" << min_value << ")\n";
    for (const auto& x : boxes)
    {
        if (x < min_value)
        {
            x.print();
            std::cout << '\n';
        }
    }

    std::cout << "Boxes above volume (" << min_value << ")\n";
    for (const auto& x : boxes)
    {
        if (min_value < x)
        {
            x.print();
            std::cout << '\n';
        }
    }

    std::cout << std::endl;
}

void printCompareBoxs(const Box &a, const Box &b)
{
    const char true_value[]{"true"};
    const char false_value[]{"false"};

    if (a < b)
    {
        a.print();
        std::cout << " is less than ";
        b.print();
    }
    else
    {
        b.print();
        std::cout << " is less than ";
        a.print();
    }
    std::cout << std::endl;
}