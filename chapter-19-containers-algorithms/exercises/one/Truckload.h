// Truckload.h
#ifndef TRUCKLOAD_H
#define TRUCKLOAD_H

#include "Box.h"
#include <memory> // For std::shared_ptr<>
#include <vector>

using SharedBox = std::shared_ptr<Box>;

class Truckload
{
private:
    std::vector<SharedBox> boxes;

public:
    Truckload() = default; // No-arg constructor - empty truckload

    Truckload(SharedBox box) // Constructor - one Box
    {
        boxes.push_back(box);
    }

    Truckload(const std::vector<SharedBox> &boxes); // Constructor - vector of Boxes

    size_t getSize() const { return boxes.size(); }
    
    void swap(Truckload &other) noexcept; // Swap function (noexcept!)

    std::vector<SharedBox>::const_iterator cbegin() const { return boxes.cbegin(); }
    std::vector<SharedBox>::const_iterator cend() const { return boxes.cend(); }
    std::vector<SharedBox>::iterator begin() {return boxes.begin(); }
    std::vector<SharedBox>::iterator end() { return boxes.end(); }

    void addBox(SharedBox box) { boxes.push_back(box); }; // Add a new Box
    bool removeBox(SharedBox box);                        // Remove a Box from the Truckload

    SharedBox& operator[](size_t index); // Overloaded subscript operator
};

// Stream output operator to replace listBoxes() member
std::ostream &operator<<(std::ostream &stream, const Truckload &load);

// Non-member swap
void swap(Truckload& one, Truckload& other) noexcept;

#endif