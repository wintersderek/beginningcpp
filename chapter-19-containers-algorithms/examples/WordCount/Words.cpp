#include <iomanip>
#include <iostream>
#include "Words.h"

Words extract_words(std::string_view text, std::string_view separators)
{
    Words result {};

    size_t start {text.find_first_not_of(separators)};
    size_t end {};

    while (start != std::string_view::npos)
    {
        end = text.find_first_of(separators, (start + 1));
        
        if (end == std::string_view::npos)
            end = text.length();
        result.push_back(text.substr(start, end - start));
        start = text.find_first_not_of(separators, end + 1);
    }
    return result;
}

WordCounts count_words(const Words& words)
{
    WordCounts result {};

    for (const auto& word : words)
    {
        ++result[std::string(word)];
    }
    return result;
}

void show_word_counts(const WordCounts& wordCounts)
{
    size_t max_len = max_word_length(wordCounts);

    std::cout << std::left;

    for(const auto& [key, value] : wordCounts)
    {
        std::cout << std::setw(max_len + 2) << key << value << '\n';
    }
}

size_t max_word_length(const WordCounts& wordCounts)
{
    size_t result {};

    for(const auto& [key, value] : wordCounts)
    {
        if (key.length() > result) result = key.length();
    }
    return result;
}

std::string enter_words()
{
    std::cout << "Enter some words terminated with %\n";
    std::string value;
    std::getline(std::cin, value, '%');
    return value;
}

void print_vector(const Words &words)
{
    for(const auto& w : words)
    {
        std::cout << w << '\n';
    }
}