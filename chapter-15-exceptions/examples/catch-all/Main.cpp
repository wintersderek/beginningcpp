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
            try
            {
                if (i == 3)
                    throw trouble;
                else if (i == 5)
                    throw moreTouble;
                else if (i == 6)
                    throw bigTrouble;
            }
            catch (const MoreTrouble &e)
            {
                if (typeid(e) == typeid(MoreTrouble))
                {
                    std::cerr << "MoreTrouble caught in inner block: " 
                              << e.what() << '\n';
                }
                else
                {
                    std::cerr << "Inner caught type not match\n";
                    throw;
                }
            }
            catch (...)
            {
                std::cerr << "Caught all in inner block\n";
                throw;
            }
        }
        catch(const Trouble& e)
        {
            std::cerr << typeid(e).name() << " caught in outer block: "
                      << e.what() << '\n';
        }
        std::cout << "End of loop - i is " << i << '\n';
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