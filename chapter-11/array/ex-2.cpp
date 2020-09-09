/*
    Use header files for classes
*/  
#include <iostream>
#include "box.h"

int main()
{
    Box box_one{80.5, 50.2, 14.0};

    Box box_two{7};
    
    Box box_three{10};
    
    Box box_four {box_three};
    
    //Box boxes[7] {box_four, box_two, box_three, box_four};
    Box boxes[4]{box_one, box_two, box_three, box_four};

    std::cout << std::endl;
}