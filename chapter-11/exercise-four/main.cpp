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
    Integer value_four {value_three};

    std::cout << value_one.getInteger() << " compared to " 
              << value_two.getInteger() << ": " 
              << compare(value_one, value_two) << "\n"
              << value_four.getInteger() << " compared to " 
              << value_three.getInteger() << ": "
              << compare(value_four, value_three) << "\n";
}

void printChange(Integer &value)
{
    std::cout << "Integer Value: " << value.getInteger() << "\n";
    value.setInteger((value.getInteger() + 12)); 
    std::cout << "Set Value: ";
    value.printInteger();
    std::cout << "\n";
}