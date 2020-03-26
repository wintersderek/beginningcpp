// Create an std::vector<int> that contains integers from 1 to an upper bound
// set by the user.  Output each int that is not a multiple of 7 or 13.  Put
// 10 to a line.

#include <iostream>
#include <iomanip>
#include <vector>

int main () {
    std::vector<unsigned int> values;
    unsigned int end {0};

    std::cout << "Enter a upper bound integer: ";
    while (end == 0) {
        std::cin >> end;
    }

    unsigned int i {1};
    do {
        values.push_back(i);
    } while (i++ < end);

    i = 1;
    for (auto x : values) {
        if (!((x%7==0)||(x%13==0)) )
        {
            std::cout << std::setw(10) << x;
            i++;
            if (i > 10) {
                std::cout << std::endl;
                i = 1;
            }
        }
    }

    std::cout << std::endl;
    return 0;
}