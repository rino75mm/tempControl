#pragma once

#include "Controller.h"

// ON/OFF制御クラス

class OnOffController : public Controller
{
public:
	OnOffController( Heater* pHeater, TempSensor* pTempSensor, LevelSensor* pHigh, LevelSensor* pMid, LevelSensor* pLow );
	virtual ~OnOffController();

	//------------------------------------
	/**
	 * 調節感度を設定
	 **/
	virtual void setHysteresis( double hysteresis );

protected:
	//------------------------------------
	/**
	 * 操作量をsv,pvより計算
	 **/
	virtual double calculateMV();

private:
	//------------------------------------
	/**
	 * 調節感度
	 **/
	double _hysteresis;
};

