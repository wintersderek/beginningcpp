/*
Throwing a fundamental type exception
*/

#include <iostream>

int main(int argc, char* argv[])
{
    for (size_t i {0}; i < 7; ++i)
    {
        try
        {
            if (i < 3) throw i;

            std::cout << "i not thrown - value is " << i << '\n';

            if (i > 5) throw "Here is another!";

            std::cout << "End of try block\n";
        }
        catch(size_t i)
        {
            std::cerr << "i caught - value is " << i << '\n';
        }
        catch(const char* msg)
        {
            std::cerr << "message caught - message is " << msg << '\n';
        }

        std::cout << "After all catch blocks - i is " << i << "\n\n";
    }

    std::cout << std::endl;
    return EXIT_SUCCESS;    
}