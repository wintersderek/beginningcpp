/*
Show how std::find() and std::find_if work
*/
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include "../RandomGenerator.h"

void show_find(const std::vector<std::string>& values);
void show_find_if(const std::vector<std::string>& values);

template <typename T>
void printVector(const std::vector<T>& values, unsigned width, unsigned perline)
{
    size_t i {};
    for(const auto& x : values)
    {
        std::cout << std::setw(width) << x;
        if (++i % perline == 0)
            std::cout << '\n';
    }
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> values = getCharStrings(50);

    std::cout << std::left;
    printVector(values, 12, 5);

    /*  Show how std::find() works */
    show_find(values);
    
    /*  Show how std::find_if() works */
    show_find_if(values);


    std::cout << std::endl;
    return 0;
}

void show_find(const std::vector<std::string>& values)
{
    do
    {
        std::string match;
        std::cout << "\nEnter a value to find: ";
        std::cin >> match;
        std::cin.ignore();
        auto it = std::find(values.cbegin(), values.cend(), match);
        if (it != values.cend())
        {
            std::cout << *it << " was found at the "
                      << (it - values.cbegin() + 1) << " position\n";
        }
        else
        {
            std::cout << match << " was not found\n";
            break;
        }
    } while (true);
}

void show_find_if(const std::vector<std::string>& values)
{
    do
    {
        unsigned char needle;
        std::cout << "Enter a character for string to begin with: ";
        std::cin >> needle;
        std::cin.ignore();

        auto compare = [needle](std::string_view x) { return x[0] == needle; };

        auto it = std::find_if(values.cbegin(), values.cend(), compare);
        while (it != values.cend())
        {
            std::cout << *it << " found at position " << (it - values.cbegin()) << '\n';
            it = std::find_if(++it, values.cend(), compare);
        }

        std::cout << "Run again? [y/n]: ";
        std::cin >> needle;
        std::cin.ignore();
        if (!(needle == 'y')) break;
    } while (true);
}
