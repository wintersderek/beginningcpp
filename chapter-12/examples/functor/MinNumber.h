#ifndef MIN_NUMBER_H
#define MIN_NUMBER_H
#include "NumberContainer.h"

class MinNumber
{
public:
    SharedNumber operator()(const NumberContainer& container);
};
#endif