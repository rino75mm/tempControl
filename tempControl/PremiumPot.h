#pragma once

#include "Pot.h"

// プレミアムポットクラス

class PremiumPot : public Pot
{
public:
	PremiumPot( LiquidInfo* pWater );
	virtual ~PremiumPot();

private:
	//------------------------------------
	/**
	 * 組み立て
	 **/
	void assemble( LiquidInfo* pWater );

	//------------------------------------
	/**
	 * レベルセンサ位置(LOW)
	 **/
	const double LOW_POS = 0.025;

	//------------------------------------
	/**
	 * ヒーターのワット数
	 **/
	const int WATT = 1000;

	//------------------------------------
	/**
	 * 円筒形の半径(cm)
	 **/
	const double RADIUS = 10.0;

	//------------------------------------
	/**
	 * 円筒形の高さ(cm)
	 **/
	const double HEIGHT = 40.0;

	//------------------------------------
	/**
	 * 円筒形の厚さ(cm)
	 **/
	const double THICKNESS = 0.5;

	//------------------------------------
	/**
	 * 円筒形の熱伝導率(W/cm・℃)
	 **/
	const double THERMAL_CONDUCTIVITY = 1.0/1000;

	//------------------------------------
	/**
	 * 比例係数
	 **/
	const double KP = 250;

	//------------------------------------
	/**
	 * 積分係数
	 **/
	const double KI = 0.005;

	//------------------------------------
	/**
	 * 微分係数
	 **/
	const double KD = 0.1;
};


