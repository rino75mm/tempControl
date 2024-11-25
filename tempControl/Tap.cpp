#include "Tap.h"

#include <iostream>
using namespace std;

#define RUNOFF 10.0

//---------------------------------------------------------
Tap::Tap()
    : _bOpen( false )
    , _runOff( RUNOFF )
{
}

//---------------------------------------------------------
Tap::~Tap()
{
}

//---------------------------------------------------------
void Tap::turnOn()
{
    if ( false == isOpen() ) {
        cout << "ŽÖŒû‚ðŠJ‚­" << endl;
    }
    _bOpen = true;
}

//---------------------------------------------------------
void Tap::turnOff()
{
    if ( true == isOpen() ) {
        cout << "ŽÖŒû‚ð•Â‚¶‚é" << endl;
    }
    _bOpen = false;
}

//---------------------------------------------------------
bool Tap::isOpen() const
{
    return _bOpen;
}

//---------------------------------------------------------
double Tap::getRunOff() const
{
    return _runOff;
}
