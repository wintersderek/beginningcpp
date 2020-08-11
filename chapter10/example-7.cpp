#include <iostream>
#include "compare.h"

int main()
{
    std::vector<double> data {1.5, 4.6, 3.1, 1.1, 3.8, 2.1};

    std::cout << "Maximum Value: " << compare::max(data) << "\n"
              << "Minimum Value: " << compare::min(data) << std::endl;
}