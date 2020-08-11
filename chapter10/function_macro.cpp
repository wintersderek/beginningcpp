/*
Demonstrate the usage of the function macro
*/

#include <iostream>

#define MAX(A, B) (A > B ? A : B)

int main ()
{
    std::cout << "MAX(5, 7): " << MAX(5, 7) << "\n";
    std::cout << "MAX(3.14, 1.6): " << MAX(3.14, 1.6) << "\n";
    std::cout << "MAX('a', 'Z'): " << MAX('a', 'Z') << "\n";

}