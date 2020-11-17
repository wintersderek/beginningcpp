#include <iostream>
#include "MyTroubles.h"

void trySomething(int i);

int main(int argc, char* argv[])
{
    for(int i {}; i < 2; ++i)
    {
        try
        {
            trySomething(i);
        }
        catch(const Trouble& e)
        {
            std::cerr << "Exception: " << e.what() << '\n';
        }
        std::cout << '\n';
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}

void trySomething(int i)
{
    if (i == 0)
        throw Trouble {};
    else
    {
        throw Trouble {"Nobody knows the trouble i've seen..."};
    }
}