
#include "ArraySorter.h" 

using namespace std;


void ArraySorter::stepCompleted(ostream& aOStream) 
{
	aOStream << "State: ";
	auto lThis = this;
	aOStream << *lThis << endl;
}


void ArraySorter::swapElements(unsigned int aSourcIndex, unsigned int aTargetIndex) 
{
	swap(fArrayOfNumbers[aSourcIndex], fArrayOfNumbers[aTargetIndex]);
}

const unsigned int ArraySorter::at(unsigned int aIndex) const
{
	return fArrayOfNumbers[aIndex];
}

const unsigned int ArraySorter::getRange() const
{
	return fArraySize;
}

ostream& operator<<(std::ostream& aOStream, const ArraySorter& aObject)
{
	aOStream << "[";
	for (int i = 0; i < aObject.getRange(); i++) {
		aOStream << aObject.at(i);
		if (i < (aObject.getRange() - 1))
			aOStream << ", ";
	}
	aOStream << "]";
	return aOStream;
}


void ArraySorter::sort(std::ostream& aOStream) { };