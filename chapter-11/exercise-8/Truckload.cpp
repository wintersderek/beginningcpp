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
    Package* pPrevious {nullptr};
    Package* pCurrent = pHead;

    while(pCurrent)
    {
        if (pCurrent->pBox == pBox)
        {
            if (pPrevious)
            {
                //Set previous' next to current next
                pPrevious->pNext = pCurrent->pNext;
                pCurrent->pNext->pPrevious = pPrevious;
            }
            else
            {
                //First element should be current's next
                pHead = pCurrent->pNext;
                //Since this is the first element in the doubly linked list, the
                //pHead should not have a previous element
                pHead->pPrevious = nullptr;
            }
            // Linked list is now set.  Now we decouple current from the list,
            // and delete it.
            pCurrent->pNext = nullptr;
            delete pCurrent;
            // Return success for box removal
            return true;            
        }

        // Set previous to current and current to next
        pPrevious = pCurrent;
        pCurrent = pCurrent->pNext;        
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
        getFirstBox();
        return nullptr;
    }
    else
    {
        if (!pCurrent->pPrevious)
        {
            return nullptr;
        }
        else
        {
            pCurrent = pCurrent->pPrevious;
            return pCurrent ? pCurrent->pBox : nullptr;
        }        
    }    
}

/*  List the boxes in the truckload */
void TruckLoad::listBoxes() const
{
    //const size_t boxesPerLine = 5;
    //size_t count {};

    for (Package* package{pHead}; package; package = package->pNext)
    {
        package->pBox->listBox();
        //if (! (++count % boxesPerLine)) std::cout << std::endl;
    }
    //if (count % boxesPerLine) std::cout << std::endl;    
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