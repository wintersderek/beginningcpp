#ifndef CURVEBALL_H
#define CURVEBALL_H
#include <exception>
#include <string>
#include <string_view>

class CurveBall : public std::exception
{
protected:
    std::string message;

public:
    CurveBall(std::string_view msg="Issue") : message {msg} {}

    virtual const char* what() const noexcept override { return message.c_str(); }
};

#endif