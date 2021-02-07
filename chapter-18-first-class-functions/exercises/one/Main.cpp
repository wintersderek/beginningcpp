/*
Exercise 18-1. Define and test a lambda expression that returns the number of
elements in a vector<string> container that begin with a given letter.
*/
#include <iostream>
#include <string>
#include <vector>

auto add_string {[](std::vector<std::string>& container){
    std::cout << "Enter a string: ";
    std::string new_value;
    std::cin >> new_value;
    container.push_back(new_value);
}};

int main(int argc, const char* argv[])
{
    std::vector<std::string> values;
    add_string(values);

    while (values.back() != "end")
    {
        add_string(values);
    }

    char needle;
    std::cout << "Enter a character to search for: ";
    std::cin >> needle;

    auto words {[needle, &values]() {
        unsigned count {0};
        for(size_t i {}; i < values.size(); ++i)
        {
            if (values[i][0] == needle)
                ++count;
        }
        return count;
    }};
    std::cout << "There are " << words() << " words beginning with the letter "
              << needle << std::endl;
    return EXIT_SUCCESS;
}