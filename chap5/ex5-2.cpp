// Sum integers from user and output the average as a floating point.
#include <iomanip>
#include <iostream>

int main () {
    const char yes {'y'};
    int number {};
    int sum {};
    int count {};
    char answer {};

    while (true) {
        std::cout << "Enter an integer: ";
        std::cin >> number;

        sum += number;
        count += 1;
        std::cout << "Would you like to enter another number (y/n)?";
        std::cin >> answer;
        if (std::tolower(answer) != yes) {
            break;
        }
    }

    std::cout << std::setw(10) << "Sum" << std::setw(15) << "Average" << "\n"
              << std::setw(10) << "----------" << std::setw(15) << "----------"
              << "\n" << std::setw(10) << sum << std::setw(15) 
              << (sum / count) << std::endl;
        

    
    return 0;
}