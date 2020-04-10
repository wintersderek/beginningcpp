// Use the indirect member selection variable

#include <iostream>
#include <vector>

int main () {
    std::vector<int>* p_data { new std::vector<int> };
    std::vector<int> data;

    int test {5};

    p_data->push_back(1);
    p_data->push_back(test);

    return 0;
}