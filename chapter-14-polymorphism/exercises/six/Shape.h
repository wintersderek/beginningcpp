#ifndef SHAPE_H
#define SHAPE_H
#include "Point.h"

class Shape
{
protected:
    Point position;

    Shape(const Point& shapePosition) : position {shapePosition} {}

public:
    virtual ~Shape() = default;

    virtual double area() const = 0;
    virtual void scale(double factor) = 0;
    virtual double perimeter() const = 0;

    virtual void move(const Point& newPosition) { position = newPosition; }
};
#endif