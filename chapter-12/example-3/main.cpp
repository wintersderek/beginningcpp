/*
Operator overload for <
*/

#include <iostream>
#include <string_view>
#include <utility>          // Used for namespace rel_ops
#include <vector>
#include "Box.h"

void printCompareBoxs(const Box& a, const Box& b, std::string_view message);

int main()
{
    using namespace std::rel_ops;
    const double min_value {18.0};
    const unsigned box_count {200};
    const Box test_box {4.0, 4.0, 4.0};

    std::vector<Box> boxes {};

    for (size_t i {0}; i < box_count; ++i)
    {
        boxes.push_back(Box::getRandomBox());
    }

    std::cout << "Boxes size: " << boxes.size() << '\n';
    for (const auto& b : boxes)
    {
        if (b <= test_box)
        {
            printCompareBoxs(b, test_box, "is less than or equal to");
        }
    }

    for (const auto& b : boxes)
    {
        if (b == test_box)
        {
            printCompareBoxs(b, test_box, "is equal to");
        }
    }

    for (const auto& b: boxes)
    {
        if (b > test_box)
        {
            printCompareBoxs(b, test_box, "is greater than");
        }
    }

    for (const auto& b : boxes)
    {
        if (b != test_box)
        {
            printCompareBoxs(b, test_box, "is not equal");
        }
    }

    for (size_t i {0}; i < boxes.size() - 1; ++i)
    {
        // for every box, compare the i box with each other box, as long
        // as i box doesn't equal j box
        for (size_t j {i + 1}; j < boxes.size(); ++j)
        {
            if (boxes[i] == boxes[j])
            {
                std::cout << "Box " << i << " = " << j << '\n';
            }
        }
    }

    std::cout << std::endl;
}

void printCompareBoxs(const Box &a, const Box &b, std::string_view message)
{
    a.print();
    std::cout << ' ' << message << ' ';
    b.print();
    std::cout << '\n';
}