#pragma once

// 環境（外気）情報を保持するクラス

class Environment
{
private:
	//------------------------------------
	/**
	 * 外気温
	 **/
	double _temp;

	//------------------------------------
	/**
	 * 外気の熱伝達率(W/cm・℃)
	 **/
	double _heatTransferCoefficient;

public:
	Environment( double heatTransferCoefficient );
	~Environment();

	//------------------------------------
	/**
	 * 外気温を設定
	 **/
	void setTemp( double temp );

	//------------------------------------
	/**
	 * 外気温を取得
	 **/
	double getTemp() const;

	//------------------------------------
	/**
	 * 外気の熱伝達率を取得
	 **/
	double getHeatTransferCoefficient() const;
};

