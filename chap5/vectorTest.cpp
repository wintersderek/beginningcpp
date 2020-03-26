// Showcase the use of the std::vector<T>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> values {1, 2, 3, 5, 7};

    values.push_back(11);
    std::cout << "Vector Size: " << values.size() << std::endl;

    for (auto i : values) {
        std::cout << "Value: " << i << std::endl;
    }

    values.clear();
    std::cout << "Vector Size After Clear: " << values.size() << std::endl;

    values.assign(20, 10);
    std::cout << "Vector Size after assign: " << values.size() << std::endl;

    values.pop_back();
    std::cout << "Vector Size after pop_back: " << values.size()
              << std::endl;
    return 0;
}