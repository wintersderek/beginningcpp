#ifndef XPACK_H
#define XPACK_H
#include <iostream>
#include "ToughPack.h"

class XPack : public ToughPack
{
public:
    XPack(double lv, double wv, double hv) : ToughPack{lv, wv, hv}
    {
        std::cout << "XPack(double, double, double) - volume(): " 
                  << volume() << '\n';
    }

    ~XPack()
    {
        std::cout << "~XPack() - volume(): " << volume() << '\n';
    }

    double volume(int i=1000) const override
    {
        return 0.80 * Box::volume();
    }
};

#endif