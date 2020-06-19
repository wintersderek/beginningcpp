/*
Exercise 8: define to the power of function
*/

#include <iostream>
#include <iomanip>
#include <cmath>

double power(double x, int n);
double compute_power(double x, int n);

int main ()
{
    for (int i {-3}; i <=3; ++i)
    {
        std::cout << std::setw(10) << compute_power(8.0, i) << "\n";
    }

    std::cout << std::endl;
    return 0;
}

double compute_power(double x, int n)
{
    if (std::fmod(x, 2.0) == 0)
    {
        double temp {power(x, n/2)};
        return temp * temp;
    }
    else
    {
        return power(x, n);
    }
    
}

double power(double x, int n)
{
    if (n == 0)
    {
        return 1.0;
    }
    else if (n > 0)
    {
        return x * power(x, n - 1);
    }
    else
    {
        return 1.0/ power(x, -n);
    }
    
    

}