/*
    Chapter 7 Exercise 2: Enter arbitrary text and count word frequency
        - read an arbitrary amount of text over multiple lines
        - record unique words and their usage count
        - Output word and counts
            - 3 per line
            - align word left and count right
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using vector_pair =  std::vector<std::pair<std::string, unsigned int>>;

size_t find_longest_word(vector_pair& list);
size_t find_longest_number(vector_pair& list);

std::vector<std::pair<std::string, unsigned int>> get_word_frequency(std::string& text); 

void bubble_sort(vector_pair& list);

int main () 
{
    std::string text;
    std::cout << "Enter some text and terminate with ^:\n";
    std::getline(std::cin, text, '^');

    // Get the word frequency
    vector_pair list = get_word_frequency(text);

    // Find the longest word and number
    size_t longest_word = find_longest_word(list) + 2;
    size_t longest_number = find_longest_number(list) + 2;

    // Print the word list
    bubble_sort(list);
    for (size_t i = 0; i < list.size(); i++)
    {
        std::cout << std::left << std::setw(longest_word) << list[i].first
                  << std::right << std::setw(longest_number)
                  << list[i].second << std::setw(2) << " ";

        if ((i + 1) % 3 == 0)
        {
            std::cout << std::endl;
        }
    }
    
    return 0;
}

void bubble_sort(vector_pair& list)
{
    bool sorted {false};

    while (!sorted) 
    {
        sorted = true;

        for (size_t i = 1; i < list.size(); i++)
        {
            if (list[i - 1].first > list[i].first)
            {
                sorted = false;
                list[i].swap(list[i - 1]);
            }
        }
        
    }


}

std::vector<std::pair<std::string, unsigned int>> get_word_frequency(std::string& text)
{
    std::vector<std::pair<std::string, unsigned int>> return_value;
    std::string separators {" ,;:.\"!?'\n"};

    size_t start {text.find_first_not_of(separators)};

    while (start != std::string::npos)
    {
        size_t end {text.find_first_of(separators, start)};
        if (end == std::string::npos)
            end = text.length();

        std::string found {text.substr(start, end - start)};
        bool contains {false};

        for (auto &&i : return_value)
        {
            if (found == i.first)
            {
                ++i.second;
                contains = true;
                break;
            }
        }

        if (contains == false)
        {
            return_value.push_back(std::make_pair(found, 1));
        }
        
        start = text.find_first_not_of(separators, end+1);
    }

    return return_value;
}

size_t find_longest_word(vector_pair& list)
{
    unsigned int return_value {};

    for (auto &&item : list)
    {
        if (item.first.length() > return_value)
        {
            return_value = item.first.length();
        }
    }

    return return_value;    
}

size_t find_longest_number(vector_pair& list)
{
    unsigned int return_value {};

    for (auto &&item : list)
    {
        std::string number_value {std::to_string(item.second)};
        if (number_value.length() > return_value)
        {
            return_value = number_value.length();
        }
    }

    return return_value;    
}