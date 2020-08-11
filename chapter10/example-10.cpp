/*
Use static asserts
*/

#include <iostream>
#include <vector>
#include <string>
#include "average.h"

int main ()
{
    const std::vector<double> data {1.5, 2.5, 3.5, 4.5};
    std::cout << "Average of data: " << test_sa::average(data) << "\n";

    //const std::vector<std::string> v_string {"Imelda", "Derek", "Dani", "Emma"};
    //std::cout << "Average of v_string: " << test_sa::average(v_string) << "\n";

    const std::vector<float> v_empty;
    std::cout << "Average of v_empty: " << test_sa::average(v_empty) << "\n";

    std::cout << std::endl;
    return 0;
}