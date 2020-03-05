// Demonstrate using an int to hold 4 char values
#include <iostream>
#include <iomanip>

int main ()
{
    unsigned int value {};
    unsigned char char_value {};
    unsigned int forth_mask  {0xff000000};
    unsigned int third_mask  {0x00ff0000};
    unsigned int second_mask {0x0000ff00};
    unsigned int first_mask  {0x000000ff};

    // Ask for the first character
    std::cout << std::left << std::setw(28) << "Enter first character: ";
    std::cin >> char_value;
    // Put the character into the high byte
    value = char_value << 24;

    // Ask for the second character
    std::cout << std::setw(28) << "Enter second character: ";
    std::cin >> char_value;
    value = value | (char_value << 16);

    // Ask for the third character
    std::cout << std::setw(28) << "Enter the third character: ";
    std::cin >> char_value;
    value = value | (char_value << 8);

    // Ask for the forth character
    std::cout << std::setw(28) << "Enter the forth character: ";
    std::cin >> char_value;
    value = value | char_value;

    // Output the value as hexidecimal
    std::cout << std::right << std::hex << std::showbase 
              << std::setfill('0') << "Value is: " << value << "\n";

    // Output the characters in reverse order
    std::cout << (static_cast<char>(value & first_mask)) << "\n"
              << (static_cast<char>((value & second_mask) >> 8)) << "\n"
              << (static_cast<char>((value & third_mask) >> 16)) << "\n"
              << (static_cast<char>((value & forth_mask) >> 24)) << std::endl;

    return 0;
}