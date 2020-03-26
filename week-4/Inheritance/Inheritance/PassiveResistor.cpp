#include "PassiveResistor.h"

using namespace std;

bool PassiveResistor::mustScale(double aValue) const 
{
	return (aValue >= 1000);
}

const double PassiveResistor::getMultiplier() const
{
	return 0;
}

const std::string PassiveResistor::getMajorUnit() const
{
	return std::string();
}

const std::string PassiveResistor::getMinorUnits() const
{
	return std::string();
}

void PassiveResistor::setBaseValue(double aBaseValue)
{
}

