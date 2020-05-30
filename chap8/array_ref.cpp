/*
Show passing an array as reference to limit array size
*/

#include <iostream>
#include <array>

double average(const double (&array)[10]);

int main()
{
    double my_array[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 9};

    std::cout << "Average: " << average(my_array) << std::endl;
    return 0;
}

double average (const double (&array)[10])
{
    double result {};

    for(auto& i: array)
    {
        result += i;
    }

    return result / std::size(array);
}