
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

	try
	{
		if ((fPosition <= fLimit) || (fLimit == 0))
		{
			fPosition++;
			fCurrent = fCurrent + fPrevious;
			fPrevious = fCurrent;
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

FibonacciSequenceIterator FibonacciSequence::begin()
{
	return FibonacciSequenceIterator(*this, 1);
}

FibonacciSequenceIterator FibonacciSequence::end()
{
	return FibonacciSequenceIterator(*this, fLimit);
}
