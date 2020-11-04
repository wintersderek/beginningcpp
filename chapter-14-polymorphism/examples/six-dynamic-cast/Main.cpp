#include <iomanip>
#include <iostream>
#include <memory>
#include "Box.h"
#include "Carton.h"
#include "ToughPack.h"
#include "CerealPack.h"
#include "Contents.h"


int main (int argc, char* argv[])
{
    std::unique_ptr<Box> pBox {
        std::make_unique<CerealPack>(20.0, 30.0, 40.0, "Cardboard", "Raisin Bran")
    };

    pBox->showVolume();

    Contents* pContent {dynamic_cast<Contents*>(pBox.get())};
    if (pContent == nullptr)
    {
        std::cout << "Dynamic cast failed.\n";
    }
    else
    {
        std::cout << "Dynamic cast succeded.\n";
        pContent->printContent();
    }

    pBox = std::make_unique<Carton>(20.0, 30.0, 40.0);
    pContent = dynamic_cast<Contents*>(pBox.get());
    
    if (pContent == nullptr)
    {
        std::cout << "Dynamic cast failed.\n";
    }
    else
    {
        std::cout << "Dynamic cast succeded.\n";
        pContent->printContent();
    }
    pBox->showVolume();

    std::cout << std::endl;
    return EXIT_SUCCESS;
}

