#pragma once

#include "ElectricalApparatus.h"
#include "Observer.h"

class TempSensor;

// 温度表示器クラス

class TempIndicator : public ElectricalApparatus
	                , public Observer
{
public:
	TempIndicator();
	TempIndicator( TempSensor* pSubject );
	virtual ~TempIndicator();

	//------------------------------------
	/**
	 * 温度センサの設定
	 **/
	void setTempSensor( TempSensor* pSubject );

	//------------------------------------
	/**
	 * 温度表示の更新
	 **/
	virtual void update( Subject* pSubject );

private:
	//------------------------------------
	/**
	 * 温度センサ
	 **/
	TempSensor* _pSubject;

	//------------------------------------
	/**
	 * 経過時間
	 **/
	int _second;
};



