#include "Truckload.h"
/* Constructor for adding a vector of packages to the truckload */
TruckLoad::TruckLoad(const std::vector<SharedBox>& boxes)
{
    for (const auto pBox : boxes)
    {
        addBox(pBox);
    }    
}

/* Constructor: copy constructor */
TruckLoad::TruckLoad(const TruckLoad& truck)
{
   for (Package* package {truck.pHead}; package; package = package->pNext)
   {
       addBox(package->pBox);
   }
}

/*  Add a Box to the truckload */
void TruckLoad::addBox(SharedBox pBox)
{
    Package* pPackage = new Package(pBox);

    // If pTail is not empty, add the new package as next; otherwise, the
    // linked list is empty so set to pHead.
    if (pTail)
    {
        pTail->pNext = pPackage;
        //The new packages previous pointer should be set to pTail to make the
        //doubly linked list work correctly.
        pPackage->pPrevious = pTail;
    }
    else
    {
        pHead = pPackage;
        //Since this is the first package, there is no pPrevious pointer
        pHead->pPrevious = nullptr;
    }
    
    // Finally, set pTail to the new package.
    pTail = pPackage;
}

/* Remove Box */
bool TruckLoad::removeBox(SharedBox pBox)
{

    Iterator it {this->getIterator()};

    for(SharedBox next {it.getNextBox()}; next; next = it.getNextBox())
    {
        if (pBox == next)
        {
            // We found the box to remove
            return this->removeBox(it);
        }
    }
    return false;
}

bool TruckLoad::removeBox(Iterator& it)
{
    auto pRemove = it.pCurrent;
    
    if (pRemove)
    {
        
        if (pRemove->pPrevious)
        {
            // This is not the first box in the truckload.  We need to link
            // up pPrevious with pNext.
            pRemove->pPrevious->pNext = pRemove->pNext;
        }
        else
        {
            // This is the first box in the truckload.  We need to set pNext 
            // to the pHead
            pHead = pRemove->pNext;
        }

        if (pRemove->pNext)
        {
            pRemove->pNext->pPrevious = pRemove->pPrevious;
            pRemove->pNext = nullptr;
        }

        delete pRemove;
        return true;
    }
    return false;
}

/* Get First Box */
SharedBox TruckLoad::Iterator::getFirstBox()
{
    pCurrent = pHead;
    return pCurrent? pCurrent->pBox : nullptr;
}

/* Get the last Box */
SharedBox TruckLoad::Iterator::getLastBox()
{
    pCurrent = pTail;
    return pCurrent? pCurrent->pBox: nullptr;
}

/* Get Next Box */
SharedBox TruckLoad::Iterator::getNextBox()
{
    if (!pCurrent)
    {
        return getFirstBox();
    }
    else
    {
        pCurrent = pCurrent->pNext;
        return pCurrent ? pCurrent->pBox : nullptr;
    }
}

/* Get Previous Box (Iterator) */
SharedBox TruckLoad::Iterator::getPreviousBox()
{
    if (!pCurrent)
    {
        // Class invariant has never been initialized
        return getLastBox();
    }
    else
    {
        pCurrent = pCurrent->pPrevious;  // Move to the previous package
        return pCurrent ? pCurrent->pBox : nullptr;
    }    
}

/*  List the boxes in the truckload */
void TruckLoad::listBoxes() const
{
    for (Package* package{pHead}; package; package = package->pNext)
    {
        package->pBox->listBox();
    }
}

void TruckLoad::listBoxesReverse() const
{
    for (Package* package {pTail}; package; package = package->pPrevious)
    {
        package->pBox->listBox();
    }
}

SharedBox TruckLoad::getBiggest(const TruckLoad &truck)
{
    TruckLoad::Iterator it {truck.getIterator()};
    SharedBox biggest {it.getFirstBox()};
    SharedBox next {it.getNextBox()};

    while (next)
    {
        if (next->compare(*biggest) > 0)
        {
            biggest = next;
        }
        next = it.getNextBox();
    }
    return biggest;
}

SharedBox TruckLoad::getSmallest(const TruckLoad& truck)
{
    TruckLoad::Iterator it {truck.getIterator()};
    SharedBox smallest {it.getFirstBox()};
    SharedBox next {it.getNextBox()};

    while (next)
    {
        if (next->compare(*smallest) < 0)
        {
            smallest = next;
        }
        next = it.getNextBox();
    }
    return smallest;
}