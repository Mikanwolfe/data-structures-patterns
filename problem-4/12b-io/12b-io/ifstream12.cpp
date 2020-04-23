#include "ifstream12.h"

// Design Patterns | Week 6 DSP | 101624964
//  Why is the content harder than the concept?
//  Adaptor design pattern seems easier than 12b-io.

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
	
}

// Implements the mapping process, returns 0, 1, or -1. -1 = eof.
int ifstream12::readBit()
{
	// Check for empty buffer, then eof.
	if (fBytesAvailable == 0)
		reload();
	if (eof())
		return -1;

	if ((fBuffer[fByteIndex] & (1 << fBitIndex)) != 0)

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

// Checks of end of File := (Buffer Empty (=0) or FStream.EOF())
bool ifstream12::eof() const
{
	return ((fBytesAvailable == 0) || fIStream.eof());
}

