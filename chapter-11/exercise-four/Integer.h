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
    explicit Integer(int integer = 0);
    Integer(const Integer& x);
    ~Integer() = default;

    int getInteger() const { return _integer; }
    void setInteger(int integer) { _integer = integer; }
    void printInteger() const 
    {
        std::cout << _integer;
    }

    //int compare(const Integer& x) const;
    friend int compare(const Integer& x, const Integer& y);
};

Integer::Integer(int integer) : _integer {integer}
{
    std::cout << "Constructor has been called." << std::endl;
}

Integer::Integer(const Integer& x) : _integer{x._integer}
{
    std::cout << "Copy constructor has been called." << std::endl;
}

int compare(const Integer& x, const Integer& y)
{
    std::cout << "\t\tfriend\n\n";
    if (x._integer < y._integer)
    {
        return -1;
    }
    else if (x._integer == y._integer)
    {
        return 0;
    }
    else
    {
        return +1;
    }
}

int not_friend_compare(const Integer &x, const Integer &y)
{
    if (x.getInteger() < y.getInteger())
    {
        return -1;
    }
    else if (x.getInteger() == y.getInteger())
    {
        return 0;
    }
    else
    {
        return +1;
    }
}
#endif