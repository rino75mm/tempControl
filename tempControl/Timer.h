#pragma once

class TimerTask;

// タイマークラス

class Timer
{
private:
	//------------------------------------
	/**
	 * タイマータスクの最大数
	 **/
	static const int MAX_TASK_COUNT = 10;

	//------------------------------------
	/**
	 * キューに登録されているタスク数
	 **/
	int _taskCount;

	//------------------------------------
	/**
	 * タイマータスクのキュー
	 **/
	TimerTask* _pQueue[ MAX_TASK_COUNT ];

public:
	Timer();
	~Timer();

	//------------------------------------
	/**
	 * キューにタスクを追加
	 **/
	void addTask( TimerTask* pTask );

	//------------------------------------
	/**
	 * タイマー開始
	 **/
	void start( int second );
};

