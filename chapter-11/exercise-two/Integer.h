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
    Integer() : Integer (0) {};
    Integer(const Integer& x);
    ~Integer() = default;

    int getInteger() const { return _integer; }
    void setInteger(int integer) { _integer = integer; }
    void printInteger() const 
    {
        std::cout << _integer;
    }

    //int compare(const Integer& x) const;
    int compare(const Integer x) const;
};

Integer::Integer(int integer) : _integer {integer}
{
    std::cout << "Constructor has been called." << std::endl;
}

Integer::Integer(const Integer& x) : Integer(x.getInteger())
{
    std::cout << "Copy constructor has been called." << std::endl;
}

/*
int Integer::compare(const Integer& x) const
{
    if (_integer < x.getInteger())
    {
        return -1;
    }
    else if (_integer == x.getInteger())
    {
        return 0;
    }
    else
    {
        return +1;
    }    
}
*/
int Integer::compare(Integer x) const
{
    if (_integer < x.getInteger())
    {
        return -1;
    }
    else if (_integer == x.getInteger())
    {
        return 0;
    }
    else
    {
        return +1;
    }
    
}
#endif