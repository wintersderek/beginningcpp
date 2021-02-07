/*
Test if you can have a function pointer that retains state with a static
variable.
*/

#include <iostream>

using Test = void (*)();

void my_callback();
void write_stuff(Test my_test);

int main(int argc, char const *argv[])
{
    auto* cb = &my_callback;
    write_stuff(cb);
    std::cout << std::endl;
    return 0;
}

void my_callback()
{
    static int current {};
    ++current;
    std::cout << "Current: " << current << '\n';
}

void write_stuff(Test my_test)
{
    for (size_t i {}; i < 10; ++i)
    {
        my_test();
    }
}