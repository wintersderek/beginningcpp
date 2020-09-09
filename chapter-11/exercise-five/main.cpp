#include "Integer.h"

void printChange(Integer& value);
void incrementOne();

int main() 
{
    const int one {12};
    const int two {24};
    const int three {42};

    Integer::printCount();
    
    Integer value_one {one};
    Integer value_two {two};

    Integer::printCount();

    Integer value_three {three};
    Integer value_four {value_three};

    incrementOne();
    Integer::printCount();
    std::cout << value_one.getInteger() << " compared to " 
              << value_two.getInteger() << ": " 
              << (value_one.compare(value_two)) << "\n"
              << value_four.getInteger() << " compared to " 
              << value_three.getInteger() << ": "
              << (value_four.compare(value_three)) << "\n";
    Integer::printCount();

}

void incrementOne()
{
    Integer myInteger {57};
    std::cout << "Created My Integer!" << "\n";
    Integer::printCount();
}

    void printChange(Integer &value)
{
    std::cout << "Integer Value: " << value.getInteger() << "\n";
    value.setInteger((value.getInteger() + 12)); 
    std::cout << "Set Value: ";
    value.printInteger();
    std::cout << "\n";
}