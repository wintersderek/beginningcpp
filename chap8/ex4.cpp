/*
Write a program that accepts 2 to 4 arguments.
    - if less than 2 or greater than 4 args are provided, print error and
      exit.
    - if the right amount is provided, output the arguments
*/

#include <iostream>

int main (int argc, char* argv[])
{
    if (argc < 3 || argc > 5)
    {
        std::cout << "The program accepts 2 to 4 parameters" << std::endl;
        return 0;
    }

    for (size_t i {1}; i < argc; i++)
    {
        std::cout << argv[i] << "\n";
    }
    std::cout << std::endl;    
}   