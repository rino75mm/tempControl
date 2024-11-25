#pragma once

#include "ElectricalApparatus.h"
#include "TimerTask.h"

class Heater;
class LevelSensor;
class TempSensor;

// 水の温度を制御するコントローラ基底クラス

class Controller : public TimerTask
	             , public ElectricalApparatus
{
public:
	Controller( Heater* pHeater, TempSensor* pTempSensor, LevelSensor* pHigh, LevelSensor* pMid, LevelSensor* pLow );
	virtual ~Controller();

	//------------------------------------
	/**
	 * 目標温度を設定
	 **/
	void setSV( double sv );

	//------------------------------------
	/**
	 * ヒータを制御
	 **/
	void control();

	//------------------------------------
	/**
	 *タイマーがタイムアップしたときに実行（ヒータを制御）
	 **/
	virtual void run();

protected:
	//------------------------------------
	/**
	 * 操作量をsv,pvより計算
	 **/
	virtual double calculateMV() = 0;

	//------------------------------------
	/**
	 * 目標温度
	 **/
	double _sv;

	//------------------------------------
	/**
	 * 現在温度
	 **/
	double _pv;

	//------------------------------------
	/**
	 * 操作量
	 **/
	double _mv;

	//------------------------------------
	/**
	 * レベルセンサ(HIGH)
	 **/
	LevelSensor* _pHigh;

	//------------------------------------
	/**
	 * レベルセンサ(MID)
	 **/
	LevelSensor* _pMid;

	//------------------------------------
	/**
	 * レベルセンサ(LOW)
	 **/
	LevelSensor* _pLow;

private:
	//------------------------------------
	/**
	 * 操作量(mv)に従いヒータを加熱
	 **/
	void manipulateTarget();

	//------------------------------------
	/**
	 * ヒータ
	 **/
	Heater* _pHeater;

	//------------------------------------
	/**
	 * 温度センサ
	 **/
	TempSensor* _pTempSensor;
};


