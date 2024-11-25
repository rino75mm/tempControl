#pragma once

#include "Controller.h"

// PID§ŒäƒNƒ‰ƒX

class PIDController : public Controller
{
public:
	PIDController( Heater* pHeater, TempSensor* pTempSensor, LevelSensor* pHigh, LevelSensor* pMid, LevelSensor* pLow );
	virtual ~PIDController();

	//------------------------------------
	/**
	 * ‘€ì—Ê‚ğsv,pv‚æ‚èŒvZ
	 **/
	virtual void setPID( double Kp, double Ki, double Kd );

protected:
	//------------------------------------
	/**
	 * ‘€ì—Ê‚ğsv,pv‚æ‚èŒvZ
	 **/
	virtual double calculateMV();

private:
	//------------------------------------
	/**
	 * ”ä—áŒW”
	 **/
	double _Kp;

	//------------------------------------
	/**
	 * Ï•ªŒW”
	 **/
	double _Ki;

	//------------------------------------
	/**
	 * ”÷•ªŒW”
	 **/
	double _Kd;

	//------------------------------------
	/**
	 * •Î·
	 **/
	double _deviation;

	//------------------------------------
	/**
	 * —İÏ•Î·
	 **/
	double _cumulativeDeviation;
};

