#include "ifstream12.h"

// Design Patterns | Week 6 DSP | 101624964
//  Why is the content harder than the concept?
//  Adaptor design pattern seems easier than 12b-io!

using namespace std;

/* ---- Private Methods ---- */

// Clears/Resets buffer
void ifstream12::init()
{
	// Clear buffer to all zeroes
	for (size_t i = 0; i < fBufferSize; i++)
		fBuffer[i] = 0;

	fByteIndex = 0;
	fBitIndex = 7;
}

// "Reload" the buffer
void ifstream12::reload()
{
	init(); // Clear the buffer

	// This function is called whenever the buffer is empty, and therefore 
	//  we have to fill up the buffer through the intput stream
	fIStream.read((char*)fBuffer, fBufferSize);

	// There are two ways to count the number of characters in our buffer: 
	//  Check the size of the fBuffer, or use fStream.gcount()
	//  gcount refers to the number of characters returned in the last unformatted input-op.
	//  It makes it simpler to use count here
	fBytesAvailable = fIStream.gcount();
}

// Implements the mapping process, returns 0, 1, or -1. -1 = eof.
int ifstream12::readBit()
{
	// Check for empty buffer, and then check eof.
	if (fBytesAvailable == 0)
		reload();
	if (eof())
		return -1;

	// Check the bit at fBitIndex, if the statement is true then the bit is 1, else 0.
	int lResult = 0;
	if ((fBuffer[fByteIndex] & (1 << fBitIndex)) != 0)
		lResult =  1;

	// Move the fBitIndex and account for changes once it has hit 0
	if (--fBitIndex == -1) 
	{
		fBitIndex = 7;
		fByteIndex++;
		fBytesAvailable--;
	}


	return lResult;
}


/* ---- Public Methods ---- */

ifstream12::ifstream12(const char* aFileName, size_t aBufferSize)
{
	// Set up buffer
	fBufferSize = aBufferSize;
	fBuffer = new unsigned char[fBufferSize];
	init();

	// Load file
	open(aFileName);
	
}

// Destructor, clears buffer and closes file.
ifstream12::~ifstream12()
{
	close();
	delete[] fBuffer;
}

ifstream12& ifstream12::operator>>(size_t& a12BitValue)
{
	// Clear the 12-bit value
	a12BitValue = 0;

	// Creating a 12-bit value
	for (size_t i = 0; i < 12; i++) 
	{
		// Reading in a bit (returns 0, 1, or -1)
		int lBit = readBit();

		if (lBit == -1)
			break;

		// Place the bit (lBit) in position i
		a12BitValue = (lBit << (i)) + a12BitValue;

	}
	return *this;
}


// Open a particular file in filestream (does not init!)
void ifstream12::open(const char* aFileName)
{
	if (aFileName)
		fIStream.open(aFileName, ifstream::binary);
}

// Closes the filestream (does not clear!)
void ifstream12::close()
{
	fIStream.close();
}

bool ifstream12::isOpen() const
{
	return fIStream.is_open();
}

bool ifstream12::good() const
{
	return fIStream.good();
}

// Checks of end of File := (Buffer Empty (=0) AND FStream.EOF())
bool ifstream12::eof() const
{
	return ((fBytesAvailable == 0) && fIStream.eof());
}

