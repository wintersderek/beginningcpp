#include <iostream>
#include <memory>
#include <vector>
#include "Box.h"
#include "Can.h"
#include "Carton.h" 
#include "ToughPack.h"
#include "Vessel.h"

int main (int argc, char* argv[])
{
    Box box {40, 30, 20};
    Carton carton {40, 30, 20, "Plastic"};
    ToughPack pack {40, 30, 20};
    Can can {10, 3};

    
    std::vector<std::unique_ptr<Vessel>> vessels;
    vessels.push_back(std::make_unique<Box>(40, 30, 20));
    vessels.push_back(std::make_unique<Carton>(40, 30, 20, "Plastic"));
    vessels.push_back(std::make_unique<ToughPack>(40, 30, 20));
    vessels.push_back(std::make_unique<Can>(10, 3));

    for (const auto& v : vessels)
    {
        std::cout << "Object " << typeid(*(v.get())).name() << " has volume " 
                  << v->volume() << '\n';
    }

    std::vector<Vessel*> stuff {&box, &carton, &pack, &can};
    for (const auto& s : stuff)
    {
        std::cout << "\n\nObject " << typeid(*s).name() << "has volume " 
                  << s->volume() << '\n';
    }

    std::cout << std::endl;
    return EXIT_SUCCESS;
}