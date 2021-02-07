#include <iomanip>
#include <iostream>
#include <vector>
#include "Statistics.h"

int main(int argc, char const *argv[])
{
    std::vector<double> my_data {};
    double (*pCenter)(std::vector<double>&) {average};
    //auto* pAverage = &average<int>;

    std::cout << std::setprecision(4);
    std::cout << std::setw(8) << "Average" << std::setw(8) << "Mean\n";
    for (size_t i {1}; i <= 10; ++i)
    {
        pCenter = &average;
        my_data.push_back(i);
        //pCenter = &average<int>;
        std::cout << std::setw(8) << pCenter(my_data);
        pCenter = &mean;
        std::cout << std::setw(8) << pCenter(my_data) << '\n';
    }

    my_data.push_back(3.2);
    my_data.push_back(5.9);
    my_data.push_back(5.8);
    //my_data.push_back(17.9);

    std::sort(my_data.begin(), my_data.end());

    std::cout << pCenter(my_data);

    std::cout << std::endl;
    return 0;
}
