#include <iostream>
#include "MyObject.h"

int main (int argc, char* argv[])
{
    MyObject myObj {};
    std::cout << "myObj.getFive(): " << myObj.getFive() << '\n';
    std::cout << "The end." << std::endl;
    return EXIT_SUCCESS;
}