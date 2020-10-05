/*
Provide a post-multiplication operator to allow a box to be multiplied
by an unsigned integer that produces a box that has a height that is n times
the original object.
*/
#include <iostream>
#include "Box.h"

int main ()
{
    Box myBox {2, 3, 4};
    Box bTwo {2,2,2};
    std::cout << "Box is " << myBox << "\tTwo is " << bTwo << "\n\n";

    std::cout << "*******   ADDITION   *******\n" << myBox << " + "
              << bTwo << " = " << (myBox + bTwo) << '\n';
    
    std::cout << "myBox before += " << myBox << "\tmyBox += " << bTwo 
              << " is ";
    myBox += bTwo;
    std::cout << myBox << '\n';

    std::cout << "\n\n*******   MULTIPLICATION   *******\n";
    std::cout << "Box is " << myBox << "\tTwo is " << bTwo << "\n\n";
    unsigned int n {3};
    Box newBox = myBox * 3;

    std::cout << "After multiplying by " << n << " new box is " << newBox << '\n';
    Box otherBox = 3 * myBox;
    std::cout << "After multiplying by " << n << " other box is " << otherBox;
    std::cout << "\nBox is " << myBox << "\tTwo is " << bTwo << "\n";

    std::cout << myBox << " *= 2 is ";
    myBox *= 2;
    std::cout << myBox;

    std::cout << "\n\n*******   DIVISION   *******\n";
    newBox = newBox / n;
    std::cout << "After dividing by " << n << " new box is " << newBox << '\n';
    otherBox = n / otherBox;
    std::cout << "After dividing by " << n << " otehr box is " << otherBox << '\n';

    std::cout << myBox << " /= 2 is ";
    myBox /= 2;
    std::cout << myBox << std::endl;
    return EXIT_SUCCESS;
}