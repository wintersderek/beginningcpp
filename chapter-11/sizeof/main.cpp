/*
Show how sizeof() works with classes
*/

#include <iostream>

class Test
{
    private:
        //int t1 {1};
        double t2 {4.5};
        //int t3 {5};
        double t4 {3.14};

    public:
        Test() = default;
        void print(){
            std::cout << t2 << std::endl;
        }
};

int main()
{
    std::cout << "Size of int: " << sizeof(int) << "\n";
    std::cout << "Size of double: " << sizeof(double) << "\n";

    std::cout << "Size of Test: " << sizeof(Test) << "\n";

    Test obj_one {};
    std::cout << "Size of object<Test>: " << sizeof(obj_one) << "\n";

    std::cout << std::endl;
}