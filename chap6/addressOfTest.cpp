
#include <iostream>

int main () {
    int value {365};
    int value_two {420};

    int* pvalue {&value};

    std::cout << "My Value " << value << " resides at " << pvalue << std::endl;

    std::cout << "Dereferenced: " << *pvalue << std::endl;
    *pvalue = 180;
    std::cout << "Dereferenced Assignment: " << *pvalue << std::endl;
    std::cout << "Address: " << pvalue << std::endl;
    pvalue = &value_two;
    std::cout << "Changed address of pointer\n\tNew Value: " << *pvalue 
              << "\n\tNew Address: " << pvalue << std::endl;

    return 0;
}