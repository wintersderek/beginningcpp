#ifndef CAN_H
#define CAN_H
#include "Vessel.h"

// A macro defining the mathematical constant π
#define PI 3.141592653589793238462643383279502884

class Can : public Vessel
{
protected:
    double height {1.0};
    double diameter {1.0};

public:
    Can() = default;
    Can(double hv, double dv) : height{hv}, diameter {dv} {}

    double volume() const override
    { 
        return PI * diameter * diameter * height / 4;
    }
};
#endif