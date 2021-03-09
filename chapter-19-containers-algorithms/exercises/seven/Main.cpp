/*
Exercise 19-7. erase() and erase_if() are not the only algorithms for which the
remove-erase idiom is applicable. Another example is std::unique(), which is 
used to remove duplicates from a presorted range of elements. Write a little 
program that fills a vector<> with a considerably large amount of random 
integers between 0 and RAND_MAX, sorts this sequence, removes the duplicates, 
and then prints out the amount of remaining elements.
*/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "../../../RandomGenerator.h"

int main(int argc, char const *argv[])
{
    const unsigned number {1'000'000};

    std::vector<int> values {getInts(number, 0, RAND_MAX)};
    //std::vector<int> values {getInts(number, 0, 500)};
    std::sort(begin(values), end(values));
    size_t initial {values.size()};

    /* Unique-Erase idiom */
    auto it = std::unique(begin(values), end(values));
    values.erase(it, end(values));
    size_t final_size {values.size()};

    std::cout << std::left;
    printVector(values, 12, 5);
    std::cout << '\n' << std::setw(14) << "Initial Size:" << initial << '\n'
              << std::setw(14) << "Final Size: " << final_size;
    std::cout << std::endl;
    return 0;
}
