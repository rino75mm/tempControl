#include "ElectricalApparatus.h"

#include <iostream>
#include <string>
using namespace std;

//---------------------------------------------------------
ElectricalApparatus::ElectricalApparatus()
	: _powerState( OFF )
{
}

//---------------------------------------------------------
ElectricalApparatus::~ElectricalApparatus()
{
}

//---------------------------------------------------------
void ElectricalApparatus::powerOn()
{
	if ( OFF == getPowerState() ) {
		cout << "�d��ON" << endl;
	}
	_powerState = ON;
}

//---------------------------------------------------------
void ElectricalApparatus::powerOff()
{
	if ( ON == getPowerState() ) {
		cout << "�d��OFF" << endl;
	}
	_powerState = OFF;
}

//---------------------------------------------------------
Switch ElectricalApparatus::getPowerState() const
{
	return _powerState;
}
