#ifndef BOX_H
#define BOX_H
#include <iostream>

class Box
{
protected:
    double length {1.0};
    double width {1.0};
    double height {1.0};

public:
    // Constructors
    Box() = default;
    Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv} 
    {
        //std::cout << "Box(double, double, double)\n";
    }

    Box(const Box& box) : Box{box.length, box.width, box.height}
    {
        //std::cout << "Box(const Box&)\n";
    }

    virtual ~Box() { std::cout << "~Box() called\n"; }

    // Behavior
    void showVolume() const
    {
        std::cout << "Box usable volume is " << volume() << '\n';
    }

    virtual double volume(int i=5) const
    {
        return (length * width * height);
    }
};
#endif