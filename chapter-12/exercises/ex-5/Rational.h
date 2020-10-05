#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational
{
private:
    long numerator;
    long denominator;

public:
    Rational(long n, long d);
    
    // Type Conversion
    explicit operator float () const { return static_cast<float>(numerator) / denominator; }
    explicit operator double () const { return static_cast<double>(numerator) / denominator; }

    std::ostream& write(std::ostream& output) const;
};

Rational::Rational(long n, long d)
{
    if (d == 0) throw "Denominator is zero!";
    numerator = n;
    denominator = +d;
}

std::ostream& Rational::write(std::ostream& output) const
{
    output << this->numerator << '/' << this->denominator;
    return output;
}

std::ostream& operator <<(std::ostream& output, const Rational& r)
{
    r.write(output);
    return output;
}


#endif