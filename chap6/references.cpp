// Show how references work

#include <iostream>
#include <iomanip>

int main () {
    double data {3.5};
    double& r_data {data};

    std::cout << std::left
              << std::setw(20) << "Address of data:"
              << &data << "\n"
              << std::setw(20) << "Address of r_data:"
              << &r_data << std::endl;

    return 0;
}