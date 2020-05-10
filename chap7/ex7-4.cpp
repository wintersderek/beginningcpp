/*
Exercise 7-4: determine if 2 words are anagrams
    - Prompt the user for two words
    - Determine if the 2 words are anagrams
        - both words contain the same number of letters
        - both words contain the same letters
    - Output statement of anagram-ness
*/
#include <iostream>
#include <string>
#include <cctype>

std::string sanatize_string (std::string& value);

int main ()
{
    std::string one {};
    std::string two {};
    
    std::cout << "Enter the first word: ";
    std::getline(std::cin, one);
    
    std::cout << "Enter the second word: ";
    std::getline(std::cin, two);

    std::string one_lower {sanatize_string(one)};
    std::string two_lower {sanatize_string(two)};

    bool anagrams {false};

    if (one_lower.length() == two_lower.length())
    {
        anagrams = true;

        for (auto& ch : one_lower)
        {
            if (std::isalpha(ch))
            {
                size_t found = two_lower.find_first_of(ch);
                if (found != std::string::npos)
                {
                    two_lower.erase(found, 1);
                }
                else
                {
                    anagrams = false;
                    break;
                }
            }
        }
    }

    // Print results of anagram-ness
    std::cout << one << " & " << two << " are " << (anagrams? "": "not ")
              << "anagrams." << std::endl;
    return 0;
}

std::string sanatize_string (std::string& value)
{
    // lower case
    std::string result;
    for (auto& ch : value)
    {
        if (ch != ' ')
        {
            result += std::tolower(ch);
        }
    }
    return result;
}