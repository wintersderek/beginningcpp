#include "Integer.h"

void printChange(Integer& value);

int main() 
{
    const int one {12};
    const int two {24};
    const int three {42};

    Integer value_one {one};
    Integer value_two {two};
    Integer value_three {three};
    Integer value_four {value_one};

    printChange(value_one);
    printChange(value_two);
    printChange(value_three);
    printChange(value_four);

    const Integer value_five {value_two.getInteger() + 7};
    std::cout << "Value 5: " << value_five.getInteger() << "\n";
    value_five.printInteger();
    std::cout << std::endl;
}

void printChange(Integer &value)
{
    std::cout << "Integer Value: " << value.getInteger() << "\n";
    value.setInteger((value.getInteger() + 12)); 
    std::cout << "Set Value: ";
    value.printInteger();
    std::cout << "\n";
}