// Show how c-strings work
#include <iostream>

int main () {
    char vowels[] {'a', 'e', 'i', 'o', 'u'};
    char s_vowels[] {"aeiou"};

    std::cout << "String Vowels: " << s_vowels << std::endl;

    std::cout << "Character Vowels: " << vowels << std::endl;

}