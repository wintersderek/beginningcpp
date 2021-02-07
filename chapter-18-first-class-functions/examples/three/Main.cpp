#include <iostream>
#include "Less.h"

int main(int argc, char const *argv[])
{
    Less my_less {};

    std::cout << "5 < 3: " << (my_less(5, 3) ? "true" : "false") << '\n';
    std::cout << "5 < 5: " << (my_less(5, 5) ? "true" : "false") << '\n';
    std::cout << "5 < 7: " << (my_less(5, 7) ? "true" : "false") << '\n';
    std::cout << std::endl;
    return 0;
}
