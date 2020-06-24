// Show nuances of char pointers

#include <iostream>

int main () {
    const char* pgreeting {"Hello Derek!"};

    std::cout << "pgreeting = " << pgreeting << std::endl;
    std::cout << "*pgreeting = " << *pgreeting << std::endl;
    std::cout << "&pgreeting = " << &pgreeting << std::endl;

    return 0;
}