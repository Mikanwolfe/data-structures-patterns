
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
	fSequenceObject.advance();
	return *this;
}

FibonacciSequenceIterator FibonacciSequenceIterator::operator++(int)
{
	FibonacciSequenceIterator temp = *this;
	fIndex++;
	fSequenceObject.advance();
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
	return fSequenceObject.begin();
}

FibonacciSequenceIterator FibonacciSequenceIterator::end() const
{
	return fSequenceObject.end();;
}
