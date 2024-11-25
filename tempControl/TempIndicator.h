#pragma once

#include "ElectricalApparatus.h"
#include "Observer.h"

class TempSensor;

// ���x�\����N���X

class TempIndicator : public ElectricalApparatus
	                , public Observer
{
public:
	TempIndicator();
	TempIndicator( TempSensor* pSubject );
	virtual ~TempIndicator();

	//------------------------------------
	/**
	 * ���x�Z���T�̐ݒ�
	 **/
	void setTempSensor( TempSensor* pSubject );

	//------------------------------------
	/**
	 * ���x�\���̍X�V
	 **/
	virtual void update( Subject* pSubject );

private:
	//------------------------------------
	/**
	 * ���x�Z���T
	 **/
	TempSensor* _pSubject;

	//------------------------------------
	/**
	 * �o�ߎ���
	 **/
	int _second;
};



