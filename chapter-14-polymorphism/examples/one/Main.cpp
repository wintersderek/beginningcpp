#include <iomanip>
#include <iostream>
#include "Box.h"
#include "Carton.h"
#include "ToughPack.h"

int main (int argc, char* argv[])
{
    Box box {20.0, 30.0, 40.0};
    ToughPack hard_box {20.0, 30.0, 40.0};
    Carton carton {20.0, 30.0, 40.0, "Plastic"};

    std::cout << std::setw(15) << std::left << "(box)";
    box.showVolume();
    
    std::cout << std::setw(15) << "(hard_box)";
    hard_box.showVolume();

    std::cout << std::setw(15) << "(carton)";
    hard_box.showVolume();

    std::cout << "\n\nhard_box direct access to volume: " << hard_box.volume() << '\n';

    Box* pBox {&hard_box};
    std::cout << "pBox->volume():\t" << pBox->volume();

    std::cout << std::endl;

    return EXIT_SUCCESS;
}