/*
Showcase some of the most useful standard macros
*/

#include <iostream>

int main()
{
    std::cout << "Line and File before change: " << __LINE__ << " : " 
              << __FILE__ << "\n";

#line 1000 "file_changed.cpp"

    std::cout << "Line and File after change: " << __LINE__ << " : "
              << __FILE__ << "\n";

    std::cout << "Compile Date: " << __DATE__ << "\n"
              << "Compile Time: " << __TIME__ << "\n"
              << "Highest C++: " << __cplusplus << "\n";

    std::cout << std::endl;
    return 0;
}