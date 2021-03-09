/*
Exercise 19-5. Not all Standard Library algorithms are defined by the algorithms 
    header. Some are defined by the numeric header as well. One such example is 
    accumulate(). Research this algorithm and use it to implement an 
    algorithm-like function template that computes the average of a given 
    iterator range. Exercise your newly implemented template with a little test 
    program.
*/
#include <iostream>
#include <iterator>
#include <numeric>
#include <optional>
#include <stdexcept>
#include "../../../RandomGenerator.h"

template <typename Container>
double average(const Container& values);

template <typename T, typename Iter>
std::optional<T> average_v2(Iter begin, Iter end);

int main(int argc, char const *argv[])
{
    std::vector<double> values = getDoubleVector(2000000, 1.0, 10.0);
    //std::vector<double> values;
    //printVector(values, 10, 10);
    /*std::cout << "Average One: " << average(values) << "\nAverage Two: "
              << *average_v2<double>(std::begin(values), std::end(values)); */
    std::cout << "Average Two: "
              << *average_v2<double>(std::begin(values), std::end(values));
    std::cout << std::endl;
    return 0;
}

template <typename T, typename Iter>
std::optional<T> average_v2(Iter begin, Iter end)
{
    const auto count {std::distance(begin, end)};
    std::cout << "Count : " << count << '\n';
    T sum = std::accumulate(begin, end, T{});
    return (count != 0) ? std::optional<T>(T{sum/count}) : std::nullopt;
}

template <typename Container>
double average(const Container& values)
{
    if (values.size() == 0)
        throw std::logic_error("Cannot compute average for empty values");

    //double result = std::accumulate(std::begin(values), std::end(values), 0.0);
    return std::accumulate(std::begin(values), std::end(values), 0.0) / 
                (values.size() * 1.0);
}