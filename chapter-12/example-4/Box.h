#ifndef EXAMPLE_ONE
#define EXAMPLE_ONE
#include <iostream>
#include <memory>
#include <utility>
#include "Random.h"

class Box
{
    private:
        static inline std::unique_ptr<RandomNumber> generator {nullptr};
        double length;
        double width;
        double height;

    public:
        /* Constructors */
        Box(double lv, double wv, double hv) : length{lv}, width{wv}, height{hv} {}

        Box() : Box(1.0, 1.0, 1.0) {}

        /* Getters */
        inline double getLength () const { return length; }
        inline double getWidth () const { return width; }
        inline double getHeight() const { return height; }

        /* Members */
        inline double volume () const { return length * width * height; } 

        /* Operators */
        inline bool operator < (const Box& rBox) const
        {
            return this->volume() < rBox.volume();
        }

        bool operator < (double x) const;

        inline void print() const
        {
            std::cout << "Box(" << this->height << 'x' << this->length << 'x'
                      << this->width << ") -(" << this->volume() << ')';
        }

        inline bool operator == (const Box& box) const
        {
            return this->height == box.height && this->length == box.length &&
                   this->width == box.width;
        }

        inline std::ostream& write(std::ostream& out) const
        {
            out << "Box(" << (this->length) << ", " << (this->width) << ", "
                << (this->height) << ')';
            return out;
        }
        
        static Box getRandomBox();
};

inline bool Box::operator<(double x) const
{
    return this->volume() < x;
}

inline bool operator<(double x, const Box& box)
{
    return x < box.volume();
}

std::ostream& operator<<(std::ostream& stream, const Box& box);

#endif