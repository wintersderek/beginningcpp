#include <iostream>

int main ()
{
    int x{}, y{};
    std::cout << "Enter two positive integers: ";
    std::cin >> x >> y;
    std::cout << "\n";

    if (x <= 0 || y <= 0)
    {
        std::cout << "Only positive integers are allowed";
    }   
    else
    {
        if (bool oneUp {(x >= y)}; (x % y == 0 || y % x == 0))
        {
            std::cout << (oneUp? x : y)
                      << " is a multiple of "
                      << (oneUp? y : x);
        }
        else
        {
            std::cout << (oneUp? x: y)
                      << " is not a multiple of "
                      << (oneUp? y: x);
        }
        
    }
    
    std::cout << std::endl;

    return 0;
}