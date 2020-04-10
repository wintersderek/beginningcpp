// Record day temperatures and get average using smart pointers
#include <iostream>
#include <iomanip>
#include <cctype>
#include <memory>
#include <vector>

int main () {
    // Create a vector of shared poiters to vector of double
    std::vector<std::shared_ptr<std::vector<double>>> records;
    size_t day {1};

    while (true) {
        // Create vector as a pointer to store current days temperatures
        auto p_record { std::make_shared<std::vector<double>>() };
        records.push_back(p_record);

        std::cout << "Enter temperatures for day " << day++
                  << " separated by spaces.  Enter 1000 to end:\n";

        // Get the days temperatures
        while (true) {
            double t {};
            std::cin >> t;

            if (t == 1000.0) break;

            p_record->push_back(t);
        }

        std::cout << "Enter another day's temperature (Y/n)? ";
        char answer {};
        std::cin >> answer;
        if (std::toupper(answer) != 'Y') break;
    }

    day = 1;

    std::cout << std::fixed << std::setprecision(2) << std::endl;

    for(auto record : records) {
        double total {};
        size_t count {};

        std::cout << "Temperature for day " << day++ << ":\n";
        for (auto temp : *record) {
            std::cout << temp << "\t";
            total += temp;
            
            if (++count % 5 == 0) {
                std::cout << std::endl;
            }
        }
        std::cout << "\nAverage Temperature: " << total/count << std::endl;
    }

    return 0;
}