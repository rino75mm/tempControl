#pragma once

#include "ElectricalApparatus.h"
#include "Subject.h"
#include "TimerTask.h"

class Tube;

// レベルセンサクラス

class LevelSensor : public TimerTask
	              , public ElectricalApparatus
	              , public Subject
{
public:
	LevelSensor();
	LevelSensor( Tube* pTube, double height );
	virtual ~LevelSensor();

	//------------------------------------
	/**
	 * 水筒を設定
	 **/
	void setTube( Tube* pTube );

	//------------------------------------
	/**
	 * 取付位置の割合を設定
	 **/
	void setHeight( double height );

	//------------------------------------
	/**
	 * 設定水位を超えたかどうか
	 **/
	bool isReached() const;

	//------------------------------------
	/**
	 * タイマーがタイムアップしたときに実行（水位の感知）
	 **/
	virtual void run();

private:
	//------------------------------------
	/**
	 * 水位の感知
	 **/
	void measure();

	//------------------------------------
	/**
	 * 水筒
	 **/
	Tube* _pTube;

	//------------------------------------
	/**
	 * 取付位置の割合(％)
	 **/
	double _height;

	//------------------------------------
	/**
	 * 設定水位に達したか
	 **/
	bool _bReached;
};


