#pragma once

#include "TimerTask.h"
#include <iostream>
#include <string>
using namespace std;

// 液体の情報を保持するクラス

class LiquidInfo : public TimerTask
{
private:
	//------------------------------------
	/**
	 * 液体の種類
	 **/
	string _liquidType;

	//------------------------------------
	/**
	 * 液体の識別子
	 **/
	string _ident;

	//------------------------------------
	/**
	 * 液体の質量
	 **/
	double _mass;

	//------------------------------------
	/**
	 * 液体の温度
	 **/
	double _temp;

	//------------------------------------
	/**
	 * 液体の比熱
	 **/
	double _specificHeat;

	//------------------------------------
	/**
	 * 液体の熱量
	 **/
	double _joule;

	//------------------------------------
	/**
	 * 液体の熱損失量
	 **/
	double _losingJoule;

	//------------------------------------
	/**
	 * 液体の体積
	 **/
	double _volume;

	//------------------------------------
	/**
	 * 液体の密度
	 **/
	double _density;

	//------------------------------------
	/**
	 * 混合できるか判定
	 **/
	bool isPossibleToAddLiquid( LiquidInfo* pLiquid );

	//------------------------------------
	/**
	 * 比熱を取得
	 **/
	double getThemalBalancedTemp();

public:
	LiquidInfo( string liquidType, string ident, double mass, double temp, double specificHeat, double density );
	virtual ~LiquidInfo();

	//------------------------------------
	/**
	 * 液体の種類を取得
	 **/
	string getLiquidType() const;

	//------------------------------------
	/**
	 * 液体の識別子を取得
	 **/
	string getIdent() const;

	//------------------------------------
	/**
	 * 液体の質量を取得
	 **/
	double getMass() const;

	//------------------------------------
	/**
	 * 液体の温度を取得
	 **/
	double getTemp() const;

	//------------------------------------
	/**
	 * 液体の比熱を取得
	 **/
	double getSpecificHeat() const;

	//------------------------------------
	/**
	 * 液体の熱量を取得
	 **/
	double getJoule() const;

	//------------------------------------
	/**
	 * 液体の体積を取得
	 **/
	double getVolume() const;

	//------------------------------------
	/**
	 * 混合できる液体同士か判定
	 **/
	virtual bool isMixable( LiquidInfo* pLiquid ) const = 0;

	//------------------------------------
	/**
	 * 液体の情報を表示
	 **/
	void showLiquid() const;

	//------------------------------------
	/**
	 * 液体を混合
	 **/
	bool add( LiquidInfo* pLiquid );

	//------------------------------------
	/**
	 * 液体を除去
	 **/
	void removeMass( double mass );

	//------------------------------------
	/**
	 * 液体の熱量を設定
	 **/
	void setJoule( double joule );

	//------------------------------------
	/**
	 * 液体の熱損失量を設定
	 **/
	void setLosingJoule( double losingJoule );

	//------------------------------------
	/**
	 * 温度変換
	 **/
	void changedTemp();

	//------------------------------------
	/**
	 *　水を流出
	 **/
	void runOff( double runOff );

	//------------------------------------
	/**
	 * タイマーがタイムアップしたときに実行（温度変換）
	 **/
	virtual void run();
};
