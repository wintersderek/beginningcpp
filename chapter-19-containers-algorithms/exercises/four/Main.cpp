/*
Exercise 19-4. Research the std::partition() algorithm and use it to 
reimplement the removeEvenNumbers() function of either Ex19_10 or Ex19_14.
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include "../../../RandomGenerator.h"

std::vector<int> getRandomVector(unsigned count);

int main(int argc, char const *argv[])
{
    std::vector<int> values = getRandomVector(40);
    printVector(values, 7, 10);
    std::cout << "------------------------------------\n";
    auto it = std::partition(values.begin(), 
                             values.end(), 
                             [](int x) { return x % 2 != 0; });
    values.erase(it, values.end());
    printVector(values, 7, 10);
    std::cout << std::endl;
    return 0;
}


std::vector<int> getRandomVector(unsigned count)
{
    std::vector<int> result (count);
    IntGenerator gen {1, 10000};

    for(auto it = result.begin(); it != result.end(); ++it)
        *it = gen();
    
    return result;
}