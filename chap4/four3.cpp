#include <iostream>
#include <iomanip>

int main () 
{
    double x {0}, y {0};
    std::cout << "Enter a number: ";
    std::cin >> x;

    bool inRange {static_cast<bool>(x >= 1 && x <= 100)};

    std::cout << std::setprecision(8);
    
    if (inRange)
    {
        if (x > 50)
            std::cout << x << " is greater than 50.";
        else if (x == 50)
            std::cout << x << " is equal to 50.";
        else
        {
            std::cout << x << " is less than 50.";
        }
        
    }
    else
    {
        std::cout << x << " is not between 1 and 100!";
    }

    std::cout << std::endl;
    
    return 0;
}