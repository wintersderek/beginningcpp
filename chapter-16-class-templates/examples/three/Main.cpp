#include <iomanip>
#include <iostream>
#include <typeinfo>
#include "Array.h"
#include "Box.h"

int main(int argc, char* argv[])
{
    try
    {
        const size_t num_values {21};
        const int min_index {-10};
        const int max_index {
            min_index + (static_cast<int>(num_values) - 1)
        };

        Array<double, min_index> values {num_values};

        for (int i {min_index}; i <= max_index; ++i)
        {
            values[i] = i + 1;
        }

        std::cout << "Sums of pairs of elements:";
        size_t lines {};
        for (int i {max_index}; i >= min_index; --i)
        {
            std::cout << (lines++ % 5 == 0 ? "\n" : "") << std::setw(5)
                      << values[i] + values[i - 1];
        }
    }
    catch(const std::out_of_range& ex)
    {
        std::cerr << "\nout_of_range caught: " << ex.what() << '\n';
    }

    try
    {
        const size_t num_values{11};
        const int start {};
        Array<Box, (start - 5)> values {num_values};
        for (size_t i {start}; i <= (start + static_cast<int>(num_values) - 5); ++i)
        {
            std::cout << "Box volume is " << values[i].volume() << '\n';
        }
    }
    catch(const std::exception& ex)
    {
        std::cerr << '\n' << typeid(ex).name() << " - out_of_range caught: " 
                  << ex.what() << '\n';
    }

    std::cout << std::endl;
    return EXIT_SUCCESS;
}