// Demonstrate the use of stringstream

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

int main () 
{
    std::stringstream content {};
    std::stringstream val {"123 5.47 23.56 x yesterday"};
    std::vector<double> values;
    size_t value_count {};

    std::cout << "How many values would you like to enter: ";
    std::cin >> value_count;

    // Fill the vector with values
    for (size_t i {}; i < value_count; ++i) 
    {
        double d {};
        std::cin >> d;
        values.push_back(d);
    }

    auto initial_precision = content.precision();

    for (size_t i {}; i < values.size(); ++i)
    {
        content << std::setprecision(4) << std::setw(8) << std::right
                << values[i];

        if ((i+1) % 5 == 0)
        {
            content << std::endl;
        }
    }

    std::cout << content.str() << std::endl;

    std::cout << val.str() << std::endl;
    int a {};
    float b {};
    double c {};
    char d {};
    std::string e {};

    val >> a >> b >> c >> d >> e;

    std::cout << a << "\n" << b << "\n" << c << "\n" << d<< "\n" << e
              << std::endl;
              

    return 0;
}