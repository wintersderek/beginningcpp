// Print the square of all odd numbers from 1 to a values entered by
// the user.

#include <iostream>
#include <iomanip>

int main() {
    unsigned int value {};

    // Ask user for a positive integer
    while (!value){
        std::cout << "Enter a positive integer: ";
        std::cin >> value;
    }

    // Print each odd number and its square value, up to the number entered
    //     Number           Square
    // ----------       ----------
    std::cout << std::setw(10) << "Number" << std::setw(5) << " "
              << std::setw(15) << "Square" << "\n"
              << std::setw(10) << "----------" << std::setw(5) << " "
              << std::setw(15) << "---------------" << std::endl;

    for(size_t i {1}; i <= value; ++i){
        if ((i % 2) != 0) {
            std::cout << std::setw(10) << i << std::setw(5) << " "
                      << std::setw(15) << (i*i) << std::endl;
        }
    } 
    return 0;
}