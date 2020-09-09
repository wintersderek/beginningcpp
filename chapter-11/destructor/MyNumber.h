#ifndef HDI_MY_NUMBER
#define HDI_MY_NUMBER

#include <iostream>

class MyNumber{
    private:
        static inline size_t object_count {};
        double _value;
    public:
        MyNumber(double value);
        MyNumber(const MyNumber& x);
        MyNumber() : MyNumber(1.2) {};
        //~MyNumber() = default;
        ~MyNumber();

        inline double getMyNumber() { return _value; }
        
        static inline size_t getObjectCount() { return object_count; }
};

#endif