/* 
    Dynamically allocate an array of float based off user input size.
        - should use a smart pointer to hold array.
        - using pointer notation, set each value in the array to 1/(n+1)pow2
        - calculate the sum of the elements using array notation, multiply
          the sum by 6, and output the square root of the result.
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <memory>

int main () {
    size_t array_size {};
    std::cout << "What size of array would you like? ";
    std::cin >> array_size;

    auto p_values {std::make_unique<double[]>(array_size)};

    // Set all values to 1 / (n + 1) squared
    for (size_t i {}; i < array_size; ++i){
        p_values[i] = 1.0 / (std::pow(i + 1.0, 2));
    }

    double sum {};
    for (size_t i {}; i < array_size; ++i){
        sum += p_values[i];
    }

    std::cout << std::left;
    std::cout << std::setw(10) << "Sum:" << std::setprecision(15) 
              << sum << std::endl;
    std::cout << std::setw(10) << "Result:" << std::setprecision(15)
              << std::sqrt(sum * 6.0) << std::endl;

    return 0;
}