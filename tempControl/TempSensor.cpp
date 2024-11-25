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
	cout << " ���x�Z���T�ғ���" << endl;
}

//---------------------------------------------------------
TempSensor::~TempSensor()
{
	powerOff();
	cout << " ���x�Z���T��~" << endl;
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
		cout << "�����x�Z���T�̓d����OFF�ł�" << endl;
		return;
	}
	_ASSERT( _pSubject );

	_temp = _pSubject->getLiquidInfo()->getTemp();
}

