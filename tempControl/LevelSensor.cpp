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
	cout << " レベルセンサ稼働中" << endl;
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
	cout << " レベルセンサ稼働中" << endl;
}

//---------------------------------------------------------
LevelSensor::~LevelSensor()
{
	powerOff();
	cout << " レベルセンサ停止" << endl;
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
		cout << "※レベルセンサの電源がOFFです" << endl;
		return;
	}

	if ( _pTube->getLevel() > ( _height * _pTube->getHeight() ) ) {
		_bReached = true;
	}
	else {
		_bReached = false;
	}
}
