#include <iostream>
#include <typeinfo>
#include "Box.h"
#include "Carton.h"

class NonPolyBased 
{
/*
public:
    virtual ~NonPolyBased () = default;
    */
};

class NonPolyDerived : public NonPolyBased {};

Box& GetSomeBox();
NonPolyBased& GetSomeNonPoly();

int main (int argc, char* argv[])
{
    // Part 1: typeid() on types and == operator
    std::cout << "Type double has name " << typeid(double).name() << std::endl;
    std::cout << "1 is " << (typeid(1) == typeid(int) ? "an int" : "no int") << "\n\n";

    // Part 2: typeid() on polymorphic references
    Carton carton{1, 2, 3, "paperboard"};
    Box &boxReference = carton;
    
    std::cout << "Type of carton is " << typeid(carton).name() << std::endl;
    std::cout << "Type of boxReference is " << typeid(boxReference).name() << std::endl;
    std::cout << "These are " << (typeid(carton) == typeid(boxReference) ? "" : "not ")
              << "equal\n\n";
    
    // Part 3: typeid() on polymorphic pointers
    Box *boxPointer = &carton;
    std::cout << "Type of &carton is " << typeid(&carton).name() << std::endl;
    std::cout << "Type of boxPointer is " << typeid(boxPointer).name() << std::endl;
    std::cout << "Type of *boxPointer is " << typeid(*boxPointer).name() << "\n\n";
    
    // Part 4: typeid() with non-polymorphic classes
    NonPolyDerived derived;
    NonPolyBased &baseRef = derived;
    std::cout << "Type of baseRef is " << typeid(baseRef).name() << "\n\n";
    
    // Part 5: typeid() on expressions
    const auto &type_info1 = typeid(GetSomeBox());     // function call evaluated
    const auto &type_info2 = typeid(GetSomeNonPoly()); // function call not evaluated
    std::cout << "Type of GetSomeBox() is " << type_info1.name() << std::endl;
    std::cout << "Type of GetSomeNonPoly() is " << type_info2.name() << std::endl;
    return EXIT_SUCCESS;
}

Box& GetSomeBox()
{
    std::cout << "GetSomeBox() called ...\n";
    static Carton box {2, 3, 5, "duplex"};
    return box;
}

NonPolyBased& GetSomeNonPoly()
{
    std::cout << "\t\tGetSomeNonPoly() called ...\n";
    static NonPolyDerived non;
    return non;
}
