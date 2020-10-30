#ifndef CEREALPACK_H
#define CEREALPACK_H
#include "Carton.h"
#include "Contents.h"

class CerealPack : public Carton, public Contents
{
public:
    CerealPack(double lv, double wv, double hv, std::string_view mat, std::string_view cont="Cereal") :
        Carton{lv, wv, hv, mat}, Contents{cont} {}

    ~CerealPack()
    {
        std::cout << "~CerealPack() called\n";
    }
};
#endif