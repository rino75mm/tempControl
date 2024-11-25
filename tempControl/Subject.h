#pragma once

#include <list>
using namespace std;

class Observer;

// �ϑ��Ώۂ̃N���X

class Subject
{
public:
	Subject();
	virtual ~Subject();

	//------------------------------------
	/**
	 * �ϑ��҂�o�^
	 **/
	void addObserver( Observer* pObserver );

	//------------------------------------
	/**
	 * �ϑ��҂�����
	 **/
	void removeObserver( Observer* pObserver );

	//------------------------------------
	/**
	 * �ϑ��Ώۂ̕ω����ϑ��҂ɒʒm����
	 **/
	void notify();

protected:
	//------------------------------------
	/**
	 * �ϑ���
	 **/
	list< Observer* > _observer;
};

