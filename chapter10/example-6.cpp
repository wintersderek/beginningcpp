/* 
Example 10-6: using namespaces
*/
#include <iostream>
#include <iomanip>
#include "constants.h"


int main()
{
    using std::cout;

    cout << std::setw(7) << "PI: " << hdi_constants::pi << "\n"
              << std::setw(7) << "E: " << hdi_constants::e << "\n"
              << std::setw(7) << "Sqrt2: " << hdi_constants::sqrt_2
              << std::endl;
    return 0;
}