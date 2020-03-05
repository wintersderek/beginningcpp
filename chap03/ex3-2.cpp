// How many square boxes can fit on a rectangular self.

#include <iostream>
const double INCHES_IN_FOOT {12.0};

int main()
{
    // Read the dimensions of the shelf in feet.  The length and depth must
    // be of type double.
    double shelf_length {};
    double shelf_depth {};
    std::cout << "Enter the shelf length in feet: ";
    std::cin >> shelf_length;
    std::cout << "\nEnter the shelf depth in feet: ";
    std::cin >> shelf_depth;

    // Read the dimension of the box in inches.  The dimension must be
    // type int.
    int box_dimension {};
    std::cout << "\nEnter box dimension: ";
    std::cin >> box_dimension;

    // Calculate the number of boxes the shelf can hold in a single layer
    // of type long and output the results.
    long boxes {static_cast<long>((shelf_length * INCHES_IN_FOOT) / box_dimension) *
                static_cast<long>((shelf_depth * INCHES_IN_FOOT) / box_dimension)};

    std::cout << "\nBoxes that will fit: " << boxes << std::endl;

    return 0;
}
