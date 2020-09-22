#ifndef EXAMPLE_ONE
#define EXAMPLE_ONE
#include <algorithm>
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
        Box(double value_one, double value_two, double value_three);

        Box() : Box(1.0, 1.0, 1.0) {}

        Box(const Box& box) : Box(box.length, box.width, box.height)
        {
#ifdef HDI_DEBUG
            std::cout << "Copy Constructor called\n";
#endif
        }

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

        inline bool operator == (const Box& box) const
        {
            return this->height == box.height && this->length == box.length &&
                   this->width == box.width;
        }

        inline Box operator+(const Box& box) const
        {
#ifdef HDI_DEBUG
            std::cout << "+ operator called\n";
#endif
            Box copy {*this};
            copy += box;
            return copy;
        }

        inline Box& operator+=(const Box& box)
        {
#ifdef HDI_DEBUG
            std::cout << "+= operator called\n";
#endif
            this->length = std::max(length, box.length);
            this->width = std::max(width, box.width);
            this->height += box.height;
            return *this;
        }

        /* Other members */
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