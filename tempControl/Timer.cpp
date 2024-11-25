#include "Timer.h"

#include "TimerTask.h"
#include <iostream>
using namespace std;

//---------------------------------------------------------
Timer::Timer()
	:_taskCount( 0 )
{
	for ( int i = 0; i < MAX_TASK_COUNT; i++ ) {
		_pQueue[ i ] = NULL;
	}
}

//---------------------------------------------------------
Timer::~Timer()
{
}

//---------------------------------------------------------
void Timer::start( int second )
{
	for ( int sec = 1; sec <= second; sec++ ) {
		for ( int i = 0; i < _taskCount; i++ ) {
			_ASSERT( _pQueue[ i ] );
			_pQueue[ i ]->run();
		}
	}
}

//---------------------------------------------------------
void Timer::addTask( TimerTask* pTask )
{
	_ASSERT( pTask );
	if ( MAX_TASK_COUNT< _taskCount ) {
		cout << ">Å¶É^ÉXÉNÇ™Ç¢Ç¡ÇœÇ¢Ç≈Ç∑" << endl;
		return;
	}

	_pQueue[ _taskCount ] = pTask;
	_taskCount++;
}
