#ifndef CARTON_H
#define CARTON_H
#include <string>
#include <string_view>
#include "Box.h"

class Carton : public Box
{
private:
    std::string material;

public:
    Carton(double lv, double wv, double hv, std::string_view mat="Cardboard") :
        Box{lv, wv, hv}, material {mat} {}

    ~Carton() = default;
    
    double volume() const override
    {
        const double vol {(length - 0.5) * (width - 0.5) * (height - 0.5)};
        return (vol > 0.0) ? vol : 0.0;
    }
};

#endif