#pragma once

// �^�C�}�[���^�C���A�b�v�������Ɏ��s����^�X�N�N���X

class TimerTask
{
public:
	TimerTask();
	virtual ~TimerTask();

	//------------------------------------
	/**
	 * �^�C�}�[���^�C���A�b�v�����Ƃ��Ɏ��s(�h���N���X�Ŏ���)
	 **/
	virtual void run() = 0;
};

