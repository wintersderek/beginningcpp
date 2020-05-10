/*
Chapter 7, Exercise 5: Determine words that begin with letters
    - Accept an arbitrary amount of text
    - Accept a list of letters
    - Determine and display all words in text that begin with the letters
    - Case insensitve comparison
*/

#include <iostream>
#include <string>
#include <cctype>

int main ()
{
    std::string text {};
    std::string letters {};

    std::cout << "Enter analysis text terminated with ^:\n";
    std::getline(std::cin, text, '^');
    std::cout << "Enter first char letters: ";
    std::cin >> letters;

    // Get case-insensitive letters to look for
    std::string case_agnostic_letters {letters};
    for (auto& ch : letters)
    {
        if (std::isalpha(ch))
        {
            case_agnostic_letters += (std::islower(ch))? std::toupper(ch) :
                std::tolower(ch);
        }
    }

    std::string delimiters {" \".,';:?!*#\n\t"};
    size_t start {text.find_first_not_of(delimiters)};

    while (start != std::string::npos)
    {
        size_t end {text.find_first_of(delimiters, (start + 1))};
        if (end == std::string::npos)
        {
            end = text.length();
        }

        if (case_agnostic_letters.find(text[start]) != std::string::npos)
        {
            std::cout << text.substr(start, (end - start)) << std::endl;
        }

        start = text.find_first_not_of(delimiters, (end + 1));
    }

    return 0;
}