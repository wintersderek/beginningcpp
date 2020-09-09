/*
Define a truck load
*/
#ifndef TRUCKLOAD_H
#define TRUCKLOAD_H
#include <memory>
#include <vector>
#include "Box.h"
//#include "Package.h"

using SharedBox = std::shared_ptr<Box>;

class TruckLoad
{
private:
    class Package
    {
        public:
            //Pointer to the box contained in this package
            std::shared_ptr<Box> pBox;
            // Pointer to the next package.  This makes it a singly linked list.
            Package *pNext;
            // Pointer to the previous package.  This makes it a doubly linked list.
            Package* pPrevious;

            // Constructor
            Package(SharedBox pb) : pBox {pb}, 
                                    pNext {nullptr}, 
                                    pPrevious {nullptr} {};

            ~Package() { delete pNext;}

    };

    Package *pHead{};    //Pointer to first package
    Package *pTail{};    //Pointer to last package

public:
    // Create the Iterator pattern for the truckload
    class Iterator
    {
    private:
        Package* pHead {nullptr};
        Package* pCurrent {nullptr};
        Package* pTail {nullptr};

        // Make the constructor private, and ensure only a TruckLoad can 
        // create it.
        friend class TruckLoad;
        explicit Iterator (Package* start, Package* end) : 
            pHead {start}, pTail {end} {}
    
    public: 
        // Get first object of the iterator
        SharedBox getFirstBox();
        // Get next object of the iterator
        SharedBox getNextBox();
        // Get the previous object of the iterator
        SharedBox getPreviousBox();
        // Get the last object of the iterator
        SharedBox getLastBox();
    };

    //Constructors
    TruckLoad() = default;      //Compiler will create the default constructor
    // Create truck load with a single box
    TruckLoad(SharedBox pBox) { pHead = pTail = new Package{pBox}; }
    // Create a truckload from a vector of boxes
    TruckLoad(const std::vector<SharedBox>& boxes);
    // Copy constructor - create truckload from another truckload
    TruckLoad(const TruckLoad& truck);

    //Destructor
    ~TruckLoad() { delete pHead; }

    //Member methods
    Iterator getIterator() const { return Iterator(pHead, pTail); }

    // Add Box
    void addBox(SharedBox pBox);

    // Remove a Box
    bool removeBox(SharedBox pBox);

    //  List the Boxes
    void listBoxes() const;
    void listBoxesReverse() const;

    static SharedBox getBiggest(const TruckLoad& truck);
    static SharedBox getSmallest(const TruckLoad& truck);
};

#endif