
// COS30008, Problem Set 6, 2020
// Modified by 101624964 for submission

#pragma once

#include "List.h"
#include <stdexcept>

template<class T>
class Stack
{
private:
	List<T> fElements;

public:
    
    typedef typename List<T>::Iterator Iterator;
    
    bool isEmpty() const
    {
        return fElements.isEmpty();
    }
    int size() const
    {
        return fElements.size();
    }
    void push(const T& aItem) 
    {
        fElements.push_back(aItem);
    }
    void pop()
    {
        fElements.remove(top());
    }
    const T& top() const
    {
        return fElements[fElements.size()-1];
    }

    // stack indexer
    const T& operator[](size_t aIndex) const
    {
        return fElements[aIndex];
    }

    // stack iterators
    //  Note: Are stacks just discount lists? It certainly feels that way
    Iterator begin() const
    {
        return fElements.begin();
    }
    Iterator end() const
    {
        return fElements.end();
    }
    Iterator rbegin() const
    {
        return fElements.rbegin();
    }
    Iterator rend() const
    {
        return fElements.rend();
    }
};

