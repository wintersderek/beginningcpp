#ifndef OPTIMUM_H
#define OPTIMUM_H

#include <vector>

template <typename T>
class Less
{
public:
    bool operator()(const T& a, const T& b) { return a < b; }
};

template <typename T>
using Compare = bool (*)(const T&, const T&);

template <typename T, typename Ftor>
const T* find_optimum(const std::vector<T>& data, Ftor comp)
{
    // No action if vector is empty
    if (data.empty()) return nullptr;

    const T* result {&data[0]};

    for (size_t i {1}; i < data.size(); ++i)
    {
        if (comp(data[i], *result)) result = &data[i];
    }
    return result;
}
#endif