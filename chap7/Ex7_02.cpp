// Iterate a string to determine number of consanants and vowels

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

int main() {
    std::string text;

    std::cout << "Enter a line of text: ";
    std::getline(std::cin, text);

    int consonants {};
    int vowels {};

    for (size_t i {}; i < text.length(); ++i) {
        if (std::isalpha(text[i])) {
            switch (std::tolower(text[i]))
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                ++vowels;
                break;
            
            default:
                ++consonants;
                break;
            }
        }
    }

    std::cout << std::left << std::setw(8) << "Vowels"
              << std::setw(10) << "Consonants" << "\n"
              << std::setw(8) << vowels << std::setw(10) << consonants 
              << std::endl;

    return 0;
}