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

// �|�b�g�N���X

class Pot : public ElectricalApparatus
	      , public TimerTask
{
public:
	Pot();
	virtual ~Pot();

	//------------------------------------
	/**
	 * �q�[�^�[�̓d��ON
	 **/
	void turnHeaterOn();

	//------------------------------------
	/**
	 * �q�[�^�[�̓d��OFF
	 **/
	void turnHeaterOff();

	//------------------------------------
	/**
	 * �֌����J��
	 **/
	void turnTabOn();

	//------------------------------------
	/**
	 * �֌������
	 **/
	void turnTabOff();

	//------------------------------------
	/**
	 * �t�̂𒍂�
	 **/
	void pourLiquid( LiquidInfo* pWater );

	//------------------------------------
	/**
	 * �������̉t�̂��擾(�t�̏��\��)
	 **/
	void showLiquidInfo() const;

	//------------------------------------
	/**
	 * ����ݒ�
	 **/
	void setEnviroment( Environment& rEnvironment );

	//------------------------------------
	/**
	 * �ڕW���x��ݒ�
	 **/
	void setSV( double& rTemp );

	//------------------------------------
	/**
	 *�^�C�}�[���^�C���A�b�v�����Ƃ��Ɏ��s
	 **/
	virtual void run();

protected:

	//------------------------------------
	/**
	 * ���x���Z���T�ʒu(MID)
	 **/
	const double MID_POS = 50.0 / 100.0;

	//------------------------------------
	/**
	 * ���x���Z���T�ʒu(HIGH)
	 **/
	const double HIGH_POS = 90.0 / 100.0;

	//------------------------------------
	/**
	 * ����
	 **/
	Tube _tube;

	//------------------------------------
	/**
	 * �q�[�^�[
	 **/
	Heater _heater;

	//------------------------------------
	/**
	 * ���x�Z���T
	 **/
	TempSensor _tempSensor;

	//------------------------------------
	/**
	 * ���x�\����
	 **/
	TempIndicator _tempIndicator;

	//------------------------------------
	/**
	 * ���x���Z���T(LOW)
	 **/
	LevelSensor _lowLevelSensor;

	//------------------------------------
	/**
	 * ���x���Z���T(MID)
	 **/
	LevelSensor _midLevelSensor;

	//------------------------------------
	/**
	 * ���x���Z���T(HIGH)
	 **/
	LevelSensor _highLevelSensor;

	//------------------------------------
	/**
	 * ���x���\����
	 **/
	LevelIndicator _levelIndicator;

	//------------------------------------
	/**
	 * �R���g���[��
	 **/
	Controller* _pController;
};


