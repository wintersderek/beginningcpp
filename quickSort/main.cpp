/*
This will demonstrate recursion performing the quick sort algorithim.
    1 Ask user to enter some text (terminated by *)
    2 Parse the text into a list of words
    3 Sort the list of words using quick sort
        - pick the middle word and make sure all words on the left side are
          less than it and all words on the right side are higher than it.
        - recurse for each side until there are no more "sides"
    4 Display the sorted list
        - Find the largest word size
        - Ask user the number of words to display per line
        - Display the list 
*/
#include <iostream>
#include <string>
#include <string_view>
#include <iomanip>
#include <memory>
#include <vector>

// Create aliases
using Words = std::vector<std::shared_ptr<std::string>>;

// Define function prototypes
size_t max_word_length(const Words& words);
void display_words(const Words& words);

int main ()
{
    //1
    std::string text {};
    std::cout << "Enter the text to analyse terminated with *:\n";
    std::getline(std::cin, text, '*');
    
    return 0;
}