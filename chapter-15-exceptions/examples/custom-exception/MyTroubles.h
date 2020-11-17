#ifndef MYTROUBLES_H
#define MYTROUBLES_H
#include <iostream>
#include <string>
#include <string_view>

class Trouble
{
protected:
    std::string message;

public:
    Trouble(std::string_view msg = "An error happened.") : message{msg} 
    {
#ifdef DEBUG
        std::cout << "Trouble(std::string_view) called\n";
#endif
    }

    Trouble(const Trouble& t)
    {
        message = t.message;
#ifdef DEBUG
        std::cout << "Trouble(&) called\n";
#endif
    }

    ~Trouble()
    {
#ifdef DEBUG
        std::cout << "~Trouble() called\n";
#endif
    }

    std::string_view what() const { return message; }
};
#endif