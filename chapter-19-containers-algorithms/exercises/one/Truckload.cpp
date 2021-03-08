#include <algorithm>
#include <iterator>
#include <stdexcept>
#include "Truckload.h"

// Constructor - vector of Boxes
Truckload::Truckload(const std::vector<SharedBox> &boxes)
{
    std::copy(boxes.cbegin(), boxes.cend(), std::back_inserter(this->boxes));
}

// Swap function (noexcept!)
void Truckload::swap(Truckload& other) noexcept
{
    boxes.swap(other.boxes);
}

// Remove a Box from the Truckload
bool Truckload::removeBox(SharedBox box)
{
    // Use the remove erase idiom
    auto it = std::remove(std::begin(boxes), std::end(boxes), box);
    const bool result = it != std::end(boxes);
    boxes.erase(it, std::end(boxes));
    return result;
}

// Overloaded subscript operator
SharedBox& Truckload::operator[](size_t index)
{
    if (index >= boxes.size())
    {
        throw std::out_of_range(std::to_string(index) + " is out of range");
    }
    return boxes[index];
}

// Stream output operator to replace listBoxes() member
std::ostream& operator<<(std::ostream& stream, const Truckload& load)
{
    std::for_each(load.cbegin(), load.cend(), [&stream](SharedBox b) {
        stream << (*b) << '\n';
    });
    return stream;
}

void swap(Truckload& one, Truckload& other) noexcept
{
    one.swap(other);
}