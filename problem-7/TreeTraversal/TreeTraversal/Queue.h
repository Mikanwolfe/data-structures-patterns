
// COS30008, Problem Set 7, 2020
//  Modified by 101624964 for submission.

#pragma once

#include "List.h"
#include <stdexcept>

template<class T>
class Queue
{
private:
  List<T> fElements;

public:

  typedef DoublyLinkedNodeIterator<T> Iterator;

  bool isEmpty() const
  {
      return fElements.isEmpty();

  }
  int size() const
  {
      return fElements.size();
  }
  void enqueue(const T& aElement)
  {
      fElements.push_back(aElement);
  }
  void dequeue()
  {
      fElements.remove(top());
  }
  const T& top() const
  {
      return fElements[0];
  }

  // stack indexer
  const T& operator[](size_t aIndex) const
  {
      return fElements[aIndex];
  }
 
  // stack iterators
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
