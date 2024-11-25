#pragma once

#include "ElectricalApparatus.h"
#include "Observer.h"

class LevelSensor;
class Subject;

// レベル表示器クラス

class LevelIndicator : public ElectricalApparatus
	                 , public Observer
{
public:
	LevelIndicator();
	LevelIndicator( LevelSensor* pHigh, LevelSensor* pMid, LevelSensor* pLow );
	virtual ~LevelIndicator();

	//------------------------------------
	/**
	 * レベルセンサの設定
	 **/
	void setLevelSensor( LevelSensor* pHigh, LevelSensor* pMid, LevelSensor* pLow );

	//------------------------------------
	/**
	 * 温度表示の更新
	 **/
	virtual void update( Subject* pSubject );

private:

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

	//------------------------------------
	/**
	 * HIGHに達したか
	 **/
	bool _bReachedToHighLevel;

	//------------------------------------
	/**
	 * MIDに達したか
	 **/
	bool _bReachedToMidLevel;

	//------------------------------------
	/**
	 * LOWに達したか
	 **/
	bool _bReachedToLowLevel;

	//------------------------------------
	/**
	 * 表示表示するかどうか判定するためのカウント
	 **/
	int _countForLevelIndication;
};



