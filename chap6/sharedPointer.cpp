// Demonstrate shared pointers std::shared_ptr<T>

#include <iostream>
#include <iomanip>
#include <memory>

int main () {
    // Define shared pointer with new
    std::shared_ptr<int> p_one { new int {42} };
    // Define shared pointer with std::make_shared<T>()
    auto p_two { std::make_shared<int>(12) };

    std::cout << std::left
              << std::setw(20) << "Value One:" 
              << std::hex << std::showbase << p_one << "\n" << std::dec
              << std::setw(20) << "Value One *:" << *p_one << "\n"
              << std::setw(20) << "Value Two:" 
              << std::hex << std::showbase << p_two << "\n" << std::dec
              << std::setw(20) << "Value Two *:" << *p_two << std::endl;

    return 0;
}