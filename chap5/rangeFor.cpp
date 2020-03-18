// Attempt to demonstrate the ranged for loop
#include <iostream>
#include <iterator>
#include <iomanip>

int main () {
    const unsigned int number {40};
    unsigned int values[number] {};
    unsigned int sum {};
    unsigned long long factorial {1ull};

    for (size_t i {0}; i < std::size(values); ++i) {
        values[i] = i + 1;
    }

    // Print out the columns
    std::cout << std::setw(10) << "Integer"
              << std::setw(10) << "Sum"
              << std::setw(40) << "Factorial" << "\n"
              << std::setw(10) << "-------"
              << std::setw(10) << "---"
              << std::setw(40) << "-----------" << "\n";

    
    for (auto i : values) {
        sum += i;
        factorial *= i;

        std::cout << std::setw(10) << i
                  << std::setw(10) << sum
                  << std::setw(40) << factorial << "\n";
    }

    std::cout << std::endl;

    return 0;
}