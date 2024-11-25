#pragma once

enum Switch {
	OFF,
	ON,
};

// 電気機器クラス

class ElectricalApparatus
{
public:
	ElectricalApparatus();
	virtual ~ElectricalApparatus();

	//------------------------------------
	/**
	 * 電源ON/OFF
	 **/
	void powerOn();
	void powerOff();

	//------------------------------------
	/**
	 * 電源の状態を取得
	 **/
	Switch getPowerState() const;

protected:
	//------------------------------------
	/**
	 * 電源の状態
	 **/
	Switch _powerState;
};

