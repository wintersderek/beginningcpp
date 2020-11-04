#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>
#include "Box.h"
#include "Carton.h"
#include "ToughPack.h"


int main (int argc, char* argv[])
{
    std::vector<std::unique_ptr<Box>> polymorphicBoxes;
    polymorphicBoxes.push_back(std::make_unique<Box>(20.0, 30.0, 40.0));
    polymorphicBoxes.push_back(std::make_unique<ToughPack>(20.0, 30.0, 40.0));
    polymorphicBoxes.push_back(std::make_unique<Carton>(20.0, 30.0, 40.0));

    for (const auto& b : polymorphicBoxes)
    {
        b->showVolume();
    }

    std::cout << std::endl;
    return EXIT_SUCCESS;
}

