/*
1. Ask user for character.
2. Use a library function to determine if the letter is a lower case vowel.
3. Output the lower case value with its binary character code.
*/

#include <iostream>
#include <cctype>

enum class vowels {
    a = 'a', e = 'e', i = 'i', o = 'o', u = 'u'
};

int main () {
    char in_char {0};
    std::cout << "Enter a character: ";
    std::cin >> in_char;

    if (std::isalpha(in_char) && std::islower(in_char) &&
            (in_char == static_cast<char>(vowels::a) || 
             in_char == static_cast<char>(vowels::e) || 
             in_char == static_cast<char>(vowels::i) || 
             in_char == static_cast<char>(vowels::o) || 
             in_char == static_cast<char>(vowels::u))){
        std::cout << "\nThe character is a lower case vowel.";
    }

    std::cout << "\n\n" << in_char << " - 0b"
              << static_cast<int>((in_char >> 7 & 1)) 
              << static_cast<int>((in_char >> 6 & 1))
              << static_cast<int>((in_char >> 5 & 1))
              << static_cast<int>((in_char >> 4 & 1))
              << static_cast<int>((in_char >> 3 & 1))
              << static_cast<int>((in_char >> 2 & 1))
              << static_cast<int>((in_char >> 1 & 1))
              << static_cast<int>((in_char & 1))
              << std::endl;

    return 0;
}