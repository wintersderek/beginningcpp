#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>
#include "RandomGenerator.h"

template <typename T, typename C>
void print_set(const std::set<T, C>& values, unsigned per_line, unsigned width);

int main(int argc, char const *argv[])
{
    while (true)
    {
        std::set<int, std::greater<>> my_set{};
        RandomGenerator rg{1, 10};
        unsigned count{};
        std::cout << "Enter set size: ";
        std::cin >> count;
        
        for (size_t i{}; i < count; ++i)
        {
            int new_value {static_cast<int>(rg())};
            std::cout << "Contains " << new_value << " = " << my_set.count(new_value) << '\n';
            if (my_set.count(new_value) != 0)
            {
                std::cout << "My set (" << my_set.size() << "already contains {" 
                          << new_value << "}\n";
            }
            else
            {
                my_set.insert(new_value);
            }
        }

        print_set(my_set, 10, 4);

        unsigned char answer {};
        std::cout << "Would you like to test another set [Y/n]: ";
        std::cin >> answer;
        if (answer == 'N' || answer == 'n')
        {
            break;
        }
        else
        {
            my_set.clear();
            std::system("clear");
        }        
    }

    std::cout << std::endl;
    return 0;
}

template <typename T, typename C>
void print_set(const std::set<T, C>& values, unsigned per_line, unsigned width)
{
    unsigned line_count {};
    std::for_each(values.cbegin(), values.cend(), [line_count, per_line, width](T x) mutable {
        std::cout << std::setw(width) << x;
        if (++line_count % per_line == 0) std::cout << '\n';
    });
    std::cout << '\n';
}
