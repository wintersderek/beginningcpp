// Show the use of bitwise compliment

#include <iostream>
#include <bitset>

int main()
{
    unsigned short value {0x0};
    unsigned short onVal {0xf};

    std::cout << "Value before turning on: " << std::bitset<16>(value) << "\n";
    value |= onVal;
    std::cout << "Value after turning on:" << std::bitset<16>(value) << "\n";
    value &= ~onVal;
    std::cout << "Value after turning off:" << std::bitset<16>(value) << "\n"; 
    return 0;
}