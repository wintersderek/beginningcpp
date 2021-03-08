/*
Show how std::copy_if() works
*/
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include "../RandomGenerator.h"

std::set<int> fillSet_1_to_N(size_t N);

int main(int argc, char const *argv[])
{
    const size_t count {20};

    std::set<int> numbers = {fillSet_1_to_N(count)};
    std::vector<int> odds (numbers.size());
    auto end_odds = std::copy_if(std::begin(numbers), 
                                 std::end(numbers), 
                                 std::begin(odds),
                                 [](int x) { return x % 2 == 1; });
    odds.erase(end_odds, std::end(odds));

    printVector(odds, 5, 10);
    std::cout << std::endl;
    return 0;
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