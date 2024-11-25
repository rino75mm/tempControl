#include "Subject.h"

#include <algorithm>
#include <iostream>
#include "Observer.h"

//---------------------------------------------------------
Subject::Subject()
	:_observer( NULL )
{
}

//---------------------------------------------------------
Subject::~Subject()
{
}

//---------------------------------------------------------
void Subject::addObserver( Observer* pObserver )
{
	_ASSERT( pObserver );

	_observer.push_back( pObserver );
}

//---------------------------------------------------------
void Subject::removeObserver( Observer* pObserver )
{
	_ASSERT( pObserver );

	_observer.remove( pObserver );
}

//---------------------------------------------------------
void Subject::notify()
{
	for ( auto* pObserver : _observer ) {
		pObserver->update( this );
	}
}
