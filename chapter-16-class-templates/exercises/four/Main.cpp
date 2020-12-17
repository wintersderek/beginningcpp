/*
Create an application to utilize the SparseArray template
*/

#include <iostream>
#include "Random.h"
#include "SparseArray.h"

int main (int argc, char* argv[])
{
    RandomNumbers value_gen {32, 212};
    RandomNumbers index_gen {0, 499};

    SparseArray<int> myInts;
    for (size_t i {}; i < 20; ++i)
    {
        myInts[index_gen.getNext()] = value_gen.getNext();
    }

    for (size_t i {}; i < 500; ++i)
    {
        if (myInts.element_exists_at(i))
        {
            std::cout << "myInts[" << i << "] = " << myInts[i] << '\n';
        }
    }

    std::cout << std::endl;
    return EXIT_SUCCESS;
}