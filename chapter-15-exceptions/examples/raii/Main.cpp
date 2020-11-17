#include <iostream>
#include "DoubleArrayRAII.h"

int main (int argc, char* argv[])
{
    size_t values {};
    std::cout << "Enter the number of values to capture: ";
    std::cin >> values;

    DoubleArrayRAII myDoubles {values};
    myDoubles.fill();
    
    std::cout << "Done..." << std::endl;
    return EXIT_SUCCESS;
}