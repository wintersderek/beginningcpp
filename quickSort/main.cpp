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
void extract_words(Words& words, std::string_view text, std::string_view sep);
void swap(Words& words, size_t first, size_t second);
void sort(Words& words);
void sort(Words& words, size_t start, size_t end);

void print_it(const Words& words);

int main ()
{
    const auto separators {" ,.!?\"\n"};

    //1
    std::string text {};
    std::cout << "Enter the text to analyse terminated with *:\n";
    std::getline(std::cin, text, '*');
    
    //2
    Words words {};
    extract_words(words, text, separators);

    if (words.empty())
    {
        std::cout << "Nothing to analyse!" << std::endl;
        return 0;
    }

    //3
    sort(words);

    //4
    display_words(words);

    std::cout << std::endl;
    return 0;
}

void sort (Words& words, size_t start, size_t end)
{
    std::cout << "\tsort [" << start << "] to [" << end << "]\n";
    if (!(end > start))
    {
        return;
    }
    // Pick an arbitrary element in the set to be the pivot
    swap(words, start, ((start + end) / 2));
    size_t current {start};

    for (size_t i {start +1}; i <= end; ++i) 
    {
        if (*words[i] < *words[start])
        {
            // This will put all elements less than start directly after
            // start.
            //std::cout << *words[i] << " < " << *words[start] << "  ";
            swap(words, ++current, i);
        }
    }

    // Put start after all elements ordered in the for loop
    swap(words, start, current);
    print_it(words);

    if (current > start)
    {
        // We have a block of elements on the left of the pivot
        sort(words, start, (current - 1));
    }

    if (current < end)
    {
        // We have a block of elements on the right of the pivot
        sort(words, (current + 1), end);
    }
}

void sort(Words& words)
{
    if (words.size() > 0)
    {
        std::cout << "Beginning sort...\n";
        sort(words, 0, (words.size() - 1));
    }
}

size_t max_word_length(const Words& words)
{
    size_t result {};

    for(const auto& s : words)
    {
        if (s->length() > result)
            result = s->length();
    }
    return result;
}

void display_words(const Words& words)
{
    size_t max_length {max_word_length(words)};

    size_t per_line {};
    std::cout << "How man words per line? ";
    std::cin >> per_line;
    std::cout << "\n\n" << std::left;    

    for (size_t i = 0; i < words.size(); i++)
    {
        std::cout << std::setw(max_length + 2) << *words[i];
        if ((i + 1) % per_line == 0)
            std::cout << "\n";
    }
}

void extract_words(Words& words, std::string_view text, std::string_view sep)
{
    size_t start {text.find_first_not_of(sep)};

    while (start != std::string_view::npos)
    {
        size_t end {text.find_first_of(sep, (start + 1))};
        if (end == std::string_view::npos)
        {
            end = text.length();
        }
        
        words.push_back(
            std::make_shared<std::string>(text.substr(start, (end - start))));

        start = text.find_first_not_of(sep, (end + 1));
    }
}

void swap(Words& words, size_t first, size_t second)
{
    //Only swap the pointers if the items to swap are within the bounds
    if (first < words.size() && second < words.size())
    {
        auto ptr {words[first]};
        words[first] = words[second];
        words[second] = ptr;
        //std::swap(words[first], words[second]);
    }
    else
    {
        std::cout << "Invalid swap...\n";
    }   
}

void print_it(const Words& words)
{
    for(auto& p: words)
    {
        std::cout << *p << " ";
    }
    std::cout << "\n";
}