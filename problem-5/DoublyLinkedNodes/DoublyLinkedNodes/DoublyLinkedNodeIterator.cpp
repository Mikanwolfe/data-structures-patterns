
#include "DoublyLinkedNode.h"
#include "DoublyLinkedNodeIteratorPS5.h"

template<class DataType>
inline DoublyLinkedNodeIterator<DataType>::DoublyLinkedNodeIterator(const Node& aList)
{

}

template<class DataType>
const DataType& DoublyLinkedNodeIterator<DataType>::operator*() const
{
	// TODO: insert return statement here
}

template<class DataType>
Iterator& DoublyLinkedNodeIterator<DataType>::operator++()
{
	// TODO: insert return statement here
}

template<class DataType>
Iterator DoublyLinkedNodeIterator<DataType>::operator++(int)
{
	return Iterator();
}

template<class DataType>
Iterator& DoublyLinkedNodeIterator<DataType>::operator--()
{
	// TODO: insert return statement here
}

template<class DataType>
Iterator DoublyLinkedNodeIterator<DataType>::operator--(int)
{
	return Iterator();
}

template<class DataType>
bool DoublyLinkedNodeIterator<DataType>::operator==(const Iterator& aOtherIter) const
{
	return false;
}

template<class DataType>
bool DoublyLinkedNodeIterator<DataType>::operator!=(const Iterator& aOtherIter) const
{
	return false;
}

template<class DataType>
Iterator DoublyLinkedNodeIterator<DataType>::begin() const
{
	return Iterator();
}

template<class DataType>
Iterator DoublyLinkedNodeIterator<DataType>::end() const
{
	return Iterator();
}

template<class DataType>
Iterator DoublyLinkedNodeIterator<DataType>::rbegin() const
{
	return Iterator();
}

template<class DataType>
Iterator DoublyLinkedNodeIterator<DataType>::rend() const
{
	return Iterator();
}
