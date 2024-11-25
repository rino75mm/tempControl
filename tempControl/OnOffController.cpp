#include "OnOffController.h"

#include <iostream>
#include "LevelSensor.h"
using namespace std;

//------------------------------------
OnOffController::OnOffController( Heater* pHeater, TempSensor* pTempSensor, LevelSensor* pHigh, LevelSensor* pMid, LevelSensor* pLow )
	: Controller( pHeater, pTempSensor, pHigh, pMid, pLow )
	, _hysteresis( 0.0 )
{
	cout << " ON/OFF制御稼働中" << endl;
}

//------------------------------------
OnOffController::~OnOffController()
{
	cout << " ON/OFF制御停止" << endl;
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
		// (目標温度-調節感度)以上の場合
		return 0.0;
	}
	// (目標温度-調節感度)未満の場合
	return 100.0;
}

