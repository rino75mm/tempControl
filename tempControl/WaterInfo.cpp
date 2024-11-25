#include "WaterInfo.h"

#define SPECIFIC_HEAT 4.2
#define DENSITY       1.0

//---------------------------------------------------------
WaterInfo::WaterInfo( string liquidType, string ident, double mass, double temp )
	:LiquidInfo( liquidType, ident, mass, temp, SPECIFIC_HEAT, DENSITY )
{
}

//---------------------------------------------------------
WaterInfo::~WaterInfo()
{
}

//---------------------------------------------------------
bool WaterInfo::isMixable( LiquidInfo* pLiquid ) const
{
	_ASSERT( pLiquid );

	return typeid( WaterInfo ) == typeid( *pLiquid );
}

