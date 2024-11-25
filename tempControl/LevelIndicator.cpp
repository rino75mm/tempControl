#include "LevelIndicator.h"

#include <iostream>
#include "LevelSensor.h"
#include "Subject.h"
#include <string>
using namespace std;

//---------------------------------------------------------
LevelIndicator::LevelIndicator()
	: ElectricalApparatus()
	, Observer()
	, _pHigh( NULL )
	, _pMid( NULL )
	, _pLow( NULL )
	, _bReachedToHighLevel( false )
	, _bReachedToMidLevel( false )
	, _bReachedToLowLevel( false )
	, _countForLevelIndication( 0 )
{
}

//---------------------------------------------------------
LevelIndicator::LevelIndicator( LevelSensor* pHigh, LevelSensor* pMid, LevelSensor* pLow )
	: ElectricalApparatus()
	, Observer()
	, _pHigh( pHigh )
	, _pMid( pMid )
	, _pLow( pLow )
	, _bReachedToHighLevel( false )
	, _bReachedToMidLevel( false )
	, _bReachedToLowLevel( false )
	, _countForLevelIndication( 0 )
{
	_ASSERT( _pHigh );
	_ASSERT( _pMid );
	_ASSERT( _pLow );
}

//---------------------------------------------------------
LevelIndicator::~LevelIndicator()
{
}

//---------------------------------------------------------
void LevelIndicator::setLevelSensor( LevelSensor* pHigh, LevelSensor* pMid, LevelSensor* pLow )
{
	_ASSERT( pHigh );
	_ASSERT( pMid );
	_ASSERT( pLow );

	_pHigh = pHigh;
	_pMid  = pMid;
	_pLow  = pLow;
}

//---------------------------------------------------------
void LevelIndicator::update( Subject* pSubject )
{
	_ASSERT( pSubject );

	if ( pSubject == _pHigh ) {
		_bReachedToHighLevel = static_cast< LevelSensor* >( pSubject )->isReached();
		_countForLevelIndication++;
	}
	else if ( pSubject == _pMid ) {
		_bReachedToMidLevel = static_cast< LevelSensor* >( pSubject )->isReached();
		_countForLevelIndication++;
	}
	else if ( pSubject == _pLow ) {
		_bReachedToLowLevel = static_cast< LevelSensor* >( pSubject )->isReached();
		_countForLevelIndication++;
	}
	else {
		return;
	}

	// �S�Ẵ��x���Z���T�̔��肪����������A�R���\�[���ɕ\������
	if ( 3 != _countForLevelIndication ) {
		return;
	}

	string highLevel = _bReachedToHighLevel ? "ON" : "OFF";
	string midLevel  = _bReachedToMidLevel ? "ON" : "OFF";
	string lowLevel  = _bReachedToLowLevel ? "ON" : "OFF";

	cout << ">���ʕ\����F";
	cout << " (��,��,��)=" << "(" << lowLevel << ","
		                          << midLevel << ","
		                          << highLevel << ")" << "�ł� " << endl;

	_countForLevelIndication = 0;
}
