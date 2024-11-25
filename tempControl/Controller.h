#pragma once

#include "ElectricalApparatus.h"
#include "TimerTask.h"

class Heater;
class LevelSensor;
class TempSensor;

// ���̉��x�𐧌䂷��R���g���[�����N���X

class Controller : public TimerTask
	             , public ElectricalApparatus
{
public:
	Controller( Heater* pHeater, TempSensor* pTempSensor, LevelSensor* pHigh, LevelSensor* pMid, LevelSensor* pLow );
	virtual ~Controller();

	//------------------------------------
	/**
	 * �ڕW���x��ݒ�
	 **/
	void setSV( double sv );

	//------------------------------------
	/**
	 * �q�[�^�𐧌�
	 **/
	void control();

	//------------------------------------
	/**
	 *�^�C�}�[���^�C���A�b�v�����Ƃ��Ɏ��s�i�q�[�^�𐧌�j
	 **/
	virtual void run();

protected:
	//------------------------------------
	/**
	 * ����ʂ�sv,pv���v�Z
	 **/
	virtual double calculateMV() = 0;

	//------------------------------------
	/**
	 * �ڕW���x
	 **/
	double _sv;

	//------------------------------------
	/**
	 * ���݉��x
	 **/
	double _pv;

	//------------------------------------
	/**
	 * �����
	 **/
	double _mv;

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

private:
	//------------------------------------
	/**
	 * �����(mv)�ɏ]���q�[�^�����M
	 **/
	void manipulateTarget();

	//------------------------------------
	/**
	 * �q�[�^
	 **/
	Heater* _pHeater;

	//------------------------------------
	/**
	 * ���x�Z���T
	 **/
	TempSensor* _pTempSensor;
};


