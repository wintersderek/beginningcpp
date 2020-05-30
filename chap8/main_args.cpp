/*
Show how arguments to main are handled.
*/
#include <iostream>

int main(int argc, char* argv[])
{
    // argc is a count of command line arguments found.
    std::cout << "Number of command line arguments: " << argc << "\n";

    // argv is an array of pointers to the command line arguments including
    // the program name
    for (size_t i = 0; i < argc; i++)
    {
        if (argv[i] != nullptr)
        {
            std::cout << argv[i] << "\n";
        }
    }

    if (argv[argc] == nullptr)
    {
        std::cout << "argv[" << argc << "] is a null pointer\n";
    }

    std::cout << std::endl;
    
    return 0;       
}