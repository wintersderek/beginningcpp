#include <iostream>
#include <vector>
#include "Employee.h"
#include "Executive.h"

int main(int argc, char* argv[])
{
    std::vector<Employee> employees;
    std::vector<Executive> executives;

    employees.push_back(Employee{"Derek", 49, Gender::Male, 312});
    employees.push_back(Employee{"Tom", 38, Gender::Male, 418});
    employees.push_back(Employee{"Jafeth", 21, Gender::Male, 245});
    employees.push_back(Employee{"Stuart", 39, Gender::Male, 134});
    employees.push_back(Employee{"Robert", 52, Gender::Male, 114});

    executives.push_back(Executive{"Imelda", 47, Gender::Female, 001});
    executives.push_back(Executive{"Dani", 10, Gender::Female, 002});
    executives.push_back(Executive{"Emma", 3, Gender::Female, 003});
    executives.push_back(Executive{"Yessica", 39, Gender::Female, 004});
    executives.push_back(Executive{"Tara", 46, Gender::Female, 005});

    for(size_t i {0}; i < employees.size(); ++i)
    {
        employees[i].who();
    }
    std::cout << '\n';
    for (size_t i {0}; i < executives.size(); ++i)
    {
        executives[i].who();
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}