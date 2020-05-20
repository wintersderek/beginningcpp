// Display the size of a pointer on the system

#include <iostream>
#include <iomanip>

int main () {
    std::cout << std::setw(20) << "Type"
              << std::setw(10) << "Pointer"
              << std::setw(10) << "Actual"
              << "\n"
              << std::setw(20) << "--------"
              << std::setw(10) << "--------"
              << std::setw(10) << "--------"
              << "\n"
              << std::setw(20) << "char"
              << std::setw(10) << sizeof(char*)
              << std::setw(10) << sizeof(char)
              << "\n"
              << std::setw(20) << "unsigned char"
              << std::setw(10) << sizeof(unsigned char*)
              << std::setw(10) << sizeof(unsigned char)
              << "\n"
              << std::setw(20) << "short"
              << std::setw(10) << sizeof(short*)
              << std::setw(10) << sizeof(short)
              << "\n"
              << std::setw(20) << "unsigned short"
              << std::setw(10) << sizeof(unsigned short*)
              << std::setw(10) << sizeof(unsigned short)
              << "\n"
              << std::setw(20) << "int"
              << std::setw(10) << sizeof(int*)
              << std::setw(10) << sizeof(int)
              << "\n"
              << std::setw(20) << "unsigned int"
              << std::setw(10) << sizeof(unsigned int*)
              << std::setw(10) << sizeof(unsigned int)
              << "\n"
              << std::setw(20) << "float"
              << std::setw(10) << sizeof(float*)
              << std::setw(10) << sizeof(float)
              << "\n"
              << std::setw(20) << "long"
              << std::setw(10) << sizeof(long*)
              << std::setw(10) << sizeof(long)
              << "\n"
              << std::setw(20) << "double"
              << std::setw(10) << sizeof(double*)
              << std::setw(10) << sizeof(double)
              << "\n"
              << std::setw(20) << "long long"
              << std::setw(10) << sizeof(long long*)
              << std::setw(10) << sizeof(long long)
              << "\n";

    return 0;
}