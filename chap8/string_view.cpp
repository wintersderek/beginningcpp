/*
Show how std::string_view works.
*/

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <iomanip>

using namespace std;

void get_text(string& text);

void find_words(vector<string>& words, const string& text, const string separators);

void find_words_sv(vector<string>& words, std::string_view text, 
                   std::string_view separators);

void display_words(const vector<string>& words);

int main ()
{
    string text;
    string find;

    get_text(text);

    string separators {" \n\t'\";:.!?,"};
    vector<std::string> words;
    //find_words(words, text, separators);
    find_words_sv(words, text, separators);

    display_words(words);

    return 0;
}

void find_words_sv(vector<string>& words, std::string_view text, 
                   std::string_view separators)
{
    size_t start {text.find_first_not_of(separators)};

    while (start != string::npos)
    {
        size_t end {text.find_first_of(separators, (start + 1))};
        if (end == string::npos)
        {
            end = text.length();
        }

        words.push_back(std::string{text.substr(start, (end - start))});

        start = text.find_first_not_of(separators, (end + 1));
    }
}

void find_words(vector<string>& words, const string& text, 
                const string separators)
{
    size_t start {text.find_first_not_of(separators)};

    while (start != string::npos)
    {
        size_t end {text.find_first_of(separators, (start + 1))};
        if (end == string::npos)
        {
            end = text.length();
        }

        words.push_back(text.substr(start, (end - start)));

        start = text.find_first_not_of(separators, (end + 1));
    }
}

void display_words(const vector<string>& words)
{
    size_t max_length {};
    for(auto& s : words)
    {
        if (s.length() > max_length)
        {
            max_length = s.length();
        }
    }

    std::cout << "Words (" << words.size() << ")\n" 
              << "------------------------------------------------------\n"
              << std::left;

    for (size_t i = 0; i < words.size(); i++)
    {
        std::cout << std::setw(max_length + 2) << words[i];
        if ((i+1) % 5 == 0)
        {
            std::cout << "\n";
        }
    }
    std::cout << std::endl;
}

void get_text(string& text)
{
    std::cout << "Enter the text to search terminated with *:\n" << std::flush;
    std::getline(std::cin, text, '*');
}