/*
Show that an std::forward_list<> can only move forward with pointers
*/
#include <chrono>
#include <iomanip>
#include <iostream>
#include <forward_list>
#include "RandomGenerator.h"

auto GetList(size_t members)
{
    std::forward_list<unsigned char> result;
    CharGenerator gen {};

    for(size_t i {}; i < members; ++i)
        result.push_front(gen());

    return result;
}

int main(int argc, char const *argv[])
{
    auto mylist = GetList(1000000);
    size_t i {0};

    std::chrono::time_point t_one = std::chrono::high_resolution_clock::now();
    for (auto it {mylist.cbegin()}; it != mylist.cend(); ++it)
    {
        std::cout << std::setw(2) << *it;
        if (++i % 30 == 0)
            std::cout << '\n';
    }
    std::chrono::time_point t_two = std::chrono::high_resolution_clock::now();

    std::cout << '\n';
    i = 0;

    std::chrono::time_point t_three = std::chrono::high_resolution_clock::now();
    for (const auto x : mylist)
    {
        std::cout << std::setw(2) << x;
        if (++i % 30 == 0)
            std::cout << '\n';
    }
    std::chrono::time_point t_four = std::chrono::high_resolution_clock::now();
    std::cout << '\n';
    i = 0;

    std::chrono::time_point t_five = std::chrono::high_resolution_clock::now();
    for (auto&& x : mylist)
    {
        std::cout << std::setw(2) << x;
        if (++i % 30 == 0)
            std::cout << '\n';
    }
    std::chrono::time_point t_six = std::chrono::high_resolution_clock::now();
    std::cout << '\n';
    std::cout << '\n';
    // Calculate the times
    std::chrono::duration d_one = std::chrono::duration_cast<std::chrono::nanoseconds>(t_two - t_one);
    std::chrono::duration d_two = std::chrono::duration_cast<std::chrono::nanoseconds>(t_four - t_three);
    std::chrono::duration d_three = std::chrono::duration_cast<std::chrono::nanoseconds>(t_six - t_five);

    std::cout << std::left;
    std::cout << std::setw(15) << "For iterator:" << d_one.count() << '\n'
              << std::setw(15) << "Range-For:" << d_two.count() << '\n' 
              << std::setw(15) << "Range-For&&:" << d_three.count();



    std::cout << std::endl;
    return 0;
}
