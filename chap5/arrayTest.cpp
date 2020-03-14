// Demonstrate arrays in C++

#include <iostream>

int main () {
    
    const size_t array_size {200};
    unsigned int int_array [array_size] {}; // This initializes all values to 0

    for (size_t i {}; i < array_size; ++i) {
        int_array[i] = i;
    }

    for (size_t i {0}; i < array_size + 2000; ++i) {
        std::cout << "int_arra[" << i << "] = " << int_array[i] << "\n";
    }

    return 0;
}