/*
Class for containing the numbers.
    - Linked list of numbers
    - Iterator of numbers
    - subscript overload implemention
*/
#include <memory>
#include "Number.h"

using SharedNumber = std::shared_ptr<Number>;

class NumberContainer
{
private:
    /* Number Item is the linked list */
    class NumberItem
    {
        public:
            SharedNumber number;
            //Pointer to the next ClassType object
            NumberItem* next;
            //Pointer to the previous ClassType object
            NumberItem* previous;

            // Constructor
            NumberItem(SharedNumber n) : 
                number {n}, next {nullptr}, previous {nullptr} {}

            // Destructor
            ~NumberItem() { delete next; }
    };

    NumberItem* pHead {};
    NumberItem* pTail {};

public:
    class Iterator
    {
    private:
        NumberItem* pHead {};
        NumberItem* pCurrent {};
        NumberItem* pTail {};

        friend class NumberContainer;
        explicit Iterator(NumberItem* head, NumberItem* tail) : 
            pHead {head}, pTail {tail} {}

    public:
        SharedNumber getFirst();
        SharedNumber getNext();
        SharedNumber getLast();
        SharedNumber getCurrent();
    };
    
    static inline const size_t line_count {10};

    static SharedNumber nullNumber;

    /*  CONSTRUCTORS */
    NumberContainer() = default;
    explicit NumberContainer(SharedNumber n) 
    {
        pHead = pTail = new NumberItem(n);
    }

    /* 
        DESTRUCTOR - must delete the head pointer.  This will cause a cascade
                     of deletes because ~NumberItem() deletes its next pointer.
    */
    ~NumberContainer() { delete pHead; }

    /* NON-CONST MEMBERS */
    void addNumber(SharedNumber n);
    
    bool deleteNumber(SharedNumber n);

    SharedNumber& operator[](size_t index);

    /* CONST MEMBERS */
    inline NumberContainer::Iterator getIterator() const
    {
        return Iterator(pHead, pTail);
    }
};

std::ostream& operator<<(std::ostream& outstream, NumberContainer& container);