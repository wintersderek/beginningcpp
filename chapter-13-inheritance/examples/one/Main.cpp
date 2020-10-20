#include <iostream>
#include "Box.h"
#include "Carton.h"

int main (int argc, char* argv[])
{
    //Box box {40.0, 30.0, 20.0};
    Carton carton {};
    Carton chocolateCarton {"Solid bleached paperboard"};

    // Print the object's size
    //std::cout << "box occupies " << sizeof box << " bytes" << '\n';
    std::cout << "carton occupies " << sizeof carton << " bytes" << '\n';
    std::cout << "chocolateCarton occupies " << sizeof(chocolateCarton)
              << " bytes" << '\n';

    // Print the object's volume
    //std::cout << "box volume " << box.volume() << '\n';
    std::cout << "carton volume " << carton.volume() << '\n';
    std::cout << "chocolateCarton volume " << chocolateCarton.volume() << '\n';

    std::cout << std::endl;
    return EXIT_SUCCESS;
}