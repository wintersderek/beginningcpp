/*
Demonstrate std::function<>
*/

#include <iostream>
#include <functional>
#include <cmath>

bool less(int x, int y) { return x < y; }

int main(int argc, char const *argv[])
{
    int x {3}, y {5};
    std::function<bool(int, int)> compare {less};
    std::cout << std::boolalpha;

    std::cout << "Less: " << compare(x, y) << '\n';

    compare = std::greater<>{};
    std::cout << "Greater: " << compare(x, y) << '\n';

    int n {10};
    compare = [n](int x, int y) { return std::abs(x - n) < std::abs(y - n); };
    std::cout << x << " nearer to " << n << " than " << y << ": " 
              << compare(x, y) << '\n';


    std::function<void(const int&)> empty;
    if (empty)
    {
        std::cout << "Empty points to a function\n";
    }
    else
    {
        std::cout << "Empty does not point to a function.\n";
    }
    std::cout << std::endl;
    return 0;
}
