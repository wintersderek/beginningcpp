/*
Demonstrate the usage of a priority queue
*/

#include <iomanip>
#include <iostream>
#include <functional>
#include <queue>
#include <vector>
#include "RandomGenerator.h"

int main(int argc, char const *argv[])
{
    std::priority_queue<double, std::vector<double>,std::less<>> myqueue {};
    RandomGenerator rd {100, 1};

    for(size_t i {}; i < 20; ++i)
    {
        //std::cout << std::setw(10) << rd() << '\n';
        myqueue.push(rd());
        //std::cout << "Top: " << myqueue.top() << '\n';
    }

    while (!myqueue.empty())
    {
        std::cout << myqueue.top() << '\n';
        myqueue.pop();
    }

    std::cout << std::endl;
    return 0;
}
