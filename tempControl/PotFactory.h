#pragma once

// �|�b�g�𐶐�����t�@�N�g���[�N���X

class LiquidInfo;
class Pot;

class PotFactory
{
public:

	PotFactory();
	~PotFactory();

	//------------------------------------
	/**
	 * �|�b�g�𐶐�
	 **/
	static Pot* create( int type, LiquidInfo* pWater );

	//------------------------------------
	/**
	 * �|�b�g�̒�`
	 **/
	enum {
		STANDARD_POT,	// �X�^���_�[�h�|�b�g
		PREMIUM_POT,	// �v���~�A���|�b�g
	};
};


