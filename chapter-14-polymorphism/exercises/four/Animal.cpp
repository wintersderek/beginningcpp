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

std::vector<Sheep*> Zoo::herd() const
{
    std::vector<Sheep*> retValue;

    for(const auto& a : animals)
    {
        if (typeid(*a) == typeid(Sheep))
        {
            //std::shared_ptr<Sheep> sheep = dynamic_cast<Sheep*>(a);
            retValue.push_back(dynamic_cast<Sheep*>(a.get()));
        }

        /*
        Sheep* pSheep = dynamic_cast<Sheep*>(a.get());
        if (pSheep != nullptr)
        {
            retValu.push_back(pSheep);
        }
        */
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