/*
Exercise 19-1. In practice, we would never recommend you to implement your own 
    linked list data structure to store Boxes in Truckload. At the time it made 
    perfect sense to practice nested classes, as well as working with pointers; 
    but normally you should follow our advice from earlier in this chapter and 
    simply use a vector<> instead (a polymorphic vector<>, to be precise — see
    Chapter 14). If you need a sequence container, a vector<> is almost always 
    the way to go!  Eliminate the linked list from the Truckload class of 
    Exercise 17-1 according to this guideline.  Notice how you can now adhere 
    to the rule of zero as well (see Chapter 18)?
*/

// Exercise 17-1 Define move operators for the Truckload class
#include <iostream>
#include <memory>
#include <cstdlib> // For random number generator
#include <ctime>   // For time function
#include "Truckload.h"

// Function to generate integral random box dimensions from 1 to max_size
inline double random(double max_size)
{
    return 1.0 + rand() / (RAND_MAX / max_size + 1);
}

int main()
{
    const double dimLimit{99.0};        // Upper limit on Box dimensions
    std::srand((unsigned)std::time(0)); // Initialize the random number generator
    Truckload load;
    const size_t boxCount{10}; // Number of Box object to be created

    // Create boxCount Box objects (one too many)
    for (size_t i{}; i < boxCount + 1; ++i)
        load.addBox(std::make_shared<Box>(random(dimLimit), random(dimLimit), random(dimLimit)));

    // Remove the middle box
    std::cout << "Size Before Remove: " << load.getSize() << '\n';
    load.removeBox(load[load.getSize() / 2]);
    std::cout << "Size After Remove: " << load.getSize() << '\n';

    std::cout << "The boxes in the Truckload are:\n";
    std::cout << load;
    std::cout << "-------\n";

    // Rule of zero: even though we haven't defined any copy/move members,
    // defaults are generated for us that work correctly now!
    Truckload moveConstructedLoad(std::move(load));

    std::cout << "The boxes in the move constructed Truckload are:\n";
    std::cout << moveConstructedLoad;

    Truckload moveAssignedLoad;
    moveAssignedLoad = std::move(moveConstructedLoad);

    std::cout << "The boxes in the move assigned Truckload are:\n";
    std::cout << moveAssignedLoad;
}