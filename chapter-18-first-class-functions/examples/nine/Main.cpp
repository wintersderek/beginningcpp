/*
Use a lambda expression within a class
*/

#include <iostream>
#include <vector>
#include "Finder.h"
#include "Optimum.h"

int main(int argc, char const *argv[])
{
    Finder my_finder{};
    std::vector<double> my_values {2.5, 3.8, 1.7, 5.7, 3.3};

    while (true)
    {
        double my_number{};
        std::cout << "Enter a double (0 to quit): ";
        std::cin >> my_number;
        
        if (my_number == 0) break;
        
        my_finder.setSearchNumber(my_number);
        std::cout << (*my_finder.findNearest(my_values)) << " is closest to "
                  << my_number << '\n';
        my_values.push_back(my_number);
    }

    std::cout << std::endl;
    return 0;
}
