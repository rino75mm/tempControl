#pragma once

// ���i�O�C�j����ێ�����N���X

class Environment
{
private:
	//------------------------------------
	/**
	 * �O�C��
	 **/
	double _temp;

	//------------------------------------
	/**
	 * �O�C�̔M�`�B��(W/cm�E��)
	 **/
	double _heatTransferCoefficient;

public:
	Environment( double heatTransferCoefficient );
	~Environment();

	//------------------------------------
	/**
	 * �O�C����ݒ�
	 **/
	void setTemp( double temp );

	//------------------------------------
	/**
	 * �O�C�����擾
	 **/
	double getTemp() const;

	//------------------------------------
	/**
	 * �O�C�̔M�`�B�����擾
	 **/
	double getHeatTransferCoefficient() const;
};

