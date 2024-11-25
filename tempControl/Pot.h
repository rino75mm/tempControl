#pragma once

#include "ElectricalApparatus.h"
#include "TimerTask.h"

#include "Heater.h"
#include "LevelIndicator.h"
#include "LevelSensor.h"
#include "TempIndicator.h"
#include "TempSensor.h"
#include "Tube.h"

class Controller;
class Environment;

// ポットクラス

class Pot : public ElectricalApparatus
	      , public TimerTask
{
public:
	Pot();
	virtual ~Pot();

	//------------------------------------
	/**
	 * ヒーターの電源ON
	 **/
	void turnHeaterOn();

	//------------------------------------
	/**
	 * ヒーターの電源OFF
	 **/
	void turnHeaterOff();

	//------------------------------------
	/**
	 * 蛇口を開く
	 **/
	void turnTabOn();

	//------------------------------------
	/**
	 * 蛇口を閉じる
	 **/
	void turnTabOff();

	//------------------------------------
	/**
	 * 液体を注ぐ
	 **/
	void pourLiquid( LiquidInfo* pWater );

	//------------------------------------
	/**
	 * 水筒内の液体を取得(液体情報表示)
	 **/
	void showLiquidInfo() const;

	//------------------------------------
	/**
	 * 環境を設定
	 **/
	void setEnviroment( Environment& rEnvironment );

	//------------------------------------
	/**
	 * 目標温度を設定
	 **/
	void setSV( double& rTemp );

	//------------------------------------
	/**
	 *タイマーがタイムアップしたときに実行
	 **/
	virtual void run();

protected:

	//------------------------------------
	/**
	 * レベルセンサ位置(MID)
	 **/
	const double MID_POS = 50.0 / 100.0;

	//------------------------------------
	/**
	 * レベルセンサ位置(HIGH)
	 **/
	const double HIGH_POS = 90.0 / 100.0;

	//------------------------------------
	/**
	 * 水筒
	 **/
	Tube _tube;

	//------------------------------------
	/**
	 * ヒーター
	 **/
	Heater _heater;

	//------------------------------------
	/**
	 * 温度センサ
	 **/
	TempSensor _tempSensor;

	//------------------------------------
	/**
	 * 温度表示器
	 **/
	TempIndicator _tempIndicator;

	//------------------------------------
	/**
	 * レベルセンサ(LOW)
	 **/
	LevelSensor _lowLevelSensor;

	//------------------------------------
	/**
	 * レベルセンサ(MID)
	 **/
	LevelSensor _midLevelSensor;

	//------------------------------------
	/**
	 * レベルセンサ(HIGH)
	 **/
	LevelSensor _highLevelSensor;

	//------------------------------------
	/**
	 * レベル表示器
	 **/
	LevelIndicator _levelIndicator;

	//------------------------------------
	/**
	 * コントローラ
	 **/
	Controller* _pController;
};


