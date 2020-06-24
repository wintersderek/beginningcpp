// Static function variables

#include <iostream>

size_t do_it();

int main ()
{
    for (size_t i = 0; i < 100; i++)
    {
        if (do_it() % 10 == 0)
        {
            std::cout << "It was done.\n";
        }
    }
    std::cout << std::endl;
}

size_t do_it()
{
    static size_t x {};
    return ++x;
}