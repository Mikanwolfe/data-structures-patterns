
#include "FibonacciSequence.h"
#include "FibonacciSequenceIterator.h"
#include <stdexcept>
#include <iostream>

FibonacciSequence::FibonacciSequence(unsigned long aLimit)
{
	fLimit = aLimit;
	fPrevious = 0;
	fCurrent = 1;
	fPosition = 1;
}

const unsigned long& FibonacciSequence::current() const
{
	return fCurrent;
}

void FibonacciSequence::advance()
{
	// Check for whether or not there is a limit
	//  An exception should be thrown if it is exceeded.

	unsigned long lNext;

	try
	{
		if ((fPosition <= fLimit) || (fLimit == 0))
		{
			fPosition++;
			lNext = fCurrent + fPrevious;
			fPrevious = fCurrent;
			fCurrent = lNext;
		}
		else
		{
			throw std::out_of_range("Fibonacci Sequence limit exceeded!");
		}
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
}

const unsigned long& FibonacciSequence::getLimit() const
{
	return fLimit;
}

// This method has to "restart" the sequence object
// I tried ssending a new object back but it broke. I wonder if there's a better
// way to do this
FibonacciSequenceIterator FibonacciSequence::begin()
{
	fPrevious = 0;
	fCurrent = 1;
	fPosition = 1;
	return FibonacciSequenceIterator(*this);
	
}

FibonacciSequenceIterator FibonacciSequence::end()
{
	return FibonacciSequenceIterator(*this, fLimit+1);
}
