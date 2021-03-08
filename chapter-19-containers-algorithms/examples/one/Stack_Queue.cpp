/*
Show how a stack and a queue work
*/

#include <iomanip>
#include <iostream>
#include <stack>
#include <queue>

int main(int argc, char const *argv[])
{
    std::stack<int> my_stack {};
    std::queue<int> my_queue {};
    for(size_t i {1}; i <= 10; ++i) my_stack.push(i);
    for(size_t i {1}; i <= 10; ++i) my_queue.push(i);

    std::cout << "Stack: ";
    std::cout << std::left;
    while(!my_stack.empty())
    {
        std::cout << std::setw(3) << my_stack.top();
        my_stack.pop();
    }
    std::cout << "\nQueue: ";
    while(!my_queue.empty())
    {
        std::cout << std::setw(3) << my_queue.front();
        my_queue.pop();
    }
    std::cout << '\n';

    std::cout << std::endl;
    return 0;
}
