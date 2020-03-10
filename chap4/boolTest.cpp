// Show output of type bool

#include <iostream>
#include <iomanip>

int main() 
{
    bool testOne {};
    bool testTwo {true};

    std::cout << "Test one: " << testOne << "\n"
              << "Test two: " << testTwo << "\n";

    std::cout << "Adding boolean IO manipulator to stream"
              << std::boolalpha << "\n";

    std::cout << "Test one: " << testOne << "\n"
              << "Test two: " << testTwo << "\n";

    std::cout << std::endl;
    return 0;
}