/*
Exercise 9-4: create a template for my_size that mimics std::size.  It must
              work for the following types
    - fixed arrays
    - std::vectors
    - std::array
*/

#include <iostream>
#include <vector>
#include <array>

template <typename T, size_t N>
inline size_t my_size(const T (&array)[N]){ return N; }

template <typename T>
inline size_t my_size(const std::vector<T>& a) { return a.size(); }

template <typename T, size_t N>
inline size_t my_size(const std::array<T, N>& a) { return a.size(); }

int main ()
{
    double double_values[] {1.5, 2.7, 3.14, 8.9};
    int int_values[3] {};

    std::cout << "Size of doule_values: " << my_size(double_values) << "\n";

    std::cout << "Size of int_values: " << my_size(int_values) << "\n";

    std::cout << "Size of char {values}: " 
              << my_size({'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}) << "\n";

    std::vector<int> my_vector {};
    std::cout << "Size of my_vector: " << my_size(my_vector) << "\n";

    std::array<int, 12> my_array {};
    std::cout << "Size of my_array: " << my_size(my_array);

    std::cout << std::endl;
    return 0;
}

template <typename T1>
size_t my_size(const T1 a)
{
    return a.size();
}