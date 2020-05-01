// Demonstrate the use of c_str() of the std::string
#include <iostream>
#include <string>
#include <iomanip>

int main () {
    std::string temp_value {"This is my string."};
    std::string temp_one;  //empty string
    std::string temp_two {temp_value, 7};
    std::string temp_three {temp_value};
    std::string temp_four {temp_value, 11, 6};
    std::string temp_five (12, 'i');

    const char* values = temp_value.c_str();

    for (size_t i {}; i < temp_value.length(); ++i) {
        std::cout << values[i];
    }

    std::cout << "\n\n"
              << std::left << std::setw(15) << "NAME" 
              << std::setw(20) << "VALUE" 
              << std::right << std::setw(10) << "LENGTH" << std::endl;

    std::cout << std::left << std::setw(15) << "----------" 
              << std::setw(20) << "------------------" 
              << std::right << std::setw(10) << "-------" << std::endl;

    std::cout << std::left << std::setw(15) << "temp_value" 
              << std::setw(20) << temp_value 
              << std::right << std::setw(10) << temp_value.length() << std::endl;

    std::cout << std::left << std::setw(15) << "temp_one" 
              << std::setw(20) << temp_one
              << std::right << std::setw(10) << temp_one.length() << std::endl;

    std::cout << std::left << std::setw(15) << "temp_two" 
              << std::setw(20) << temp_two
              << std::right << std::setw(10) << temp_two.length() << std::endl;

    std::cout << std::left << std::setw(15) << "temp_three" 
              << std::setw(20) << temp_three
              << std::right << std::setw(10) << temp_three.length() << std::endl;

    std::cout << std::left << std::setw(15) << "temp_four" 
              << std::setw(20) << temp_four
              << std::right << std::setw(10) << temp_four.length() << std::endl;

    std::cout << std::left << std::setw(15) << "temp_five" 
              << std::setw(20) << temp_five
              << std::right << std::setw(10) << temp_five.length() << std::endl;


    std::cout << std::endl;
    return 0;
}