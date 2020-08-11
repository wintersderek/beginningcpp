/*
    Do some tests with the <random> header
*/

#include <iostream>
#include <random>
#include <iomanip>

int main()
{

    //std::mt19937 mt(1729); // Create the random number generator with seed
    
    // Create a random device instead of a deterministic seed
    std::random_device rd;
    std::mt19937 mt(rd());

    // Create the distribution (range you want numbers in) for the random
    std::uniform_int_distribution<int> dist(1, 3);

    for (size_t i{0}; i < 25; i++)
    {
        std::cout << std::setw(4) << dist(mt);
        if (i % 4 == 0)
        {
            std::cout << "\n";
        }
    }
    std::cout << std::endl;
}