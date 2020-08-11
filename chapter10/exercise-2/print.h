/*
Declare print(std::string_view)
*/

#ifndef HDI_PRINT_H
#define HDI_PRINT_H

#include <iostream>
#include <string_view>

extern int calls;
void print(std::string_view value);
#endif