// Demonstrate the usage of enum
#include <iostream>

int main()
{
    enum class Day : short {Sunday = 1, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
    Day today {Day::Sunday};
    enum class Punctuation : char {Period = '.', Question = '?'};

    std::cout << "Today is : " << static_cast<short>(today) << "\n";
    std::cout << "Period = " << static_cast<char>(Punctuation::Period) << "\n";
    
    return 0;
}