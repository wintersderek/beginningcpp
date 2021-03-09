/*
Exercise 19-6. Another algorithm that is defined by the numeric header is the 
oddly named iota() algorithm, which you can use to fill a given range with 
values M, M+1, M+2, and so on. Use it to rework the fillVector_1_to_N() 
function of Ex19_10.
*/
#include <iostream>
#include <numeric>
#include <vector>
#include "../../../RandomGenerator.h"

std::vector<int> fillVector_1_to_N(size_t count);

int main(int argc, const char* argv[])
{
    size_t n {40};
    std::vector<int> values = fillVector_1_to_N(n);
    printVector(values, 4, 20);
    std::cout << std::endl;
    return EXIT_SUCCESS;
}

std::vector<int> fillVector_1_to_N(size_t count)
{
    std::vector<int> result (count);
    std::iota(std::begin(result), std::end(result), 1);
    return result;
}