/*
Temporary class to test the TruckLoad class.
*/
#include <iostream>
#include <vector>
#include "RandomNumber.h"
#include "Truckload.h"

inline SharedBox randomBox(RandomNumber& rd)
{
    return std::make_shared<Box>(rd.getNext(), rd.getNext(), rd.getNext());
}

int main()
{
    // Create the random number generator
    RandomNumber myRandom {1, 99};

    // Create the truck load
    TruckLoad load_one {};

    const size_t count {12};

    // Add <count> packages to the truck load
    for (size_t i {}; i < count; ++i)
    {
        load_one.addBox(randomBox(myRandom));
    }

    // List the boxes in the truck load
    load_one.listBoxes();

    // Copy the load_one to load_two and then find the largest box in load_two
    TruckLoad load_two{load_one};
    SharedBox biggest = TruckLoad::getBiggest(load_two);
    std::cout << "Largest box: ";
    biggest->listBox();
    std::cout << "\n"; 

    load_two.removeBox(biggest);
    load_two.listBoxes();

    // Create a vector with 20 boxes
    const size_t box_count {20};
    std::vector<SharedBox> boxes {};

    for (size_t i {0}; i < box_count; ++i)
    {
        boxes.push_back(randomBox(myRandom));
    }

    // Create a truckload from the vector
    TruckLoad load_three {boxes};

    // List the truckload
    load_three.listBoxes();

    // Find the smallest box using a for loop
    auto smallest {TruckLoad::getSmallest(load_three)};
    std::cout << "Smallest: ";
    smallest->listBox();
    std::cout << std::endl;
}

