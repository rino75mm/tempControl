#pragma once

#include "Pot.h"

// スタンダードポットクラス

class StandardPot : public Pot
{
public:
	StandardPot( LiquidInfo* pWater );
	virtual ~StandardPot();

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
	const double LOW_POS = 10.0 / 100.0;

	//------------------------------------
	/**
	 * ヒーターのワット数
	 **/
	const int WATT = 500;

	//------------------------------------
	/**
	 * 円筒形の半径(cm)
	 **/
	const double RADIUS = 5.0;

	//------------------------------------
	/**
	 * 円筒形の高さ(cm)
	 **/
	const double HEIGHT = 20.0;

	//------------------------------------
	/**
	 * 円筒形の厚さ(cm)
	 **/
	const double THICKNESS = 0.5;

	//------------------------------------
	/**
	 * 円筒形の熱伝導率(W/cm・℃)
	 **/
	const double THERMAL_CONDUCTIVITY = 1.0 / 100;

	//------------------------------------
	/**
	 * コントローラの調節感度
	 **/
	const double HYSTERESIS = 0.8;
};


