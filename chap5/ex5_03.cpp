// For loop controlled by floating point
#include <iostream>
#include <iomanip>

int main() {
    const double pi {3.14159265358979323846};
    const size_t per_line {2};
    size_t line_count {};

    for (double radius {0.2}; radius <= 3.0; radius += 0.2) {
        std::cout << std::fixed << std::setprecision(2)
                  << "   radius = " << std::setw(5) << radius
                  << "   area = " << std::setw(6) << pi * radius * radius
                  << "   delta to 3 = " << std::scientific
                  << ((radius + 0.2) - 3.0) << std::endl;

                  /*

        if (per_line == ++line_count) {
            std::cout << std::endl;
            line_count = 0;
        }
        */
    }
    
    std::cout << std::endl;

    return 0;
}