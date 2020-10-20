#include <iostream>
#include "Ardvark.h"
#include "Lion.h"

int main (int argc, char* argv[])
{
    Lion lion {"Leo", 400};
    Ardvark ardvark {"Algernon", 50};

    lion.who();
    ardvark.who();
    
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
