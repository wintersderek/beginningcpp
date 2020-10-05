#include "MinNumber.h"

SharedNumber MinNumber::operator()(const NumberContainer& container)
{
    NumberContainer::Iterator it {container.getIterator()};
    SharedNumber minimum {nullptr};
    for(SharedNumber n {it.getNext()}; n; n = it.getNext())
    {
        if (minimum == nullptr || n->getNumber() < minimum->getNumber())
        {
            minimum = n;
        }
    }
    return minimum;
}