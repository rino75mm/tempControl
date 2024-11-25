#pragma once

#include "TimerTask.h"

class Environment;
class LiquidInfo;
class Tap;

// �����N���X

class Tube : public TimerTask
{
private:
	//------------------------------------
	/**
	 * �~���`�̔��a(cm)
	 **/
	double _radius;

	//------------------------------------
	/**
	 * �~���`�̍���(cm)
	 **/
	double _height;

	//------------------------------------
	/**
	 * �~���`�̌���(cm)
	 **/
	double _thickness;

	//------------------------------------
	/**
	 * �M�`����(W/cm�E��)
	 **/
	double _themalConducivity;

	//------------------------------------
	/**
	 * �M�`�����W��
	 **/
	double _themalConducivityCoeff;

	//------------------------------------
	/**
	 * �������̉t��
	 **/
	LiquidInfo* _pLiquid;

	//------------------------------------
	/**
	 * �����̒u����Ă����
	 **/
	Environment* _pEnvironment;

	//------------------------------------
	/**
	 * �����̎֌�
	 **/
	Tap* _pTap;

	//------------------------------------
	/**
	 *�@�M�̈ړ�
	 **/
	void transferHeat();

	//------------------------------------
	/**
	 *�@���𗬏o
	 **/
	void runOff();

	//------------------------------------
	/**
	 *�@�\�ʐς��擾
	 **/
	double getSurfaceArea() const;

	//------------------------------------
	/**
	 *�@���ʐς��擾
	 **/
	double getSideArea() const;

public:
	Tube();
	Tube( double radius, double height, double thickness, double themalConducivity, Tap* pTap );
	virtual ~Tube();

	//------------------------------------
	/**
	 * �������̉t�̂�ݒ�
	 **/
	void addLiquidInfo( LiquidInfo* pLiquid );

	//------------------------------------
	/**
	 * �������̉t�̂�ݒ�
	 **/
	LiquidInfo* getLiquidInfo() const;

	//------------------------------------
	/**
	 * �����̒u����Ă������ݒ�
	 **/
	void setEnvironment( Environment* pEnvironment );

	//------------------------------------
	/**
	 * �����̃T�C�Y��ݒ�
	 **/
	void setSize( double radius, double height, double thickness, double themalConducivity );

	//------------------------------------
	/**
	 * �����̍������擾
	 **/
	double getHeight() const;

	//------------------------------------
	/**
	 * ���ʂ��擾
	 **/
	double getLevel() const;

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
	 *�^�C�}�[���^�C���A�b�v�����Ƃ��Ɏ��s�i�M�̈ړ��j
	 **/
	virtual void run();
};
