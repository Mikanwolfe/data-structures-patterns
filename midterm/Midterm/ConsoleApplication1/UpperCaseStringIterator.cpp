
// COS30008, Midterm, 2020
// By 101624964 for submission. 

#include "UpperCaseStringIterator.h"
#include "UpperCaseString.h"

UpperCaseStringIterator::UpperCaseStringIterator(const UpperCaseString& aString, int aStart)
	: fString(aString) // Member initialiser
{
	fIndex = aStart;
}

const char UpperCaseStringIterator::operator*() const
{
	return fString[fIndex];
}

UpperCaseStringIterator UpperCaseStringIterator::operator++(int)
{
	UpperCaseStringIterator temp = *this;
	fIndex++;
	return temp;
}

UpperCaseStringIterator UpperCaseStringIterator::operator--()
{
	fIndex--;
	return *this;
}

bool UpperCaseStringIterator::operator==(const UpperCaseStringIterator& aOther) const
{
	//Iterators are equal if they refer to the same element. 
	return (fIndex == aOther.fIndex);
}

bool UpperCaseStringIterator::operator!=(const UpperCaseStringIterator& aOther) const
{
	return !(*this == aOther);
}

UpperCaseStringIterator UpperCaseStringIterator::begin() const
{
	return fString.begin();
}

UpperCaseStringIterator UpperCaseStringIterator::end() const
{
	return fString.end();
}

UpperCaseStringIterator UpperCaseStringIterator::rbegin() const
{
	return fString.rbegin();
}

UpperCaseStringIterator UpperCaseStringIterator::rend() const
{
	return fString.rend();
}
