// Demonstrate the use of XOR ^
#include <iostream>

int main()
{
    unsigned short bitTwo {1u << 1}; //0b0010
    unsigned short value {0x0};

    std::cout << "Value before bit flip: " << value << "\n";
    value ^= bitTwo;
    std::cout << "Value after bit flip: " << value << "\n";
    value ^= bitTwo;
    std::cout << "Final flip value: " << value << "\n";
    return 0;
}