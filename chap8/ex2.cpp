/*
Write a function that reverses a string.
    - Prompt the user for a string of characters.
    - Call function to reverse string
    - Write reversed string to output
*/
#include <iostream>
#include <string>

void reverse(std::string& text);

int main ()
{
    std::string text {};
    std::cout << "Enter text to reverse:\n";
    std::getline(std::cin, text);

    reverse(text);

    std::cout << text << std::endl;
}

void reverse(std::string& text)
{
    size_t l = text.length();
    for(size_t i {}; i < (l / 2); i++)
    {
        std::swap(text[i], text[l - i -1]);
    }
}