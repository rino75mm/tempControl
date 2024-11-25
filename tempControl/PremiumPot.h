#pragma once

#include "Pot.h"

// �v���~�A���|�b�g�N���X

class PremiumPot : public Pot
{
public:
	PremiumPot( LiquidInfo* pWater );
	virtual ~PremiumPot();

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
	const double LOW_POS = 0.025;

	//------------------------------------
	/**
	 * �q�[�^�[�̃��b�g��
	 **/
	const int WATT = 1000;

	//------------------------------------
	/**
	 * �~���`�̔��a(cm)
	 **/
	const double RADIUS = 10.0;

	//------------------------------------
	/**
	 * �~���`�̍���(cm)
	 **/
	const double HEIGHT = 40.0;

	//------------------------------------
	/**
	 * �~���`�̌���(cm)
	 **/
	const double THICKNESS = 0.5;

	//------------------------------------
	/**
	 * �~���`�̔M�`����(W/cm�E��)
	 **/
	const double THERMAL_CONDUCTIVITY = 1.0/1000;

	//------------------------------------
	/**
	 * ���W��
	 **/
	const double KP = 250;

	//------------------------------------
	/**
	 * �ϕ��W��
	 **/
	const double KI = 0.005;

	//------------------------------------
	/**
	 * �����W��
	 **/
	const double KD = 0.1;
};


