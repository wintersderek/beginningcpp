// Count the whitespace characters in a line up to the first #
#include <iostream>

int main () {
    size_t max_size {1000};
    char values[max_size] {};
    unsigned int count {};
    
    std::cout << "Enter a line of text: ";
    std::cin.getline(values, max_size);

    for(auto i : values) {
        if (i != '\0') {
            ++count;
        }
    }

    std::cout << "Characters Entered: " << count << std::endl;

    for(size_t i {count - 1}; i < count; --i) {
        std::cout << values[i];
    }

    std::cout << std::endl;

    return 0;
}