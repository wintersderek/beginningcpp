/*
 Exercise 18-3. In this exercise, you will compare the performance of two sorting
algorithms. Given a sequence of n elements, quicksort should in theory use about n
log2 n comparisons on average, and bubble sort n2
. Let’s see whether you can replicate these theoretical results in practice! 
Start by recycling the quicksort template fromthe previous exercise (perhaps 
rename it to quicksort()?). Then you should extractthe bubble sort algorithm from 
Ex5_09, and generalize it to work for any element type and comparison callback as 
well. Next you define an integer comparison functor that counts the number of times 
it is called (it can sort in any which order you prefer). Use it to count the 
number of comparisons that both algorithms need to sort, for instance, sequences 
of 500, 1,000, 2,000, and 4,000 random integer values between 1 and 100.  Do 
these numbers agree, at least more or less, with the theoretical expectations?
*/

#include <cmath>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include "BubbleSort.h"
#include "IntFunctor.h"
#include "QuickSort.h"
#include "RandomGenerator.h"

template <typename T>
    void print_vector(const std::vector<T> &values, 
                      const unsigned per_line,
                      const unsigned width = 5);

double compute_n_log2_n(const unsigned count);

int main(int argc, char const *argv[])
{
    unsigned number_of_randoms {5000};
    RandomGenerator generator {1, 1000};
    std::vector<int> one = generator.getRandoms(number_of_randoms);
    //std::vector<int> two = generator.getRandoms(number_of_randoms);
    std::vector<int> two {one};
    IntFunctor<int> functor_one {};
    IntFunctor<int> functor_two{};
    bubblesort(one, functor_one);
    //print_vector(one, 15, 5);

    std::cout << "\n\n";

    quicksort(two, functor_two);
    //print_vector(two, 15, 5);

    std::cout << "Bubble Sort: " << functor_one.getCount() << "\tTheoretical: "
              << (number_of_randoms * number_of_randoms) << '\n';
    std::cout << "Quick Sort: " << functor_two.getCount() << "\tTheoretical: "
              << compute_n_log2_n(number_of_randoms) << '\n';

    std::cout << std::endl;
    return 0;
}

template <typename T>
    void print_vector(const std::vector<T>& values, 
                      const unsigned per_line, 
                      const unsigned width)
{
    if (values.empty()) return;

    for (size_t i {}; i < values.size();)
    {
        std::cout << std::setw(width) << values[i];
        if (++i % per_line == 0)
        {
            std::cout << '\n';
        }   
    }
    std::cout << '\n';
}

double compute_n_log2_n(const unsigned count)
{
    if (count <= 0) throw std::invalid_argument("Count must be greater than zero");

    return (count * std::log2(count));
}