//Find mode

#include <iostream>
#include <vector>

int main () {
    std::vector<int> values {1, 2, 3, 4, 5, 6, 7, 7, 7, 8, 8, 9, 10, 11, 12, 12, 12, 12};

    std::vector<std::pair<int, int>> log {};

    // Find the count of each value in values
    for (size_t i {}; i < values.size(); ++i) {
        bool in_log {};

        for (size_t j {}; j < log.size(); ++ j) {
            if (log[j].first == values[i]) {
                // Number is already in log, so we need to increment value 
                // and break the loop.
                ++log[j].second;
                in_log = true;
                break;
            }
        }

        if (!in_log) {
            log.push_back(std::make_pair(values[i], 1));
        }
    }

    // Determine which number has the most values
    std::vector<std::pair<int, int>> most {};
    for (size_t i {}; i < log.size(); ++i) {
        
        if (most.size() == 0 || log[i].second > most[0].second) {
            // Clear most and add new pair
            most.clear();
            most.push_back(log[i]);
        } else if (log[i].second == most[0].second) {
            most.push_back(log[i]);
        }
    }

    // Print out the modes
    std::cout << "The modes are: ";
    for (size_t i {}; i < most.size(); ++i) {
        std::cout << most[i].first << " ";
    }

    std::cout << std::endl;
    return 0;
}