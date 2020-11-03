#include <iostream>
#include "Animal.h"
#include "Zoo.h"
#include "Sheep.h"
//Animal
std::string Animal::who() const
{
    return getName() + getWeightMsg() + getSoundMessage();
}

// Zoo
std::ostream& Zoo::write(std::ostream& output) const
{
    for(const auto& a : animals)
    {
        output << a->who() << '\n';
    }
    return output;
}

std::vector<std::shared_ptr<Sheep>> Zoo::herd() const
{
    std::vector<std::shared_ptr<Sheep>> retValue;

    for(const auto& a : animals)
    {
        /*
        if (typeid(*a) == typeid(Sheep))
        {
            //std::shared_ptr<Sheep> sheep = dynamic_cast<Sheep*>(a);
            retValue.push_back(dynamic_cast<Sheep*>(a.get()));
        }
        */

        std::shared_ptr<Sheep> pSheep = std::dynamic_pointer_cast<Sheep>(a);
        if (pSheep)
        {
            retValue.push_back(pSheep);
        }

    }
    return retValue;
}

// Sheep
void Sheep::sheer()
{
    this->weight *= 0.90;
}

// Non-Class
std::ostream& operator<<(std::ostream& output, const Zoo& zoo)
{
    return zoo.write(output);
}