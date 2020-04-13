// Create an array an initialize it with the first 50 odd numbers.
// Print out the array using pointer notation (10 to line), and then
// print out in reverse order using pointer notation (10 to a line).

#include <iostream>
#include <iomanip>

int main () {
    const size_t array_size {50};
    int* vars { new int[array_size] };
    int index {};
    int number {};

    // Fill array with odd numbers
    while (index < array_size) {
        if (number % 2 != 0){
            *(vars + index++) = number;
        }
        ++number;
    }

    std::cout << std::left;

    // Print array 10 to a line using pointer notation
    for(size_t i {}; i < array_size; ++i){
        std::cout << std::setw(5) << *vars++;
        if ((i + 1) % 10 == 0) {
            std::cout << std::endl;
        }

    }

    std::cout << std::endl;

    // Print reverse array 10 to a line using pointer notation
    for (size_t i {1}; i <= array_size; ++i) {
        std::cout << std::setw(5) << *(--vars);
        if (i % 10 == 0){
            std::cout << std::endl;
        }
    }
    return 0;

    delete[] vars;
    vars = nullptr;
}