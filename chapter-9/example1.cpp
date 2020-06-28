/*
Show template usage.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <vector>

template <typename T> T larger(T a, T b);
template <> int* larger(int* a, int* b);
template <typename T> T larger(const T data[], size_t size);
template <typename T> T larger(const std::vector<T>& data);
//template <typename T> T* larger(T* a, T* B);

int main()
{
    int big_int {1234567}, small_int {123};
    int val1 {10}, val2 {12}, val3 {14}, val4 {16};

    // Pointer passing
    std::cout << "Larger Pointer (1234567): " << *larger(&small_int, &big_int)
              << "\n";
    std::cout << "Larger Pointer (123): " << *larger(&small_int, &val1)
              << "\n";
    std::cout << "Larger Pointer (16): " << *larger(&val4, &val2)
              << "\n";
    std::cout << "Larger Pointer (1234567): " << *larger(&val3, &big_int)
              << "\n";

    int values[] {205, 100, 89, 201, 45, 199};
    std::cout << "Array Larger: " << larger(values, std::size(values)) << "\n";

    const char data[] {"A nods as good as a wink"};
    std::cout << "Text Array Larger: " << larger(data, std::size(data)) << "\n";

    std::vector<char> v {'a', ';', '&', 'A', 'Z', 'b'};
    std::cout << "Vector<char>: " << larger(v) << "\n";

    std::cout << std::endl;
    return 0;
}

template <typename T>
T larger(const std::vector<T>& data)
{
    T result {0};

    if (data.size() > 0)
    {
        for (auto &&i : data)
        {
            if (i > result)
            {
                result = i;
            }
        }
    }
    return result;
}

template <typename T>
T larger(const T data[], size_t size)
{
    T result {0};

    for (size_t i {0}; i < size; i++)
    {
        if (data[i] > result)
        {
            result = data[i];
        }
    }
    return result;
}

// This is the better option to avoid parameter copy
template <typename T>
T larger(T a, T b)
{
    return (a > b) ? a : b;
}

template <>
int* larger(int *a, int *b)
{
    return (*a > *b) ? a : b;
}