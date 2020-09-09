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
    int _integer;
    static inline size_t objectCount {};

public:
    explicit Integer(int integer = 0);
    Integer() : Integer (0) {};
    Integer(const Integer& x);
    ~Integer();

    int getInteger() const { return _integer; }
    void setInteger(int integer) { _integer = integer; }
    void printInteger() const 
    {
        std::cout << _integer;
    }

    int compare(const Integer& x) const;
    
    static void printCount();
};

Integer::Integer(int integer) : _integer {integer}
{
    ++Integer::objectCount;
    std::cout << "Constructor has been called." << std::endl;
}

Integer::Integer(const Integer& x) : Integer(x._integer)
{
    std::cout << "Copy constructor has been called." << std::endl;
}

Integer::~Integer()
{
    --Integer::objectCount;
}

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

void Integer::printCount()
{
    std::cout << "Current object count: " << Integer::objectCount << "\n";
}
#endif