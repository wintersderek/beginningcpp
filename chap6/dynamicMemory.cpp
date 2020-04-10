// Allocate memory on the free store with new

#include <iostream>
#include <iomanip>

int main () {
    double* pvalue {new double};
    

    std::cout << "Address of new: " << pvalue << "\n"
              << "Value of new: " << *pvalue << std::endl;
    *pvalue = 3.1415;

    std::cout << "Value of new: " << *pvalue << std::endl;

    // Create and Delete many dynamically allocated memory areas in free store
    for(size_t i {}; i < 1'000; ++i) {
        double temp {*pvalue + i};
        delete pvalue;
        pvalue = nullptr;
        pvalue = new double {temp};
    }

    std::cout << "Value: " << *pvalue << std::endl;
    delete pvalue;
    pvalue = nullptr;

    size_t max_size {};
    std::cout << "Enter max size: ";
    std::cin >> max_size;
    int* p_ints { new int[max_size] {} };
    std::cout << "new[] address: " << p_ints << std::endl;
    for (size_t i {}; i < max_size; ++i) {
        //std::cout << i;
        //*(p_ints + i) = i;
        p_ints[i] = i;
    }

    // Print the dynamic array in reverse order
    for (size_t i {}; i < max_size; ++i) {
        std::cout << "[" << ((max_size - 1) - i) << "] = " 
                  << *(p_ints + ((max_size - 1) - i)) << std::endl;
    }

    delete[] p_ints;
    p_ints = nullptr;
    std::cout << "Done" << std::endl;

    return 0;
}