#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Person.h"

class Employee : public Person
{
private:
    unsigned int p_number;

public:
    // Constructors
    Employee(std::string_view nv, unsigned int av, Gender gv, unsigned int pv) :
        Person {nv, av, gv}, p_number {pv} {}

    void who() const;
};
#endif