#ifndef TOUGHPACK_H
#define TOUGHPACK_H

#include "Box.h"

class ToughPack : public Box
{
public:
    // Constructor
    ToughPack(double lv, double wv, double hv) : Box {lv, wv, hv} 
    {
        std::cout << "ToughPack(double, double, double) - volume(): " 
                  << volume() << '\n';
    }

    ~ToughPack() { 
        std::cout << "~ToughPack() - volume(): " << volume() << '\n'; 
    }
    
    // Volume is 15% less due to packing material
    double volume(int i=500) const override
    {
        //std::cout << "ToughPack parameter = " << i << '\n';
        return (0.85 * Box::volume());
    }
};

#endif