#include <iostream>
#include "Carton.h"

int main (int argc, char* argv[])
{
    // Create 4 cartons covering each of the constructors
    Carton empty {};
    std::cout << '\n';
    Carton carton {20.0, 30.0, 40.0, "Glassine Board"};
    std::cout << '\n';

    Carton copy {carton};
    std::cout << '\n';

    // Show volumes
    std::cout << "Volume of empty: " << empty.volume() << '\n';
    std::cout << "Volume of carton: " << carton.volume() << '\n';
    std::cout << "Volume of copy: " << copy.volume() << '\n';
    std::cout << std::endl;
    return EXIT_SUCCESS;
}