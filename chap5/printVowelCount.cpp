// Determine the number of vowels in an input string
#include <iostream>
#include <iterator>
#include <cctype>

int main () {
    const char vowel[] = {'a', 'e', 'i', 'o', 'u'};
    const int max_length {100};
    char text[max_length] {};
    size_t vowel_count {0};
    
    std::cout << "Enter a line of text:" << std::endl;

    // Read a line of text up to the max length
    std::cin.getline(text, max_length);

    std::cout << "You entered:\n" << text << std::endl;

    // Count the number of vowels in the text
    for(size_t i {}; i < std::size(text); ++i) {
        
        if (std::isalpha(text[i])) {
            std::cout << "Text: " << text[i] << std::endl;

            for (size_t j {}; j < std::size(vowel); ++j) {
                if (text[i] == vowel[j]) {
                    std::cout << "\ttext[" << i << "](" << text[i] << ") = "
                            << "vowel[" << j << "](" << vowel[j] << ")"
                            << std::endl;
                    ++vowel_count;
                    break;
                }
            }
        }
    }

    std::cout << "The number of vowels: " << vowel_count << std::endl;
}