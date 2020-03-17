
// COS30008, Problem Set 1, 2020

#pragma once

#include <iostream>

#define MAX_DEGREE 20+1+1           // max degree 0 to 20 plus 1 for integral

class Polynomial
{
private:
	int fDegree;					// the maximum degree of the polynomial
	double fCoeffs[MAX_DEGREE];		// the coefficients (0..10, 0..20)

public:
    // the default constructor (initializes all member variables)
	Polynomial();

	// binary operator* to multiple to polynomials
	// arguments are read-only, signified by const
	// the operator* returns a fresh polynomial with degree i+j
	Polynomial operator*( const Polynomial& aRight ) const;
    
    // binary operator== to compare two polynomials
    // arguments are read-only, signified by const
    // the operator== returns true if this polynomial is
    // structurally equivalent to the aRHS polynomial
    bool operator==( const Polynomial& aRHS ) const;

	// input operator for polynomials
	friend std::istream& operator>>( std::istream& aIStream, Polynomial& aObject );

	// output operator for polynomials
	friend std::ostream& operator<<( std::ostream& aOStream, const Polynomial& aObject );

    // new methods in problem set 1
    // call operator to calculate polynomial for a given x (i.e., aX)
    double operator()( double aX ) const;

    // compute differential
    // the differential is a fresh polynomial with degree fDegree-1
    // the method does not change the current object
    Polynomial getDifferential() const;
    
    // compute indefinite integral
    // the indefinite integral is a fresh polynomial with degree fDegree+1
    // the method does not change the current object
    Polynomial getIndefiniteIntegral() const;

    // calculate definite integral
    // the method computes the indefinite integral and then calculates it
    // for xlow and xhigh and returns the difference
    // the method does not change the current object
    double getDefiniteIntegral( double aXLow, double aXHigh ) const;
};

