
#include "FibonacciSequenceIterator.h"
#include "FibonacciSequence.h"

FibonacciSequenceIterator::FibonacciSequenceIterator(FibonacciSequence& aSequenceObject, unsigned long aStart)
	: fSequenceObject(aSequenceObject) // member initialiser
{
	fIndex = aStart;
}

const unsigned long& FibonacciSequenceIterator::operator*() const
{
	return fSequenceObject.current();
}

FibonacciSequenceIterator& FibonacciSequenceIterator::operator++()
{
	fIndex++;
	return *this;
}

FibonacciSequenceIterator FibonacciSequenceIterator::operator++(int)
{
	FibonacciSequenceIterator temp = *this;
	fIndex++;
	return temp;
}

bool FibonacciSequenceIterator::operator==(const FibonacciSequenceIterator& aOther) const
{
	return (fIndex == aOther.fIndex);
}

bool FibonacciSequenceIterator::operator!=(const FibonacciSequenceIterator& aOther) const
{
	return !(*this == aOther);
}

FibonacciSequenceIterator FibonacciSequenceIterator::begin() const
{
	FibonacciSequenceIterator result = *this;
	result.fIndex = 0;

	return result;
}

FibonacciSequenceIterator FibonacciSequenceIterator::end() const
{
	FibonacciSequenceIterator result = *this;
	result.fIndex = fSequenceObject.getLimit();

	return result;
}
