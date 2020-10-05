#include <iomanip>
#include "NumberContainer.h"

SharedNumber NumberContainer::Iterator::getFirst()
{
    this->pCurrent = this->pHead;
    return (pCurrent) ? pCurrent->number : nullptr;
}

SharedNumber NumberContainer::Iterator::getCurrent()
{
    if (!pCurrent)
    {
        return getFirst();
    }
    else
    {
        return pCurrent->number;
    }    
}

SharedNumber NumberContainer::Iterator::getNext()
{
    if (!pCurrent)
    {
        return getFirst();
    }
    else
    {
        pCurrent = pCurrent->next;
        return (pCurrent) ? pCurrent->number : nullptr;
    }    
}

SharedNumber NumberContainer::Iterator::getLast()
{
    pCurrent = pTail;
    return (pCurrent) ? pCurrent->number : nullptr;
}

void NumberContainer::addNumber(SharedNumber n)
{
    // Create a new NumberItem
    NumberItem* added_item = new NumberItem(n);

    // If tail exists, set tail next to added_item
    if (pTail)
    {
        pTail->next = added_item;
    }
    else
    {
        //This is the first item in the list
        pHead = added_item;
    }
    
    pTail = added_item;
}

SharedNumber NumberContainer::operator[](size_t index) const
{
    size_t current{};
    for (NumberItem* n {this->pHead}; n; n = n->next)
    {
        if (index == current++)
        {
            return n->number;
        }
    }
    return nullptr;
}

std::ostream &operator<<(std::ostream &outstream, NumberContainer &container)
{
    auto it {container.getIterator()};
    size_t count {0};

    for (auto n = it.getFirst(); n; n = it.getNext())
    {
        outstream << std::setw(5) << *n;
        if (!(++count % NumberContainer::line_count))
            outstream << '\n';
    }

    if (count % NumberContainer::line_count)
        outstream << '\n';

    return outstream;
}