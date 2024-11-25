#include "PremiumPot.h"

#include <iostream>
#include "PIDController.h"
using namespace std;

//---------------------------------------------------------
PremiumPot::PremiumPot( LiquidInfo* pWater )
    :Pot()
{
    cout << " プレミアムポット稼働中" << endl;
    assemble( pWater );
}

//---------------------------------------------------------
PremiumPot::~PremiumPot()
{
    cout << " プレミアムポット停止" << endl;
}

//---------------------------------------------------------
void PremiumPot::assemble( LiquidInfo* pWater )
{
    //水筒
    _tube.setSize( RADIUS, HEIGHT, THICKNESS, THERMAL_CONDUCTIVITY );
    _tube.addLiquidInfo( pWater );

    //ヒータ
    _heater.setWatt( WATT );
    _heater.setTarget( &_tube );

    //温度センサ
    _tempSensor.setSubject( &_tube );
    _tempSensor.addObserver( &_tempIndicator );

    //温度表示器
    _tempIndicator.setTempSensor( &_tempSensor );

    //レベルセンサ(LOW)
    _lowLevelSensor.setTube( &_tube );
    _lowLevelSensor.setHeight( LOW_POS );
    _lowLevelSensor.addObserver( &_levelIndicator );

    //レベルセンサ(MID)
    _midLevelSensor.setTube( &_tube );
    _midLevelSensor.setHeight( MID_POS );
    _midLevelSensor.addObserver( &_levelIndicator );

    //レベルセンサ(HIGH)
    _highLevelSensor.setTube( &_tube );
    _highLevelSensor.setHeight( HIGH_POS );
    _highLevelSensor.addObserver( &_levelIndicator );

    //レベル表示器
    _levelIndicator.setLevelSensor( &_highLevelSensor, &_midLevelSensor, &_lowLevelSensor );

    //コントローラ
    PIDController* pController = new PIDController( &_heater, &_tempSensor, &_highLevelSensor, &_midLevelSensor, &_lowLevelSensor );
    _ASSERT( pController );
    pController->setPID( KP, KI, KD );
    _pController = pController;
}
