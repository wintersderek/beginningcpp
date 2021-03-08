/*
Exercise 19-2. Replace both instances of your self-defined Stack<> in Ex16_04A 
    with an instance of std::stack<>.
*/

#include <algorithm>
#include <iostream>
#include <stack>

int main(int argc, char const *argv[])
{
    std::string words[]{"The", "quick", "brown", "fox", "jumps"};
    std::stack<std::string> wordStack; // A stack of strings

    for (size_t i{}; i < std::size(words); ++i)
        wordStack.push(words[i]);

    std::stack<std::string> newStack{wordStack}; // Create a copy of the stack

    // Display the words in reverse order
    while (!newStack.empty())
    {
        std::cout << newStack.top() << " ";
        newStack.pop();
    }
        
    std::cout << std::endl;

    // Reverse wordStack onto newStack
    while (!wordStack.empty())
    {
        newStack.push(wordStack.top());
        wordStack.pop();
    }        

    // Display the words in original order
    while (!newStack.empty())
    {
        std::cout << newStack.top() << " ";
        newStack.pop();
    }
        
    std::cout << std::endl;

    std::cout << std::endl
              << "Enter a line of text:" << std::endl;
    std::string text;
    std::getline(std::cin, text); // Read a line into the string object

    std::stack<const char> characters; // A stack for characters

    for (size_t i{}; i < text.length(); ++i)
        characters.push(text[i]); // Push the string characters onto the stack

    std::cout << std::endl;
    while (!characters.empty())
    {
        std::cout << characters.top(); // Pop the characters off the stack
        characters.pop();
    }        

    std::cout << std::endl;
}
