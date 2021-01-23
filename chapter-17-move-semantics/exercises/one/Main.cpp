#include <iostream>
#include "Box.h"
#include "Truckload.h"

SharedBox makeBox(double lv, double wv, double hv)
{
    return std::make_shared<Box>(lv, wv, hv);
}

Truckload makeTruck()
{
    Truckload result {};
    result.addBox(makeBox(1,2,3));
    result.addBox(makeBox(2,3,4));
    result.addBox(makeBox(3,4,5));
    return result;
}

int main(int argc, char const *argv[])
{
    // Test the move constructor
    Truckload a {makeTruck()};
    //a.addBox(std::make_shared<Box>(1, 2, 3));
    Truckload b {};
    b = std::move(a);

    // Test the move assignment
    std::cout << std::endl;
    return 0;
}
