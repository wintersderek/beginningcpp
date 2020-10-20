#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Employee.h"

class Executive : public Employee
{
typedef unsigned int Uint;
public:
    // Constructor
    Executive(std::string_view nv, Uint av, Gender gv, Uint pv) :
        Employee {nv, av, gv, pv} {}

    void who() const;
};

#endif