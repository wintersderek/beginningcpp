#include <array>
#include <iostream>
#include <string>
#include "Stack.h"

int main (int argc, char* argv[])
{
    std::string words[] {"The", "quick", "brown", "fox", "jumps"};

    Stack<std::string> values;

    for(size_t i {}; i < std::size(words); ++i)
    {
        values.push(words[i]);
    }

    Stack<std::string> copy {values};

    // Display in reverse order
    while (copy)
    {
        std::cout << copy.pop() << ' ';
    }
    std::cout << '\n';

    // Put the values back into copy and display in the correct order
    while (values)
    {
        copy.push(values.pop());
    }
    while (copy)
    {
        std::cout << copy.pop() << ' ';
    }
    std::cout << '\n';

    // Get a line of text from the user and display it in reverse order
    std::cout << "Enter a line of text: ";
    std::string line;
    std::getline(std::cin, line);
    Stack<const char> characters;
    for(size_t i {}; i < line.length(); ++i)
    {
        characters.push(line[i]);
    }
    while (characters)
    {
        std::cout << characters.pop();
    }
    

    std::cout << std::endl;
    return EXIT_SUCCESS;
}