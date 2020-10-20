#ifndef ARDVARK_H
#define ARDVARK_H
#include "Animal.h"

class Ardvark : public Animal
{
public:
    Ardvark(std::string_view ardvark_name, int ardvark_weight) : 
        Animal {ardvark_name, ardvark_weight}
    {
        std::cout << "Ardvark(string_view, int) called\n";
    }
};
#endif