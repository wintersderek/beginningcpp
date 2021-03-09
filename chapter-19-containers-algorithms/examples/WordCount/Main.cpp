/*
Count the different words in a string
*/

#include <iomanip>
#include <iostream>
#include "Words.h"

int main(int argc, char const *argv[])
{
    //std::string_view data = enter_words();
    std::string data = enter_words();
    //std::cout << "Enter the data terminated by %:\n";
    //std::getline(std::cin, data, '%');

    Words words = extract_words(data);
    //print_vector(words);
    
    WordCounts counts = count_words(words);
    show_word_counts(counts);
    std::cout << std::endl;
    return 0;
}
