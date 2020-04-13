// Use references in a ranged for loop
#include <iostream>
#include <iomanip>

int main () {

    const double F2C {5.0/9.0};
    double temperatures[] {10, 15, 20, 25, 30, 35, 40};
    
    for (auto& temp : temperatures) {
        temp = (temp - 32.0) * F2C;
    }

    for (size_t i {}; i < std::size(temperatures); ++i){
        std::cout << temperatures[i] << std::endl;
    }
    return 0;
}