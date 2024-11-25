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
		cout << "“dŒ¹ON" << endl;
	}
	_powerState = ON;
}

//---------------------------------------------------------
void ElectricalApparatus::powerOff()
{
	if ( ON == getPowerState() ) {
		cout << "“dŒ¹OFF" << endl;
	}
	_powerState = OFF;
}

//---------------------------------------------------------
Switch ElectricalApparatus::getPowerState() const
{
	return _powerState;
}
