#pragma once

#include "LiquidInfo.h"
#include <iostream>
#include <string>
using namespace std;

// 水の情報を保持するクラス

class WaterInfo : public LiquidInfo
{
public:
	WaterInfo( string liquidType, string ident, double mass, double temp );
	virtual ~WaterInfo();

	//------------------------------------
	/**
	 * 混合できる液体同士か判定
	 **/
	virtual bool isMixable( LiquidInfo* pLiquid ) const;
};

