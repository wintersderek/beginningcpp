/*
Chapter 7 Exercise 3: replace words in text with astrik version.
    - Accept an arbitrary length of text
    - Accept a word to replace.
    - Case-insensitively replace all whole words found with the same
      number of characters of astrik
    - Output the new string
*/

#include <iostream>
#include <string>
#include <cctype>

int main () 
{
    std::string entered_text {};
    std::cout << "Enter some text to analyse.  Terminate with ^\n";
    std::getline(std::cin, entered_text, '^');

    std::string to_replace {};
    std::cout << "Enter a word to be replaced: ";
    std::cin >> to_replace;
    std::string replacement (to_replace.length(), '*');

    // Update to_replace to lower case
    for (auto& c : to_replace)
    {
        c = std::tolower(c);
    }

    std::string word_delimiters {" ,.?!'\"()\n"};

    size_t start {entered_text.find_first_not_of(word_delimiters)};

    while (start != std::string::npos)
    {
        // Find the end of the word
        size_t end {entered_text.find_first_of(word_delimiters, start)};
        if (end == std::string::npos)
        {
            end = entered_text.length();
        }

        //Get the compare string
        std::string compare {entered_text.substr(start, (end-start))};
        for (auto&ch : compare)
        {
            ch = std::tolower(ch);
        }

        // Determine if the word is what we need to replace
        if (compare == to_replace)
        {
            entered_text.replace(start, (end-start), replacement);
        }

        start = entered_text.find_first_not_of(word_delimiters, (end + 1));
    }

    std::cout << "\n\n" << entered_text << std::endl;

    return 0;
}