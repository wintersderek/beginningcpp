#include <memory>
#include "MyNumber.h"

int main()
{
    auto one {std::make_unique<MyNumber>(3.14)};
    std::cout << "One Value: " << (one->getMyNumber()) << "\n";

    MyNumber numbers[10] {};

    MyNumber copyNumber {numbers[1]};

    std::cout << "Count: " << MyNumber::getObjectCount() << "\n";

    std::cout << std::endl;
}