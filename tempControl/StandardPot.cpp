#include "StandardPot.h"

#include "Controller.h"
#include <iostream>
#include "LiquidOperation.h"
#include "OnOffController.h"
#include "Tap.h"
using namespace std;

//---------------------------------------------------------
StandardPot::StandardPot( LiquidInfo* pWater )
    :Pot()
{
    cout << " �X�^���_�[�h���|�b�g�ғ���" << endl;
    assemble( pWater );
}

//---------------------------------------------------------
StandardPot::~StandardPot()
{
    cout << " �X�^���_�[�h���|�b�g��~" << endl;
}

//---------------------------------------------------------
void StandardPot::assemble( LiquidInfo* pWater )
{
    //����
    _tube.setSize( RADIUS, HEIGHT, THICKNESS, THERMAL_CONDUCTIVITY );
    _tube.addLiquidInfo( pWater );

    //�q�[�^
    _heater.setWatt( WATT );
    _heater.setTarget( &_tube );

    //���x�Z���T
    _tempSensor.setSubject( &_tube );
    _tempSensor.addObserver( &_tempIndicator );

    //���x�\����
    _tempIndicator.setTempSensor( &_tempSensor );

    //���x���Z���T(LOW)
    _lowLevelSensor.setTube( &_tube );
    _lowLevelSensor.setHeight( LOW_POS );
    _lowLevelSensor.addObserver( &_levelIndicator );

    //���x���Z���T(MID)
    _midLevelSensor.setTube( &_tube );
    _midLevelSensor.setHeight( MID_POS );
    _midLevelSensor.addObserver( &_levelIndicator );

    //���x���Z���T(HIGH)
    _highLevelSensor.setTube( &_tube );
    _highLevelSensor.setHeight( HIGH_POS );
    _highLevelSensor.addObserver( &_levelIndicator );

    //���x���\����
    _levelIndicator.setLevelSensor( &_highLevelSensor, &_midLevelSensor, &_lowLevelSensor );

    //�R���g���[��
    OnOffController* pController = new OnOffController( &_heater, &_tempSensor, &_highLevelSensor, &_midLevelSensor, &_lowLevelSensor );
    _ASSERT( pController );
    pController->setHysteresis( HYSTERESIS );
    _pController = pController;
}
