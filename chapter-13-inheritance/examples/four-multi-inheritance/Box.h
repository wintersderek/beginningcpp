#ifndef BOX_H
#define BOX_H

#include <iomanip>
#include <iostream>

class Box
{
protected:
    double length {1.0};
    double width {1.0};
    double height {1.0};
    
public:
    // Constructors
    Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv} {
        std::cout << "Box(double, double, double) called\n";
    }

    Box(double side) : Box{side, side, side}
    {
        std::cout << "Box(side) called\n";
    }

    Box()
    {
        std::cout << "Box()\n";
    }

    Box(const Box& box) : length {box.length}, width {box.width}, height {box.height}
    {
        std::cout << "Box(const Box&) called\n";
    }

    ~Box()
    {
        std::cout << "~Box() called\n";
    }

    // Behavior
    double volume() const { return length * width * height; }
    // Mutators

    // Accessors
    double getLength() const { return length; }
    double getWidth() const { return width; }
    double getHeight() const { return height; }
};

std::ostream& operator<<(std::ostream& output, const Box& box)
{
    output << "Box(" << std::setw(2) << box.getLength() << ',' << std::setw(2)
           << box.getWidth() << ',' << std::setw(2) << box.getHeight() << ')';
    return output;
}
#endif