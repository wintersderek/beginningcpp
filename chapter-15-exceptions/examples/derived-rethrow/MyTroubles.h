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
    Trouble(std::string_view msg = "There's a problem") : message{msg} {}
    virtual ~Trouble() = default;

    virtual std::string_view what() const { return message; }
};

class MoreTrouble : public Trouble
{
public:
    MoreTrouble(std::string_view msg="There's more trouble...") : 
        Trouble {msg} {}
};

class BigTrouble : public MoreTrouble
{
public:
    BigTrouble(std::string_view msg="Really big trouble...") : 
        MoreTrouble {msg} {}
};
#endif