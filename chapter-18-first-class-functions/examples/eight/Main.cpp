#include <iomanip>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "Optimum.h"


int main(int argc, char const *argv[])
{
    auto less {[](int x, int y) -> bool { return x < y; }};
    auto greater {[](int x, int y) ->bool {return x > y; }};

    std::vector<int> my_values {9, 8, 7, 6, 5, 4, 21};

    std::cout << std::left;
    std::cout << std::setw(22) << "Least: " << (*find_optimum(my_values, less)) << '\n';
    std::cout << std::setw(22) << "Greatest: " << (*find_it(my_values, greater)) << '\n';

    /* Do some string comparisons */
    auto longest { 
        [](const std::string& x, const std::string& y) { return x.length() > y.length(); }
    };
    auto alpha_low {
        [](const std::string& x, const std::string& y) { return x < y; }
    };
    auto alpha_high{
        [](const std::string &x, const std::string &y) { return x > y; }
    };

    std::vector<std::string> str_values {"This", "is", "the", "value", "for", "comparison"};
    std::cout << std::setw(22) << "Longest string: " << (*find_optimum(str_values, longest)) << '\n';
    std::cout << std::setw(22) << "First alphabetically: " << (*find_optimum(str_values, alpha_low)) << '\n';
    std::cout << std::setw(22) << "Last alphabetically: " << (*find_optimum(str_values, alpha_high)) << '\n';

    int my_number {};
    std::cout << "Enter a number: ";
    std::cin >> my_number;

    auto nearer {[&](int x, int y) { 
        ++my_number;
        return std::abs(x - my_number) < std::abs(y - my_number);
    }};
    std::cout << std::setw(22) << "Nearest my number is: " 
              << (*find_optimum(my_values, nearer)) << '\n';

    std::cout << std::setw(22) << "My Number: " << my_number << '\n';
    std::cout << std::endl;
    return 0;
}
