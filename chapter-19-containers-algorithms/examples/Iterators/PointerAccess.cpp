/*
Demonstrate pointer access with iterators
*/

#include <iomanip>
#include <iostream>
#include <vector>

std::vector<char> getCharacters()
{
    std::vector<char> result(26);
    //std::cout << "Size of vector: " << result.size() << '\n';
    char start {'a'};
    for (size_t i {}; i < result.size(); ++i, ++start)
    {
        result[i] = start;
    }
    return result;
}

void printVector(const std::vector<char>& x)
{
    for(size_t i {}; i < x.size(); ++i)
    {
        std::cout << x[i] << ' ';
    }
}

int main(int argc, char const *argv[])
{
    std::vector<char> one = getCharacters();

    auto it = one.cbegin();
    auto back = one.cend();
    std::cout << "Start: " << *it << "\nReverse: ";

    it += 10;

    for (size_t i {5}; i > 0; --i, --it)
    {
        std::cout << *it << ' ';
    }
    std::cout << "\nForward: \n";

    for(size_t i {26}; i > 0; --i, ++it)
    {
        if (it == one.cend()) break;
        std::cout << *it << '-';
    }
    
    std::cout << std::endl;
    return 0;
}
