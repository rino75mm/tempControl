#include "Tube.h"

#include "Environment.h"
#include "LiquidInfo.h"
#include "Tap.h"
#include <iostream>
using namespace std;

#define PI 3.14

//---------------------------------------------------------
Tube::Tube()
    : TimerTask()
    , _radius( 0.0 )
    , _height( 0.0 )
    , _thickness( 0.0 )
    , _themalConducivity( 0.0 )
    , _themalConducivityCoeff( 0.0 )
    , _pLiquid( NULL )
    , _pEnvironment( NULL )
    , _pTap( new Tap )
{
    _ASSERT( _pTap );
}

//---------------------------------------------------------
Tube::Tube( double radius, double height, double thickness, double themalConducivity, Tap* pTap )
    : TimerTask()
    , _radius( radius )
    , _height( height )
    , _thickness( thickness )
    , _themalConducivity( themalConducivity )
    , _themalConducivityCoeff( themalConducivity / thickness )
    , _pLiquid( NULL )
    , _pEnvironment( NULL )
    , _pTap( pTap )
{
    _ASSERT( _pTap );
}

//---------------------------------------------------------
Tube::~Tube()
{
}

//---------------------------------------------------------
void Tube::transferHeat()
{
    _ASSERT ( _pLiquid );

    double losingJoule       = 0.0;
    double surfaceArea       = getSurfaceArea();
    double sideArea          = getSideArea();
    double tempOfLiquid      = _pLiquid->getTemp();
    double tempOfEnvironment = _pEnvironment->getTemp();

    // …‚Ì•\–Ê‚©‚ç‚Ì”M‘¹Ž¸
    losingJoule = _pEnvironment->getHeatTransferCoefficient() * surfaceArea * ( tempOfLiquid - tempOfEnvironment);

    // …“›‚Ì•Ç“à‚Ì”M’Ê‰ß‚É‚æ‚é”M‘¹Ž¸
    losingJoule += _themalConducivityCoeff * ( surfaceArea + sideArea ) * ( tempOfLiquid - tempOfEnvironment);

    // ”M‘¹Ž¸—Ê‚ðÝ’è
    _pLiquid->setLosingJoule( losingJoule );
}

//---------------------------------------------------------
void Tube::runOff()
{
    if ( !_pTap->isOpen() ) {
        return;
    }

    _pLiquid->runOff( _pTap->getRunOff() );
}

//---------------------------------------------------------
double Tube::getSurfaceArea() const
{
    double surfaceArea = PI * ( _radius * _radius );
    
    return surfaceArea;
}

//---------------------------------------------------------
double Tube::getSideArea() const
{
    double sideArea = ( 2 * _pLiquid->getVolume() ) / _radius;

    return sideArea;
}

//---------------------------------------------------------
void Tube::addLiquidInfo ( LiquidInfo* pLiquid )
{
    _ASSERT( pLiquid );

    if ( NULL == _pLiquid ) {
        _pLiquid = pLiquid;
    }
    else {
        _pLiquid->add( pLiquid );
    }
}

//---------------------------------------------------------
LiquidInfo* Tube::getLiquidInfo() const
{
    return _pLiquid;
}

//---------------------------------------------------------
void Tube::setEnvironment( Environment* pEnvironment )
{
    _ASSERT( pEnvironment );

    _pEnvironment = pEnvironment;
}

//---------------------------------------------------------
void Tube::setSize( double radius, double height, double thickness, double themalConducivity )
{
    _radius                 = radius;
    _height                 = height;
    _thickness              = thickness;
    _themalConducivity      = themalConducivity;
    _themalConducivityCoeff = themalConducivity / thickness;
}

//---------------------------------------------------------
double Tube::getHeight() const
{
    return _height;
}

//---------------------------------------------------------
double Tube::getLevel() const
{
    _ASSERT ( _pLiquid );

    double level = _pLiquid->getVolume() / getSurfaceArea();

    return level;
}

//---------------------------------------------------------
void Tube::turnTabOn()
{
    _pTap->turnOn();
}

//---------------------------------------------------------
void Tube::turnTabOff()
{
    _pTap->turnOff();
}

//---------------------------------------------------------
void Tube::run()
{
    transferHeat();
    runOff();
}
