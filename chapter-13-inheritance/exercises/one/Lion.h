#ifndef LION_H
#define LION_H
#include "Animal.h"

class Lion : public Animal
{
public:
    Lion(std::string_view lion_name, int lion_weight) : 
        Animal {lion_name, lion_weight}
    {
        std::cout << "Lion(string_view, int) called\n";
    }
};
#endif