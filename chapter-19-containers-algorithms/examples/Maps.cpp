/*
Showcase the functionality of the standard library maps.
*/

#include <iomanip>
#include <iostream>
#include <map>
#include <string>

using SMap = std::map<std::string, int>;

SMap fill_map();
void print_map(const SMap& values);

int main(int argc, char const *argv[])
{
    std::map<std::string, int> my_values = fill_map();
    
    unsigned char answer;

    do
    {
        std::string test;
        std::cout << "Enter a key to test: ";
        std::getline(std::cin, test);

        auto test_result = my_values.find(test);
        if (test_result != my_values.cend())
        {
            std::cout << test_result->first << " = " << test_result->second << '\n';
        }
        else
        {
            std::cout << test << " is not in the map.\n";
        }

        std::cout << "Test the map again [Y/n]? ";
        std::cin >> answer;
        std::cin.ignore();
    } while (!(answer == 'N' || answer == 'n'));
    
    print_map(my_values);
    std::cout << std::endl;
    return 0;
}

void print_map(const SMap& values)
{
    std::cout << std::left;
    /* print the values */
    for(const auto& [key, value] : values)
    {
        std::cout << std::setw(10) << key << value << '\n';
    }
}

SMap fill_map()
{
    SMap result {};
    unsigned char answer{};

    do
    {
        std::cout << "Enter the key: ";
        std::string temp;
        std::getline(std::cin, temp);
        std::cin.clear();
        std::cout << "Enter the value: ";
        int temp_int {};
        std::cin >> temp_int;

        result[temp] = temp_int;

        std::cout << "Enter another user name [Y/n]? ";
        std::cin >> answer;
        std::cin.ignore();
    } while (!(answer == 'N' || answer == 'n'));
    return result;
}