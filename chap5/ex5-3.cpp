#include <iostream>
#include <cctype>

int main () {
    char value {};
    const char quit {'#'};
    unsigned int count {};
    
    std::cout << "Enter some text: ";

    do {
        std::cin >> value;
        if (!std::isspace(value)) {
            ++count;
        }
    } while (value != quit);

    --count;
    std::cout << "Total Chars: " << count << std::endl;    
}