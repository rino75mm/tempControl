#include "TempSensor.h"

#include <iostream>
#include "LiquidInfo.h"
#include "Tube.h"
using namespace std;

//---------------------------------------------------------
TempSensor::TempSensor()
	: TimerTask()
	, ElectricalApparatus()
	, Subject()
	, _pSubject( NULL )
	, _temp( 0.0 )
{
	powerOn();
	cout << " 温度センサ稼働中" << endl;
}

//---------------------------------------------------------
TempSensor::~TempSensor()
{
	powerOff();
	cout << " 温度センサ停止" << endl;
}

//---------------------------------------------------------
double TempSensor::getTemp() const
{
	return _temp;
}

//---------------------------------------------------------
void TempSensor::setSubject( Tube* pSubject )
{
	_ASSERT( pSubject );
	_pSubject = pSubject;
}

//---------------------------------------------------------
void TempSensor::run()
{
	measure();
	notify();
}

//---------------------------------------------------------
void TempSensor::measure()
{
	if ( OFF == getPowerState() ) {
		cout << "※温度センサの電源がOFFです" << endl;
		return;
	}
	_ASSERT( _pSubject );

	_temp = _pSubject->getLiquidInfo()->getTemp();
}

