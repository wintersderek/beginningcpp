/*
Use auto for compiler deduction of return type.
*/

#include <iostream>
#include <string>

//template <typename T1, typename T2> auto larger(T1 a, T2 b);
template <typename T1, typename T2>
auto larger(T1 a, T2 b)
{
    return (a > b) ? a : b;
}

int main()
{
    /***    Using auto for return type deduction    ***/
    double at_one{16.59};
    int at_two{15};
    //char at_data_one{'A'};
    std::string at_data_two{"Z"};
    std::cout << "Larger - double/int: " << larger(at_one, at_two) << "\n";
    std::cout << "Larger - char/string: " << larger("A", at_data_two);

    std::cout << std::endl;
    return 0;
}

