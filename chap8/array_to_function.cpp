// Passing arrays to a function

#include <iostream>
#include <array>

double average(double array[], size_t count);
double average_ptr_notation(double array[], size_t count);

int main ()
{
    double values[] {1.0, 2.0, 3, 4, 5, 6, 7, 8, 9, 11.5};
    size_t count = std::size(values);

    std::cout << "Average: " << average(values, std::size(values)) << "\n"
              << "Average (ptr): " << average_ptr_notation(values, count)
              << std::endl;

    return 0;
}

double average(double array[], size_t count)
{
    double sum {};

    for (size_t i = 0; i < count; i++)
    {
        sum += array[i];
    }

    return sum/count;
}

double average_ptr_notation(double array[], size_t count)
{
    double sum {};

    for (size_t i = 0; i < count; i++)
    {
        sum += *array;
        array++;
    }

    return sum/count;
}