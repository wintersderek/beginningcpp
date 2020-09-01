#include "MyNumber.h"

MyNumber::MyNumber(double value)
{
#ifdef HDI_DEBUG
    std::cout << "Constructor called" << std::endl;
#endif
    _value = value;
    ++MyNumber::object_count;
}

MyNumber::MyNumber(const MyNumber& x) : MyNumber::MyNumber(x._value)
{
#ifdef HDI_DEBUG
    std::cout << "\tCopy Constructor" << std::endl;
#endif
}

MyNumber::~MyNumber()
{
#ifdef HDI_DEBUG
    std::cout << "Destructor called" << std::endl;
#endif
    --MyNumber::object_count;
}

