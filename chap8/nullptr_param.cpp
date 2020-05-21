// Test what happens when a nullptr is sent to a function and
// it does not check before dereferencing

#include <memory>
#include <iostream>
void test_it(long* test);

int main()
{
    long* value {};

    test_it(value);

    *value = 5;
    std::cout << "Before: " << *value << "\n";
    test_it(value);

    return 0;
}

void test_it(long* test)
{
    if (test == nullptr)
    {
        std::cout << "Test is null!";
    }
    else
    {
        *test += 10;
        std::cout << "Value of test: " << *test;
        std::cout << std::endl;
    }
}