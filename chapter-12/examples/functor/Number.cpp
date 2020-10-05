/*  Initialization and Non-inline members for Number.h */
#include "Number.h"


std::ostream &operator<<(std::ostream &stream, const Number &number)
{
    return number.write(stream);
}

RandomNumber Number::rg = RandomNumber(1, 100);

Number Number::getRandomNumber()
{
    return Number(Number::rg.getNext());
}