#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>
#include <utility>

// Sort a range of vector elements
template <typename T, typename Compare>
void quicksort(std::vector<T> &data, Compare& comp, size_t start, size_t end)
{
    // Start index must be less than end index for 2 or more elements
    if (!(start < end))
        return;

    // Choose middle value to partition set
    std::swap(data[start], data[(start + end) / 2]); // Swap middle value with start

    // Check data against chosen value
    size_t current{start}; // The index of the last element less than the chosen element (after partitioning)
    for (size_t i{start + 1}; i <= end; ++i)
    {
        // The comparison callback evaluate i truer than the partition element.
        // It is && with decending (true for decending, false for ascending)
        if (comp(data[i], data[start]))    // Is comparison with chosen element?
            std::swap(data[++current], data[i]); // Yes, so swap to the left
    }

    // Swap the partition (first element) with the last element that returned
    // true in the for loop
    std::swap(data[start], data[current]);

    if (current)
        quicksort(data, comp, start, current - 1); // Sort left subset if exists
    quicksort(data, comp, current + 1, end);       // Sort right subset if exists
}

template <typename T, typename Compare>
void quicksort(std::vector<T>& data, Compare& comp)
{
    if (!data.empty())
        quicksort(data, comp, 0, data.size() - 1);
}
#endif