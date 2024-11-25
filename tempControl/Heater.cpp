#include "Heater.h"

#include "LiquidInfo.h"
#include "Tube.h"

#define PERCENT_COEF 0.01

//---------------------------------------------------------
Heater::Heater()
	: TimerTask()
	, ElectricalApparatus()
	, _watt( 0 )
	, _outputRatio( 0.0 )
	, _pTarget( NULL )
	, _switchState( OFF )
{
	powerOn();
	cout << " �q�[�^�[�d��ON" << endl;
}

//---------------------------------------------------------
Heater::Heater( int watt ) 
	: TimerTask()
	, ElectricalApparatus()
	, _watt( watt )
	, _outputRatio( 0.0 )
	, _pTarget( NULL )
	, _switchState( OFF )
{
	powerOn();
	cout << " �q�[�^�[�ғ���" << endl;
}

//---------------------------------------------------------
Heater::~Heater()
{
	powerOff();
	cout << " �q�[�^�[��~" << endl;
}

//---------------------------------------------------------
void Heater::switchOn()
{
	_switchState = ON;
	cout << "�q�[�^�[�X�C�b�`ON" << endl;
}

//---------------------------------------------------------
void Heater::switchOff() 
{
	_switchState = OFF;
	_ASSERT( _pTarget );
	_pTarget->getLiquidInfo()->setJoule( 0.0 );
	cout << "�q�[�^�[�X�C�b�`OFF" << endl;
}

//---------------------------------------------------------
Switch Heater::getSwitchState() const
{
	return _switchState;
}

//---------------------------------------------------------
void Heater::heat()
{
	int second = 1;
	double joule = ( _watt * ( _outputRatio * PERCENT_COEF ) ) * second;

	_pTarget->getLiquidInfo()->setJoule( joule );
}

//---------------------------------------------------------
void Heater::setWatt( int watt )
{
	_watt = watt;
}

//---------------------------------------------------------
void Heater::setTarget( Tube* pTarget )
{
	_ASSERT( pTarget );

	_pTarget = pTarget;
}

//---------------------------------------------------------
void Heater::setOutputRatio( int ratio )
{
	if ( ( 0 > ratio ) || ( 100 < ratio ) ) {
		return;
	}

	_outputRatio = ratio;
}

//---------------------------------------------------------
void Heater::run()
{
	if ( OFF == getSwitchState() ) {
		return;
	}
	if ( 100 <= _pTarget->getLiquidInfo()->getTemp() ) {
		switchOff();
		return;
	}

	heat();
}


