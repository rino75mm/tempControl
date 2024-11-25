#include "LiquidInfo.h"

//---------------------------------------------------------
LiquidInfo::LiquidInfo( string liquidType, string ident, double mass, double temp, double specificHeat, double density )
	 :TimerTask()
	 ,_liquidType( liquidType )
	 ,_ident( ident )
	 ,_mass( mass )
	 ,_temp( temp )
	 ,_specificHeat( specificHeat )
	 ,_joule( 0.0 )
	 ,_losingJoule( 0.0 )
	 , _volume( mass / density )
	 ,_density( density )
{
}

//---------------------------------------------------------
LiquidInfo::~LiquidInfo()
{
}

//---------------------------------------------------------
bool LiquidInfo::isPossibleToAddLiquid( LiquidInfo* pLiquid )
{
	_ASSERT( pLiquid );

	if ( ( 0 == _mass ) && 
		 ( 0 == pLiquid->_mass ) ) {
		return false;
	}
	return true;
}

//---------------------------------------------------------
double LiquidInfo::getThemalBalancedTemp()
{
	double themalBalanced = 0.0;
	themalBalanced = _mass * _specificHeat;

	return themalBalanced;
}

//---------------------------------------------------------
string LiquidInfo::getLiquidType() const
{
	return _liquidType;
}

//---------------------------------------------------------
string LiquidInfo::getIdent() const
{
	return _ident;
}

//---------------------------------------------------------
double LiquidInfo::getMass() const
{
	return _mass;
}

//---------------------------------------------------------
double LiquidInfo::getTemp() const
{
	return _temp;
}

//---------------------------------------------------------
double LiquidInfo::getSpecificHeat() const
{
	return _specificHeat;
}

//---------------------------------------------------------
double LiquidInfo::getJoule() const
{
	return _joule;
}

//---------------------------------------------------------
double LiquidInfo::getVolume() const
{
	return _volume;
}

//---------------------------------------------------------
void LiquidInfo::showLiquid() const
{
	cout << " " << getLiquidType() << getIdent() << "=(éøó ,ëÃêœ,â∑ìx)=(";
	cout << getMass() << ",";
	cout << getVolume() << ",";
	cout << getTemp() << ")" << endl;
}

//---------------------------------------------------------
bool LiquidInfo::add( LiquidInfo* pLiquid )
{
	_ASSERT( pLiquid );

	if ( !isMixable( pLiquid ) || 
		 !isPossibleToAddLiquid( pLiquid ) ) {
		cout << ">ç¨çáÇ≈Ç´Ç‹ÇπÇÒ" << endl;
		return false;
	}

	double themalBalanced1 = this->getThemalBalancedTemp();
	double themalBalanced2 = pLiquid->getThemalBalancedTemp();

	_mass   = _mass + pLiquid->getMass();
	_volume = _mass / _density;
	_temp   = ( ( themalBalanced1 * _temp ) + ( themalBalanced2 * pLiquid->_temp ) ) / ( themalBalanced1 + themalBalanced2 );

	// ãÛÇ…Ç∑ÇÈ
	pLiquid->_mass   = 0.0;
	pLiquid->_volume = 0.0;
	pLiquid->_temp   = 0.0;

	return true;
}

//---------------------------------------------------------
void LiquidInfo::removeMass( double mass )
{
	_mass = _mass - mass;

	if ( 0 > _mass ) {
		_mass = 0;
	}
	_volume = _mass / _density;
}

//---------------------------------------------------------
void LiquidInfo::setJoule( double joule )
{
	if ( 0 > joule ) {
		joule = 0;
	}

	_joule = joule;
}

//---------------------------------------------------------
void LiquidInfo::setLosingJoule( double losingJoule )
{
	_losingJoule = losingJoule;
}

//---------------------------------------------------------
void LiquidInfo::changedTemp()
{
	double risingTemp = ( _joule - _losingJoule ) / ( _specificHeat * _mass );
	_temp += risingTemp;
}

//---------------------------------------------------------
void LiquidInfo::runOff( double runOff )
{
	double mass = runOff * _density;
	removeMass( mass );
}

//---------------------------------------------------------
void LiquidInfo::run()
{
	changedTemp();
}
