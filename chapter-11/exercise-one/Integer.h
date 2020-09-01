/*
Header for the Integer class
    - private member variable of type int
    - public getter, setter
    - public printer
*/

#ifndef HDI_INTEGER
#define HDI_INTEGER
#include <iostream>

class Integer
{
private:
    int _integer {};

public:
    explicit Integer(int integer);
    ~Integer() = default;

    int getInteger() const { return _integer; }
    void setInteger(int integer) { _integer = integer; }
    void printInteger() const 
    {
        std::cout << _integer;
    }
};

Integer::Integer(int integer) : _integer {integer}
{
    std::cout << "Constructor has been called." << std::endl;
}
#endif