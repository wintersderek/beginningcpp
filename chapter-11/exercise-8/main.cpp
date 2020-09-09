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

    const size_t count {7};

    // Add <count> packages to the truck load
    for (size_t i {}; i < count; ++i)
    {
        load_one.addBox(randomBox(myRandom));
    }

    // List the boxes in the truck load
    load_one.listBoxes();
    load_one.listBoxesReverse();


    // Iterate boxes forward
    std::cout << "\n\n****************   FORWARD  ****************" << '\n';
    TruckLoad::Iterator it{load_one.getIterator()};
    SharedBox next {it.getNextBox()};
    while (next)
    {
        next->listBox();
        next = it.getNextBox();
        if (next)
        {
            next->listBox();
            next = it.getNextBox();
        }
    }

    // Iterate boxes reverse
    std::cout << "\n****************   BACKWARD  ****************" << '\n';
    SharedBox previous {it.getLastBox()};
    while (previous)
    {
        previous->listBox();
        previous = it.getPreviousBox();
    }

    std::cout << "DONE!" << std::endl;
}

