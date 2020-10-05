/*
Operator overload for <
*/

#include <iostream>
#include <iomanip>
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
    size_t line_max {5};
    for (size_t i {0}; i < box_count; )
    {
        std::cout << std::setw(7) << boxes[i];

        if (++i % line_max == 0)
        {
            std::cout << '\n';
        }
    }

    Box temp {boxes[0] + boxes[1]};
    std::cout << "Box[0] + Box[1] = " << temp << '\n';

    std::cout << "+ Box[2] = " << (temp + boxes[2]) << '\n';

    std::cout << "*******\t\tBox with +=\n";
    for(size_t i {boxes.size() - 2}; i >= 0; --i)
    {
        std::cout << i << '\n';
        std::cout << boxes[boxes.size() - 1] << " += " << boxes[i]
                  << " = " << (boxes[boxes.size() - 1] += boxes[i]) << '\n';
        if (i==0) break;
    }

    std::cout << std::endl;
}

