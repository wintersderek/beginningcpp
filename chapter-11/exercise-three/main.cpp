#include "Integer.h"

void printChange(Integer& value);

int main() 
{
    Integer value_four {4};
    Integer value_five {5};
    Integer value_six {6};
    Integer value_seven {7};
    Integer value_eight {8};

    std::cout << "Calculation: " << value_eight.add(Integer(Integer(value_seven.multiply(value_five.getInteger())).getInteger()).add(Integer(Integer(value_six.multiply(value_five.multiply(value_five.getInteger()))).getInteger()).add(Integer(value_four.multiply(value_five.multiply(value_five.multiply(value_five.getInteger())))).getInteger())));
    
    std::cout << std::endl;
}