// Showcase array pointers
#include <iostream>
#include <iomanip>

int main () {
    float values[10] {};
    float* pvalues {values};

    std::cout << std::left;
    std::cout << std::setw(25) << "Output array name: " 
              << std::setw(20) << values << "\n"
              << std::setw(25) << "Output & array name: " 
              << std::setw(20) << &values << std::endl;

    std::cout << "Use pointer arithmetic to fill an array" << std::endl;
    for (size_t i {0}; i < std::size(values); ++i) {
        *pvalues = i + 0.2;
        if (i < std::size(values) - 1) {
            ++pvalues;
        }
    }

    for(auto i : values) {
        std::cout << i << std::endl;
    }
    return 0;
}