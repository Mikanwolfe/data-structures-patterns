
// COS30008, Midterm, 2020
// Modified by 101624964 for submission. 

#include "UpperCaseString.h"

#include <cctype>
#include <stdexcept>

using namespace std;

// --- Don't touch anything above this line --- //

#include "UpperCaseStringIterator.h"

UpperCaseString::UpperCaseString( const char* aInitialValue )
{
    // a C-string contains at least one character: '\0'.
    size_t lLength = 1;
    
    // compute the length + 1 of aInitialValue
    for ( int i = 0; aInitialValue[i] != '\0'; i++ )
    {
        lLength++;
    }

    // allocate memory
    fValue = new char[lLength];
    
    // copy aInitialValue to fValue and make it upper case
    for ( int i = 0; i < lLength; i++ )
    {
        fValue[i] = toupper( aInitialValue[i] );
    }
}

UpperCaseString::~UpperCaseString()
{
    // We need to free the memory in the stored fValue array
    delete[] fValue;
}

int UpperCaseString::size() const
{
    // "size" here will be taken to refer to the length of the array
    //   Ideally we'd like to use sizeof(fValue) / sizeof(fValue[0]), however, since
    //   we can't use sizeof() on a pointer (it returns 4), we have to count all values again.
    size_t lLength = 0;

    for (int i = 0; fValue[i] != '\0'; i++)
    {
        lLength++;
    }

    return lLength;
}

const char UpperCaseString::operator[](int aIndex) const
{
    return fValue[aIndex];
}

UpperCaseStringIterator UpperCaseString::begin() const
{
    return UpperCaseStringIterator(*this, 0);
}

UpperCaseStringIterator UpperCaseString::end() const
{
    return UpperCaseStringIterator(*this, size() + 1);
}

// Returns an iterator positioned at last element
UpperCaseStringIterator UpperCaseString::rbegin() const
{
    return UpperCaseStringIterator(*this, size());
}

// Returns an iterator positioned before the first element
UpperCaseStringIterator UpperCaseString::rend() const
{
    return UpperCaseStringIterator(*this, -1);
}

std::ostream& operator<<(std::ostream& aOStream, const UpperCaseString& aString)
{
    for (int i = 0; i < aString.size(); i++) 
    {
        aOStream << aString[i];
    }

    return aOStream;
}
