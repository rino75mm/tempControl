#include "Pot.h"

#include "Controller.h"
#include "LiquidInfo.h"
#include "Tap.h"

//------------------------------------
Pot::Pot()
    : ElectricalApparatus()
    , TimerTask()
    , _tube()
    , _heater()
    , _tempSensor()
    , _tempIndicator()
    , _lowLevelSensor()
    , _midLevelSensor()
    , _highLevelSensor()
    , _levelIndicator()
    , _pController( NULL )
{
    powerOn();
}

//------------------------------------
Pot::~Pot()
{
    _tempSensor.removeObserver( &_tempIndicator );
    _lowLevelSensor.removeObserver( &_levelIndicator );
    _midLevelSensor.removeObserver( &_levelIndicator );
    _highLevelSensor.removeObserver( &_levelIndicator );
    powerOff();
}

//------------------------------------
void Pot::turnHeaterOn()
{
    _heater.switchOn();
}

//------------------------------------
void Pot::turnHeaterOff()
{
    _heater.switchOff();
}

//------------------------------------
void Pot::turnTabOn()
{
    _tube.turnTabOn();
}

//------------------------------------
void Pot::turnTabOff()
{
    _tube.turnTabOff();
}

//------------------------------------
void Pot::pourLiquid( LiquidInfo* pWater )
{
    _tube.addLiquidInfo( pWater );
}

//------------------------------------
void Pot::showLiquidInfo() const
{
    LiquidInfo* pWater = _tube.getLiquidInfo();
    _ASSERT( pWater );

    pWater->showLiquid();
}

//------------------------------------
void Pot::setEnviroment( Environment& rEnvironment )
{
    _tube.setEnvironment( &rEnvironment );
}

//------------------------------------
void Pot::setSV( double& rTemp )
{
    _pController->setSV( rTemp );
}

//------------------------------------
void Pot::run()
{
    LiquidInfo* pWater = _tube.getLiquidInfo();
    _ASSERT( pWater );
    _ASSERT( _pController );

    pWater->run();
    _tempSensor.run();
    _lowLevelSensor.run();
    _midLevelSensor.run();
    _highLevelSensor.run();
    _pController->run();
    _tube.run();
    _heater.run();
}
