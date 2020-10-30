#include <iostream>
#include "Commodity.h"

int main(int argc, char* argv[])
{
    Commodity commod {"Gold"};

    std::cout << "Commodity Name: " << commod.getName() << '\n';
    std::cout << std::endl;
    return EXIT_SUCCESS;
}