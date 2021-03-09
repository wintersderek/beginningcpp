#ifndef WORDS_H
#define WORDS_H

#include <map>
#include <string>
#include <string_view>
#include <vector>

using Words = std::vector<std::string_view>;
using WordCounts = std::map<std::string, size_t>;

// Function prototypes
Words extract_words(std::string_view text, std::string_view separators = " ,.!?\"\n");
WordCounts count_words(const Words& words);
void show_word_counts(const WordCounts& wordCounts);
size_t max_word_length(const WordCounts& wordCounts);
std::string enter_words();
void print_vector(const Words& words);

#endif