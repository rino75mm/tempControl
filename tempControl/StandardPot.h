#pragma once

#include "Pot.h"

// �X�^���_�[�h�|�b�g�N���X

class StandardPot : public Pot
{
public:
	StandardPot( LiquidInfo* pWater );
	virtual ~StandardPot();

private:
	//------------------------------------
	/**
	 * �g�ݗ���
	 **/
	void assemble( LiquidInfo* pWater );

	//------------------------------------
	/**
	 * ���x���Z���T�ʒu(LOW)
	 **/
	const double LOW_POS = 10.0 / 100.0;

	//------------------------------------
	/**
	 * �q�[�^�[�̃��b�g��
	 **/
	const int WATT = 500;

	//------------------------------------
	/**
	 * �~���`�̔��a(cm)
	 **/
	const double RADIUS = 5.0;

	//------------------------------------
	/**
	 * �~���`�̍���(cm)
	 **/
	const double HEIGHT = 20.0;

	//------------------------------------
	/**
	 * �~���`�̌���(cm)
	 **/
	const double THICKNESS = 0.5;

	//------------------------------------
	/**
	 * �~���`�̔M�`����(W/cm�E��)
	 **/
	const double THERMAL_CONDUCTIVITY = 1.0 / 100;

	//------------------------------------
	/**
	 * �R���g���[���̒��ߊ��x
	 **/
	const double HYSTERESIS = 0.8;
};


