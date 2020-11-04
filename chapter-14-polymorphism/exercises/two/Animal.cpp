#include <iostream>
#include "Animal.h"
#include "Sheep.h"
#include "Zoo.h"

std::string Animal::who() const
{
    return name + " is " + std::to_string(weight) + " lbs.";
}

std::ostream& Zoo::write(std::ostream& output) const
{
    for(const auto& a : animals)
    {
        output << a->who() << " It makes the sound " << a->sound() << '\n';
    }
    return output;
}

std::ostream& operator<<(std::ostream& output, const Zoo& zoo)
{
    return zoo.write(output);
}

std::string Sheep::who() const
{
    return "Woolly" + name + " is " + std::to_string(weight*0.90) + " lbs.";
}