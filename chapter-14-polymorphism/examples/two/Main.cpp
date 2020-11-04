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
    std::cout << "hard_box volume() directly: " << hard_box.volume() << '\n';
    
    std::cout << std::setw(15) << "(carton)";
    carton.showVolume();

    // Use base pointer
    Box* pBox {&box};
    std::cout << "box volume through pBox: " << pBox->volume() << '\n';
    pBox->showVolume();

    pBox = &hard_box;
    std::cout << "hard_box volume through pBox: " << pBox->volume() << '\n';
    pBox->showVolume();
    
    pBox = &carton;
    std::cout << "carton volume through pBox: " << pBox->volume() << '\n';
    pBox->showVolume();

    std::cout << std::endl;

    return EXIT_SUCCESS;
}