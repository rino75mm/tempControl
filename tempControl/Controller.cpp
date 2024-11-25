#include "Controller.h"

#include "Heater.h"
#include <iostream>
#include "LevelSensor.h"
#include "TempSensor.h"
using namespace std;

//------------------------------------
Controller::Controller( Heater* pHeater, TempSensor* pTempSensor, LevelSensor* pHigh, LevelSensor* pMid, LevelSensor* pLow )
	: TimerTask()
	, ElectricalApparatus()
	, _sv( 0.0 )
	, _pv( 0.0 )
	, _mv( 0.0 )
	, _pHeater( pHeater )
	, _pTempSensor( pTempSensor )
	, _pHigh( pHigh )
	, _pMid( pMid )
	, _pLow( pLow )
{
	_ASSERT( _pHeater );
	_ASSERT( _pTempSensor );

	powerOn();
}

//------------------------------------
Controller::~Controller()
{
	powerOff();
}

//------------------------------------
void Controller::setSV( double sv )
{
	if ( ( 20.0 > sv ) || ( 98.5 < sv ) ) {
		sv = 98.5;
	}
	_sv = sv;
}

//------------------------------------
void Controller::control()
{
	_pv = _pTempSensor->getTemp();
	if ( ( !_pHigh->isReached() ) &&
		 ( _pLow->isReached() ) ) {
		_mv = calculateMV();
	}
	else {
		_mv = 0.0;
	}
	manipulateTarget();
}

//------------------------------------
void Controller::run() 
{
	control();
}

//------------------------------------
void Controller::manipulateTarget()
{
	_pHeater->setOutputRatio( _mv );
}
