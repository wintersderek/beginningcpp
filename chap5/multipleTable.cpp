/* Attempt to create a multiplication table in C++.  It should require a
   user to enter a value between 2 and 20.  Then print out a multiplication
   table for the values 1-to-n.
*/

#include <iostream>
#include <cctype>
#include <iomanip>

int main () {
    unsigned int table_size {};
    const unsigned int min_size {2};
    const unsigned int max_size {15};
    char answer {};
    const char yes {'y'};

    do {
        std::cout << "Enter the multiplication table size (2 - 15): ";
        std::cin >> table_size;

        if (table_size >= min_size && table_size <= max_size) {
            // Print the multiplication table Header
            std::cout << std::setw(5) << "|";
            for (size_t i {1}; i <= table_size; ++i){
                std::cout << std::setw(3) << i << std::setw(2) << "|"; 
            }
            std::cout << std::endl;

            // Print the multiplication table Separator
            for (size_t i {0}; i <= table_size; ++i){
                std::cout << "-----";
            }
            std::cout << std::endl;

            // Print each line in the multiplication table
            for (size_t i {1}; i <= table_size; ++i) {
                std::cout << std::setw(3) << i << std::setw(2) << "|";

                for (size_t j {1}; j <= table_size; ++j) {
                    std::cout << std::setw(3) << (i * j) << std::setw(2) << "|";
                }
                
                std::cout << std::endl;
            }


        } else {
            // User did ont enter a value range
            std::cout << "Only values between " << min_size << " and "
                      << max_size << " are allowed!" 
                      << std::endl;
        }

        std::cout << "Would you like to print another multiplication table"
                  << " (y/n)? " << std::endl;
        std::cin >> answer;

    } while (std::tolower(answer) == yes);

    return 0;
}