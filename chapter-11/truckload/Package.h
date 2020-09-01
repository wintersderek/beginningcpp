/*
Package class for linked list
*/

#ifndef PACKAGE_H
#define PACKAGE_H

#include <memory>
#include "Box.h"

using SharedBox = std::shared_ptr<Box>;

class Package
{
private:
    //Pointer to the box contained in this package
    std::shared_ptr<Box> pBox;
    // Pointer to the next package.  This is what makes it a linked list.
    Package* pNext;
public:
    Package(std::shared_ptr<Box> pb) : pBox{pb}, pNext{nullptr} {}
    ~Package() { delete pNext; }

    // Retrieve the Box pointer
    std::shared_ptr<Box> getBox() const { return pBox; }

    // Get the next package in the linked list
    Package* getNext() const { return pNext; }
    // Set the next package in the linked list
    void setNext(Package* pPackage) { pNext = pPackage; }
};

#endif