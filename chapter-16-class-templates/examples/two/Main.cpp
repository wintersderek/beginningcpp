#include <iomanip>
#include <iostream>
#include "Array.h"
#include "Box.h"

int main(int argc, char* argv[])
{
    try
    {
        const size_t num_values {50};
        Array<double> values {num_values};

        for (size_t i {0}; i < num_values; ++i)
        {
            values[i] = i + 1;
        }

        std::cout << "Sums of pairs of elements:";
        size_t lines {};
        for (size_t i {num_values - 1}; i >= 0; --i)
        {
            std::cout << (lines++ % 5 == 0 ? "\n" : "") << std::setw(5)
                      << values[i] + values[i - 1];
        }
    }
    catch(const std::out_of_range& ex)
    {
        std::cerr << "out_of_range caught: " << ex.what();
    }

    try
    {
        const size_t num_values{10};
        Array<Box> values {num_values};
        for (size_t i {}; i <= num_values; ++i)
        {
            std::cout << "Box volume is " << values[i].volume() << '\n';
        }
    }
    catch(const std::out_of_range& ex)
    {
        std::cerr << "out_of_range caught: " << ex.what() << '\n';
    }

    std::cout << std::endl;
    return EXIT_SUCCESS;
}