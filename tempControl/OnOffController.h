#pragma once

#include "Controller.h"

// ON/OFF����N���X

class OnOffController : public Controller
{
public:
	OnOffController( Heater* pHeater, TempSensor* pTempSensor, LevelSensor* pHigh, LevelSensor* pMid, LevelSensor* pLow );
	virtual ~OnOffController();

	//------------------------------------
	/**
	 * ���ߊ��x��ݒ�
	 **/
	virtual void setHysteresis( double hysteresis );

protected:
	//------------------------------------
	/**
	 * ����ʂ�sv,pv���v�Z
	 **/
	virtual double calculateMV();

private:
	//------------------------------------
	/**
	 * ���ߊ��x
	 **/
	double _hysteresis;
};

