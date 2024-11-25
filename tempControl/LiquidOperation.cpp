#include "LiquidOperation.h"

#include "Controller.h"
#include "Environment.h"
#include "Heater.h"
#include "LevelIndicator.h"
#include "LevelSensor.h"
#include "OnOffController.h"
#include "PIDController.h"
#include "Pot.h"
#include "PotFactory.h"
#include "TempIndicator.h"
#include "TempSensor.h"
#include "Timer.h"
#include "WaterInfo.h"

#define HEAT_TRANSFER_COEFFICIENT    0.0008
#define TEMP_OUTSIDE                 20.0

#define SEC_10                       10
#define SEC_20                       20
#define SEC_30                       30
#define SEC_50                       50

//---------------------------------------------------------
LiquidOperation::LiquidOperation()
{
}

//---------------------------------------------------------
LiquidOperation::~LiquidOperation() 
{
}

//---------------------------------------------------------
LiquidInfo* LiquidOperation::createWater()
{
	string ident;
	double mass;
	double temp;

	cout << ">水の識別子は？" << endl;
	cin >> ident;
	cout << ">水の質量(g)は？ " << endl;
	cin >> mass;
	cout << ">水の温度(℃)は？ " << endl;
	cin >> temp;

	WaterInfo* pWater = new WaterInfo( "水", ident, mass, temp );

	_ASSERT( pWater );
	return pWater;
}

//---------------------------------------------------------
void LiquidOperation::doExperiment()
{
	LiquidInfo* pLiquid1 = createWater();
	LiquidInfo* pLiquid2 = createWater();
	_ASSERT( pLiquid1 );
	_ASSERT( pLiquid2 );

	cout << "【混合前】" << endl;
	pLiquid1->showLiquid();
	pLiquid2->showLiquid();
	bool state = pLiquid1->add( pLiquid2 );
	if ( false == state ) {
		return;
	}
	cout << "【混合後】" << endl;
	pLiquid1->showLiquid();

	double mass;
	cout << ">取り除く質量(g)は？ " << endl;
	cin >> mass;
	cout << "【除去前】" << endl;
	pLiquid1->showLiquid();
	pLiquid1->removeMass( mass );
	cout << "【除去後】" << endl;
	pLiquid1->showLiquid();

	delete( pLiquid1 );
	delete( pLiquid2 );
}

//---------------------------------------------------------
void LiquidOperation::heatWater()
{
	// 環境
	Environment environment( HEAT_TRANSFER_COEFFICIENT );
	environment.setTemp( TEMP_OUTSIDE );

	// タイマーを生成
	Timer timer;

	// ポットを生成
	int type = 0;
	cout << ">ポットは( 0:Standard, 1:Premium )？" << endl;
	cin >> type;
	LiquidInfo* pWater = LiquidOperation::createWater();
	Pot* pPot = PotFactory::create( type, pWater );
	pPot->setEnviroment( environment );
	pPot->powerOn();

	// タスクを追加
	timer.addTask( pPot );

	cout << "加熱前" << endl;
	cout << " 環境温度=" << environment.getTemp() << endl;
	pPot->showLiquidInfo();

	cout << "加熱中" << endl;
	pPot->turnHeaterOn();
	timer.start( SEC_10 );
	pPot->showLiquidInfo();

	cout << "水の追加" << endl;
	pWater = LiquidOperation::createWater();
	pPot->pourLiquid( pWater );
	pPot->showLiquidInfo();

	cout << "再加熱" << endl;
	timer.start( SEC_50 );
	pPot->showLiquidInfo();

	// 蛇口を開く
	pPot->turnTabOn();
	timer.start( SEC_30 );
	pPot->showLiquidInfo();

	// 蛇口を閉じる
	pPot->turnTabOff();
	timer.start( SEC_10 );
	pPot->showLiquidInfo();

	// ヒーターのスイッチ切る
	pPot->turnHeaterOff();

	cout << ">自然冷却中" << endl;
	timer.start( SEC_20 );
	pPot->showLiquidInfo();

	delete( pPot );
}

