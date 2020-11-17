#ifndef NUMBEREXCEPTIONS_H
#define NUMBEREXCEPTIONS_H
#include <stdexcept>
#include <iostream>
#include <string>

class NotANumber : public std::domain_error
{
public:
    NotANumber(const std::string& value) : 
        std::domain_error {value + " is not a number"} {}
};

class NegativeNumber : public std::domain_error
{
public:
    NegativeNumber (int value) : 
        std::domain_error {std::to_string(value) + " is a negative number"} {}
};

class OddNumber : public std::domain_error
{
public: 
    OddNumber(int value) : 
        std::domain_error {std::to_string(value) + " is an odd number"} {}
};

#endif