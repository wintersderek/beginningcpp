/*
Verify user input of a valid date
    - 
*/
#include <iostream>

bool isValidLeapYear(unsigned int year);

int main ()
{
    unsigned start;
    unsigned end;

    std::cout << "Enter a starting year: ";
    
    return 0;
}

bool isValidLeapYear(unsigned int year)
{
    
    return (year % 100 == 0) ?
                (year % 400 == 0) :
                    (year % 4 == 0);
}