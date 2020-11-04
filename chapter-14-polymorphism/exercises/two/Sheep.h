#ifndef SHEEP_H
#define SHEEP_H
#include "Animal.h"

class Sheep : public Animal
{
public:
    Sheep(std::string_view sName, int iWeight) : Animal {sName, iWeight} {}

    virtual std::string sound() const override { return "Baaa!"; }

    virtual std::string who() const override;
};
#endif