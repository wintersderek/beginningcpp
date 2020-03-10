// Compare two integers to see if they are the same
#include <iostream>

int main()
{
    int x {}, y {};

    std::cout << "Enter two integers: " << std::endl;
    std::cin >> x >> y;

    if (x == y)
    {
        std::cout << x << " = " << y;
    }
    else
    {
        std::cout << x << " != " << y;
    }
    
    std::cout << std::endl;
    return 0;
}