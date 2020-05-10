// show the <string> std::sto# functions

#include <iostream>
#include <string>

int main () 
{
    std::string int_val {"153"};
    std::string float_value {"3.145"};
    std::string long_long_val {"2005"};

    int my_int {std::stoi(int_val)};
    std::cout << "Int: " << my_int;

    float my_float {std::stof(float_value)};
    std::cout << "Float: " << my_float;

    long long my_ll {std::stoll(long_long_val)};
    std::cout << "Long Long: " << my_ll;
    
    return 0;
}