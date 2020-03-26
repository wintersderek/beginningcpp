// See what happens when you use std::cin for an int, but provide a char or
// a string.
#include <iostream>

int main () {
    int my_var {};

    std::cout << "Enter an integer: " << std::endl;

    std::cin >> my_var;

    std::cout << "You entered: " << my_var << std::endl;
    
    return 0;
}