#ifndef CEREALPACK_H
#define CEREALPACK_H
#include <iostream>
#include "Carton.h"
#include "Contents.h"

class CerealPack: public Carton, public Contents
{
public:
    // Constructors
    CerealPack(double lv, double wv, double hv, std::string_view cerealTypeValue) :
        Carton {lv, wv, hv, "Cardboard"}, Contents {cerealTypeValue}
    {
        std::cout << "CerealPack(double, double, double, "
                  << this->name << ") called\n";
        Contents::volume = 0.9 * Carton::volume();
    }

    // Destructors
    ~CerealPack()
    {
        std::cout << "~CerealPack(" << this->name << ") called\n";
    }
};
#endif