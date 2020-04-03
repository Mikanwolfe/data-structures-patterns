#include "InsertionSort.h"

using namespace std;


InsertionSort::InsertionSort(int aArrayOfNumbers[], unsigned int aArraySize)
	:ArraySorter(aArrayOfNumbers, aArraySize) { }

void InsertionSort::sort(std::ostream& aOStream) 
{
	for (int i = 1; i < getRange(); i++)
	{

		for (int j = i; j > 0; j--)
		{
			if (at(j-1) > at(j)) {
				swapElements(j-1, j);
				
			}
		}
		stepCompleted(aOStream);
	}
}