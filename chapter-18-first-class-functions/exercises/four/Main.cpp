/*
Exercise 18-4. Create a generic function that collects all elements of a vector<T>
that satisfy a given unary callback function. This callback function accepts a T value
and returns a Boolean value that indicates whether the element should be part of the
function’s output. The resulting elements are to be collected and returned in another
vector. Use this higher-order function to gather all numbers greater than a user
provided value from a sequence of integers, all capital letters from a sequence of
characters, and all palindromes from a sequence of strings. A palindrome is a string
that reads the same backward and forward (such as, for example, "racecar", "noon",
or "kayak").
*/

#include <cctype>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "RandomGenerator.h"

template <typename T, typename Compare>
std::vector<T> collectElements(const std::vector<T>& values, Compare comp);

template <typename T>
void print_vector(const std::vector<T>& values, unsigned per_row, unsigned width);

int main(int argc, char const *argv[])
{
    int user_value {};
    std::cout << "Enter a number to partition the set between 1 and 100: ";
    std::cin >> user_value;
    // higher-order: numbers greater than a user provided value
    auto numbers {[user_value](int test) -> bool { return test > user_value; }};

    // higher-order: all capital letters
    auto characters {[](char test) -> bool { return std::isupper(test); }};

    // higher-order: all palindromes
    auto palindromes {[](const std::string& test) -> bool {
        bool result {true};
        for (size_t i {}; i < (test.size() / 2); i++)
        {
            if (test[i] != test[(test.size() - 1 - i)])
            {
                result = false;
                break;
            }
        }
        return result;
    }};

    // Create vector of numbers
    RandomGenerator rg {1, 100};
    std::vector<int> values_int = rg.getRandomInts(30);
    // Create vector of characters 65 - 122
    RandomGenerator rg_two {65, 122};
    std::vector<char> values_chars = rg_two.getRandomChars(30);
    // Create vector of palindroms
    std::vector<std::string> values_pal {
        "racecar", "noon", "kayak", "derek", "imelda", "emma", "danny", "ere",
        "redivider", "deified"
    };

    // Test number gatherer
    std::vector<int> matching_ints = collectElements(values_int, numbers);

    // Test character gatherer
    std::vector<char> matching_chars = collectElements(values_chars, characters);

    // Test palindrom gatherer
    std::vector<std::string> matching_palin = collectElements(values_pal, palindromes);

    // Print new vectors
    std::cout << std::left;
    print_vector(matching_ints, 10, 5);
    std::cout << '\n';
    print_vector(matching_chars, 15, 3);
    std::cout << '\n';
    print_vector(matching_palin, 3, 11);

    std::cout << std::endl;
    return 0;
}

template <typename T, typename Compare>
std::vector<T> collectElements(const std::vector<T>& values, Compare comp)
{
    std::vector<T> results;

    for(size_t i {}; i < values.size(); ++i)
    {
        if (comp(values[i]))
            results.push_back(values[i]);
    }
    return results;
}

template <typename T>
void print_vector(const std::vector<T>& values, unsigned per_row, unsigned width)
{
    if (values.empty()) return;

    for(size_t i {}; i < values.size(); )
    {
        std::cout << std::setw(width) << values[i];

        if (++i % per_row == 0)
            std::cout << '\n';
    }
}