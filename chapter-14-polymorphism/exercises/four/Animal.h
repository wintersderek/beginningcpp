#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <string_view>

class Animal
{
protected:
    std::string name;   // Contains the animal name like "Fido".
    int weight;         // Animal weight in lbs.

public:
    Animal(std::string_view sName, int iWeight) : 
        name {sName}, weight {iWeight} {}

    virtual ~Animal() = default;

    std::string who() const;

    virtual std::string sound() const = 0;

    virtual std::string getName() const { return name; }
    virtual std::string getWeightMsg() const { return " is " + std::to_string(weight) + " lbs and"; };
    virtual std::string getSoundMessage() const { return " makes the sound " + sound(); }
};
#endif