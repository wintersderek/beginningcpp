#ifndef COW_H
#define COW_H
#include "Animal.h"

class Cow : public Animal
{
public:
    Cow(std::string_view sName, int iWeight) : Animal {sName, iWeight} {}

    virtual std::string sound() const override { return "Moo!"; }
};
#endif