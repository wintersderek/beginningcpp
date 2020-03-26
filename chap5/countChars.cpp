// Count the whitespace characters in a line up to the first #
#include <iomanip>
#include <iostream>
#include <cctype>

int main () {
    size_t max_size {1000};
    char values[max_size] {};
    unsigned int count {};
    const char end {'#'};

    std::cout << "Enter a line of text: ";
    std::cin.getline(values, max_size);

    for(auto i : values) {
        if (!std::isspace(i) && std::isprint(i)) {
            ++count;
            if (i == end)
                break;
        }
    }

    std::cout << "Non whitespace characters: " << count << std::endl;

    return 0;
}