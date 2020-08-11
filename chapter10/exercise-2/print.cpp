/*
Define print(std::string_view)
*/

#include "print.h"
int calls {0};
void print(std::string_view value)
{
    calls += 1;
    std::cout << value << std::endl;
}