/*
Initial class for learning class creation.
*/
#include <iostream>

class Box
{

    private:
        double length {1.5};
        double width {1.5};
        double height {1.5};

    public:
        // Create the default constructor
        Box() = default;

        // Create the constructor to force initialization
        Box(double lengthValue, double widthValue, double heightValue)
        {
#ifdef HDI_DEBUG            
            std::cout << "Constructor called\n";
#endif
            length = lengthValue;
            width = widthValue;
            height = heightValue;
        }

        double volume()
        {
            return length * width * height;
        }
};

int main()
{
    Box box_one {80.5, 50.2, 14.0};

    std::cout << "My box volume: " << box_one.volume() << "\n";

    Box box_two {};
    std::cout << "Box Two Volume: " << box_two.volume() << "\n";

    std::cout << std::endl;
}