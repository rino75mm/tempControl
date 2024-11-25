#pragma once

#include "ElectricalApparatus.h"
#include "Subject.h"
#include "TimerTask.h"

class Tube;

// ���x���Z���T�N���X

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
	 * ������ݒ�
	 **/
	void setTube( Tube* pTube );

	//------------------------------------
	/**
	 * ��t�ʒu�̊�����ݒ�
	 **/
	void setHeight( double height );

	//------------------------------------
	/**
	 * �ݒ萅�ʂ𒴂������ǂ���
	 **/
	bool isReached() const;

	//------------------------------------
	/**
	 * �^�C�}�[���^�C���A�b�v�����Ƃ��Ɏ��s�i���ʂ̊��m�j
	 **/
	virtual void run();

private:
	//------------------------------------
	/**
	 * ���ʂ̊��m
	 **/
	void measure();

	//------------------------------------
	/**
	 * ����
	 **/
	Tube* _pTube;

	//------------------------------------
	/**
	 * ��t�ʒu�̊���(��)
	 **/
	double _height;

	//------------------------------------
	/**
	 * �ݒ萅�ʂɒB������
	 **/
	bool _bReached;
};


