// Perform a bubble sort using an std::vector<t>

#include <iostream>
#include <vector>

int main () {
    std::vector<double> values;
    bool continue_loop {true};

    while (continue_loop) {
        double value {};
        std::cout << "Enter a value, or nothing to end input: ";
        std::cin >> value;
        if (value == 0) {
            continue_loop = false;
        } else {
            values.push_back(value);
        }
    }

    if (values.empty()) {
        std::cout << "Nothing to sort." << std::endl;
        return 0;
    }

    continue_loop = true;
    while (continue_loop) {
        continue_loop = false;
        for (size_t i {}; i < (values.size() - 1); ++i) {
            if (values[i] > values[i + 1]) {
                double temp = values[i];
                values[i] = values[i + 1];
                values[i + 1] = temp;
                continue_loop = true;
            }
        }
    }

    for (size_t i {}; i < values.size(); ++i) {
        std::cout << values[i] << std::endl;
    }
    
    return 0;
}