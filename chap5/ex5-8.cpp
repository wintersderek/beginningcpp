// Print out the first 93 fibbonaci numbers using an <array>
#include <array>
#include <iostream>
#include <limits>

int main () {
    const size_t max_size {93};
    std::array<unsigned long long, max_size> fibbonaci {1, 1};

    for(size_t i {2}; i < fibbonaci.size(); ++i) {
        fibbonaci[i] = fibbonaci[i - 2] + fibbonaci[i - 1];
    }

    for (auto i : fibbonaci) {
        std::cout << i << std::endl;
    }

    std::cout << std::numeric_limits<unsigned long long>::max()
              << " (limit)" << std::endl;
    return 0;
}