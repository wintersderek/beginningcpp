/*
Demonstrate simple recursion with the factorial of a number.
    - Ask the user for a number
    - Ask the user if they would like to see the work
    - Compute the factorial of the number
        - If see work, show each step of the factorial
    - Ask user if they would like to execute again
*/

#include <iostream>
#include <cctype>

unsigned long long factorial(unsigned number, bool show_work);

int main()
{
    while (true)
    {
        unsigned number {};
        std::cout << "Enter a number to factorial: ";
        std::cin >> number;

        char answer {};
        std::cout << "Would you like to see the work? [Y/n]: ";
        std::cin >> answer;

        unsigned long long result { factorial(number, 
                                        std::tolower(answer) == 'y')};
        std::cout << " = " << result << "\n\n";

        std::cout << "Would you like to execute again? [Y/n]: ";
        std::cin >> answer;

        if (std::tolower(answer) != 'y')
            break;

        std::cout << "\n";
    }

    return 0;
}

unsigned long long factorial(unsigned number, bool show_work)
{
    if (show_work)
        std::cout << number;

    if (number <= 1)
        return 1LL;

    if (show_work)
        std::cout << " x ";

    return number * factorial((number -1), show_work);
}