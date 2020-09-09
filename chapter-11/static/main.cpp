/*
    Showcase the usage of static members
*/ 

#include <iostream>
#include <vector>
#include "Word.h"

int main()
{
    std::cout << "Word count: " << Word::getWordCount() << "\n";
    Word my_word {"Ser", "To be", true};
    
    std::cout << "Byte size for Word: " << sizeof(Word) << "\n";

    std::vector<Word> words{};
    words.push_back(Word("Hola", "Hello"));
    words.push_back(Word("Estar", "To be", true));
        /*
        Word("Hola", "Hello"),
        Word("Estar", "To be", true),
        Word("Por eso", "that is why")
    };
    */

    std::cout << "Vector count: " << words.size() << "\n";

    std::cout << "Word count: " << Word::getWordCount() << "\n";

    std::cout << std::endl;
}