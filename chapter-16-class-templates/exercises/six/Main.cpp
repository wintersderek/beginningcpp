#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include "DoubleLinkedList.h"
#include "Main.h"
#include "SparseArray.h"


int main(int argc, char const *argv[])
{
    SparseArray<DoubleLinkedList<std::string>> values;

    fill_data_array(values);

    for (size_t i {}; i < index_limit; ++i)
    {
        if (values.element_exists_at(i))
        {
            // Print the letter
            std::cout << sparse_map[i] << ": ";

            // Print each word
            auto it {values[i].get_forward_iterator()};
            while (it)
            {
                std::cout << it.value() << ' ';
                it.move_next();
            }
            std::cout << '\n';
        }
    }

    std::cout << std::endl;
    return 0;
}

void fill_data_array(SparseArray<DoubleLinkedList<std::string>> &values)
{
    // Get the data from the user
    const char* delimiters {" .;!?,[]()*&^$#@~\\\n\r"};
    std::string user_data {get_user_data()};

    size_t start {user_data.find_first_not_of(delimiters, 0)};

    if (start != std::string::npos)
    {
        size_t end{user_data.find_first_of(delimiters, start)};

        while (end != std::string::npos)
        {
            std::string temp{user_data.substr(start, (end - start))};
            values[get_array_index(temp[0])].push_back(temp);

            start = user_data.find_first_not_of(delimiters, (end + 1));
            if (start == std::string::npos)
            {
                break;
            }

            end = user_data.find_first_of(delimiters, start);
        }

        if (start != std::string::npos)
        {
            std::string temp {user_data.substr(start, user_data.length() - start)};
            values[get_array_index(user_data[0])].push_back(temp);
        }
    }
}

size_t get_array_index(char lookup)
{
    if (!std::isalpha(lookup))
    {
        throw std::domain_error("Character " + std::string(1, lookup) +
                                " is not a supported index");
    }

    lookup = std::tolower(lookup);
    size_t index{alphabet.find_first_of(lookup)};
    if (index == std::string::npos)
    {
        throw std::out_of_range(std::string("Character ") + 
                std::string(1, lookup) + 
                " does not have an index");
    }
    return index;
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