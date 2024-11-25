#pragma once

#include "ElectricalApparatus.h"
#include "TimerTask.h"
#include <iostream>
#include <string>
using namespace std;

class Tube;

// �������M����q�[�^�[�N���X

class Heater : public TimerTask
	         , public ElectricalApparatus

{
private:
	//------------------------------------
	/**
	 * �q�[�^�[�̃��b�g��
	 **/
	int _watt;

	//------------------------------------
	/**
	 * �o�͔�
	 **/
	double _outputRatio;

	//------------------------------------
	/**
	 * �q�[�^�[�̉��M�Ώ�
	 **/
	Tube* _pTarget;

	 //------------------------------------
	 /**
	  * �q�[�^�[�̃X�C�b�`�̏��
	  **/
	Switch _switchState;

public:
	Heater();
	Heater( int watt );
	virtual ~Heater();

	//------------------------------------
	/**
	 * �q�[�^�[�̃X�C�b�`ON/OFF
	 **/
	void switchOn();
	void switchOff();

	//------------------------------------
	/**
	 * �q�[�^�[�̃X�C�b�`�̏�Ԃ��擾
	 **/
	Switch getSwitchState() const;

	//------------------------------------
	/**
	 * ���M
	 **/
	void heat();

	//------------------------------------
	/**
	 * ���b�g����ݒ�
	 **/
	void setWatt( int watt );

	//------------------------------------
	/**
	 * �q�[�^�[�̉��M�Ώۂ�ݒ�
	 **/
	void setTarget( Tube* pTarget );

	//------------------------------------
	/**
	 * �o�͔��ݒ�
	 **/
	void setOutputRatio( int ratio );

	//------------------------------------
	/**
	 *�^�C�}�[���^�C���A�b�v�����Ƃ��Ɏ��s�i���M�j
	 **/
	virtual void run();
};

