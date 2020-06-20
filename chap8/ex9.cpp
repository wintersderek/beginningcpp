/*
Exercise 8: define to the power of function
*/

#include <iostream>
#include <iomanip>

long double power(double x, int n);
long double mult(long double x, long double y);

int main ()
{

    long double result{power(1.5, 1000)};
    std::cout << "power(1.5, 1000) = " << result;

    std::cout << std::endl;
    return 0;
}

long double power(double x, int n)
{
    if (n == 0)
    {
        return 1.0;
    }
    else if (n > 0)
    {
        if (n % 2 == 0)
        {
            long double temp {power(x, n / 2)};
            return mult(temp, temp);
        }
        else
        {
            //return x * power(x, n - 1);
            return mult(x, power(x, n - 1));
        }
    }
    else
    {
        return 1.0/ power(x, -n);
    }
}

long double mult(long double x, long double y)
{
    static size_t count {};

    std::cout << "Multiplication Count: " << ++count << "\n";

    return x * y;
}