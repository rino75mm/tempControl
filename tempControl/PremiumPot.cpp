#include "PremiumPot.h"

#include <iostream>
#include "PIDController.h"
using namespace std;

//---------------------------------------------------------
PremiumPot::PremiumPot( LiquidInfo* pWater )
    :Pot()
{
    cout << " �v���~�A���|�b�g�ғ���" << endl;
    assemble( pWater );
}

//---------------------------------------------------------
PremiumPot::~PremiumPot()
{
    cout << " �v���~�A���|�b�g��~" << endl;
}

//---------------------------------------------------------
void PremiumPot::assemble( LiquidInfo* pWater )
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
    PIDController* pController = new PIDController( &_heater, &_tempSensor, &_highLevelSensor, &_midLevelSensor, &_lowLevelSensor );
    _ASSERT( pController );
    pController->setPID( KP, KI, KD );
    _pController = pController;
}
