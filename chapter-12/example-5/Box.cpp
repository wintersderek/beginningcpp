#include <vector>
#include "Box.h"
#include "QuickSort.h"

Box::Box(double value_one, double value_two, double value_three)
{
    std::vector<double> temp {value_one, value_two, value_three};
    hdi::quick_sort(temp);
    this->length = temp[2];
    this->width = temp[1];
    this->height = temp[0];
}

Box Box::getRandomBox()
{
    if (generator == nullptr)
    {
        // Create the random number generator
        generator = std::make_unique<RandomNumber>(1, 8);
    }
    return Box(generator->getNext(), generator->getNext(), generator->getNext());
}

std::ostream& operator<<(std::ostream& stream, const Box& box)
{
    box.write(stream);
    return stream;
}