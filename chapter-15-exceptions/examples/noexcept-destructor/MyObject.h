#ifndef MYOBJECT_H
#define MYOBJECT_H
#include <exception>
class MyObject
{

public:
    MyObject() = default;

    int getFive() const noexcept { return 5; }
    
    ~MyObject() { throw std::exception {}; }
};
#endif