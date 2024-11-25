#include "TempIndicator.h"

#include <iostream>
#include "Subject.h"
#include "TempSensor.h"
using namespace std;

//---------------------------------------------------------
TempIndicator::TempIndicator()
	: ElectricalApparatus()
	, Observer()
	, _pSubject( NULL )
	, _second( 0 )
{
}

//---------------------------------------------------------
TempIndicator::TempIndicator( TempSensor* pSubject )
	: ElectricalApparatus()
	, Observer()
	, _pSubject( pSubject )
	, _second( 0 )
{
	_ASSERT( _pSubject );
}

//---------------------------------------------------------
TempIndicator::~TempIndicator()
{
}

//---------------------------------------------------------
void TempIndicator::setTempSensor( TempSensor* pSubject )
{
	_ASSERT( pSubject );

	_pSubject = pSubject;
}

//---------------------------------------------------------
void TempIndicator::update( Subject* pSubject )
{
	_ASSERT( pSubject );
	_ASSERT( _pSubject );
	if ( pSubject != _pSubject ) {
		return;
	}

	double temp = static_cast< TempSensor* >( pSubject )->getTemp();
	_second++;

	cout << ">温度表示器：";
	cout << " 温度は" << temp << "です " << "(" << _second << ")" << endl;
}
