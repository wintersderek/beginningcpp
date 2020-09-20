#ifndef EXAMPLE_ONE
#define EXAMPLE_ONE
#include <memory>
#include "Random.h"

class Box
{
    private:
        static inline std::unique_ptr<RandomNumber> generator {nullptr};
        double length;
        double width;
        double height;

    public:
        Box(double lv, double wv, double hv) : length{lv}, width{wv}, height{hv} {}

        Box() : Box(1.0, 1.0, 1.0) {}

        double volume () const { return length * width * height; } 

        bool operator < (const Box& rBox) const
        {
            return this->volume() < rBox.volume();
        }

        bool operator > (const Box& rBox) const
        {
            return this->volume() > rBox.volume();
        }

        static Box getRandomBox();
};

Box Box::getRandomBox()
{
    if (generator == nullptr)
    {
        // Create the random number generator
        generator = std::make_unique<RandomNumber>(1, 20);
    }
    return Box(generator->getNext(), generator->getNext(), generator->getNext());
}

#endif