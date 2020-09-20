/*
Operator overload for <
*/

#include <iostream>
#include <string_view>
#include <utility>          // Used for namespace rel_ops
#include <vector>
#include "Box.h"

int main()
{
    using namespace std::rel_ops;
    const double min_value {18.0};
    const unsigned box_count {10};
    const Box test_box {4.0, 4.0, 4.0};

    std::vector<Box> boxes {};

    for (size_t i {0}; i < box_count; ++i)
    {
        boxes.push_back(Box::getRandomBox());
    }

    std::cout << "Boxes size: " << boxes.size() << '\n';
    for (const Box& b : boxes)
    {
        std::cout << b << '\n';
    }
    std::cout << std::endl;
}

