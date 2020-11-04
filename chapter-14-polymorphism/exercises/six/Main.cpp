#include <iostream>
#include <memory>
#include <vector>
#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"

using VecPtr = std::vector<std::shared_ptr<Shape>>;

VecPtr getShapes();
void listShapes(const VecPtr& shapes);
void scaleShapes(VecPtr& shapes, double factor);

int main(int argc, char* argv[])
{
    VecPtr shapes {getShapes()};
    listShapes(shapes);
    scaleShapes(shapes, 1.5);
    listShapes(shapes);

    std::cout << std::endl;
    return EXIT_SUCCESS;
}

VecPtr getShapes()
{
    return VecPtr {
        std::make_shared<Circle>(Point{2, 2}, 4),
        std::make_shared<Rectangle>(Point{3, 3}, 5, 6),
        std::make_shared<Circle>(Point{4, 4}, 7),
        std::make_shared<Rectangle>(Point{5, 5}, 8, 9)
    };
}

void listShapes(const VecPtr& shapes)
{
    double totalArea {};
    double totalPerimeter {};

    for(const auto& s : shapes)
    {
        totalArea += s->area();
        totalPerimeter += s->perimeter();
    }
    std::cout << "Total Area: " << totalArea << "\tTotal Perimeter: " 
              << totalPerimeter << '\n';
}

void scaleShapes(VecPtr& shapes, double factor)
{
    for(auto& s : shapes)
    {
        s->scale(factor);
    }
}