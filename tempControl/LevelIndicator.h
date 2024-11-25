#pragma once

#include "ElectricalApparatus.h"
#include "Observer.h"

class LevelSensor;
class Subject;

// ���x���\����N���X

class LevelIndicator : public ElectricalApparatus
	                 , public Observer
{
public:
	LevelIndicator();
	LevelIndicator( LevelSensor* pHigh, LevelSensor* pMid, LevelSensor* pLow );
	virtual ~LevelIndicator();

	//------------------------------------
	/**
	 * ���x���Z���T�̐ݒ�
	 **/
	void setLevelSensor( LevelSensor* pHigh, LevelSensor* pMid, LevelSensor* pLow );

	//------------------------------------
	/**
	 * ���x�\���̍X�V
	 **/
	virtual void update( Subject* pSubject );

private:

	//------------------------------------
	/**
	 * ���x���Z���T(HIGH)
	 **/
	LevelSensor* _pHigh;

	//------------------------------------
	/**
	 * ���x���Z���T(MID)
	 **/
	LevelSensor* _pMid;

	//------------------------------------
	/**
	 * ���x���Z���T(LOW)
	 **/
	LevelSensor* _pLow;

	//------------------------------------
	/**
	 * HIGH�ɒB������
	 **/
	bool _bReachedToHighLevel;

	//------------------------------------
	/**
	 * MID�ɒB������
	 **/
	bool _bReachedToMidLevel;

	//------------------------------------
	/**
	 * LOW�ɒB������
	 **/
	bool _bReachedToLowLevel;

	//------------------------------------
	/**
	 * �\���\�����邩�ǂ������肷�邽�߂̃J�E���g
	 **/
	int _countForLevelIndication;
};



