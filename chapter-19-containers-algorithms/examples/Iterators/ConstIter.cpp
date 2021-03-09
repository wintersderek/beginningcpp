/*
Show how const iterators cannot modify elements
*/

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char const *argv[])
{
    const std::vector<std::string> values {"This", "is", "the", "value", "list"};

    auto it = values.begin();
    (*it)[0] = 't';
    it->clear();

    for(const auto x : values)
    {
        std::cout << x << '\n';
    }

    std::cout << std::endl;
    return 0;
}
