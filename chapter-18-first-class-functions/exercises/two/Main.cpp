/*
 Exercise 18-2. Throughout this book you’ve already defined various sort functions but
always to sort elements in ascending order and always according to the evaluation of
the < operator. Clearly, a truly generic sorting function would benefit from a comparison
callback, completely analogous to the find_optimum<>() templates that you worked
with throughout this chapter. 
    - Take the solution to Exercise 9-6 and generalize its sort<>() template accordingly. 
    - Sort a sequence of integers in descending order (that is, from large to small); 
    - Sort a sequence of characters alphabetically, ignoring the case ('a' must rank 
      before 'B', even though 'B' < 'a'); 
    - Sort a sequence of floating-point values in ascending order but ignoring the 
      sign (5.5 should thus precede -55.2 but not -3.14).
*/

#include <algorithm>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include "QuickSort.h"

std::string string_to_lower(std::string_view value);
std::string str_to_lower(std::string value);

template <typename T>
void print_vector(unsigned width, unsigned per_line, std::vector<T>& values);

int main(int argc, char const *argv[])
{
    auto greater {[](int x, int y) -> bool { return x > y; }};
    auto lesser {[](double x, double y) -> bool { return std::abs(x) < std::abs(y); }};
    auto alpha {[](std::string_view x, std::string_view y) {
        std::string lhs (string_to_lower(x));
        std::string rhs {string_to_lower(y)};
        return lhs < rhs;
    }};
    auto lower_compare {[](std::string x, std::string y) {
        return str_to_lower(x) < str_to_lower(y);
    }};

    std::vector<int> integers{45, 89, 23, 56, 9, 12, 79, 33};
    std::vector<double> floats{5.5, -55.2, -3.14, 7.5, 2.6, 9.1, -9.9};
    std::vector<std::string> names{"Imelda", "derek", "Danny", "tom", "Emma", "Yessica", "jeff", "eric", "scott", "angus"};
    std::cout << std::left;

    sort(integers, greater);
    print_vector(4, 7, integers);
    
    sort(floats, lesser);
    print_vector(7, 5, floats);

    sort(names, lower_compare);
    print_vector(10, 4, names);

    std::cout << std::endl;
    return 0;
}

std::string string_to_lower(std::string_view value)
{
    std::string result{std::string(value)};

    for (size_t i{}; i < result.size(); ++i)
    {
        if (std::isupper(result[i]))
            result[i] = std::tolower(result[i]);
    }
    return result;
}

std::string str_to_lower(std::string value)
{
    std::transform(value.begin(), 
                   value.end(), 
                   value.begin(),
                   [] (unsigned char x) { return std::tolower(x); });
    return value;
}

template <typename T>
void print_vector(unsigned width, unsigned per_line, std::vector<T>& values)
{
    for(size_t i {}; i < values.size(); )
    {
        std::cout << std::setw(width) << values[i];
        if (++i % per_line == 0)
            std::cout << '\n';
    }
    std::cout << '\n';
}