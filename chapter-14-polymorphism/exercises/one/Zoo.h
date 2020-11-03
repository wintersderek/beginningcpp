#ifndef ZOO_H
#define ZOO_H
#include <iostream>
#include <memory>
#include <vector>
#include "Animal.h"

class Zoo
{
protected:
    std::vector< std::shared_ptr<Animal> > animals;

public:
    Zoo() = default;

    void addAnimal(std::shared_ptr<Animal> animal) { animals.push_back(animal); }

    std::ostream& write(std::ostream& output) const;
};

std::ostream& operator<<(std::ostream& output, const Zoo& zoo);
#endif