#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <utility>
#include <vector>

template <typename T, typename Compare>
void bubblesort(std::vector<T>& values, Compare& comparison)
{
    // Don't do anything if values is empty
    if (values.empty()) return;

    while (true)
    {
        bool swapped {false};

        for (size_t i {}; i < (values.size() - 1); ++i)
        {
            if (comparison(values[i+1], values[i]))
            {
                std::swap(values[i], values[i + 1]);
                swapped = true;
            }
        }

        if (!swapped) break; // Entire vector is sorted

        if (comparison.getCount() % 1000 == 0)
        {
            std::cout << '.';
        }
    }
}

#endif