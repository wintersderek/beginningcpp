#include <iostream>
#include "MyTroubles.h"

void trySomething(int i);

int main(int argc, char* argv[])
{
    Trouble trouble;
    MoreTrouble moreTouble;
    BigTrouble bigTrouble;

    for(int i {}; i < 7; ++i)
    {
        try
        {
            if (i == 3)
                throw trouble;
            else if (i == 5)
                throw moreTouble;
            else if (i == 6)
                throw bigTrouble;
        }
        
        catch (const BigTrouble &e)
        {
            std::cerr << "BigTrouble caught: " << e.what() << '\n';
        }
        catch (const MoreTrouble &e)
        {
            std::cerr << "MoreTrouble caught: " << e.what() << '\n';
        }
        
        catch (const Trouble &e)
        {
            std::cerr << "Trouble caught: " << e.what() << '\n';
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