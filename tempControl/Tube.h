#pragma once

#include "TimerTask.h"

class Environment;
class LiquidInfo;
class Tap;

// 水筒クラス

class Tube : public TimerTask
{
private:
	//------------------------------------
	/**
	 * 円筒形の半径(cm)
	 **/
	double _radius;

	//------------------------------------
	/**
	 * 円筒形の高さ(cm)
	 **/
	double _height;

	//------------------------------------
	/**
	 * 円筒形の厚さ(cm)
	 **/
	double _thickness;

	//------------------------------------
	/**
	 * 熱伝導率(W/cm・℃)
	 **/
	double _themalConducivity;

	//------------------------------------
	/**
	 * 熱伝導率係数
	 **/
	double _themalConducivityCoeff;

	//------------------------------------
	/**
	 * 水筒内の液体
	 **/
	LiquidInfo* _pLiquid;

	//------------------------------------
	/**
	 * 水筒の置かれている環境
	 **/
	Environment* _pEnvironment;

	//------------------------------------
	/**
	 * 水筒の蛇口
	 **/
	Tap* _pTap;

	//------------------------------------
	/**
	 *　熱の移動
	 **/
	void transferHeat();

	//------------------------------------
	/**
	 *　水を流出
	 **/
	void runOff();

	//------------------------------------
	/**
	 *　表面積を取得
	 **/
	double getSurfaceArea() const;

	//------------------------------------
	/**
	 *　側面積を取得
	 **/
	double getSideArea() const;

public:
	Tube();
	Tube( double radius, double height, double thickness, double themalConducivity, Tap* pTap );
	virtual ~Tube();

	//------------------------------------
	/**
	 * 水筒内の液体を設定
	 **/
	void addLiquidInfo( LiquidInfo* pLiquid );

	//------------------------------------
	/**
	 * 水筒内の液体を設定
	 **/
	LiquidInfo* getLiquidInfo() const;

	//------------------------------------
	/**
	 * 水筒の置かれている環境を設定
	 **/
	void setEnvironment( Environment* pEnvironment );

	//------------------------------------
	/**
	 * 水筒のサイズを設定
	 **/
	void setSize( double radius, double height, double thickness, double themalConducivity );

	//------------------------------------
	/**
	 * 水筒の高さを取得
	 **/
	double getHeight() const;

	//------------------------------------
	/**
	 * 水位を取得
	 **/
	double getLevel() const;

	//------------------------------------
	/**
	 * 蛇口を開く
	 **/
	void turnTabOn();

	//------------------------------------
	/**
	 * 蛇口を閉じる
	 **/
	void turnTabOff();

	//------------------------------------
	/**
	 *タイマーがタイムアップしたときに実行（熱の移動）
	 **/
	virtual void run();
};
