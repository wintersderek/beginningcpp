#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>
#include "Box.h"
#include "Carton.h"
#include "ToughPack.h"


int main (int argc, char* argv[])
{
    std::vector<Box> boxes;
    boxes.push_back(Box {20.0, 30.0, 40.0});
    boxes.push_back(ToughPack {20.0, 30.0, 40.0});
    boxes.push_back(Carton {20.0, 30.0, 40.0, "Plastic"});

    for(const auto& b : boxes)
    {
        b.showVolume();
    }

    std::cout << "\n-----\n";

    std::vector<std::unique_ptr<Box>> polymorphicBoxes;
    polymorphicBoxes.push_back(std::make_unique<Box>(20.0, 30.0, 40.0));
    polymorphicBoxes.push_back(std::make_unique<ToughPack>(20.0, 30.0, 40.0));
    polymorphicBoxes.push_back(std::make_unique<Carton>(20.0, 30.0, 40.0));

    for (const auto& b : polymorphicBoxes)
    {
        b->showVolume();
    }

    ToughPack hard_box {20.0, 30.0, 40.0};

    std::unique_ptr<Box> pBox {std::make_unique<ToughPack>(hard_box)};
    std::cout << "Smart hard_box volume: " << pBox->volume();
    std::cout << std::endl;
    return EXIT_SUCCESS;
}

