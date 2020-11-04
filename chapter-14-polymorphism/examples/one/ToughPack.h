#ifndef TOUGHPACK_H
#define TOUGHPACK_H

#include "Box.h"

class ToughPack : public Box
{
public:
    // Constructor
    ToughPack(double lv, double wv, double hv) : Box {lv, wv, hv} {}

    // Volume is 15% less due to packing material
    double volume() const
    {
        return (0.85 * length * width * height);
    }
};

#endif