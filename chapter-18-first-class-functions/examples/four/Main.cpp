#include <iostream>
#include <vector>
#include "Optimum.h"

template <typename T>
bool greater(const T& a, const T& b) { return a > b; }

int main(int argc, char const *argv[])
{
    std::vector<int> my_data {7, 4, 9, 29, 2, 5};

    Less<int> my_less {};

    std::cout << "Vector Less: " << (*(find_optimum(my_data, my_less))) << '\n';
    std::cout << "Vector Great: " << (*(find_optimum(my_data, greater<int>))) << '\n';
    std::cout << std::endl;
    return 0;
}
