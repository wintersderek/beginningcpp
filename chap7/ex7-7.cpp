/*
Chapter 7 - Exercise 7: Use string stream to sum numbers enterd by user.
    - Allow user to enter an arbitrary amount of integers terminated by #.
    - Sum integers and display the output
*/
#include <iostream>
#include <sstream>
#include <string>

int main ()
{
    std::string text {};
    std::cout << "Enter any number of integers terminated by #\n";
    std::getline(std::cin, text, '#');

    std::stringstream values {text};

    int sum {};

    while (!values.eof())
    {
        int value {};
        values >> value;
        sum += value;
    }

    std::cout << "The sum: " << sum << std::endl;
    return 0;
}