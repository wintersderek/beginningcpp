//Manager.h
#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include "Box.h"

class Manager
{
public:
    void watchEmployees(Box& sb) const 
    {
        std::cout << "employee delivered box\n";
    }
private:

};
#endif