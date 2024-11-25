#include "Environment.h"

//---------------------------------------------------------
Environment::Environment( double heatTransferCoefficient )
	:_temp( 0.0 ),
	 _heatTransferCoefficient( heatTransferCoefficient )
{
}

//---------------------------------------------------------
Environment::~Environment()
{
}

//---------------------------------------------------------
void Environment::setTemp( double temp )
{
	_temp = temp;
}

//---------------------------------------------------------
double Environment::getTemp() const
{
	return _temp;
}

//---------------------------------------------------------
double Environment::getHeatTransferCoefficient() const
{
	return _heatTransferCoefficient;
}
