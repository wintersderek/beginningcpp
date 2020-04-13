/* 
    Dynamically allocate an array of float based off user input size.
        - using pointer notation, set each value in the array to 1/(n+1)pow2
        - calculate the sum of the elements using array notation, multiply
          the sum by 6, and output the square root of the result.
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main () {
    size_t array_size {};
    std::cout << "What size of array would you like? ";
    std::cin >> array_size;

    float* values { new float[array_size] };

    // Set all values to 1 / (n + 1) squared
    for (size_t i {}; i < array_size; ++i){
        *(values + i) = 1.0 / (std::pow(i + 1.0, 2));
    }

    double sum {};
    for (size_t i {}; i < array_size; ++i){
        sum += values[i];
    }

    std::cout << std::left;
    std::cout << std::setw(10) << "Sum:" << std::setprecision(15) 
              << sum << std::endl;
    std::cout << std::setw(10) << "Result:" << std::setprecision(15)
              << std::sqrt(sum * 6.0) << std::endl;

    delete[] values;
    values = nullptr;
    return 0;
}