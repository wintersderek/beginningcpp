// Demonstrate an array<T,N>
#include <iostream>
#include <array>

int main () {
    const size_t entries {10};
    const double increment {0.2};
    std::array<double, entries> values;

    values.fill(0.0);
    std::cout << "Array Size: " << values.size() << std::endl;
    
    // Fill the array with other values
    for (size_t i {}; i < values.size(); ++i) {
        values.at(i) = i + increment;
    }

    std::cout << "Values: " << std::endl;

    for (auto i : values) {
        std::cout << "\t" << i << std::endl;    
    }
    return 0;
}