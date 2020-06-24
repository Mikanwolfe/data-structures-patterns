
// COS30008, Final Exam, 2020
//  Modified by 101624964 for submission

#pragma once

#include <stdexcept>
//#include "TreeVisitor.h"

#ifdef P3
#include "LinearVisitor.h"
#endif

template<class T>
class TTree
{
private:
    T fKey;
    TTree<T>* fLeft;
    TTree<T>* fMiddle;
    TTree<T>* fRight;

    TTree() : fKey(T())        // use default constructor to initialize fKey
    {
        fLeft = &NIL;       // loop-back: The sub-trees of a TTree object with
        fMiddle = &NIL;     //            no children point to NIL.
        fRight = &NIL;
    }

    void addSubTree(TTree<T>** aBranch, const TTree<T>& aTTree)
    {
        if (*aBranch != &NIL)
        {
            delete* aBranch;
        }

        *aBranch = (TTree<T>*) & aTTree;
    }
    // remove sub-tree and setting its address to NIL
    void removeSubTree(TTree<T>** aBranch)
    {
        if (isEmpty())
        {
            throw std::domain_error("Cannot remove from an empty tree");
        }
        if (*aBranch != &NIL)
        {
            delete* aBranch;
        }
        *aBranch = &NIL;
    }

public:

    static TTree<T> NIL;    // sentinel

    // TTree constructor (takes one argument)
    TTree(const T& aKey)
    {
        fKey = aKey;
        fLeft = &NIL;
        fMiddle = &NIL;
        fRight = &NIL;
    }

    // destructor (free sub-trees, must not free empty TTree)
    ~TTree()
    {
        if (!isEmpty())
        {
            delete fLeft;
            delete fMiddle;
            delete fRight;
        }
    }

    // copy constructor, must not copy empty TTree
    TTree(const TTree<T>& aOtherTTree)
    {
        if (&aOtherTTree == &NIL)
        {
            throw std::domain_error("Copy of NIL Requested");
        }
        fKey = aOtherTTree.fKey;
        fLeft = aOtherTTree.fLeft;
        fMiddle = aOtherTTree.fMiddle;
        fRight = aOtherTTree.fRight;

    }

    // assignment operator, must not copy empty TTree
    TTree<T>& operator=(const TTree<T>& aOtherTTree)
    {
        if (&aOtherTTree == &NIL)
        {
            throw std::domain_error("Assignment of NIL Requested");
        }

        if (this != &aOtherTTree)
        {
            fKey = aOtherTTree.fKey;

            if (fRight != &NIL)
                delete fRight;
            if (fMiddle != &NIL)
                delete fMiddle;
            if (fLeft != &NIL)
                delete fLeft;

            fRight = aOtherTTree.fRight->clone();
            fMiddle = aOtherTTree.fMiddle->clone();
            fLeft = aOtherTTree.fLeft->clone();
        }

        return *this;
    }

    // clone TTree, must not copy empty TTree
    TTree<T>* clone() const
    {
        if (!isEmpty())
        {
            return new TTree(*this);
        }
        else
        {
            return (TTree<T>*) this; // Does not copy empty tree
        }
    }

    // return key value, may throw domain_error if empty
    const T& getKey() const
    {
        return fKey;
    }

    // returns true if this TTree is empty
    bool isEmpty() const
    {
        return ((fRight == &NIL) && (fMiddle == &NIL) && (fLeft == &NIL));
        //return this == &NIL;
    }

    // getters for subtrees
    const TTree<T>& getLeft() const
    {
        return *fLeft;
    }

    const TTree<T>& getMiddle() const
    {
        return *fMiddle;
    }

    const TTree<T>& getRight() const
    {
        return *fRight;
    }

    // add a subtree
    void addLeft(const TTree<T>& aTTree)
    {
        addSubTree(&fLeft, aTTree);
    }

    void addMiddle(const TTree<T>& aTTree)
    {
        addSubTree(&fMiddle, aTTree);
    }

    void addRight(const TTree<T>& aTTree)
    {
        addSubTree(&fRight, aTTree);
    }

    // remove a subtree, may through a domain error
    const TTree<T>& removeLeft()
    {
        return removeSubTree(&fLeft);
    }

    const TTree<T>& removeMiddle()
    {
        return removeSubTree(&fMiddle);
    }

    const TTree<T>& removeRight()
    {
        return removeSubTree(&fRight);
    }

    //depth-first traversal of the tree with visitor pattern
    //void traverseDepthFirst(TreeVisitor<T>& aVisitor) const;

};
