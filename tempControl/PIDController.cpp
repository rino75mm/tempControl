#include "PIDController.h"

#include <iostream>
#include "LevelSensor.h"
using namespace std;

//------------------------------------
PIDController::PIDController( Heater* pHeater, TempSensor* pTempSensor, LevelSensor* pHigh, LevelSensor* pMid, LevelSensor* pLow )
	: Controller( pHeater, pTempSensor, pHigh, pMid, pLow )
	, _Kp( 0.0 )
	, _Ki( 0.0 )
	, _Kd( 0.0 )
	, _deviation( 0.0 )
	, _cumulativeDeviation( 0.0 )
{
	cout << " PID§Œä‰Ò“­’†" << endl;
}

//------------------------------------
PIDController::~PIDController()
{
	cout << " PID§Œä’âŽ~" << endl;
}

//------------------------------------
void PIDController::setPID( double Kp, double Ki, double Kd )
{
	_Kp = Kp;
	_Ki = Ki;
	_Kd = Kd;
}

//------------------------------------
double PIDController::calculateMV()
{
	double preDeviation = _deviation;
	_deviation = _sv - _pv;

	double proportion   = _Kp * _deviation;
	double integral     = _Ki * _cumulativeDeviation;
	double differenital = _Kd * ( _deviation - preDeviation );

	double mv = proportion + integral + differenital;

	_cumulativeDeviation += preDeviation;

	if ( mv <= 0.0 ) {
		return 0.0;
	}
	else if ( mv >= 100.0 ) {
		return 100.0;
	}
	return  mv;
}

