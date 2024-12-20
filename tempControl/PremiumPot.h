#pragma once

#include "Pot.h"

// v~A|bgNX

class PremiumPot : public Pot
{
public:
	PremiumPot( LiquidInfo* pWater );
	virtual ~PremiumPot();

private:
	//------------------------------------
	/**
	 * gÝ§Ä
	 **/
	void assemble( LiquidInfo* pWater );

	//------------------------------------
	/**
	 * xZTÊu(LOW)
	 **/
	const double LOW_POS = 0.025;

	//------------------------------------
	/**
	 * q[^[Ìbg
	 **/
	const int WATT = 1000;

	//------------------------------------
	/**
	 * ~`Ì¼a(cm)
	 **/
	const double RADIUS = 10.0;

	//------------------------------------
	/**
	 * ~`Ì³(cm)
	 **/
	const double HEIGHT = 40.0;

	//------------------------------------
	/**
	 * ~`Ìú³(cm)
	 **/
	const double THICKNESS = 0.5;

	//------------------------------------
	/**
	 * ~`ÌM`±¦(W/cmE)
	 **/
	const double THERMAL_CONDUCTIVITY = 1.0/1000;

	//------------------------------------
	/**
	 * äáW
	 **/
	const double KP = 250;

	//------------------------------------
	/**
	 * ÏªW
	 **/
	const double KI = 0.005;

	//------------------------------------
	/**
	 * ÷ªW
	 **/
	const double KD = 0.1;
};


