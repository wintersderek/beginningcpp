// Demonstrate a flat multi-dimentional array

#include <iostream>

int main () {
    int rows {}, columns {};
    std::cout << "Enter rows: ";
    std::cin >> rows;
    std::cout << "Enter columns: ";
    std::cin >> columns;

    // Create a flat array in the free store
    int* p_table { new int [rows * columns] };

    std::cout << "Elements: " << (rows * columns) << std::endl;

    for (size_t i {}; i < (rows * columns); ++i) {
        p_table[i] = i;
    } 

    while (true) {
        int i {}, j {};
        std::cout << "Enter row to get (or 1000 to exit): ";
        std::cin >> i;
        if (i == 1000)
            break;
        
        std::cout << "Enter column to get (or 1000 to exit): ";
        std::cin >> j;
        if (j == 1000)
            break;

        std::cout << "Value [" << i << "][" << j << "] = " 
                  << p_table[i * columns + j] << std::endl;
    }
    return 0;
}