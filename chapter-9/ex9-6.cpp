/*
Exercise 9-6: create quick sort as a template for vectors of any type
    - template should also be created to stream a vector of any type to cout
*/

#include <iostream>
#include <vector>

// Template to output a vector of any type
template <typename T> 
void out_vector(const std::vector<T>& a, const char* label);

// Template for quick sort helper
template <typename T> void quick_sort(std::vector<T>& a);

// Template for quick sort of a vector
template <typename T>
void quick_sort(std::vector<T>& a, size_t start, size_t end);


int main ()
{
    std::vector<int> numbers {49, 100, 38, 12, 345, 64, 48, 73, 92};
    out_vector(numbers, "Unsorted");
    quick_sort(numbers);
    out_vector(numbers, "Sorted");

    std::vector<double> fractions {0.9, 0.55, 0.34};
    out_vector(fractions, "Unsorted");
    quick_sort(fractions);
    out_vector(fractions, "Sorted");

    std::vector<char> characters {'z', 'Y', 'c', '4', 'G'};
    out_vector(characters, "Unsorted");
    quick_sort(characters);
    out_vector(characters, "Sorted");

    std::cout << std::endl;
    return 0;
}

template <typename T> 
void out_vector(const std::vector<T>& a, const char* label)
{
    std::cout << "\n=================" << label << "=================\n";
    for(auto& item : a)
    {
        std::cout << item << "\n";
    }
}

/*
Quick sort helper
*/
template <typename T> void quick_sort(std::vector<T>& a)
{
    quick_sort(a, 0, (a.size() - 1));
}

/*
Quick sort for any vector that supports < operator
*/
template <typename T>
void quick_sort(std::vector<T>& a, size_t start, size_t end)
{
    // Only attempt the quick sort on the partition if there is a range
    if (!(start < end))
    {
        return;
    }

    // Choose the middle spot to be the partition fulcrum
    std::swap(a[start], a[(start + end) / 2]);
    size_t fulcrum {start};

    // Line all values less than fulcrum right behind it
    for (size_t i {fulcrum + 1}; i <= end; i++)
    {
        if (a[i] < a[start])
        {
            // swap a[i] and ++fulcrum
            std::swap(a[i], a[++fulcrum]);
        }
    }

    // Swap a[start] and a[fulcrum] to put all values lower than the initial
    // fulcrum below it.
    std::swap(a[start], a[fulcrum]);

    // Execute the sort of the lower partition if needed
    if (fulcrum > start)
    {
        quick_sort(a, start, (fulcrum - 1));
    }

    // Execute the sort of the upper partition if needed
    if (fulcrum < end)
    {
        quick_sort(a, (fulcrum + 1), end);
    }
}