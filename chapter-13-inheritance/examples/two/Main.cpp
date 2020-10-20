#include <iostream>
#include "Carton.h"

int main (int argc, char* argv[])
{
    // Create 4 cartons covering each of the constructors
    Carton no_arg {};
    std::cout << '\n';
    Carton mat_only {"Cardboard"};
    std::cout << '\n';
    Carton sqare {3, "Plastic"};
    std::cout << '\n';
    Carton odd_shape {2, 4, 8, "Wood"};
    std::cout << '\n';
    
    // Print the object's size
    std::cout << "no_arg volume: " << no_arg.volume() << '\n';
    std::cout << "mat_only volume: " << mat_only.volume() << '\n';
    std::cout << "sqare volume: " << sqare.volume() << '\n';
    std::cout << "odd_shape volume: " << odd_shape.volume() << '\n';

    std::cout << std::endl;
    return EXIT_SUCCESS;
}