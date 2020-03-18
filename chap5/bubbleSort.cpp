// Perform the bubble sort on with random numbers
#include <iostream>
#include <random>
#include <iomanip>

int main () {
    std::mt19937 gen;
    const unsigned int array_size {10};
    unsigned int my_array[array_size] {};

    
    //std::cout << "First number: " << gen() << std::endl;
    for(size_t i {}; i < std::size(my_array); ++i) {
        gen.seed(i);
        my_array[i] = gen();
    }

    while (true) {
        bool swapped {};
        for (size_t i {0}; i < std::size(my_array) - 1; ++i) {
            if (my_array[i] > my_array[i+1]) {
                auto temp = my_array[i];
                my_array[i] = my_array[i + 1];
                my_array[i + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }

    for (size_t i {0}; i < std::size(my_array); ++i) {
        std::cout << std::setw(20) << my_array[i] << std::endl;
    }
    return 0;
}