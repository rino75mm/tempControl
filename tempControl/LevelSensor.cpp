#include "LevelSensor.h"

#include <iostream>
#include "Tube.h"
using namespace std;

//---------------------------------------------------------
LevelSensor::LevelSensor()
	: TimerTask()
	, ElectricalApparatus()
	, Subject()
	, _pTube( NULL )
	, _height( 0.0 )
	, _bReached( false )
{
	powerOn();
	cout << " ���x���Z���T�ғ���" << endl;
}

//---------------------------------------------------------
LevelSensor::LevelSensor( Tube* pTube, double height )
	: TimerTask()
	, ElectricalApparatus()
	, Subject()
	, _pTube( pTube )
	, _height( height )
	, _bReached( false )
{
	_ASSERT( _pTube );
	powerOn();
	cout << " ���x���Z���T�ғ���" << endl;
}

//---------------------------------------------------------
LevelSensor::~LevelSensor()
{
	powerOff();
	cout << " ���x���Z���T��~" << endl;
}

//---------------------------------------------------------
void LevelSensor::setTube( Tube* pTube )
{
	_ASSERT( pTube );

	_pTube = pTube;
}

//---------------------------------------------------------
void LevelSensor::setHeight( double height )
{
	_height = height;
}

//---------------------------------------------------------
bool LevelSensor::isReached() const
{
	return _bReached;
}

//---------------------------------------------------------
void LevelSensor::run()
{
	measure();
	notify();
}

//---------------------------------------------------------
void LevelSensor::measure()
{
	if ( OFF == getPowerState() ) {
		cout << "�����x���Z���T�̓d����OFF�ł�" << endl;
		return;
	}

	if ( _pTube->getLevel() > ( _height * _pTube->getHeight() ) ) {
		_bReached = true;
	}
	else {
		_bReached = false;
	}
}
