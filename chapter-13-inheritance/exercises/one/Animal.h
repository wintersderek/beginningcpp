#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>
#include <string_view>

class Animal
{
private:
    std::string name;       // Animal name
    int weight;             // Weight in pounds

public:
    // Constructors
    Animal(std::string_view animal_name, int animal_weight) :
        name {animal_name}, weight {animal_weight}
    {
        std::cout << "Animal(string_view, int) called\n";
    }

    // Behavior
    void who() const
    {
        std::cout << name << " is " << weight << "lbs.\n";
    }
};
#endif