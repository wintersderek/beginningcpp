#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
#include "Random.h"

class Number
{
private:
    static RandomNumber rg;
    double _number;

public:
    explicit Number(double number) : _number{number}
    {
#ifdef DEBUG
        std::cout << "Constructor called\n";
#endif
    }

    ~Number() = default;

    inline std::ostream& write(std::ostream& stream) const 
    {
        stream << this->_number;
        return stream;
    }

    inline double getNumber() const { return _number; }

    inline operator float () const 
    { 
#ifdef DEBUG
        std::cout << "Type conversion to float\n";
#endif
        return 12.5f; 
    }

    static Number getRandomNumber();
};

std::ostream& operator<<(std::ostream& stream, const Number& number);

#endif