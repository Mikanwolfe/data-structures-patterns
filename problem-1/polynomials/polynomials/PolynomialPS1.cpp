// COS30008 Problem Set 1 by Jimmy Trac 101624964
// Extends on tutorial 3: polynomials. 
//  The goal of this extension is to provide methods for determining
//  the derivative along with the definite and indefinite integral.
//
// Main.cpp, Polynomial.cpp, and Polynomial.h are property of and provided by 
//  the unit and its instructors.
#include "Polynomial.h"

using namespace std;

double Polynomial::operator()(double aX) const
{
	double lValue = 0;

	for (int i = 0; i <= fDegree; i++)
	{
		lValue += pow(aX, i) * fCoeffs[i];
	}

	return lValue;
};

// the constant of integration is assumed to be 0 ( c = 0).
//  i.e. initial conditions are assumed to be zero.
//  this is because we can't place "c" in the x^0 place. It'd be nice if we could.
Polynomial Polynomial::getIndefiniteIntegral() const
{
	Polynomial lIndefIntegral;

	lIndefIntegral.fDegree = this->fDegree + 1;

	for (int i = 0; i <= this->fDegree; i++)
	{
		lIndefIntegral.fCoeffs[i + 1] = this->fCoeffs[i] / (i + 1);
	}
	return lIndefIntegral;
};

Polynomial Polynomial::getDifferential() const
{
	Polynomial lDifferential;

	lDifferential.fDegree = this->fDegree - 1;

	for (int i = 0; i <= lDifferential.fDegree; i++)
	{
		lDifferential.fCoeffs[i] = this->fCoeffs[i + 1] * (i + 1);
	}

	return lDifferential;
};

double Polynomial::getDefiniteIntegral(double aXLow, double aXHigh) const
{
	Polynomial lIndefIntegral = getIndefiniteIntegral();

	return lIndefIntegral(aXHigh) - lIndefIntegral(aXLow);
};