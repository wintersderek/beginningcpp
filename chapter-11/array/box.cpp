/*
Create the definition for the declaration in box.h
*/
#include <iostream>
#include "box.h"

Box::Box(double lengthValue, double widthValue, double heightValue) :
    length {lengthValue}, width {widthValue}, height{heightValue}
{
#ifdef HDI_DEBUG
    std::cout << "3 side Constructor called\n";
#endif
}

Box::Box(double side) : Box(side, side, side)
{
#ifdef HDI_DEBUG
    std::cout << "Cube constructor called\n";
#endif
}

Box::Box(const Box& original) : 
    Box(original.length, original.width, original.height)
{
#ifdef HDI_DEBUG
    std::cout << "Copy constructor called\n";
#endif
}

double Box::volume()
{
    return length * width * height;
}