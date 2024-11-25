#pragma once

class TimerTask;

// �^�C�}�[�N���X

class Timer
{
private:
	//------------------------------------
	/**
	 * �^�C�}�[�^�X�N�̍ő吔
	 **/
	static const int MAX_TASK_COUNT = 10;

	//------------------------------------
	/**
	 * �L���[�ɓo�^����Ă���^�X�N��
	 **/
	int _taskCount;

	//------------------------------------
	/**
	 * �^�C�}�[�^�X�N�̃L���[
	 **/
	TimerTask* _pQueue[ MAX_TASK_COUNT ];

public:
	Timer();
	~Timer();

	//------------------------------------
	/**
	 * �L���[�Ƀ^�X�N��ǉ�
	 **/
	void addTask( TimerTask* pTask );

	//------------------------------------
	/**
	 * �^�C�}�[�J�n
	 **/
	void start( int second );
};

