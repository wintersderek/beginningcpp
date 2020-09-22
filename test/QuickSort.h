#ifndef HDI_QUICK_SORT
#define HDI_QUICK_SORT
#include <vector>

namespace hdi
{
    template <typename T>
    void quick_sort(std::vector<T>& values, size_t start, size_t end);
    
    // Quick sort helper function
    template <typename T>
    void quick_sort(std::vector<T>& values)
    {
        if (values.size() > 1)
        {
            quick_sort(values, 0, values.size() - 1);
        }
    }

    template <typename T>
    void quick_sort(std::vector<T>& values, size_t start, size_t end)
    {
        // Don't perform a sort if there is only one element
        if (!(start < end))
        {
            return;
        }

        // Get the middle element
        size_t middle{(start + end) / 2};
        // Swap the start and the middle element
        T temp = values[start];
        values[start] = values[middle];
        values[middle] = temp;
        middle = start;

        // Put all values less than our middle value just to the right of it
        for (size_t i{start + 1}; i <= end; ++i)
        {
            if (values[i] < values[start])
            {
                // We have a value.  Put it to the right of our test value and
                // increment the "swap" position.
                temp = values[++middle];
                values[middle] = values[i];
                values[i] = temp;
            }
        }

        // Swap start and middle to put all elements less that start to the left.
        temp = values[start];
        values[start] = values[middle];
        values[middle] = temp;

        // Sort the elements less than middle
        if (middle > start)
        {
            hdi::quick_sort(values, start, middle - 1);
        }

        // Sort the elements greater than middle
        if (middle < end)
        {
            hdi::quick_sort(values, middle + 1, end);
        }
    }
}
#endif