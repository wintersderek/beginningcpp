#include <iomanip>
#include <iostream>

#include "Box.h"
#include "Carton.h"
#include "ToughPack.h"

void showTheReference(const Box& box);

int main (int argc, char* argv[])
{
    Box box {20.0, 30.0, 40.0};
    ToughPack hard_box {20.0, 30.0, 40.0};
    Carton carton {20.0, 30.0, 40.0, "Plastic"};

    showTheReference(box);
    showTheReference(hard_box);
    showTheReference(carton);

    std::cout << std::endl;

    return EXIT_SUCCESS;
}

void showTheReference(const Box& box)
{
    std::cout << "Box usable volume is " << box.volume() << '\n';
}