/*
Create the header for the Box class
*/

#ifndef HDI_BOX
#define HDI_BOX

class Box
{
    private:
        double length{1.5};
        double width{1.5};
        double height{1.5};

    public:
        // Default constructor
        Box() = default;
        // 3 sided constructor
        Box(double lengthValue, double widthValue, double heightValue);
        // Cube constructor: calls the box
        explicit Box(double side);

        // Copy Constructor
        Box(const Box& original);

        double volume();

        // Get the address to the box
        Box* getAddres() { return this; }

        // Accessors and Mutators
        double getLength() { return length; }
        double getWidth() { return width; }
        double getHeight() { return height; }
        void setLength(double value) { if (value > 0) length = value; }
        void setWidth(double value) { if (value > 0) width = value; }
        void setHeight(double value) { if (value > 0) height = value; }
};


#endif