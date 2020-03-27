// Test the C variable array
#include <iostream>
#include <iterator>

int main () {
    size_t entry_number {};
    std::cout << "How many entries will you make:";
    std::cin >> entry_number;

    double entries[entry_number];

    for (size_t i {}; i < entry_number; i++) {
        std::cout << "Enter a value: ";
        std::cin >> entries[i];
    }

    for (size_t i {}; i < entry_number; i++) {
        std::cout << "Entry[" << i << "] = " << entries[i] << std::endl;
    }
    //std::cout << std::size(entries) << std::endl;
}