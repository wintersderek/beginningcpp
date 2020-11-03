#include <iostream>
#include "Animal.h"
#include "Zoo.h"

std::string Animal::who() const
{
    return getName() + getWeightMsg() + getSoundMessage();
}

std::ostream& Zoo::write(std::ostream& output) const
{
    for(const auto& a : animals)
    {
        output << a->who() << '\n';
    }
    return output;
}

std::ostream& operator<<(std::ostream& output, const Zoo& zoo)
{
    return zoo.write(output);
}