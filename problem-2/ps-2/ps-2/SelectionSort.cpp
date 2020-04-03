#include "SelectionSort.h"

using namespace std;


SelectionSort::SelectionSort(int aArrayOfNumbers[], unsigned int aArraySize)
	: ArraySorter(aArrayOfNumbers, aArraySize) { }


void SelectionSort::sort(std::ostream& aOStream) 
{

	// For each element of the entire array
	for (int i = 0; i < getRange() - 1; i++) 
	{
		int lLowestValue = at(i);
		int lIndexOfValue = i;

		// Starting at the currently indexed element
		for (int j = i; j < getRange(); j++) 
		{
			// Find the lowest element
			if (at(j) < lLowestValue)
			{
				lLowestValue = at(j);
				lIndexOfValue = j;
			}
		}
		// lLowestvalue is the smallest element of all the remaining elements
		//  from current index to last

		swapElements(i, lIndexOfValue);

		stepCompleted(aOStream);

	}
}
