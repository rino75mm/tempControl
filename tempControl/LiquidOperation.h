#pragma once

class Controller;
class Heater;
class LevelSensor;
class LiquidInfo;
class Pot;
class TempSensor;

// 液体の操作クラス

class LiquidOperation
{
public:
	//------------------------------------
	/**
	 * 水を生成
	 **/
	static LiquidInfo* createWater();
	
	//------------------------------------
	/**
	 * ポットの生成
	 **/
	static Pot* createPot();

	//------------------------------------
	/**
	 * 水の混合/除去
	 **/
	static void doExperiment();

	//------------------------------------
	/**
	 * 水の加熱
	 **/
	static void heatWater();

private:
	LiquidOperation();
	~LiquidOperation();
};

