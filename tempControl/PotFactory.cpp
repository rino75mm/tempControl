#include "PotFactory.h"

#include <iostream>
#include "NullPot.h"
#include "StandardPot.h"
#include "PremiumPot.h"
using namespace std;

//---------------------------------------------------------
PotFactory::PotFactory()
{
}

//---------------------------------------------------------
PotFactory::~PotFactory()
{
}

//---------------------------------------------------------
Pot* PotFactory::create( int type, LiquidInfo* pWater )
{
	Pot* pPot = NULL;

	switch ( type )
	{
	case STANDARD_POT:
	{
		pPot = new StandardPot( pWater );
		break;
	}
	case PREMIUM_POT:
	{
		pPot = new PremiumPot( pWater );
		break;
	}
	default:
		pPot = new NullPot();
		break;
	}

	double presetTemp;
	cout << ">設定温度(t)は( 20 < t <= 98.5 )？ " << endl;
	cin >> presetTemp;
	pPot->setSV( presetTemp );

	_ASSERT( pPot );
	return pPot;
}





