#include <iostream>

int main(){
    unsigned short number {16387};

    std::cout << "Unsigned short bytes: " << sizeof(number) << "\n";

    auto result{static_cast<unsigned short>(number << 2)}; //Shift left two bit positions

    std::cout << "Shift left 2: " << result << "\n";


    std::cout << std::endl;
    return 0;
}