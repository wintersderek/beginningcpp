/*
Show how std::copy_if() works
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#include "../RandomGenerator.h"

std::set<int> fillSet_1_to_N(size_t N);
void removeEraseIdiom(std::vector<int>& values);
std::vector<int> copyToVector(const std::set<int>& values);

int main(int argc, char const *argv[])
{
    const size_t count {20};

    std::set<int> numbers = {fillSet_1_to_N(count)};
    std::vector<int> v = copyToVector(numbers);
    printVector(v, 5, 20);
    std::cout << "\n\n";
    removeEraseIdiom(v);

    printVector(v, 5, 20);
    std::cout << std::endl;
    return 0;
}

std::vector<int> copyToVector(const std::set<int>& values)
{
    std::vector<int> result;
    std::copy(values.cbegin(), values.cend(), std::back_inserter(result));
    return result;
}

void removeEraseIdiom(std::vector<int>& values)
{
    /* Remove Even Numbers from the vector */
    auto first_removal = std::remove_if(values.begin(), 
                                        values.end(), 
                                        [](int x) -> bool { return x % 2 == 0; });
    values.erase(first_removal, values.end());
}

std::set<int> fillSet_1_to_N(size_t N)
{
    IntGenerator gen {1, 100};
    std::set<int> result;

    for(size_t i {}; i < N; ++i)
    {
        result.insert(gen());
    }
    return result;
}