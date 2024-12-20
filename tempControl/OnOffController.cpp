#include "OnOffController.h"

#include <iostream>
#include "LevelSensor.h"
using namespace std;

//------------------------------------
OnOffController::OnOffController( Heater* pHeater, TempSensor* pTempSensor, LevelSensor* pHigh, LevelSensor* pMid, LevelSensor* pLow )
	: Controller( pHeater, pTempSensor, pHigh, pMid, pLow )
	, _hysteresis( 0.0 )
{
	cout << " ON/OFF§äÒ­" << endl;
}

//------------------------------------
OnOffController::~OnOffController()
{
	cout << " ON/OFF§äâ~" << endl;
}

//------------------------------------
void OnOffController::setHysteresis( double hysteresis )
{
	_hysteresis = hysteresis;
}

//------------------------------------
double OnOffController::calculateMV()
{
	if ( _pv >= ( _sv - _hysteresis ) ) {
		// (ÚW·x-²ß´x)ÈãÌê
		return 0.0;
	}
	// (ÚW·x-²ß´x)¢Ìê
	return 100.0;
}

