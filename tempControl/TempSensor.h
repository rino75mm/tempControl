#pragma once

#include "ElectricalApparatus.h"
#include "Subject.h"
#include "TimerTask.h"

class Tube;

// ���x�Z���T�N���X

class TempSensor : public TimerTask
	             , public ElectricalApparatus
	             , public Subject
{
public:
	TempSensor();
	virtual ~TempSensor();

	//------------------------------------
	/**
	 * ���x���擾
	 **/
	double getTemp() const;

	//------------------------------------
	/**
	 * ���x�Z���T�̊ϑ��Ώۂ�ݒ�
	 **/
	void setSubject( Tube* pSubject );
	
	//------------------------------------
	/**
	 * �^�C�}�[���^�C���A�b�v�����Ƃ��Ɏ��s�i���x�̌v���j
	 **/
	virtual void run();

private:
	//------------------------------------
	/**
	 * ���x�̌v��
	 **/
	void measure();

	//------------------------------------
	/**
	 * ���x�Z���T�̊ϑ��Ώۂ̐���
	 **/
	Tube* _pSubject;

	//------------------------------------
	/**
	 * �ϑ��������x
	 **/
	double _temp;
};



