/*
Show template usage.
*/

#include <iostream>
#include <string>
#include <algorithm>

template <typename T> const T& larger (const T& a, const T& b);

int main ()
{
    int val1 {5}, val2 {8};
    std::cout << "INT larger: " << larger(val1, val2) << "\n";

    std::cout << "FLOAT larger: " << larger(15.5, 7.9) << "\n";

    double val3 {5.14}, val4 {1.68};
    std::cout << "DOUBLE larger: " << larger(val3, val4) << "\n";

    // Won't compile if type is not explicitly set
    std::cout << "INT/DOUBLE larger: " << larger<double>(val1, val3) << "\n";

    std::string str1 {"A"}, str2 {"Z"};
    std::cout << "std::string larger: " << larger(str1, str2) << "\n";

    std::cout << "std::min: " << std::min<int>(100, 10) << "\n";

    std::cout << std::endl;
    return 0;
}

// This is the better option to avoid parameter copy
template <typename T>
const T &larger(const T &a, const T &b)
{
    return (a > b) ? a : b;
}