/*
    Use header files for classes
*/  
#include <iostream>
#include "box.h"

int main()
{
    Box box_one{80.5, 50.2, 14.0};

    std::cout << "My box volume: " << box_one.volume() << "\n";

    Box box_two{};
    std::cout << "Box Two Volume: " << box_two.volume() << "\n";

    Box box_three{10};
    std::cout << "Box Three Volume: " << box_three.volume() << "\n";

    Box box_four {box_three};
    std::cout << "Box Four Volume: " << box_four.volume() << "\n";
    std::cout << "Box Four Sides: " << box_four.getLength() << " x "
              << box_four.getWidth() << " x " << box_four.getHeight()
              << "\n";

    std::cout << "Box address: " << box_four.getAddres() << "\n"
              << "Box address size: " << sizeof(box_four.getAddres()) << "\n";

    std::cout << std::endl;
}