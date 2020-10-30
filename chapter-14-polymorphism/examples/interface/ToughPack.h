#ifndef TOUGHPACK_H
#define TOUGHPACK_H

#include "Box.h"

class ToughPack : public Box
{
public:
    // Constructor
    ToughPack(double lv, double wv, double hv) : Box {lv, wv, hv} {}

    ~ToughPack() = default;
    
    // Volume is 15% less due to packing material
    double volume() const override
    {
        return (0.85 * Box::volume());
    }
};

#endif