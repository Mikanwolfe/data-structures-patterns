
// COS30008, Problem Set 5, 2020

#pragma once

#include "DoublyLinkedNode.h"

template<class DataType>
class DoublyLinkedNodeIterator
{
private:
    enum IteratorStates { BEFORE, DATA, AFTER };

    IteratorStates fState;

    typedef DoublyLinkedNode<DataType> Node;

    const Node* fLeftmost;   // A friendly reminder that these are all pointers
    const Node* fRightmost;  //  And therefore they hold addresses instead of values.
    const Node* fCurrent;

public:
    typedef DoublyLinkedNodeIterator<DataType> Iterator;
    typedef DoublyLinkedNode<DataType> Node;

    DoublyLinkedNodeIterator(const Node& aList)
    {
        // As there's no guarantee that the node provided is the leftmost in the list
        //  We need to iterate through them until we git Node::NIL

        fLeftmost = &aList;

        while (&fLeftmost->getPrevious() != &Node::NIL) // While the previous element is not the end
        {
            fLeftmost = &fLeftmost->getPrevious(); // Shift the leftmost element left
        }

        // The same can be done for the rightmost
        
        fRightmost = &aList;
        
        while (&fRightmost->getNext() != &Node::NIL)
        {
            fRightmost = &fRightmost->getNext();
        }

        // Setting the current position to be the passed-in one
        fCurrent = &aList;

        // Setting the current state of the position as "in the data"

        fState = DATA;
        

    }

    const DataType& operator*() const
    {
        // Return the deferenced value
        return fCurrent->getValue();
    }

    /*-- Operators will have to check for state and set state --*/
    Iterator& operator++() // Prefix Increment
    {
        // Increment and return the current

        switch(fState)
        {
            case BEFORE:
                fCurrent = fLeftmost;
                
                if (fCurrent == &Node::NIL) // If there is only 1 node, we are *after* the data set
                    fState = AFTER;
                else
                    fState = DATA;

                break;

            case DATA:

                fCurrent = &fCurrent->getNext(); // The current is now the next

                if (fCurrent == &Node::NIL) // Check for if we're past the dataset
                    fState = AFTER;

                break;

            default: // Do nothing in case after
                break;
        }

        return *this;
    }
    Iterator operator++(int) // postfix increment, return previous and update current
    {
        Iterator& temp = *this;
        ++(*this);
        return temp;
    }

    Iterator& operator--() 
    {
        switch (fState) 
        {
        case AFTER:
            fCurrent = fRightmost;
            if (fCurrent == &Node::NIL) // If there is only 1 node, we are *before* the data set
                fState = BEFORE;
            else
                fState = DATA;

            break;

        case DATA:
            fCurrent = &fCurrent->getPrevious();

            if (fCurrent == &Node::NIL) // Check for if we're past the dataset
                fState = BEFORE;

        default: // Do nothing in case before
            break;

        }
        return *this;
    }
    Iterator operator--(int) // postfix decrement, return previous and update current
    {
        Iterator& temp = *this;
        ++(*this);
        return temp;
    }

    bool operator==(const Iterator& aOtherIter) const
    {
        // To be the same, the two iterators need the same:
        //  - leftmost node     - state
        //  - rightmost node    - current node

        return 
            fCurrent == aOtherIter.fCurrent &&
            fLeftmost == aOtherIter.fLeftmost &&
            fRightmost == aOtherIter.fRightmost &&
            fState == aOtherIter.fState;
    }
    bool operator!=(const Iterator& aOtherIter) const
    {
        return !(*this == aOtherIter); // Implemented in terms of the == operator
    }

    Iterator begin() const // Iterator at start
    {
        Iterator temp = *this;
        temp.fCurrent = fLeftmost;
        temp.fState = DATA;

        return temp;
    }
    Iterator end() const // Iterator after end
    {
        return ++rbegin();
    }
    Iterator rbegin() const // Iterator at end
    {
        Iterator temp = *this;
        temp.fCurrent = fRightmost;
        temp.fState = DATA;

        return temp;
    }
    Iterator rend() const // iterator before start
    {
        return --begin();
    }
};