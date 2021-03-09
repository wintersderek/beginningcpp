/*
Show how std::sort() works
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include "../RandomGenerator.h"

std::vector<unsigned char> getChars(size_t count);

int main(int argc, char const *argv[])
{
    std::vector<unsigned char> values = getChars(52);
    printVector(values, 3, 20);
    std::cout << "\n\n";
    std::sort(values.begin(), values.end());
    printVector(values, 3, 20);
    std::cout << std::endl;
    return 0;
}

std::vector<unsigned char> getChars(size_t count)
{
    CharGenerator gen {};
    std::vector<unsigned char> result (count);
    size_t failure_count {};

    for (size_t i {}; i < count;)
    {
        unsigned char c {gen()};
        if (std::find(result.begin(), result.end(), c) == result.end())
        {
            result[i++] = c;
        }
        else{
            if (++failure_count >= count + 500)
                break;
            //std::cout << c << " is in result\t";
        }
    }

    return result;
}
