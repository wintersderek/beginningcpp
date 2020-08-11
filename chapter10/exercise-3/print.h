/*
Declare print(std::string_view)
*/

#ifndef HDI_PRINT_H
#define HDI_PRINT_H

#include <iostream>
#include <string_view>

namespace print1
{
    void print(std::string_view value);
}

namespace print2
{
    void print(std::string_view value);
}

#endif