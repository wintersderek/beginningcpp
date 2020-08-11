/*
Template using static_assert()
*/
#ifndef AVERAGE_H
#define AVERAGE_H

#include <type_traits>
#include <vector>
#include <cassert>

namespace test_sa
{
    template <typename T>
    T average(const std::vector<T> &data)
    {
        static_assert(std::is_arithmetic_v<T>,
                      "Type for average() must be arithmetic");
        assert(!data.empty());

        T sum{};

        for (const auto &item : data)
        {
            sum += item;
        }
        return sum / data.size();
    }
}

#endif