
//  COS30008, Final Exam, 2020,
//   Author 101624964 

#pragma once

#include <iostream>
#include "TreeVisitor.h"

// Linear Visitor class, prints visited notes in order. 
template<class T>
class LinearVisitor : public TreeVisitor<T>
{
public:
	virtual ~LinearVisitor() {}; // Virtual default destructor

	virtual void preVisit(const T& aKey) const
	{
		std::cout << " [";

		TreeVisitor<T>::visit(aKey);		
	}

	virtual void postVisit(const T& aKey) const
	{
		std::cout << " ]";
	}
};
