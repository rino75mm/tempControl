#include "OnOffController.h"

#include <iostream>
#include "LevelSensor.h"
using namespace std;

//------------------------------------
OnOffController::OnOffController( Heater* pHeater, TempSensor* pTempSensor, LevelSensor* pHigh, LevelSensor* pMid, LevelSensor* pLow )
	: Controller( pHeater, pTempSensor, pHigh, pMid, pLow )
	, _hysteresis( 0.0 )
{
	cout << " ON/OFF����ғ���" << endl;
}

//------------------------------------
OnOffController::~OnOffController()
{
	cout << " ON/OFF�����~" << endl;
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
		// (�ڕW���x-���ߊ��x)�ȏ�̏ꍇ
		return 0.0;
	}
	// (�ڕW���x-���ߊ��x)�����̏ꍇ
	return 100.0;
}

