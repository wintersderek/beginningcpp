/*
Test decltype()
*/

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T1, typename T2>
auto larger(T1 a, T2 b) -> decltype(a > b ? a : b);

template <typename T1, typename T2>
auto product_vectors(std::vector<T1> a, std::vector<T2> b)
{
    const size_t max_loop {std::min(a.size(), b.size())};

    decltype(a[0] * b[0]) sum {};

    for (size_t i {0}; i < max_loop; i++)
    {
        sum += a[i] * b[i];
    }
    return sum;    
}

int main ()
{
    int a {1};
    double b {0.9999999999999};

    std::cout << larger(1ull, 3.7f) << "\n";

    std::cout << larger(a, b) << "\n";

    std::vector<int> x {1, 2, 3, 4, 5, 6, 7};
    std::vector<double> y {1.5, 2.9, 3.14, 4.2, 4.3, 5.7, 7.5, 8.9};

    std::cout << "Product of vectors: " << product_vectors(x, y);

    std::cout << std::endl;
    return 0;
}

template <typename T1, typename T2>
auto larger(T1 a, T2 b) -> decltype(a > b ? a : b)
{
    return a > b ? a : b;
}

