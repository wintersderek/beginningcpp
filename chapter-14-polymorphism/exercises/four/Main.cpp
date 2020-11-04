/*
# Create a zoo from the command line
## Ask user for animal name - or "done"
### If "done", quit adding animals
## Ask user for animal weight
## Get random between 1 and 3
## Create an animal shared pointer for the random
## Add the shared pointer to the zoo
## 
*/
#include <iostream>
#include <random>
#include <string>
#include "Animal.h"
#include "Cow.h"
#include "Dog.h"
#include "Sheep.h"
#include "Zoo.h"

Zoo getRandomZoo();

int main(int argc, char* argv[])
{
    Zoo myZoo = getRandomZoo();
    std::cout << myZoo << "\n\n";

    std::vector<Sheep*> allSheep {myZoo.herd()};
    for(const auto s : allSheep)
    {
        s->sheer();
    }

    std::cout << myZoo;
    std::cout << std::endl;
    return EXIT_SUCCESS;
}

Zoo getRandomZoo()
{
    //const char* name_prompt {u8"Enter the animal name or \"done\" to finish: "};
    Zoo retValue{};
    std::string animal_name;
    std::random_device rd;
    std::mt19937 mt {rd()};
    std::uniform_int_distribution<> distrib(1,3);
    
    while (true)
    {
        std::cout << "Enter the animal name or done to finish: ";
        std::getline(std::cin, animal_name);
        if (animal_name == "done") break;
        int animal_weight;
        std::cout << "Enter the animal weight: ";
        std::cin >> animal_weight;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (distrib(mt))
        {
        case 1:
            retValue.addAnimal(std::make_shared<Cow>(animal_name, animal_weight));
            break;
        case 2:
            retValue.addAnimal(std::make_shared<Dog>(animal_name, animal_weight));
            break;
        case 3:
            retValue.addAnimal(std::make_shared<Sheep>(animal_name, animal_weight));
            break;
        default:
            throw std::bad_function_call {};
            break;
        }
    }

    return retValue;
}