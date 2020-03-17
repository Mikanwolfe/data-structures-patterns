#include "polynomial.h"


Polynomial::Polynomial() 
{
	fDegree = 0;
	for (int i = 0; i < MAX_DEGREE; i++)
	{
		fCoeffs[i] = 0;
	}
}


Polynomial Polynomial::operator*(const Polynomial& aRHS) const
{
	Polynomial lResult;

	lResult.fDegree = aRHS.fDegree + this->fDegree;


	for (int i = 0; i < fDegree; i++)
	{
		for (int j = 0; j < fDegree; j++) {
			lResult.fCoeffs[i + j] += aRHS.fCoeffs[i] * this->fCoeffs[j];
		}
	}


	return lResult;
}


bool Polynomial::operator==(const Polynomial& aRHS) const 
{
	for (int i = 0; i < fDegree; i++) 
	{
		if (!(fCoeffs[i] == aRHS.fCoeffs[i]))
			return false;
	}
	return true;
}

// Input/Pull operator for Polynomials
std::istream& operator>>(std::istream& aIStream, Polynomial& aObject)
{
	int lDegree;
	aIStream >> lDegree;
	aObject.fDegree = lDegree + 1; // We add one 

	for (int i = 0; i < aObject.fDegree; i++)
	{
		aIStream >> aObject.fCoeffs[i];
	}
	
	return aIStream;
}



// Output/Push operator for Polynomials
std::ostream& operator<<(std::ostream& aOStream, const Polynomial& aObject)
{

	aOStream << aObject.fCoeffs[0] << "x^0";
	for (int i = 1; i < aObject.fDegree; i++)
	{
		if (aObject.fCoeffs[i] != 0)
		{
			aOStream << " + " << aObject.fCoeffs[i] << "x^" << i;
		}
	}
	
	return aOStream;
}