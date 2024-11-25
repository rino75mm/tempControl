#pragma once

class Subject;

// 観測者のクラス

class Observer
{
public:
	Observer();
	virtual ~Observer();

	//------------------------------------
	/**
	 * 観測者を更新
	 **/
	virtual void update( Subject* pSubject ) = 0;
};

