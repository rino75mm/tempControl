#pragma once

// �֌��N���X

class Tap
{
public:
	Tap();
	virtual ~Tap();

	//------------------------------------
	/**
	 * �֌����J��
	 **/
	void turnOn();

	//------------------------------------
	/**
	 * �֌������
	 **/
	void turnOff();

	//------------------------------------
	/**
	 * �֌��̊J��Ԃ�Ԃ�
	 **/
	bool isOpen() const;

	//------------------------------------
	/**
	 * ���b�̗��o��(cm3/�b)��Ԃ�
	 **/
	double getRunOff() const;

private:
	//------------------------------------
	/**
	 *�֌��̊J���
	 **/
	bool _bOpen;

	//------------------------------------
	/**
	 * ���o��
	 **/
	double _runOff;
};

