/*
Verify the compiler only creates a single template per type.
*/

#include <iostream>
#include <string>

template <typename T> T larger(const T a, const T b);

int main ()
{
    std::cout << "int: " << larger(1, 4) << "\n";
    std::cout << "double: " << larger(2.5, 1.7) << "\n";
    std::cout << "double two: " << larger(12.5, 100.7) << "\n";
    std::cout << "char: " << larger('f', 'a') << "\n";

    std::string a_string {"A"}, z_string {"Z"};
    std::cout << "std::string: " << larger(a_string, z_string); 
    std::cout << std::endl;
    return 0;
}

template <typename T> T larger(const T a, const T b)
{
    static size_t count {};
    std::cout << "Count: " << ++count << "\n";
    return (a > b) ? a : b;
}