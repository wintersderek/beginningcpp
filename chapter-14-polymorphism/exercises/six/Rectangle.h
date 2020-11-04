#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape
{
protected:
    double width;
    double height;

public:
    Rectangle(const Point& leftCorner, double wv, double hv) : 
        Shape {leftCorner}, width {wv}, height {hv} {}
    
    double area() const override { return width * height; }
    double perimeter() const override { return 2 * (width + height); }
    void scale(double factor) override 
    { 
        width *= factor;
        height *= factor;
    }
};
#endif