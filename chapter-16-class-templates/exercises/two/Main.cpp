#include <iostream>
#include <string>
#include "Pair.h"

int main (int argc, char* argv[])
{
    Pair<int, std::string> one {0, "def"};
    Pair<int, std::string> two {123, "abc"};
    Pair<int, std::string> three {123, "def"};
    Pair<int, std::string> four {123, "abc"};

    std::cout << "One less than Two: " << (one < two ? "true" : "false") << '\n';
    std::cout << "Two less than Three: " << (two < three ? "true" : "false") << '\n';
    std::cout << "Three less than One: " << (three < one ? "true" : "false") << '\n';

    std::cout << "One == Two: " << (one == two ? "true" : "false") << '\n';
    std::cout << "Two == Four: " << (two == four ? "true" : "false") << '\n';
    std::cout << "\n\nOne: " << one << "\nTwo: " << two << "\nThree: " 
              << three << "\nFour: " << four;

    std::cout << std::endl;
    return EXIT_SUCCESS;
}