/*
Lambda Closure naming example
*/
#include <iostream>

int main (int argc, const char* argv[])
{
    auto less { [](int x, int y) -> bool { return x < y; }};

    std::cout << "5 < 3: " << (less(5, 3) ? "true" : "false") << '\n';
    std::cout << "3 < 5: " << (less(3, 5) ? "true" : "false") << '\n';

    std::cout << std::endl;
    return EXIT_SUCCESS;
}