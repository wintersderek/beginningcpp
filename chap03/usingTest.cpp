// Demonstrate how keyword using works

#include <iostream>

int main()
{
    using BigInt = unsigned long long;

    BigInt bi {4};

    std::cout << "Bytes in BigInt: " << sizeof(bi) << "\n"
              << "Value of BigInt: " << bi << std::endl;

    return 0;
}