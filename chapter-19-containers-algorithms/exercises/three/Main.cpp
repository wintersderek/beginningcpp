/*
Exercise 19-3. Rework your solution to Exercise 16-6 by replacing all instances
    of your SparseArray<> and linked list template types with standard 
    containers. Carefully think about which container types would be most 
    appropriate!

    It was a sparse array of characters containing a doubly linked list of 
    strings.  For example x[0] = "at", "amazone", etc. and x[1] = "bee", "be"

    This would be best served as an std::map<std::pair<unsigned char, 
    std::vector<std::string>>>.  Where the key of the map is an unsigned char
    and the value of the map is an std::vector<std::string>.
*/

#include <cctype>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

using SparseArray = std::map<unsigned char, std::vector<std::string>>;

SparseArray fill_data_array();

std::string_view get_user_data();

int main(int argc, char const *argv[])
{
    SparseArray values = fill_data_array();

    for (const auto& [key, value] : values)
    {
        std::cout << key << ": ";
        for (const auto& v : value)
        {
            std::cout << v << ' ';
        }
        std::cout << '\n';
    }

    std::cout << std::endl;
    return 0;
}

SparseArray fill_data_array()
{
    SparseArray result;
    // Get the data from the user
    const char *delimiters{" .;!?,[]()*&^$#@~\\\n\r"};
    std::string user_data{get_user_data()};

    size_t start{}, end {};

    while (std::string::npos != (start = user_data.find_first_not_of(delimiters, end)))
    {
        end = user_data.find_first_of(delimiters, start);
        if (end == std::string::npos)
            end = user_data.length();

        result[static_cast<unsigned char>(std::tolower(user_data[start]))].push_back(
            std::string(user_data.substr(start, end - start))
        );
    }
    return result;
}

std::string_view get_user_data()
{
    std::string data;
    std::cout << "Enter the data for the SparseArray.  When you are finished "
              << "enter %:\n";
    std::getline(std::cin, data, '%');
    std::cout << "Data Entered: " << data << '\n';
    return data;
}