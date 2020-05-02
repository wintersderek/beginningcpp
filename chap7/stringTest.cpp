// Miscellaneous string functions

#include <iostream>
#include <string>
#include <cctype>

void list_options()
{
    std::cout << "Chose number for string tests:\n"
              << "------------------------------\n"
              << "\t1 - Substring"
              << std::endl
              << std::endl; 
}

void substring_test(std::string& whole) 
{
    size_t start {};
    size_t number {};

    std::cout << "Enter start index: ";
    std::cin >> start;
    std::cout << "Enter number of characters: ";
    std::cin >> number;

    if (start < whole.length())
    {
        std::cout << "Substring: " 
                  << whole.substr(start, number);
    } else {
        std::cerr << "Start exceeds string length " + std::to_string(whole.length())
                  << std::endl;
    }

    std::cout << std::endl;
}

void execute_option(std::string& test_string)
{
    size_t option {};
    std::cin >> option;

    switch (option)
    {
    case 1:
        substring_test(test_string);
        break;
    
    default:
        break;
    }
}

int main ()
{
    std::string text;
    char answer {};

    std::cout << "Enter test text:\n";
    std::getline(std::cin, text, '^');
    std::cout << std::endl;

    do
    {
        list_options();
        execute_option(text);
        std::cout << "Would you like to continue [Y/n]:";
        std::cin >> answer;
    } while (std::tolower(answer) == 'y');
    
    return 0;
}