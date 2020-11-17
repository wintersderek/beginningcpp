#ifndef TOOMANYEXCEPTIONS_H
#define TOOMANYEXCEPTIONS_H
#include "CurveBall.h"

class TooManyExceptions : public CurveBall
{
public:
    TooManyExceptions(std::string_view msg="Too Many Exceptions...") :
        CurveBall {msg} {}
};

#endif