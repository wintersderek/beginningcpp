/*
Show example of using <cassert> header
*/

#include <iostream>
#include <cassert>

int main()
{
#ifdef TEST_IT
    int a {5}, b{10};
#else
    int a{10}, b{5};
#endif

    assert(a > b);

    std::cout << "Finished.";
    std::cout << std::endl;
    return 0;
}