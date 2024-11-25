#pragma once

#include "Controller.h"

// PID����N���X

class PIDController : public Controller
{
public:
	PIDController( Heater* pHeater, TempSensor* pTempSensor, LevelSensor* pHigh, LevelSensor* pMid, LevelSensor* pLow );
	virtual ~PIDController();

	//------------------------------------
	/**
	 * ����ʂ�sv,pv���v�Z
	 **/
	virtual void setPID( double Kp, double Ki, double Kd );

protected:
	//------------------------------------
	/**
	 * ����ʂ�sv,pv���v�Z
	 **/
	virtual double calculateMV();

private:
	//------------------------------------
	/**
	 * ���W��
	 **/
	double _Kp;

	//------------------------------------
	/**
	 * �ϕ��W��
	 **/
	double _Ki;

	//------------------------------------
	/**
	 * �����W��
	 **/
	double _Kd;

	//------------------------------------
	/**
	 * �΍�
	 **/
	double _deviation;

	//------------------------------------
	/**
	 * �ݐϕ΍�
	 **/
	double _cumulativeDeviation;
};

