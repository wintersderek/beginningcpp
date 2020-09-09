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

    const size_t count {20};

    // Add <count> packages to the truck load
    for (size_t i {}; i < count; ++i)
    {
        load_one.addBox(randomBox(myRandom));
    }

    load_one.listBoxes();

    // Get largest box
    auto biggest {TruckLoad::getBiggest(load_one)};
    std::cout << "Removing Box: ";
    biggest->listBox();
    load_one.removeBox(biggest);

    // List boxes
    load_one.listBoxes();
}

