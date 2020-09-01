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
            // Pointer to the next package.  This is what makes it a linked list.
            Package *pNext;
            // Constructor
            Package(SharedBox pb) : pBox {pb}, pNext {nullptr} {};
            ~Package() { delete pNext; }

    };

    Package *pHead{};    //Pointer to first package
    //Package *pCurrent{}; //Pointer to current package
    Package *pTail{};    //Pointer to last package

public:
    // Create the Iterator pattern for the truckload
    class Iterator
    {
    private:
        Package* pHead {nullptr};
        Package* pCurrent {nullptr};

        // Make the constructor private, and ensure only a TruckLoad can 
        // create it.
        friend class TruckLoad;
        explicit Iterator (Package* start) : pHead {start} {}
    
    public: 
        // Get first object of the iterator
        SharedBox getFirstBox();
        // Get next object of the iterator
        SharedBox getNextBox();
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
    Iterator getIterator() const { return Iterator(pHead); }

    // Add Box
    void addBox(SharedBox pBox);

    // Remove a Box
    bool removeBox(SharedBox pBox);

    //  List the Boxes
    void listBoxes() const;

    static SharedBox getBiggest(const TruckLoad& truck);
    static SharedBox getSmallest(const TruckLoad& truck);
};

#endif