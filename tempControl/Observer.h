#pragma once

class Subject;

// �ϑ��҂̃N���X

class Observer
{
public:
	Observer();
	virtual ~Observer();

	//------------------------------------
	/**
	 * �ϑ��҂��X�V
	 **/
	virtual void update( Subject* pSubject ) = 0;
};

