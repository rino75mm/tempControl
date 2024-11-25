#pragma once

// ポットを生成するファクトリークラス

class LiquidInfo;
class Pot;

class PotFactory
{
public:

	PotFactory();
	~PotFactory();

	//------------------------------------
	/**
	 * ポットを生成
	 **/
	static Pot* create( int type, LiquidInfo* pWater );

	//------------------------------------
	/**
	 * ポットの定義
	 **/
	enum {
		STANDARD_POT,	// スタンダードポット
		PREMIUM_POT,	// プレミアムポット
	};
};


