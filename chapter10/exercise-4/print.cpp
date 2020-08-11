/*
Define print(std::string_view)
*/

#include "print.h"

void print1::print(std::string_view value)
{
    std::cout << "print1: " << value << std::endl;
}

void print2::print(std::string_view value)
{
    std::cout << "print2: " << value << std::endl;
}