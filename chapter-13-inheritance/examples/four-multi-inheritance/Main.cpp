#include <iostream>
#include "CerealPack.h"

int main (int argc, char* argv[])
{
    // Create a multi-inherited CerealPack 
    CerealPack cp {8.0, 3.0, 10.0, "Cornflakes"};
    std::cout << "\nVolume of cp: " << cp.Carton::volume() << '\n';
    std::cout << "Contents weight of cp: " << cp.Contents::getWeight() << '\n';
    std::cout << "Carton weight of cp: " << cp.Carton::getWeight() << '\n';
    std::cout << std::endl;
    return EXIT_SUCCESS;
}