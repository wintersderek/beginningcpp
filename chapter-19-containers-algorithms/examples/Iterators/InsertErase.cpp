/*
Show how .insert() and .erase() work on containers
*/
#include <iomanip>
#include <iostream>
#include <vector>

template <typename T>
void PrintVector(const std::vector<T>& values, unsigned width=2, size_t per_line=20);

int main(int argc, char const *argv[])
{
    std::cout << std::left;
    std::vector<char> values {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'};
    std::cout << std::setw(10) << "Initial:";
    PrintVector(values);
    auto it = values.cbegin();
    values.insert(it, 'A');
    
    it = values.cbegin();
    ++it;
    values.insert(it, 'B');
    it = values.cbegin();
    it += 5;
    PrintVector(values);
    std::cout << "Going to erase: " << *it << '\n';
    values.erase(it);
    it = values.cbegin();
    it +=7;
    std::cout << "Going to erase: " << *it << '\n';
    values.erase(it);
    std::cout << std::setw(10) << "Final:";
    PrintVector(values);

    return 0;
}

template <typename T>
void PrintVector(const std::vector<T>& values, unsigned width, size_t per_line)
{
    size_t i {0};
    for(const auto& x : values)
    {
        std::cout << std::setw(width) << x;
        if (++i % per_line == 0)
        {
            std::cout << '\n';
        }
    }
    std::cout << '\n';   
}
