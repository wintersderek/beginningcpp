#ifndef BOX_H
#define BOX_H
#include <iostream>
#include <iomanip>
#include <algorithm> // For max() and min() function templates

class Box
{
private:
    double length{1.0};
    double width{1.0};
    double height{1.0};

public:
    // Constructors
    Box(double lv, double wv, double hv)
        : length{std::max(lv, wv)}, width{std::min(lv, wv)}, height{hv} {}
    Box() = default;

    double volume() const // Function to calculate the volume
    {
        return length * width * height;
    }

    // Accessors
    double getLength() const { return length; }
    double getWidth() const { return width; }
    double getHeight() const { return height; }

    bool operator<(const Box &aBox) const; // Less-than operator
    bool operator<(double value) const;    // Compare Box volume < double value

    Box operator+(const Box &aBox) const; // Function to add two Box objects
    Box& operator+=(const Box& box);

    Box operator*(unsigned int multiplier) const; // Function to muliply height
    Box& operator*=(unsigned int multiplier);

    Box operator/(unsigned int div) const; // Function to divide height
    Box& operator/=(unsigned int div);

};

// Less-than comparison for Box objects
inline bool Box::operator<(const Box &aBox) const
{
    return volume() < aBox.volume();
}

// Compare the volume of a Box object with a constant
inline bool Box::operator<(double value) const
{
    return volume() < value;
}

// Function comparing a constant with volume of a Box object
inline bool operator<(double value, const Box &aBox)
{
    return value < aBox.volume();
}

// Operator function to add two Box objects
inline Box Box::operator+(const Box &aBox) const
{
    // New object has larger length and width, and sum of heights
    return Box{*this} += aBox;
}

inline Box& Box::operator+=(const Box& box)
{
    this->length = std::max(this->length, box.length);
    this->width = std::max(this->width, box.width);
    this->height = this->height + box.height;
    return *this;
}

// Operator function to post-multipy an unsigned integer
inline Box Box::operator*(unsigned int multiplier) const
{
    Box copy {*this};
    copy *= multiplier;
    return copy;
}
inline Box& Box::operator*=(unsigned int multiplier)
{
    this->height *= multiplier;
    return *this;
}

// Operator to post-divide an unsigned integer
inline Box Box::operator/(unsigned int div) const
{
    Box copy {*this};
    copy /= div;
    return copy;
}
inline Box& Box::operator/=(unsigned int div)
{
    this->height /= div;
    return *this;
}

// Operator function to pre multiply an unsigned intger
inline Box operator*(unsigned int multiplier, const Box& box)
{
    return Box(box.getLength(), box.getWidth(), box.getHeight() * multiplier);
}
// Operator function for left-hand unsigned integer division
inline Box operator/(unsigned int left, const Box& right)
{
    return Box(right.getLength(), right.getWidth(), right.getHeight()/left);
}

// Stream output operator
std::ostream &operator<<(std::ostream &stream, const Box &box)
{
    return stream << "Box("
                  << std::setw(2) << box.getLength() << ','
                  << std::setw(2) << box.getWidth() << ','
                  << std::setw(2) << box.getHeight() << ')';
}
#endif