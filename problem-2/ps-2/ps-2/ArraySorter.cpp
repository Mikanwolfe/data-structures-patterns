
#include "ArraySorter.h"

using namespace std;

ArraySorter::ArraySorter( const int aArrayOfNumbers[], unsigned int aArraySize )
{
    // copy array into sorter
    fArrayOfNumbers = new int[aArraySize];

    for ( unsigned int i = 0; i < aArraySize; i++ )
    {
        fArrayOfNumbers[i] = aArrayOfNumbers[i];
    }
    
    fArraySize = aArraySize;
}

ArraySorter::~ArraySorter()
{
    // delete memory associated with array
    delete [] fArrayOfNumbers;
}
