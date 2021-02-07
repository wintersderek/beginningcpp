#include <iostream>
#include <vector>
#include "Near.h"
#include "Optimum.h"
#include "Random.h"

int main (int argc, const char* argv[])
{
    HDIRandom rd {1.0, 100.0};

    int needle {};
    std::cout << "Enter a number to search for: ";
    std::cin >> needle;

    std::vector<double> values = rd.get_values(50);

    std::cout << "The number nearest yours is: "
              << (*find_optimum(values, Near{needle})) << '\n';

    std::cout << std::endl;
    return EXIT_SUCCESS;
}