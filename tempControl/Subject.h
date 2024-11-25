#pragma once

#include <list>
using namespace std;

class Observer;

// ŠÏ‘ª‘ÎÛ‚ÌƒNƒ‰ƒX

class Subject
{
public:
	Subject();
	virtual ~Subject();

	//------------------------------------
	/**
	 * ŠÏ‘ªÒ‚ğ“o˜^
	 **/
	void addObserver( Observer* pObserver );

	//------------------------------------
	/**
	 * ŠÏ‘ªÒ‚ğ‰ğœ
	 **/
	void removeObserver( Observer* pObserver );

	//------------------------------------
	/**
	 * ŠÏ‘ª‘ÎÛ‚Ì•Ï‰»‚ğŠÏ‘ªÒ‚É’Ê’m‚·‚é
	 **/
	void notify();

protected:
	//------------------------------------
	/**
	 * ŠÏ‘ªÒ
	 **/
	list< Observer* > _observer;
};

