#pragma once

#include "ElectricalApparatus.h"
#include "Subject.h"
#include "TimerTask.h"

class Tube;

// 温度センサクラス

class TempSensor : public TimerTask
	             , public ElectricalApparatus
	             , public Subject
{
public:
	TempSensor();
	virtual ~TempSensor();

	//------------------------------------
	/**
	 * 温度を取得
	 **/
	double getTemp() const;

	//------------------------------------
	/**
	 * 温度センサの観測対象を設定
	 **/
	void setSubject( Tube* pSubject );
	
	//------------------------------------
	/**
	 * タイマーがタイムアップしたときに実行（温度の計測）
	 **/
	virtual void run();

private:
	//------------------------------------
	/**
	 * 温度の計測
	 **/
	void measure();

	//------------------------------------
	/**
	 * 温度センサの観測対象の水筒
	 **/
	Tube* _pSubject;

	//------------------------------------
	/**
	 * 観測した温度
	 **/
	double _temp;
};



