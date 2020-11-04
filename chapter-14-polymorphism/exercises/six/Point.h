#ifndef POINT_H
#define POINT_H

class Point
{
protected:
    double x_axis {1.0};
    double y_axis {1.0};

public:
    Point(double x, double y) : x_axis{x}, y_axis{y} {}
    ~Point() = default;

    double getX() const { return x_axis; }
    double getY() const { return y_axis; }
};
#endif