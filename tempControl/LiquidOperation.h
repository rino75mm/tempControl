#pragma once

class Controller;
class Heater;
class LevelSensor;
class LiquidInfo;
class Pot;
class TempSensor;

// �t�̂̑���N���X

class LiquidOperation
{
public:
	//------------------------------------
	/**
	 * ���𐶐�
	 **/
	static LiquidInfo* createWater();
	
	//------------------------------------
	/**
	 * �|�b�g�̐���
	 **/
	static Pot* createPot();

	//------------------------------------
	/**
	 * ���̍���/����
	 **/
	static void doExperiment();

	//------------------------------------
	/**
	 * ���̉��M
	 **/
	static void heatWater();

private:
	LiquidOperation();
	~LiquidOperation();
};

