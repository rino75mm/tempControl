#pragma once

#include "ElectricalApparatus.h"
#include "TimerTask.h"
#include <iostream>
#include <string>
using namespace std;

class Tube;

// 水を加熱するヒータークラス

class Heater : public TimerTask
	         , public ElectricalApparatus

{
private:
	//------------------------------------
	/**
	 * ヒーターのワット数
	 **/
	int _watt;

	//------------------------------------
	/**
	 * 出力比
	 **/
	double _outputRatio;

	//------------------------------------
	/**
	 * ヒーターの加熱対象
	 **/
	Tube* _pTarget;

	 //------------------------------------
	 /**
	  * ヒーターのスイッチの状態
	  **/
	Switch _switchState;

public:
	Heater();
	Heater( int watt );
	virtual ~Heater();

	//------------------------------------
	/**
	 * ヒーターのスイッチON/OFF
	 **/
	void switchOn();
	void switchOff();

	//------------------------------------
	/**
	 * ヒーターのスイッチの状態を取得
	 **/
	Switch getSwitchState() const;

	//------------------------------------
	/**
	 * 加熱
	 **/
	void heat();

	//------------------------------------
	/**
	 * ワット数を設定
	 **/
	void setWatt( int watt );

	//------------------------------------
	/**
	 * ヒーターの加熱対象を設定
	 **/
	void setTarget( Tube* pTarget );

	//------------------------------------
	/**
	 * 出力比を設定
	 **/
	void setOutputRatio( int ratio );

	//------------------------------------
	/**
	 *タイマーがタイムアップしたときに実行（加熱）
	 **/
	virtual void run();
};

