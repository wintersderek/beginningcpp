#include <chrono>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "../../../RandomGenerator.h"

int main(int argc, char const *argv[])
{
    const unsigned number{100'000'000};
    const auto one {std::chrono::high_resolution_clock::now()};
    std::vector<int> values{getInts(number, 0, RAND_MAX)};
    const auto two {std::chrono::high_resolution_clock::now()};

    const auto three {std::chrono::high_resolution_clock::now()};
    std::vector<int> other{getIntsV2(number, 0, RAND_MAX)};
    const auto four {std::chrono::high_resolution_clock::now()};

    std::cout << "One: " << std::chrono::duration_cast<std::chrono::seconds>(two - one).count()
              << '\n'
              << "Two: " << std::chrono::duration_cast<std::chrono::seconds>(four - three).count();

/*
    std::cout << '\n'
              << std::setw(14) << "Initial Size:" << initial << '\n'
              << std::setw(14) << "Final Size: " << final_size; */
    std::cout << std::endl;
    return 0;
}