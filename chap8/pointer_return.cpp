//Show return values as pointers
#include <iostream>
#include <iomanip>
#include <string_view>
#include <array>

int* larger(int* a, int* b);
const double* smallest(const double data[], size_t count);
double* shift_range(double data[], size_t count, double delta);
const double* largest(const double data[], size_t count);
double* scale_range(double data[], size_t count, double divisor);
double* normalize_range(double data[], size_t count);
void display_values(double data[], std::string_view title, size_t count, 
                        unsigned per_line);

int main()
{
    double data[] {11.0, 23.0, 13.0, 4.0, 57.0, 36.0, 317.0, 88.0,
                    9.0, 100.0, 121.0, 12.0, 3.5, 316.5};
    size_t count {std::size(data)};

    display_values(data, "Initial Values", count, 5);
    normalize_range(data, count);
    display_values(data, "Normalized Values", count, 5);
    
    return 0;
}
void display_values(double data[], std::string_view title, size_t count, 
                        unsigned per_line)
{
    std::cout << title << "\n";

    for (size_t i = 0; i < count; i++)
    {
        std::cout << std::setw(10) << data[i];
        if ((i + 1) % per_line == 0)
        {
            std::cout << "\n";
        }
    }
    std::cout << std::endl;
}

double* normalize_range(double data[], size_t count)
{
    return (scale_range(shift_range(data, count, -(*smallest(data, count))),
                count, *largest(data, count)));
}

double* scale_range(double data[], size_t count, double divisor)
{
    if (!divisor) { return nullptr; }

    for (size_t i = 0; i < count; i++)
    {
        data[i] /= divisor;
    }
    return data;
}

double* shift_range(double data[], size_t count, double delta)
{
    if (delta)
    {
        for (size_t i {}; i < count; i++)
        {
            data[i] += delta;
        }
        
    }
    return data;
}

const double* largest(const double data[], size_t count)
{
    if (!count) { return nullptr; }

    size_t max_index {};
    for (size_t i {1}; i < count; i++)
    {
        if (data[i] > data[max_index])
        {
            // A new maximum value has been found
            max_index = i;
        }
    }
    return &data[max_index];
}

const double* smallest(const double data[], size_t count)
{
    if (!count) { return nullptr; }

    size_t min_index {};

    for (size_t i {1}; i < count; i++)
    {
        if (data[min_index] > data[i])
        {
            // data[i] is the lowest so far
            min_index = i;
        }
    }
    return &data[min_index];    
}

int* larger(int* a, int* b)
{
    return (*a > *b) ? a : b;
}