#include <iomanip>
#include <iostream>
#include <memory>
#include "Box.h"
#include "Carton.h"
#include "ToughPack.h"
#include "CerealPack.h"
#include "Contents.h"
#include "XPack.h"


int main (int argc, char* argv[])
{
    ToughPack pack {1.0, 2.0, 3.0};
    pack.showVolume();

    
    XPack xpack {1.0, 2.0, 3.0};
    xpack.showVolume();

    std::cout << std::endl;
    return EXIT_SUCCESS;
}

