#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle : public Shape
{
protected:
    double radius;

public:
    static constexpr double pi {3.141592653589793238462643383279502884};

    Circle(const Point& center, double circleRadius) : 
        Shape {center}, radius {circleRadius} {}

    double area() const override { return radius * radius * pi; }
    void scale(double factor) override { radius *= factor; }
    double perimeter() const override { return 2 * pi * radius; }
};

#endif