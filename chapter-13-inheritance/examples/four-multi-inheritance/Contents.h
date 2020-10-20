#ifndef CONTENTS_H
#define CONTENTS_H

#include <iostream>
#include <string>
#include <string_view>

class Contents
{
protected:
    std::string name {"Cereal"};                // Contents Type
    double volume {};                           // Cubic Inches
    double density {0.03};                      // Pounds Per Cubic Inche

public:
    // Constructors
    Contents(std::string_view nv, double vv, double dv) :
        name {nv}, volume {vv}, density {dv}
    {
        std::cout << "Contents(string_view, double, double) called\n";
    }

    Contents(std::string_view nv) : name {nv}
    {
        std::cout << "Contents(string_view) called\n";
    }

    Contents()
    {
        std::cout << "Contents() called\n";
    }

    // Destructor
    ~Contents()
    {
        std::cout << "~Contents() called\n";
    }

    // Behavior
    double getWeight() const
    {
        return volume * density;
    }
};
#endif