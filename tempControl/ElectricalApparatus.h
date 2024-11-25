#pragma once

enum Switch {
	OFF,
	ON,
};

// �d�C�@��N���X

class ElectricalApparatus
{
public:
	ElectricalApparatus();
	virtual ~ElectricalApparatus();

	//------------------------------------
	/**
	 * �d��ON/OFF
	 **/
	void powerOn();
	void powerOff();

	//------------------------------------
	/**
	 * �d���̏�Ԃ��擾
	 **/
	Switch getPowerState() const;

protected:
	//------------------------------------
	/**
	 * �d���̏��
	 **/
	Switch _powerState;
};

