// Demonstrate multi-dimentional arrays

#include <iostream>

int main () {

    size_t rows {};
    size_t columns {};

    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> columns;


    // Dynamically create a pointer to a int[] of pointers to int[]
    int** p_rows { new int*[rows] {} };
    for(size_t i {}; i < rows; ++i) {
        p_rows[i] = new int [columns];

        for (size_t j {}; j < columns; ++j) {
            //std::cout << i*j << std::endl;
            p_rows[i][j] = i * j;
        }
    }

    for (size_t i {}; i < rows; ++i) {
        std::cout << "row[" << i << "]:\t";
        for (size_t j{}; j < columns; ++j) {
            std::cout << p_rows[i][j];
            if (j + 1 != columns) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }

    for (size_t i {}; i < rows; ++i) {
        delete[] p_rows[i];
        p_rows[i] = nullptr;
    }
    delete[] p_rows;
    p_rows = nullptr;

    return 0;
}