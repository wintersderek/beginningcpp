#ifndef DOG_H
#define DOG_H
#include "Animal.h"

class Dog : public Animal
{
public:
    Dog(std::string_view sName, int iWeight) : Animal {sName, iWeight} {}

    virtual std::string sound() const override { return "Woof"; }
};
#endif