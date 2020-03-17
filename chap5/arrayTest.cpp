// Demonstrate arrays in C++

#include <iostream>

int main () {
    
    const size_t array_size {200};
    unsigned int int_array [array_size] {}; // This initializes all values to 0

    std::cout << "Size of array_size: " << std::size(int_array) << "\n";
    
    for (size_t i {}; i < std::size(int_array); ++i) {
        int_array[i] = i;
    }

    std::cout << "(sizeof(int_array)/sizeof(int_array[0])) = "
              << (sizeof(int_array)/sizeof(int_array[0])) << "\n";

    return 0;
}