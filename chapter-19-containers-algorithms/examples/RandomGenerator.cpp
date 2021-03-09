#include <iomanip>
#include <iostream>
#include "RandomGenerator.h"

std::string getString(unsigned length)
{
    CharGenerator char_gen{};
    std::string result;
    for (size_t i{}; i < length; ++i)
    {
        result += char_gen();
    }
    return result;
}

std::vector<int> getInts(unsigned count)
{
    std::vector<int> result(count);
    IntGenerator gen{1, 1000};
    for (size_t i{}; i < count; ++i)
    {
        result[i] = gen();
    }
    return result;
}

std::vector<std::string> getCharStrings(unsigned count, unsigned min, unsigned max)
{
    IntGenerator int_gen {static_cast<int>(min), static_cast<int>(max)};
    std::vector<std::string> result;

    for(size_t i {}; i < count; ++i)
    {
        int x = {int_gen()};
        //unsigned char c = {char_gen()};

        //Push the new string
        result.push_back(getString(x));
    }

    return result;
}
