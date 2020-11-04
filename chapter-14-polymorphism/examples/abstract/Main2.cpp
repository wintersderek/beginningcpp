#include <iostream>
#include <memory>
#include "Box.h"
#include "Carton.h"
#include "ToughPack.h"

int main(int argc, char* argv[])
{
    Carton carton {20.0, 30.0, 40.0, "Plastic"};
    ToughPack pack {20.0, 30.0, 40.0};

    std::unique_ptr<Box> pBox {std::make_unique<Carton>(carton)};
    std::cout << "Carton volume is: " << pBox->volume() << '\n';

    pBox = std::make_unique<ToughPack>(pack);
    std::cout << "ToughPack volume is: " << pBox->volume() << '\n';
    
    std::cout << std::endl;
    return EXIT_SUCCESS;
}