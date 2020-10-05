#include "Box.h"

Box Box::getRandomBox()
{
    if (generator == nullptr)
    {
        // Create the random number generator
        generator = std::make_unique<RandomNumber>(1, 8);
    }
    return Box(generator->getNext(), generator->getNext(), generator->getNext());
}