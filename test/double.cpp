#include <iostream>

int main(){
    const double kPenny {0.01};
    double z {.02};
    int i = (z / kPenny);
    std::cout << ".02 / .01 = " << i << std::endl;
}