/*
Exercise 8-7: function for the fibbonaci sequence.
    - write a recursive function that computes the fibbonaci up to a certain
      number of entries.
    - ask user to enter how many numbers they would like to see of the 
      fibbonaci sequence
    - print each fibbonaci to a line, up to the number entered by the user
*/

#include <iostream>

using BN = unsigned long long;

void fibbonaci(const BN limit);
void fibbonaci(const BN limit, BN count, BN previous, BN current);

int main ()
{
    unsigned count {};
    std::cout << "How many items in the fibbonacci sequence? ";
    std::cin >> count;

    fibbonaci(count);
    std::cout << std::endl;
}

void fibbonaci(const BN limit)
{
    // Verify the user put in more than zero
    if (limit > 0)
    {
        fibbonaci(limit, 0, 0, 1);
    }
    else
    {
        std::cout << "No count specified for the sequence!";
    }
    
}
void fibbonaci(const BN limit, BN count, BN previous, BN current)
{
    if (count++ < limit - 1)
    {
        // Print the first one if previous is 0
        if (previous == 0)
        {
            std::cout << current << "\n";
        }
        // Have not reached the user specified limit for fibbonacci sequence.
        // Find and print the next number
        previous += current; 
        std::cout << previous << "\n";

        fibbonaci(limit, count, current, previous);
    }
}