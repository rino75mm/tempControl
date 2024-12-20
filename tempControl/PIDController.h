#pragma once

#include "Controller.h"

// PID§äNX

class PIDController : public Controller
{
public:
	PIDController( Heater* pHeater, TempSensor* pTempSensor, LevelSensor* pHigh, LevelSensor* pMid, LevelSensor* pLow );
	virtual ~PIDController();

	//------------------------------------
	/**
	 * ìÊðsv,pvæèvZ
	 **/
	virtual void setPID( double Kp, double Ki, double Kd );

protected:
	//------------------------------------
	/**
	 * ìÊðsv,pvæèvZ
	 **/
	virtual double calculateMV();

private:
	//------------------------------------
	/**
	 * äáW
	 **/
	double _Kp;

	//------------------------------------
	/**
	 * ÏªW
	 **/
	double _Ki;

	//------------------------------------
	/**
	 * ÷ªW
	 **/
	double _Kd;

	//------------------------------------
	/**
	 * Î·
	 **/
	double _deviation;

	//------------------------------------
	/**
	 * ÝÏÎ·
	 **/
	double _cumulativeDeviation;
};

