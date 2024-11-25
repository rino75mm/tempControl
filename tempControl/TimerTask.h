#pragma once

// タイマーがタイムアップした時に実行するタスククラス

class TimerTask
{
public:
	TimerTask();
	virtual ~TimerTask();

	//------------------------------------
	/**
	 * タイマーがタイムアップしたときに実行(派生クラスで実装)
	 **/
	virtual void run() = 0;
};

