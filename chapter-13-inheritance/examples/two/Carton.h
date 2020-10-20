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
    // Constructors
    explicit Carton(std::string_view m) : material {m} 
    {
        std::cout << "Carton(std::string_view)\n";
    }

    Carton (double lv, double wv, double hv, std::string_view mat) : Box{lv, wv, hv}, 
                                                                     material{mat} 
    {
        std::cout << "Carton(lv, wv, hv, mat) called\n";
    }

    Carton (double side, std::string_view mat) : Box{side}, material {mat}
    {
        std::cout << "Carton(double, std::string_view) called\n";
    }

    Carton()
    {
        std::cout << "Carton()\n";
    }
    // Accessors
    std::string_view getMaterial() const { return material; }

    // Member behavior
    //double carton_volume() const { return length*width*height; } // Won't compile because base class members are private
};

#endif