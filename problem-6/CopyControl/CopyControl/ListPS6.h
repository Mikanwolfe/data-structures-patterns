#pragma once

#include "DoublyLinkedNode.h"
#include "DoublyLinkedNodeIterator.h"

#include <stdexcept>

#include "List.h"
#include "Stages.h"

#define NOT_IMPLEMENTED 1

template<class T>
class List
{

private:
	// auxiliary definition to simplify node usage
	typedef DoublyLinkedNode<T> Node;

	Node* fTop;		// the first element in the list
	Node* fLast;	// the last element in the list
	int fCount;		// number of elements in the list

public:

	List<T>::List(const List& aOtherList) // copy constructor
	{
		// Initialise all instance variables:
		// Top node:

		fCount = aOtherList->fCount;


	}

	List& List<T>::operator=(const List& aOtherList)
	{
		// TODO: insert return statement here
	}

};
