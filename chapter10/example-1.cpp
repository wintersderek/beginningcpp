/*
Example 1: demonstrate our first external function
*/

#include <iostream>
#include <iomanip>

double power(double x, int n);  // Declare an external power function.
extern const int power_range;

int main ()
{
    for (int i {-power_range}; i <= power_range; ++i)
    {
        std::cout << std::setw(10) << power(8.0, i);
    }
    std::cout << std::endl;
    return 0;
}