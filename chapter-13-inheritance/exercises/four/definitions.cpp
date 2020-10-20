#include <iostream>
#include "Person.h"
#include "Employee.h"
#include "Executive.h"

std::string_view Person::getGenderText() const
{
    switch (gender)
    {
    case Gender::Female:
        return "Female";
        break;
    case Gender::Male:
        return "Male";
        break;
    default:
        return "";
        break;
    }
}
void Person::who(std::string_view type_name) const
{
    std::cout << type_name << ": " << name << ", " << age << ", "
              << getGenderText() << '\n';
}

void Employee::who() const
{
    Person::who("Employee");
}

void Executive::who() const
{
    Person::who("Executive");
}