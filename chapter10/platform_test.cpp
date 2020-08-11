/*
Use preprocessing directives to showcase 64 bit systems
*/

#include <iostream>

int main()
{
#if _WIN64 || __x86_64__ || __ppc64__
    std::cout << "System is 64 bit";
#else
    std::cout << "System is not 64 bit";
#endif

std::cout << std::endl;

}
