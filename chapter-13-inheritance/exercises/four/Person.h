#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <string_view>

enum class Gender
{
    Male,
    Female
};

class Person
{
private:
    std::string name;
    unsigned int age;
    Gender gender;

public:
    // Constructors
    Person(std::string_view name_val, unsigned int age_val, Gender gender_val) :
        name {name_val}, age {age_val}, gender {gender_val} {}

    void who(std::string_view type_name="Person") const;

    std::string_view getGenderText() const;

};
#endif